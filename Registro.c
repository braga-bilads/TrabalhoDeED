#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Registro.h"

struct registro{
    double temperatura;
    FebreEnum febre;
    int queda;
    Localizador localizador;
};

Registro CriarRegistro(double temperatura, FebreEnum febre, int queda, Localizador localizador){
    assert(localizador != NULL);

    Registro registro = (Registro) malloc(sizeof(struct registro));
    assert(registro != NULL);

    registro->temperatura = temperatura;
    registro->febre = febre;
    registro->queda = queda;
    registro->localizador = localizador;

    return registro;
}

double RecuperaTemperaturaRegistro(Registro registro){
    assert(registro != NULL);

    return registro->temperatura;
}

FebreEnum RecuperaFebreRegistro(Registro registro){
    assert(registro != NULL);

    return registro->febre;
}

int RecuperaQuedaRegistro(Registro registro){
    assert(registro != NULL);

    return registro->queda;
}

Localizador RecuperaLocalizadorRegistro(Registro registro){
    assert(registro != NULL);

    return registro->localizador;
}

void DeletarRegistro(Registro registro){
    assert(registro != NULL);

    DeletarLocalizador(registro->localizador);
    free(registro);
}



// DEBUG
char *RegistroToString(Registro registro){
    assert(registro != NULL);

    static char buffer[100];
    sprintf(buffer, "temperatura:%.2lf,febre:%d,queda:%d,localizador:{%s}",
        registro->temperatura, registro->febre,
        registro->queda, LocalizadorToString(registro->localizador));
    return buffer;
}