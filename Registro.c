#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Registro.h"

struct registro{
    double temperatura;
    FebreEnum febre;
    int queda;
    Localizador localizador;
    int contadorFebreBaixa;
    int ehVivo;
};

Registro CriarRegistro(){
    Registro registro = (Registro) malloc(sizeof(struct registro));
    assert(registro != NULL);

    registro->temperatura = 0.0;
    registro->febre = SemFebre;
    registro->queda = 0;
    registro->localizador = CriarLocalizador(0, 0);
    registro->contadorFebreBaixa = 0;
    registro->ehVivo = 1;

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

int RecuperaEhVivoRegistro(Registro registro){
    assert(registro != NULL);

    return registro->ehVivo;
}

void DeletarRegistro(Registro registro){
    assert(registro != NULL);

    DeletarLocalizador(registro->localizador);
    free(registro);
}

void AtualizarRegistro(Registro registro, double temperatura, FebreEnum febre, int queda, Localizador localizador, int ehVivo){
    assert(registro != NULL && localizador != NULL);

    registro->temperatura = temperatura;
    registro->febre = febre;
    registro->queda = queda;

    DeletarLocalizador(registro->localizador);
    registro->localizador = localizador;

    if(febre == FebreBaixa){
        registro->contadorFebreBaixa++;
    }

    registro->ehVivo = ehVivo;
}

Registro ResetarRegistro(Registro registro){
    assert(registro != NULL);

    DeletarRegistro(registro);
    return CriarRegistro();
}


// DEBUG
char *RegistroToString(Registro registro){
    assert(registro != NULL);

    static char buffer[100];
    sprintf(buffer, "temperatura:%.2lf,febre:%d,queda:%d,localizador:{%s},contadorFebreBaixa:%d,ehVivo:%d",
        registro->temperatura, registro->febre,
        registro->queda, LocalizadorToString(registro->localizador),
        registro->contadorFebreBaixa, registro->ehVivo);
    return buffer;
}