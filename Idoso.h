#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Cuidador.h"
#include "FebreEnum.h"

typedef struct idoso * Idoso;

/**
 * Coloca um amigo na lista de amigos do idoso. 
 * inputs: idoso e o amigo
 * output: void
 * pré-condição: idoso e amigo existem 
 */
void AdicionaAmigo(Idoso idoso, Idoso amigo);

/**
 * Retira um amigo da lista de amigos do idoso.
 * inputs: Idoso e amigo a ser retirado
 * output: void 
 * pré-condição:  idoso e amigo são validos 
 */
void RemoverAmigo(Idoso idoso, Idoso amigo);

/**
 * Retorna o Amigo mais proximo do idoso.
 * inputs: idoso
 * output: idoso mais proximo
 * pré-condição: idoso é valido 
 */
Idoso BuscarAmigoMaisProximo(Idoso idoso);

/**
 * Desfaz todas as amizades do idoso (caso de falecimento).
 * inputs: idoso
 * output: void
 * pré-condição : idoso é valido e foi declarado como falecido.
 */
void DesfazerAmizades(Idoso idoso);

/**
 * Adiciona um cuidador na lista de cuidadores do Idoso selecionado.
 * inputs: idoso e cuidador
 * output: void
 * pré-condição : idoso e cuidador são valido. 
 */
void AdicionarCuidador(Idoso idoso, Cuidador cuidador);

/**
 * Retorna o cuidador mais próximo na lista 
 * de cuidadores do Idoso.
 * inputs: idoso 
 * output: cuidador
 * pré-condição : Idoso é valido
 */
Cuidador BuscarCuidadorMaisProximo(Idoso idoso);

/**
 * Adiciona um novo registro na lista de registros do idoso.
 * inputs: idoso, temperatura, febre, queda.
 * output: void
 * pré-condição : os parametros passados são validos
 */
void AdicionaResgistro(Idoso idoso,double temperatura,Febre febre, int queda);

/**
 * Retorna lista de Registros
 * inputs: idoso e quantidade
 * output: lista de registros
 * pré-condição : parametros passados serem validos
 *                e quantidade é menor ou igual ao 
 *                numero de registros.
 */
Registro BuscarRegistros(Idoso idoso, int quantidade);