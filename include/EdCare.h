#ifndef EDCARE_H
#define EDCARE_H

typedef struct edcare* EdCare;

/* 
 * Aloca memoria para o sistema edcare e o inicializa
 * inputs: nenhum
 * output: o sistema edcare criado
 * pre-condicao: nenhuma
 */
EdCare CriarEdCare();

/* 
 * Libera memoria alocada para o sistema edcare
 * inputs: o sistema edcare
 * output: nenhum
 * pre-condicao: o sistema edcare existe
 */
void DeletarEdCare(EdCare Sistema_EdCare);

/* 
 * Adiciona os idosos ao sistema, e cria seus vinculos
 * inputs: o sistema edcare
 * output: nenhum
 * pre-condicao: o sistema edcare existe
 */
void CriaVinculosdeApoioEdCare(EdCare Sistema_EdCare);

/* 
 * Adiciona os cuidadores ao sistema, e cria seus vinculos
 * inputs: o sistema edcare
 * output: nenhum
 * pre-condicao: o sistema edcare existe
 */
void CriaVinculosdeCuidadoresEdCare(EdCare Sistema_EdCare);

/* 
 * Le as medidas dos sensores, e atualiza as estruturas respectivas
 * inputs: o sistema edcare
 * output: nenhum
 * pre-condicao: o sistema edcare existe
 */
void AtualizarEstruturasEdCare(EdCare Sistema_EdCare);

/* 
 * Processa as informacoes, e gera a saida respectiva
 * inputs: o sistema edcare
 * output: nenhum
 * pre-condicao: o sistema edcare existe
 */
void ProcessarInformacoesEdCare(EdCare Sistema_EdCare);

#endif