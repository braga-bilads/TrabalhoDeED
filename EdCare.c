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
    char* linha = ReadLine(apoio);
    
}

void CriaVinculosdeCuidadores(StreamReader cuidadores,EdCare Sistema_EdCare);