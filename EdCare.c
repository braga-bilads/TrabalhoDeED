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

/* 
 * Adiciona um idoso a lista de idosos do sistema edcare
 * inputs: o sistema edcare e o idoso
 * output: nenhum
 * pre-condicao: o sistema edcare e o idoso existem
 */
static void AdicionarIdosoEdCare(EdCare Sistema_EdCare, Idoso idoso);

/* 
 * Remove um idoso da lista de idosos do sistema edcare
 * inputs: o sistema edcare e o idoso
 * output: nenhum
 * pre-condicao: o sistema edcare e o idoso existem
 */
static void RemoverIdosoEdCare(EdCare Sistema_EdCare, Idoso idoso);

/* 
 * Busca um idoso na lista de idosos do sistema edcare
 * inputs: o sistema edcare e o nome do idoso
 * output: o idoso
 * pre-condicao: o sistema edcare e o nome do idoso existem
 */
static Idoso BuscarIdosoEdCare(EdCare Sistema_EdCare, char *nome);

/* 
 * Atualiza os dados de todos idosos registrados no sistema edcare
 * inputs: o sistema edcare
 * output: nenhum
 * pre-condicao: o sistema edcare existe
 */
static void AtualizarIdososEdCare(EdCare Sistema_EdCare);

/* 
 * Adiciona um cudador a lista de cuidadores do sistema edcare
 * inputs: o sistema edcare e o cudador
 * output: nenhum
 * pre-condicao: o sistema edcare e o cudador existem
 */
static void AdicionarCuidadorEdCare(EdCare Sistema_EdCare, Cuidador cuidador);

/* 
 * Busca um cuidador na lista de cuidadores do sistema edcare
 * inputs: o sistema edcare e o nome do cuidador
 * output: o cuidador
 * pre-condicao: o sistema edcare e o nome do cuidador existem
 */
static Cuidador BuscarCuidadorEdCare(EdCare Sistema_EdCare, char *nome);

/* 
 * Atualiza os dados de todos cuidadores registrados no sistema edcare
 * inputs: o sistema edcare
 * output: nenhum
 * pre-condicao: o sistema edcare existe
 */
static void AtualizarCuidadoresEdCare(EdCare Sistema_EdCare);

/* 
 * Processa as informacoes do idoso e gera um feedback
 * inputs: o idoso
 * output: o feedback gerado
 * pre-condicao: o idoso existe
 */
static char *ProcessarInformacoesIdosoEdCare(Idoso idoso);

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
    assert(Sistema_EdCare != NULL);

    DeletarLista(Sistema_EdCare->idosos, &DeletarIdoso);
    DeletarLista(Sistema_EdCare->cuidadores, &DeletarCuidador);
    free(Sistema_EdCare);
}

void CriaVinculosdeApoioEdCare(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    StreamReader sr = CriarStreamReader("apoio.txt");
    char* linha = ReadLine(sr);

    //colocando Idosos no sistema 
    char* nome = strtok(linha, ";");
    while(nome != NULL){
        AdicionarIdosoEdCare(Sistema_EdCare, CriarIdoso(nome));
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

        idoso = BuscarIdosoEdCare(Sistema_EdCare, nomeIdoso);
        amigo = BuscarIdosoEdCare(Sistema_EdCare, nomeAmigo);
        AdicionarAmigo(idoso, amigo);

        free(nomeIdoso);
        free(nomeAmigo);
        free(linha);
        
        linha = ReadLine(sr);
    }

    DeletarStreamReader(sr);
}

void CriaVinculosdeCuidadoresEdCare(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    StreamReader sr = CriarStreamReader("cuidadores.txt");
    char* linha = ReadLine(sr);

    //colocando cuidadores no sistema
    char* nome = strtok(linha, ";");
    while(nome != NULL){
        AdicionarCuidadorEdCare(Sistema_EdCare, CriarCuidador(nome));
        nome = strtok(NULL, ";");
    }
    free(linha);

    Idoso idoso = NULL;
    char* nomeIdoso = NULL;

    Cuidador cuidador = NULL;
    char* nomeCuidador = NULL;

    //relacionando cuidadores e idosos
    linha = ReadLine(sr);
    while(RecuperaEndOfStream(sr) != EOF){
        nomeIdoso = strtok(linha, ";");
        idoso = BuscarIdosoEdCare(Sistema_EdCare, nomeIdoso);

        nomeCuidador = strtok(NULL, ";");
        while(nomeCuidador != NULL){
            AdicionarCuidador(idoso, BuscarCuidadorEdCare(Sistema_EdCare, nomeCuidador));
            nomeCuidador = strtok(NULL, ";");
        }

        free(linha);
        linha = ReadLine(sr);
    }  
    
    DeletarStreamReader(sr);
}

void AtualizarEstruturasEdCare(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    AtualizarIdososEdCare(Sistema_EdCare);
    AtualizarCuidadoresEdCare(Sistema_EdCare);
}

void ProcessarInformacoesEdCare(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    int i = 0;
    Idoso idoso = BuscarItemIndex(Sistema_EdCare->idosos, i);

    while(idoso != NULL){
        StreamWriter sw = RecuperaStreamWriterIdoso(idoso);
        char *string = ProcessarInformacoesIdosoEdCare(idoso);
        WriteLine(sw, string);

        if(strcmp(string, "falecimento") == 0){
            i--;
            RemoverIdosoEdCare(Sistema_EdCare, idoso);
        }
        free(string);

        i++;
        idoso = BuscarItemIndex(Sistema_EdCare->idosos, i);
    }
}

static void AdicionarIdosoEdCare(EdCare Sistema_EdCare, Idoso idoso){
    assert(Sistema_EdCare != NULL && idoso != NULL);

    AdicionarItem(Sistema_EdCare->idosos, idoso);
}

static void RemoverIdosoEdCare(EdCare Sistema_EdCare, Idoso idoso){
    assert(Sistema_EdCare != NULL && idoso != NULL);

    RemoverItemChave(Sistema_EdCare->idosos, &CompararNomeIdoso, RecuperaNomeIdoso(idoso));
    DeletarIdoso(idoso);
}

static Idoso BuscarIdosoEdCare(EdCare Sistema_EdCare, char *nome){
    assert(Sistema_EdCare != NULL && nome != NULL);

    return BuscarItemChave(Sistema_EdCare->idosos, &CompararNomeIdoso, nome);
}

static void AtualizarIdososEdCare(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    void *idoso = NULL;
    for(ForEach(Sistema_EdCare->idosos, &idoso); idoso != NULL; ForEach(NULL, &idoso)){
        AtualizarIdoso((Idoso) idoso);
    }
}

static void AdicionarCuidadorEdCare(EdCare Sistema_EdCare, Cuidador cuidador){
    assert(Sistema_EdCare != NULL && cuidador != NULL);

    AdicionarItem(Sistema_EdCare->cuidadores, cuidador);
}

static Cuidador BuscarCuidadorEdCare(EdCare Sistema_EdCare, char *nome){
    assert(Sistema_EdCare != NULL && nome != NULL);

    return BuscarItemChave(Sistema_EdCare->cuidadores, &CompararNomeCuidador, nome);
}

static void AtualizarCuidadoresEdCare(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    void *cuidador = NULL;
    for(ForEach(Sistema_EdCare->cuidadores, &cuidador); cuidador != NULL; ForEach(NULL, &cuidador)){
        AtualizarCuidador((Cuidador) cuidador);
    }
}

static char *ProcessarInformacoesIdosoEdCare(Idoso idoso){
    assert(idoso != NULL);

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
        int contadorFebreBaixa = RecuperaContadorFebreBaixa(registroIdoso);
        if(contadorFebreBaixa == 4){
            ResetarContadorFebreBaixa(registroIdoso);
        }

        //verificando o contador de febre baixa
        FebreEnum febre = RecuperaFebreRegistro(registroIdoso);
        if(febre == FebreAlta){
            ResetarContadorFebreBaixa(registroIdoso);
        }

        return strdup(buffer);
    }

    //febre alta
    FebreEnum febre = RecuperaFebreRegistro(registroIdoso);
    if(febre == FebreAlta){
        ResetarContadorFebreBaixa(registroIdoso);

        Cuidador cuidador = BuscarCuidadorMaisProximo(idoso);
        sprintf(buffer, "febre alta, acionou %s", RecuperaNomeCuidador(cuidador));
        return strdup(buffer);
    }

    //febre baixa
    if(febre == FebreBaixa){
        int contadorFebreBaixa = RecuperaContadorFebreBaixa(registroIdoso);
        if(contadorFebreBaixa == 4){
            ResetarContadorFebreBaixa(registroIdoso);

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