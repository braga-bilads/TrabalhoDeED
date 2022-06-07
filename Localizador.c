#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "Localizador.h"

struct localizador{
    int latitude;
    int longitude;
};

Localizador CriarLocalizador(int latitude, int longitude){
    Localizador localizador = (Localizador) malloc(sizeof(struct localizador));

    assert(localizador != NULL);

    localizador->latitude = latitude;
    localizador->longitude = longitude;

    return localizador;
}

int RecuperaLatitude(Localizador localizador){
    assert(localizador != NULL);

    return localizador->latitude;
}

void ModificaLatitude(Localizador localizador, int latitude){
    assert(localizador != NULL);

    localizador->latitude = latitude;
}

int RecuperaLongitude(Localizador localizador){
    assert(localizador != NULL);

    return localizador->longitude;
}

void ModificaLongitude(Localizador localizador, int longitude){
    assert(localizador != NULL);

    localizador->longitude = longitude;
}

void DeletarLocalizador(Localizador localizador){
    assert(localizador != NULL);

    free(localizador);
}

double CalcularDistancia(Localizador localizador1, Localizador localizador2){
    assert(localizador1 != NULL && localizador2 != NULL);

    int x1 = localizador1->latitude,  x2 = localizador2->latitude,
        y1 = localizador1->longitude, y2 = localizador2->longitude;

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}



// DEBUG
char *LocalizadorToString(Localizador localizador){
    assert(localizador != NULL);

    static char buffer[100];
    sprintf(buffer, "latitude:%d,longitude:%d", localizador->latitude, localizador->longitude);
    return buffer;
}