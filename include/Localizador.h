#ifndef LOCALIZADOR_H
#define LOCALIZADOR_H

//  Tipo que define localizador (tipo opaco)
typedef struct localizador* Localizador;

/* 
 * Aloca memoria para o localizador e o inicializa
 * inputs: latitude e longitude respectivas ao localizador
 * output: localizador criado
 * pre-condicao: nenhuma
 * pos-condicao: localizador alocado e inicializado
 */
Localizador CriarLocalizador(int latitude, int longitude);

/* 
 * Modifica a latitude do localizador
 * inputs: localizador e nova latitude
 * output: nenhum
 * pre-condicao: localizador existe
 * pos-condicao: latitude foi alterada
 */
void ModificaLatitude(Localizador localizador, int latitude);

/* 
 * Modifica a longitude do localizador
 * inputs: localizador e nova longitude
 * output: nenhum
 * pre-condicao: localizador existe
 * pos-condicao: longitude foi alterada
 */
void ModificaLongitude(Localizador localizador, int longitude);

/* 
 * Libera memoria alocada para o localizador
 * inputs: localizador
 * output: nenhum
 * pre-condicao: localizador existe
 * pos-condicao: toda a memoria alocada para localizador foi liberada
 */
void DeletarLocalizador(Localizador localizador);

/* 
 * Calcula a distancia entre dois localizadores
 * inputs: os dois localizadores
 * output: distancia entre os dois localizadores
 * pre-condicao: os localizadores existem
 * pos-condicao: a distancia entre os dois localizadores foi calculada
 */
double CalcularDistancia(Localizador localizador1, Localizador localizador2);

#endif