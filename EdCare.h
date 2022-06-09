#include <stdio.h>
#include <stdlib.h>
#include "StreamReader.h"
#include "StreamWriter.h"

typedef struct edcare * EdCare;

int RetornaNumeroDeLeituras(int argc,const char ** argv);

EdCare CriaEdCare(int numeroLeituras);

void CriaVinculosdeApoio(StreamReader apoio,EdCare Sistema_EdCare);

void CriaVinculosdeCuidadores(StreamReader cuidadores,EdCare Sistema_EdCare);