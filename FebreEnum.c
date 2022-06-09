#include "FebreEnum.h"

FebreEnum RetornarFebre(double temperatura){
    if(temperatura <= 37.0){
        return SemFebre;
    }
    else if(temperatura > 37 && temperatura < 38){
        return FebreBaixa;
    }
    else{
        return FebreAlta;
    }
}