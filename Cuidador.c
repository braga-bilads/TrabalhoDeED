#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Cuidador.h"

struct cuidador{
    char *nome;
    Localizador localizador;
    StreamReader sr;
};

Cuidador CriarCuidador(char *nome){
    Cuidador cuidador = (Cuidador) malloc(sizeof(struct cuidador));
    assert(cuidador != NULL);

    cuidador->nome = strdup(nome);
    cuidador->localizador = CriarLocalizador(0, 0);

    char path[100];
    sprintf(path, "%s.txt", nome);
    cuidador->sr = CriarStreamReader(path);

    return cuidador;
}

char *RecuperaNomeCuidador(Cuidador cuidador){
    assert(cuidador != NULL);

    return cuidador->nome;
}

Localizador RecuperaLocalizadorCuidador(Cuidador cuidador){
    assert(cuidador != NULL);

    return cuidador->localizador;
}

void DeletarCuidador(Cuidador cuidador){
    assert(cuidador != NULL);

    free(cuidador->nome);
    DeletarLocalizador(cuidador->localizador);
    DeletarStreamReader(cuidador->sr);

    free(cuidador);
}

void AtualizarCuidador(Cuidador cuidador){
    assert(cuidador != NULL);

    char *string = ReadLine(cuidador->sr);
    assert(RecuperaEndOfStream(cuidador->sr) != EOF);

    int latitude = 0, longitude = 0;
    sscanf(string, "%d;%d", &latitude, &longitude);
    free(string);

    ModificaLatitude(cuidador->localizador, latitude);
    ModificaLongitude(cuidador->localizador, longitude);
}



// DEBUG
char *CuidadorToString(Cuidador cuidador){
    assert(cuidador != NULL);

    static char buffer[100];
    sprintf(buffer, "Nome:%s,Localizador{%s}", cuidador->nome, LocalizadorToString(cuidador->localizador));
    return buffer;
}