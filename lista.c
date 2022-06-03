#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <lista.h>

/*#include <seuOutroArquivo.h>
int algumaRegraDeNegocio(int);
int algumaRegraDeNegocio(int valor) {
    //faz alguma coisa aqui
    return 1; }*/

struct aponta{
    struct dado;
    struct aponta *prox;
}; typedef struct aponta Ap;

lista* cria_lista(){
    lista* li = (lista*) malloc (sizeof(lista));
    if (li !=NULL)
        *li = NULL;

    return li;
}

void libera_lista (lista* li){
    if(li !=NULL){
        Ap* no;
        while ((*li) !=NULL){
            no = *li;
            *li = (*li) ->prox;
            free(no);
    }
    free (li);
    }
}

int tamanho_lista (lista* li){
    if (li ==NULL) return 0;
    int cont = 0;
    Ap* no = *li;
    while (no !=NULL)
    {
        cont++;
        no= no ->prox;
    }
    return cont;
};

int lista_cheia (lista* li){
    return 0;
}

int lista_vazia (lista* li);{
    if (li == NULL)
        return 1;
        if (*li == NULL)
            return 1;
        return 0;
};