#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Cuidador.h"
#include "FebreEnum.h"
#include "Registro.h"
#include "Idoso.h"
#include "Lista.h"

struct idoso
{
    char* nome;
    Lista amigos;
    Lista cuidadores;
    Lista registros;
    Localizador localAtual;
    StreamReader sr;
};


void AdicionaAmigo(Idoso idoso, Idoso amigo){
    assert(idoso != NULL || amigo != NULL);

    AdicionarItem(idoso->amigos,amigo);
    AdicionarItem(amigo->amigos,idoso);
}

void RemoverAmigo(Idoso idoso, Idoso amigo){
    RemoverItemChave(idoso->amigos,&RecuperaNomeIdoso,RecuperaNomeIdoso(amigo));
}

Idoso BuscarAmigoMaisProximo(Idoso idoso);

void DesfazerAmizades(Idoso idoso);

void AdicionarCuidador(Idoso idoso, Cuidador cuidador);

Cuidador BuscarCuidadorMaisProximo(Idoso idoso);

void AdicionaResgistro(Idoso idoso,double temperatura,FebreEnum febre, int queda);

Registro BuscarRegistros(Idoso idoso, int quantidade);

char * RecuperaNomeIdoso(Idoso idoso){
    return idoso->nome;
}