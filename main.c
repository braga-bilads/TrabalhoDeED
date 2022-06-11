#include <stdio.h>
#include "EdCare.h"

int main(int argc, char const *argv[]){
    EdCare Sistema_EdCare = CriarEdCare();

    CriaVinculosdeApoio(Sistema_EdCare);
    CriaVinculosdeCuidadores(Sistema_EdCare);

    for(int i = 0; i < atoi(argv[1]); i++){
        AtualizarEstruturas(Sistema_EdCare);
        ProcessarInformacoes(Sistema_EdCare);
    }

    DeletarEdCare(Sistema_EdCare);

    return 0;
}
