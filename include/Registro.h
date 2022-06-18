#ifndef REGISTRO_H
#define REGISTRO_H

#include "Localizador.h"
#include "FebreEnum.h"

//  Tipo que define registro (tipo opaco)
typedef struct registro* Registro;

/* 
 * Aloca memoria para o registro e o inicializa
 * inputs: nenhum
 * output: registro criado
 * pre-condicao: nenhuma
 * pos-condicao: registro alocado e inicializado
 */
Registro CriarRegistro();

/* 
 * Retorna a febre registrada
 * inputs: registro
 * output: febre registrada
 * pre-condicao: registro existe
 * pos-condicao: registro nao e modificado
 */
FebreEnum RecuperaFebreRegistro(Registro registro);

/* 
 * Retorna a queda registrada
 * inputs: registro
 * output: queda registrada
 * pre-condicao: registro existe
 * pos-condicao: registro nao e modificado
 */
int RecuperaQuedaRegistro(Registro registro);

/* 
 * Retorna a localizacao registrada
 * inputs: registro
 * output: localizacao registrada
 * pre-condicao: registro existe
 * pos-condicao: registro nao e modificado
 */
Localizador RecuperaLocalizadorRegistro(Registro registro);

/* 
 * Retorna a contagem de febres baixas registrada
 * inputs: registro
 * output: contagem de febres baixas 
 * pre-condicao: registro existe
 * pos-condicao: registro nao e modificado
 */
int RecuperaContadorFebreBaixa(Registro registro);

/* 
 * Libera memoria alocada para o registro
 * inputs: registro
 * output: nenhum
 * pre-condicao: registro existe
 * pos-condicao: toda a memoria alocada para registro foi liberada
 */
void DeletarRegistro(Registro registro);

/* 
 * Atualiza os dados do registro
 * inputs: registro, febre, queda e localizador
 * output: nenhum
 * pre-condicao: registro e localizador existem
 * pos-condicao: os dados do registro foram atualizados
 */
void AtualizarRegistro(Registro registro, FebreEnum febre, int queda, Localizador localizador);

/* 
 * Reseta o contador de febre baixa do registro
 * inputs: registro
 * output: nenhum
 * pre-condicao: registro existe
 * pos-condicao: o contador de febre baixa foi zerado
 */
void ResetarContadorFebreBaixa(Registro registro);

#endif