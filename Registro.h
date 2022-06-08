#ifndef REGISTRO_H
#define REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include "Localizador.h"
#include "FebreEnum.h"

typedef struct registro* Registro;

/* 
 * Aloca memoria para o registro e o inicializa
 * inputs: temperatura, febre, queda e localizador
 * output: o registro criado
 * pre-condicao: febre tem valor valido e localizador existe
 */
Registro CriarRegistro(double temperatura, FebreEnum febre, int queda, Localizador localizador);

/* 
 * Retorna a temperatura registrada
 * inputs: o registro
 * output: a temperatura registrada
 * pre-condicao: o registro existe
 */
double RecuperaTemperaturaRegistro(Registro registro);

/* 
 * Retorna a febre registrada
 * inputs: o registro
 * output: a febre registrada
 * pre-condicao: o registro existe
 */
FebreEnum RecuperaFebreRegistro(Registro registro);

/* 
 * Retorna a queda registrada
 * inputs: o registro
 * output: a queda registrada
 * pre-condicao: o registro existe
 */
int RecuperaQuedaRegistro(Registro registro);

/* 
 * Retorna a localizacao registrada
 * inputs: o registro
 * output: a localizacao registrada
 * pre-condicao: o registro existe
 */
Localizador RecuperaLocalizadorRegistro(Registro registro);

/* 
 * Libera memoria alocada para o registro
 * inputs: o registro
 * output: nenhum
 * pre-condicao: o registro existe
 */
void DeletarRegistro(Registro registro);



// DEBUG
char *RegistroToString(Registro registro);

#endif