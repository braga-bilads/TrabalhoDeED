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
 * Retorna a latitude do localizador
 * inputs: o localizador
 * output: a latitude do localizador
 * pre-condicao: o localizador existe
 */
int RecuperaLatitude(Localizador localizador);

/* 
 * Modifica a latitude do localizador
 * inputs: o localizador e a nova latitude
 * output: nenhum
 * pre-condicao: o localizador existe
 */
void ModificaLatitude(Localizador localizador, int latitude);

/* 
 * Retorna a longitude do localizador
 * inputs: o localizador
 * output: a longitude do localizador
 * pre-condicao: o localizador existe
 */
int RecuperaLongitude(Localizador localizador);

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



// DEBUG
char *LocalizadorToString(Localizador localizador);

#endif