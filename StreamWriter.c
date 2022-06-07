#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StreamWriter.h"

struct streamWriter{
    FILE *arquivo;
};

StreamWriter CriarStreamWriter(char *path){
    StreamWriter sw = (StreamWriter) malloc(sizeof(struct streamWriter));
    assert(sw != NULL);

    sw->arquivo = fopen(path, "w");
    assert(sw->arquivo != NULL);

    return sw;
}

void DeletarStreamWriter(StreamWriter sw){
    assert(sw != NULL);
    assert(sw->arquivo != NULL);

    fclose(sw->arquivo);
    free(sw);
}

void WriteLine(StreamWriter sw, char *string){
    assert(sw != NULL);
    assert(sw->arquivo != NULL);
    
    fprintf(sw->arquivo, "%s\n", string);
}