#include "Idoso.h"
#include "Localizador.h"

struct idoso
{
    char* nome;
    Lista amigos;
    Lista cuidadores;
    Registro registro;
    StreamReader sr;
    StreamWriter sw;
    int vivo;
};

Idoso CriarIdoso(char *nome){
    assert(nome != NULL);

    Idoso idoso = (Idoso) malloc(sizeof(struct idoso));
    assert(idoso != NULL);

    idoso->nome = strdup(nome);
    idoso->amigos = CriarLista();
    idoso->cuidadores = CriarLista();
    idoso->registro = CriarRegistro();

    char path[100];
    sprintf(path, "%s.txt", nome);
    idoso->sr = CriarStreamReader(path);

    sprintf(path, "%s-saida.txt", nome);
    idoso->sw = CriarStreamWriter(path);

    idoso->vivo = 1;

    return idoso;
}

char *RecuperaNomeIdoso(Idoso idoso){
    assert(idoso != NULL);

    return idoso->nome;
}

Lista RecuperaAmigosIdoso(Idoso idoso){
    assert(idoso != NULL);

    return idoso->amigos;
}

Lista RecuperaCuidadoresIdoso(Idoso idoso){
    assert(idoso != NULL);

    return idoso->cuidadores;
}

Registro RecuperaRegistroIdoso(Idoso idoso){
    assert(idoso != NULL);

    return idoso->registro;
}

StreamWriter RecuperaStreamWriterIdoso(Idoso idoso){
    assert(idoso != NULL);

    return idoso->sw;
}

void DeletarIdoso(void *idoso){
    assert(idoso != NULL);

    DesfazerAmizades((Idoso) idoso);

    free( ((Idoso) idoso)->nome );
    DeletarLista( ((Idoso) idoso)->amigos, NULL );
    DeletarLista( ((Idoso) idoso)->cuidadores, NULL );
    DeletarRegistro( ((Idoso) idoso)->registro );
    DeletarStreamReader( ((Idoso) idoso)->sr );
    DeletarStreamWriter( ((Idoso) idoso)->sw );

    free(idoso);
}

void AdicionarAmigo(Idoso idoso, Idoso amigo){
    assert(idoso != NULL && amigo != NULL);

    AdicionarItem(idoso->amigos,amigo);
    AdicionarItem(amigo->amigos,idoso);
}

void RemoverAmigo(Idoso idoso, Idoso amigo){
    assert(idoso != NULL && amigo != NULL);

    RemoverItemChave(idoso->amigos, &CompararNomeIdoso, amigo->nome);
    RemoverItemChave(amigo->amigos, &CompararNomeIdoso, idoso->nome);
}

Idoso BuscarAmigoMaisProximo(Idoso idoso){
    assert(idoso != NULL);

    Localizador localIdoso = RecuperaLocalizadorRegistro(idoso->registro);    
    
    void *amigo = NULL;
    double dist = 0.0;
   
    ForEach(idoso->amigos, &amigo);
    while(amigo != NULL && !((Idoso) amigo)->vivo){
        ForEach(NULL, &amigo);
    }

    if(amigo == NULL){
        return NULL;
    }

    Idoso amigoMaisProximo = amigo;
    Localizador localAmigo = RecuperaLocalizadorRegistro( ((Idoso) amigo)->registro );
    double menordist = CalcularDistancia(localIdoso, localAmigo);

    for(ForEach(NULL, &amigo) ; amigo != NULL ; ForEach(NULL, &amigo))
    {
        localAmigo = RecuperaLocalizadorRegistro( ((Idoso) amigo)->registro );
        dist = CalcularDistancia(localIdoso, localAmigo);
        if (dist < menordist && ((Idoso) amigo)->vivo)
        {
            menordist = dist;
            amigoMaisProximo = amigo;
        }
    }
    
    return amigoMaisProximo;
}

void DesfazerAmizades(Idoso idoso){
    Idoso amigo = BuscarItemIndex(idoso->amigos, 0);

    while(amigo != NULL){
        RemoverAmigo(idoso, amigo);
        amigo = BuscarItemIndex(idoso->amigos, 0);
    }
}

void AdicionarCuidador(Idoso idoso, Cuidador cuidador){
    assert(idoso != NULL && cuidador != NULL);

    AdicionarItem(idoso->cuidadores, cuidador);
}

Cuidador BuscarCuidadorMaisProximo(Idoso idoso){
    assert(idoso != NULL);

    Localizador localIdoso = RecuperaLocalizadorRegistro(idoso->registro);

    void *cuidador = NULL;
    double dist = 0.0;    
   
    ForEach(idoso->cuidadores, &cuidador);
    Cuidador cuidadorMaisProximo = cuidador;
    Localizador localCuidador = RecuperaLocalizadorCuidador( (Cuidador) cuidador );
    double menordist = CalcularDistancia(localIdoso, localCuidador);
    
    for(ForEach(NULL, &cuidador) ; cuidador != NULL ; ForEach(NULL, &cuidador))
    {
        localCuidador = RecuperaLocalizadorCuidador( (Cuidador) cuidador );
        dist = CalcularDistancia(localIdoso, localCuidador);
        if (dist < menordist)
        {
            menordist = dist;
            cuidadorMaisProximo = cuidador;
        }
    }    
    
    return cuidadorMaisProximo;
}

void AtualizarIdoso(Idoso idoso){
    assert(idoso != NULL);

    char *string = ReadLine(idoso->sr);
    assert(RecuperaEndOfStream(idoso->sr) != EOF);

    if(strcmp(string, "falecimento") == 0){
        idoso->vivo = 0;
        free(string);
        return;
    }

    double temperatura = 0.0;
    int latitude = 0, longitude = 0, queda = 0;
    sscanf(string, "%lf;%d;%d;%d", &temperatura, &latitude, &longitude, &queda);
    free(string);

    FebreEnum febre = RetornarFebre(temperatura);
    Localizador localizador = CriarLocalizador(latitude, longitude);

    AtualizarRegistro(idoso->registro, febre, queda, localizador);
}

int EhIdosoVivo(Idoso idoso){
    assert(idoso != NULL);

    return idoso->vivo;
}

int CompararNomeIdoso(void *idoso, void *nome){
    assert(idoso != NULL && nome != NULL);

    return strcmp(((Idoso) idoso)->nome, (char *) nome) == 0;
}