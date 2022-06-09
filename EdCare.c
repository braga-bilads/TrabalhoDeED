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
#include "EdCare.h"

int main(int argc, char const *argv[])
{
    int numeroDeLeituras = RetornaNumeroDeLeituras(argc,argv);
    

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