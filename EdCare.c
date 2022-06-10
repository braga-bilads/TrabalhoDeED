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
void CriaVinculosdeApoio(EdCare Sistema_EdCare){
    assert(Sistema_EdCare != NULL);

    StreamReader sr = CriarStreamReader("apoio.txt");
    char* linha = ReadLine(sr);

    //colocando Idosos no sistema 
    char* nome = strtok(linha, ";");
    while(nome != NULL){
        AdicionarItem(Sistema_EdCare->idosos, CriarIdoso(nome));
        nome = strtok(linha, ";");
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
        nome = strtok(linha, ";");
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

        nomeCuidador = strtok(linha, ";");
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