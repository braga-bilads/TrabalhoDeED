#include "Idoso.h"
#include "Localizador.h"

struct idoso
{
    char* nome;
    Lista amigos;
    Lista cuidadores;
    Registro registro;
    StreamReader sr;
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

Registro RecuperaRegistro(Idoso idoso){
    assert(idoso != NULL);

    return idoso->registro;
}

void DeletarIdoso(Idoso idoso){
    assert(idoso != NULL);

    //DesfazerAmizades(idoso);

    free(idoso->nome);
    DeletarLista(idoso->amigos, NULL);
    DeletarLista(idoso->cuidadores, NULL);
    DeletarRegistro(idoso->registro);
    DeletarStreamReader(idoso->sr);

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
    Localizador localAmigo = NULL;
    double dist = 0.0;
   
    ForEach(idoso->amigos, &amigo);
    Idoso amigoMaisProximo = amigo;
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
    
}

void AdicionarCuidador(Idoso idoso, Cuidador cuidador){
    assert(idoso != NULL && cuidador != NULL);

    AdicionarItem(idoso->cuidadores, cuidador);
}

Cuidador BuscarCuidadorMaisProximo(Idoso idoso){
    assert(idoso != NULL);

    Localizador localIdoso = RecuperaLocalizadorRegistro(idoso->registro);

    void *cuidador = NULL;
    Localizador localCuidador = NULL;
    double dist = 0.0;    
   
    ForEach(idoso->cuidadores, &cuidador);
    Cuidador cuidadorMaisProximo = cuidador;
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

    AtualizarRegistro(idoso->registro,temperatura, febre, queda, localizador);
}

int EhIdosoVivo(Idoso idoso){
    return idoso->vivo;
}

int CompararNomeIdoso(void *idoso, void *nome){
    Idoso _idoso = idoso;
    char *_nome = nome;

    return strcmp(_idoso->nome, _nome) == 0;
}



// DEBUG
char *IdosoToString(Idoso idoso){
    assert(idoso != NULL);

    char buffer[1000];
    char *registroToString = RegistroToString(idoso->registro);
    sprintf(buffer, "Nome:%s,Registro{%s},Vivo:%d", idoso->nome, registroToString, idoso->vivo);
    free(registroToString);

    return strdup(buffer);
}