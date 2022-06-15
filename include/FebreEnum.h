#ifndef FEBREENUM_H
#define FEBREENUM_H

typedef enum Febre{
    SemFebre,
    FebreBaixa,
    FebreAlta
} FebreEnum;

/* 
 * Retorna a febre de acodo com a temperatura
 * inputs: a temperatura
 * output: a febre
 * pre-condicao: nenhuma
 */
FebreEnum RetornarFebre(double temperatura);

#endif