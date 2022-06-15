#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/StreamWriter.h"

struct streamWriter{
    FILE *arquivo;
};

StreamWriter CriarStreamWriter(char *path){
    assert(path != NULL);

    StreamWriter sw = (StreamWriter) malloc(sizeof(struct streamWriter));
    assert(sw != NULL);

    sw->arquivo = fopen(path, "w");
    assert(sw->arquivo != NULL);

    return sw;
}

void DeletarStreamWriter(StreamWriter sw){
    assert(sw != NULL);

    fclose(sw->arquivo);
    free(sw);
}

void WriteLine(StreamWriter sw, char *string){
    assert(sw != NULL && string != NULL);
    
    fprintf(sw->arquivo, "%s\n", string);
}