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

static int _compararNomeIdoso(void *idoso, void *nome);

struct idoso
{
    char* nome;
    Lista amigos;
    Lista cuidadores;
    Registro registro;
    StreamReader sr;
    int vivo;
};

Idoso CriarIdoso(char *nome){
    Idoso idoso = (Idoso) malloc(sizeof(struct idoso));
    assert(idoso != NULL);

    idoso->nome = strdup(nome);
    idoso->amigos = CriarLista();
    idoso->cuidadores = CriarLista();
    idoso->registro = CriarRegistro();

    char path[100];
    sprintf(path, "%s.txt", nome);
    idoso->sr = CriarStreamReader(path);

    idoso->vivo = 1;

    return idoso;
}

void AdicionarAmigo(Idoso idoso, Idoso amigo){
    assert(idoso != NULL && amigo != NULL);

    AdicionarItem(idoso->amigos,amigo);
    AdicionarItem(amigo->amigos,idoso);
}

void RemoverAmigo(Idoso idoso, Idoso amigo){
    assert(idoso != NULL && amigo != NULL);

    RemoverItemChave(idoso->amigos, &_compararNomeIdoso, amigo->nome);
    RemoverItemChave(amigo->amigos, &_compararNomeIdoso, idoso->nome);
}

Idoso BuscarAmigoMaisProximo(Idoso idoso){
    assert(idoso);

    Localizador localIdoso;
    localIdoso = RecuperaLocalizadorRegistro(idoso->registro);
    Localizador localAmigo;
    double dist = 0.1;
    double menordist =0.0;
    Idoso p;
   
    ForEach(idoso->amigos,(void**)&p);
    Idoso amigoMaisProximo  = p;
    
    for ( ; p ;ForEach(NULL,(void**)&p))
    {
        localAmigo = RecuperaLocalizadorRegistro(p->registro);
        dist = CalcularDistancia(localIdoso, localAmigo);
        if (dist<menordist)
        {
            menordist = dist;
            amigoMaisProximo = p;
        }
    }    
    
    return amigoMaisProximo;
}

void DesfazerAmizades(Idoso idoso){

}

void AdicionarCuidador(Idoso idoso, Cuidador cuidador){
    assert(idoso != NULL && cuidador != NULL);

    AdicionarItem(idoso->cuidadores, cuidador);
}

Cuidador BuscarCuidadorMaisProximo(Idoso idoso){
    assert(idoso);

    Localizador localIdoso;
    localIdoso = RecuperaLocalizadorRegistro(idoso->registro);
    Localizador localCuidador;
    double dist = 0.1;
    double menordist =0.0;
    Cuidador p;
   
    ForEach(idoso->cuidadores,(void**)&p);
    Cuidador cuidadorMaisProximo  = p;
    
    for ( ; p ;ForEach(NULL,(void**)&p))
    {
        localCuidador = RecuperaLocalizadorCuidador(p);
        dist = CalcularDistancia(localIdoso, localCuidador);
        if (dist<menordist)
        {
            menordist = dist;
            cuidadorMaisProximo = p;
        }
    }    
    
    return cuidadorMaisProximo;
}

Registro RetornaRegistro(Idoso idoso){
    assert(idoso);
    return idoso->registro;
}

char * RecuperaNomeIdoso(Idoso idoso){
    return idoso->nome;
}

void DeletarIdoso(Idoso idoso){
    assert(idoso != NULL);

    DesfazerAmizades(idoso);

    free(idoso->nome);
    DeletarLista(idoso->amigos, NULL);
    DeletarLista(idoso->cuidadores, NULL);
    DeletarLocalizador(RecuperaLocalizadorRegistro(idoso->registro));
    DeletarStreamReader(idoso->sr);

    free(idoso);
}

void AtualizarIdoso(Idoso idoso){
    assert(idoso != NULL);

    char *string = ReadLine(idoso->sr);
    assert(RecuperaEndOfStream(idoso->sr) != EOF);

    if(strcmp(string, "falecimento") == 0){
        idoso->vivo = 0;
        free(string);
        return;
    }

    double temperatura = 0.0;
    int latitude = 0, longitude = 0, queda = 0;
    sscanf(string, "%lf;%d;%d;%d", &temperatura, &latitude, &longitude, &queda);
    free(string);

    FebreEnum febre = RetornarFebre(temperatura);
    Localizador localizador = CriarLocalizador(latitude, longitude);

    AtualizarRegistro(idoso->registro,temperatura, febre, queda, localizador,1);
}

int EhIdosoVivo(Idoso idoso){
    return idoso->vivo;
}

static int _compararNomeIdoso(void *idoso, void *nome){
    Idoso _idoso = idoso;
    char *_nome = nome;

    return strcmp(_idoso->nome, _nome) == 0 ? 1 : 0;
}