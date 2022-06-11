#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Cuidador.h"
#include "FebreEnum.h"
#include "Registro.h"
#include "Idoso.h"
#include "Lista.h"
#include "Localizador.h"
#include "StreamReader.h"
#include "StreamWriter.h"
#include "EdCare.h"

static void AtualizarIdosos(EdCare Sistema_EdCare);

static void AtualizarCuidadores(EdCare Sistema_EdCare);

static char *ProcessarInformacoesIdoso(Idoso idoso);

static void RemoverIdoso(EdCare Sistema_EdCare, Idoso idoso);

struct edcare
{
    Lista idosos;
    Lista cuidadores;
};

EdCare CriarEdCare(){
    EdCare Sistema_EdCare = (EdCare)malloc(sizeof(struct edcare));
    assert(Sistema_EdCare != NULL);

    Sistema_EdCare->idosos = CriarLista();
    Sistema_EdCare->cuidadores = CriarLista();    

    return Sistema_EdCare;
}

void DeletarEdCare(EdCare Sistema_EdCare){
    DeletarLista(Sistema_EdCare->idosos, &DeletarIdoso);
    DeletarLista(Sistema_EdCare->cuidadores, &DeletarCuidador);
    free(Sistema_EdCare);
}

void CriaVinculosdeApoio(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    StreamReader sr = CriarStreamReader("apoio.txt");
    char* linha = ReadLine(sr);

    //colocando Idosos no sistema 
    char* nome = strtok(linha, ";");
    while(nome != NULL){
        AdicionarItem(Sistema_EdCare->idosos, CriarIdoso(nome));
        nome = strtok(NULL, ";");
    }
    free(linha);

    Idoso idoso = NULL;
    char* nomeIdoso = NULL;

    Idoso amigo = NULL;
    char* nomeAmigo = NULL;
    
    //colocando idosos como amigos
    linha = ReadLine(sr);
    while(RecuperaEndOfStream(sr) != EOF){
        sscanf(linha, " %m[^;];%ms", &nomeIdoso, &nomeAmigo);

        idoso = BuscarItem(Sistema_EdCare->idosos, &CompararNomeIdoso, nomeIdoso);
        amigo = BuscarItem(Sistema_EdCare->idosos, &CompararNomeIdoso, nomeAmigo);
        AdicionarAmigo(idoso, amigo);

        free(nomeIdoso);
        free(nomeAmigo);
        free(linha);
        
        linha = ReadLine(sr);
    }

    DeletarStreamReader(sr);
}

void CriaVinculosdeCuidadores(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    StreamReader sr = CriarStreamReader("cuidadores.txt");
    char* linha = ReadLine(sr);

    //colocando cuidadore no sistema 
    char* nome = strtok(linha, ";");
    while(nome != NULL){
        AdicionarItem(Sistema_EdCare->cuidadores, CriarCuidador(nome));
        nome = strtok(NULL, ";");
    }
    free(linha);

    Idoso idoso = NULL;
    char* nomeIdoso = NULL;

    Cuidador cuidador = NULL;
    char* nomeCuidador = NULL;

    //colocando idosos como amigos
    linha = ReadLine(sr);
    while(RecuperaEndOfStream(sr) != EOF){
        nomeIdoso = strtok(linha, ";");
        idoso = BuscarItem(Sistema_EdCare->idosos, &CompararNomeIdoso, nomeIdoso);

        nomeCuidador = strtok(NULL, ";");
        while(nomeCuidador != NULL){
            AdicionarCuidador(idoso, BuscarItem(Sistema_EdCare->cuidadores, &CompararNomeCuidador, nomeCuidador));
            nomeCuidador = strtok(NULL, ";");
        }

        free(linha);
        linha = ReadLine(sr);
    }  
    
    DeletarStreamReader(sr);
}

void AtualizarEstruturas(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    AtualizarIdosos(Sistema_EdCare);
    AtualizarCuidadores(Sistema_EdCare);
}

void ProcessarInformacoes(EdCare Sistema_EdCare){
    int i = 0;
    Idoso idoso = BuscarItemIndex(Sistema_EdCare->idosos, i);

    while(idoso != NULL){
        StreamWriter sw = RecuperaStreamWriterIdoso(idoso);
        char *string = ProcessarInformacoesIdoso(idoso);
        WriteLine(sw, string);

        if(strcmp(string, "falecimento") == 0){
            i--;
            RemoverIdoso(Sistema_EdCare, idoso);
        }
        free(string);

        i++;
        idoso = BuscarItemIndex(Sistema_EdCare->idosos, i);
    }
}

static void AtualizarIdosos(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    void *idoso = NULL;
    for(ForEach(Sistema_EdCare->idosos, &idoso); idoso != NULL; ForEach(NULL, &idoso)){
        AtualizarIdoso((Idoso) idoso);
    }
}

static void AtualizarCuidadores(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    void *cuidador = NULL;
    for(ForEach(Sistema_EdCare->cuidadores, &cuidador); cuidador != NULL; ForEach(NULL, &cuidador)){
        AtualizarCuidador((Cuidador) cuidador);
    }
}

static char *ProcessarInformacoesIdoso(Idoso idoso){
    char buffer[1000];

    //falecimento
    if(!EhIdosoVivo(idoso)){
        return strdup("falecimento");
    }

    Registro registroIdoso = RecuperaRegistroIdoso(idoso);

    //queda
    int queda = RecuperaQuedaRegistro(registroIdoso);
    if(queda == 1){
        Cuidador cuidador = BuscarCuidadorMaisProximo(idoso);
        sprintf(buffer, "queda, acionou %s", RecuperaNomeCuidador(cuidador));

        //verificando o contador de febre baixa
        int contadorFebreBaixa = RecuperaContadorFebreBaixaRegistro(registroIdoso);
        if(contadorFebreBaixa == 4){
            ResetarContadorFebreBaixaRegistro(registroIdoso);
        }

        //verificando o contador de febre baixa
        FebreEnum febre = RecuperaFebreRegistro(registroIdoso);
        if(febre == FebreAlta){
            ResetarContadorFebreBaixaRegistro(registroIdoso);
        }

        return strdup(buffer);
    }

    //febre alta
    FebreEnum febre = RecuperaFebreRegistro(registroIdoso);
    if(febre == FebreAlta){
        ResetarContadorFebreBaixaRegistro(registroIdoso);

        Cuidador cuidador = BuscarCuidadorMaisProximo(idoso);
        sprintf(buffer, "febre alta, acionou %s", RecuperaNomeCuidador(cuidador));
        return strdup(buffer);
    }

    //febre baixa
    if(febre == FebreBaixa){
        int contadorFebreBaixa = RecuperaContadorFebreBaixaRegistro(registroIdoso);
        if(contadorFebreBaixa == 4){
            ResetarContadorFebreBaixaRegistro(registroIdoso);

            Cuidador cuidador = BuscarCuidadorMaisProximo(idoso);
            sprintf(buffer, "febre baixa pela quarta vez, acionou %s", RecuperaNomeCuidador(cuidador));
            return strdup(buffer);
        }
        else{
            Idoso amigo = BuscarAmigoMaisProximo(idoso);
            if(amigo == NULL){
                return strdup("Febre baixa mas, infelizmente, o idoso está sem amigos na rede");
            }
            else{
                sprintf(buffer, "febre baixa, acionou amigo %s", RecuperaNomeIdoso(amigo));
                return strdup(buffer);
            }
        }
    }

    //sem febre
    return strdup("tudo ok");

}

static void RemoverIdoso(EdCare Sistema_EdCare, Idoso idoso){
    RemoverItemChave(Sistema_EdCare->idosos, &CompararNomeIdoso, RecuperaNomeIdoso(idoso));
    DeletarIdoso(idoso);
}