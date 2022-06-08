#ifndef FEBREENUM_H
#define FEBREENUM_H

typedef enum Febre{
    SemFebre,
    FebreBaixa,
    FebreAlta
} FebreEnum;

FebreEnum RetornaFebre(double temperatura);

#endif