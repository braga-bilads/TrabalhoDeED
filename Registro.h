#ifndef REGISTRO_H
#define REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include "Localizador.h"
#include "FebreEnum.h"

typedef struct registro* Registro;

/* 
 * Aloca memoria para o registro e o inicializa
 * inputs: nenhum
 * output: o registro criado
 * pre-condicao: nenhuma
 */
Registro CriarRegistro();

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
 * Retorna a contagem de febres baixas registrada
 * inputs: o registro
 * output: a contagem de febres baixas 
 * pre-condicao: o registro existe
 */
int RecuperaContadorFebreBaixa(Registro registro);

/* 
 * Retorna o atributo ehVivo registrado
 * inputs: o registro
 * output: o atributo ehVivo 
 * pre-condicao: o registro existe
 */
int RecuperaEhVivo(Registro registro);

/* 
 * Libera memoria alocada para o registro
 * inputs: o registro
 * output: nenhum
 * pre-condicao: o registro existe
 */
void DeletarRegistro(Registro registro);

/* 
 * Atualiza os dados do registro
 * inputs: o registro, temperatura, febre, queda, localizador e ehVivo
 * output: nenhum
 * pre-condicao: o registro existe
 */
void AtualizarRegistro(Registro registro, double temperatura, FebreEnum febre, int queda, Localizador localizador, int ehVivo);

/* 
 * Reseta os dados do registro
 * inputs: o registro
 * output: o registro resetado
 * pre-condicao: o registro existe
 */
Registro ResetarRegistro(Registro registro);



// DEBUG
char *RegistroToString(Registro registro);

#endif