#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StreamReader.h"

struct streamReader{
    FILE *arquivo;
    int endOfStream;
};

StreamReader CriarStreamReader(char *path){
    assert(path != NULL);

    StreamReader sr = (StreamReader) malloc(sizeof(struct streamReader));
    assert(sr != NULL);

    sr->arquivo = fopen(path, "r");
    assert(sr->arquivo != NULL);
    sr->endOfStream = 0;

    return sr;
}

int RecuperaEndOfStream(StreamReader sr){
    assert(sr != NULL);

    return sr->endOfStream;
}

void DeletarStreamReader(StreamReader sr){
    assert(sr != NULL);

    fclose(sr->arquivo);
    free(sr);
}

char *ReadLine(StreamReader sr){
    assert(sr != NULL);

    char *string = NULL;
    sr->endOfStream = fscanf(sr->arquivo, " %m[^\n]%*c", &string);

    return string;
}