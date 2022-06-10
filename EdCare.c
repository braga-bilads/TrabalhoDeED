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

struct edcare
{
    Lista idosos;
    Lista cuidadores;
    int numerodeleituras;
};


int main(int argc, char const *argv[])
{
    EdCare Sistema_EdCare = CriaEdCare(RetornaNumeroDeLeituras(argc,argv)); 
    
    StreamReader apoio = CriarStreamReader("./Entrada/apoio.txt");
    StreamReader cuidadores = CriarStreamReader("./Entrada/cuidadores.txt");
    CriaVinculosdeApoio(apoio,Sistema_EdCare);
    CriaVinculosdeCuidadores(cuidadores,Sistema_EdCare);

    return 0;
}

int RetornaNumeroDeLeituras(int argc, const char ** argv){
    if(!argc){
        printf("ERRO: numero de leituras deve ser informado\n");
        return -1;
    }
    int numeroDeLeituras;

    if(sscanf(argv[1],"%d",&numeroDeLeituras) != 1){
        printf("ERRO: numero de leituras informado é invalido\nExemplo de Sintaxe: ./EdCare 10");
        return -1;
    }
    return numeroDeLeituras;
}

EdCare CriaEdCare(int numeroLeituras){
    EdCare nova = (EdCare)malloc(sizeof(struct edcare));
    
    nova->numerodeleituras = numeroLeituras;
    nova->cuidadores = CriarLista();
    nova->idosos = CriarLista();

    return nova;
}
void CriaVinculosdeApoio(StreamReader apoio,EdCare Sistema_EdCare){
    assert(Sistema_EdCare);
    assert(apoio);

    char* linha = ReadLine(apoio);
    char* nome;

    //colocando Idosos no sistema 
    while (sscanf(linha,"%m[^;]",&nome)){ 
        AdicionarItem(Sistema_EdCare->idosos,CriarIdoso(nome));
        free(nome);
        nome = NULL;
    }
    char* nome1;
    char* nome2:
    Idoso i1;
    Idoso i2;
    //colocando idosos como amigos
    while (RecuperaEndOfStream(apoio)){
        linha = ReadLine(apoio);
        sscanf(linha;"%m[^;]%m",&nome1,&nome2);
        i1 = RetornaIdosoPeloNome(Sistema_EdCare->idosos,nome1);
        i2 = RetornaIdosoPeloNome(Sistema_EdCare->idosos,nome2);
        AdicionarAmigo(i1,i2);
        free(nome1);
        free(nome2);
    }
    
    if(nome1)
        free(nome1);
    if(nome2)
        free(nome2);
    if(nome)
        free(nome);
    if(linha)
        free(linha);
}

void CriaVinculosdeCuidadores(StreamReader cuidadores,EdCare Sistema_EdCare){
    assert(Sistema_EdCare);
    assert(cuidadores);

    char* linha = ReadLine(cuidadores);
    char* nome;

    //colocando cuidadore no sistema 
    while (sscanf(linha,"%m[^;]",&nome)){ 
        AdicionarItem(Sistema_EdCare->cuidadores,CriarCuidador(nome));
        free(nome);
        nome = NULL;
    }
    char* nome1;
    char* nome2:
    Cuidador c1;
    Cuidador c2;
  
    
    if(nome1)
        free(nome1);
    if(nome2)
        free(nome2);
    if(nome)
        free(nome);
    if(linha)
        free(linha);
}