#include <stdio.h>
#include <stdlib.h>
#include "StreamReader.h"
#include "StreamWriter.h"

typedef struct edcare* EdCare;

EdCare CriarEdCare();

void DeletarEdCare(EdCare Sistema_EdCare);

void CriaVinculosdeApoio(EdCare Sistema_EdCare);

void CriaVinculosdeCuidadores(EdCare Sistema_EdCare);

void AtualizarEstruturas(EdCare Sistema_EdCare);

void ProcessarInformacoes(EdCare Sistema_EdCare);