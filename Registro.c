#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Registro.h"

struct registro{
    double temperatura;
    FebreEnum febre;
    int queda;
    Localizador localizador;
    int contadorFebreBaixa;
};

Registro CriarRegistro(){
    Registro registro = (Registro) malloc(sizeof(struct registro));
    assert(registro != NULL);

    registro->temperatura = 0.0;
    registro->febre = SemFebre;
    registro->queda = 0;
    registro->localizador = CriarLocalizador(0, 0);
    registro->contadorFebreBaixa = 0;

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

int RecuperaContadorFebreBaixaRegistro(Registro registro){
    assert(registro != NULL);

    return registro->contadorFebreBaixa;
}

void DeletarRegistro(Registro registro){
    assert(registro != NULL);

    DeletarLocalizador(registro->localizador);
    free(registro);
}

void AtualizarRegistro(Registro registro, double temperatura, FebreEnum febre, int queda, Localizador localizador){
    assert(registro != NULL && localizador != NULL);

    registro->temperatura = temperatura;
    registro->febre = febre;
    registro->queda = queda;

    DeletarLocalizador(registro->localizador);
    registro->localizador = localizador;

    if(febre == FebreBaixa){
        registro->contadorFebreBaixa++;
    }
}

void ResetarContadorFebreBaixaRegistro(Registro registro){
    assert(registro != NULL);

    registro->contadorFebreBaixa = 0;
}


// DEBUG
#include <string.h>
char *RegistroToString(Registro registro){
    assert(registro != NULL);

    char buffer[1000];
    char *localizadorToString = LocalizadorToString(registro->localizador);
    sprintf(buffer, "Temperatura:%.2lf,Febre:%d,Queda:%d,Localizador:{%s},ContadorFebreBaixa:%d",
        registro->temperatura, registro->febre,
        registro->queda, localizadorToString,
        registro->contadorFebreBaixa);
    free(localizadorToString);

    return strdup(buffer);
}