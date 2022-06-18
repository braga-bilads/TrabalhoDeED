#ifndef EDCARE_H
#define EDCARE_H

//  Tipo que define edcare (tipo opaco)
typedef struct edcare* EdCare;

/* 
 * Aloca memoria para o edcare e o inicializa
 * inputs: nenhum
 * output: edcare criado
 * pre-condicao: nenhuma
 * pos-condicao: edcare alocado e inicializado
 */
EdCare CriarEdCare();

/* 
 * Libera memoria alocada para edcare
 * inputs: edcare
 * output: nenhum
 * pre-condicao: edcare existe
 * pos-condicao: toda a memoria alocada para edcare foi liberada
 */
void DeletarEdCare(EdCare Sistema_EdCare);

/* 
 * Adiciona os idosos ao sistema, e cria seus vinculos
 * inputs: edcare
 * output: nenhum
 * pre-condicao: edcare existe
 * pos-condicao: idosos adicionados ao sistema, e vinculos criados
 */
void CriaVinculosdeApoioEdCare(EdCare Sistema_EdCare);

/* 
 * Adiciona os cuidadores ao sistema, e cria seus vinculos
 * inputs: edcare
 * output: nenhum
 * pre-condicao: edcare existe
 * pos-condicao: cuidadores adicionados ao sistema, e vinculos criados
 */
void CriaVinculosdeCuidadoresEdCare(EdCare Sistema_EdCare);

/* 
 * Le as medidas dos sensores, e atualiza as estruturas respectivas
 * inputs: edcare
 * output: nenhum
 * pre-condicao: edcare existe
 * pos-condicao: estruturas atualizadas de acordo com seus sensores
 */
void AtualizarEstruturasEdCare(EdCare Sistema_EdCare);

/* 
 * Processa as informacoes, e gera a saida respectiva
 * inputs: edcare
 * output: nenhum
 * pre-condicao: edcare existe
 * pos-condicao: informacoes processadas e saida gerada
 */
void ProcessarInformacoesEdCare(EdCare Sistema_EdCare);

#endif