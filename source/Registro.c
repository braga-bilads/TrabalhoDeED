#include <stdlib.h>
#include <assert.h>
#include "../include/Registro.h"

struct registro{
    FebreEnum febre;
    int queda;
    Localizador localizador;
    int contadorFebreBaixa;
};

Registro CriarRegistro(){
    Registro registro = (Registro) malloc(sizeof(struct registro));
    assert(registro != NULL);

    registro->febre = SemFebre;
    registro->queda = 0;
    registro->localizador = CriarLocalizador(0, 0);
    registro->contadorFebreBaixa = 0;

    return registro;
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

int RecuperaContadorFebreBaixa(Registro registro){
    assert(registro != NULL);

    return registro->contadorFebreBaixa;
}

void DeletarRegistro(Registro registro){
    assert(registro != NULL);

    DeletarLocalizador(registro->localizador);
    free(registro);
}

void AtualizarRegistro(Registro registro, FebreEnum febre, int queda, Localizador localizador){
    assert(registro != NULL && localizador != NULL);

    registro->febre = febre;
    registro->queda = queda;

    DeletarLocalizador(registro->localizador);
    registro->localizador = localizador;

    if(febre == FebreBaixa){
        registro->contadorFebreBaixa++;
    }
}

void ResetarContadorFebreBaixa(Registro registro){
    assert(registro != NULL);

    registro->contadorFebreBaixa = 0;
}