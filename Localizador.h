#ifndef LOCALIZADOR_H
#define LOCALIZADOR_H

typedef struct localizador* Localizador;

/* 
 * Aloca memoria para o localizador e o inicializa
 * inputs: latitude e longitude respectivas ao localizador
 * output: o localizador criado
 * pre-condicao: nenhuma
 */
Localizador CriarLocalizador(int latitude, int longitude);

/* 
 * Modifica a latitude do localizador
 * inputs: o localizador e a nova latitude
 * output: nenhum
 * pre-condicao: o localizador existe
 */
void ModificaLatitude(Localizador localizador, int latitude);

/* 
 * Modifica a longitude do localizador
 * inputs: o localizador e a nova longitude
 * output: nenhum
 * pre-condicao: o localizador existe
 */
void ModificaLongitude(Localizador localizador, int longitude);

/* 
 * Libera memoria alocada para o localizador
 * inputs: o localizador
 * output: nenhum
 * pre-condicao: o localizador existe
 */
void DeletarLocalizador(Localizador localizador);

/* 
 * Calcula a distancia entre dois localizadores
 * inputs: os dois localizadores
 * output: a distancia entre os dois localizadores
 * pre-condicao: os localizadores existem
 */
double CalcularDistancia(Localizador localizador1, Localizador localizador2);

#endif