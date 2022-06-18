#ifndef FEBREENUM_H
#define FEBREENUM_H

typedef enum Febre{
    SemFebre,
    FebreBaixa,
    FebreAlta
} FebreEnum;

/* 
 * Retorna a febre de acodo com a temperatura
 * inputs: temperatura
 * output: febre
 * pre-condicao: nenhuma
 * pos-condicao: febre referente a temperatura
 */
FebreEnum RetornarFebre(double temperatura);

#endif