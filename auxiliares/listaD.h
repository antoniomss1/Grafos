
#ifndef LISTAD_H
#define LISTAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10
#define NIL -1

/*tipo do dado*/
typedef struct {
    int chave;
    //outras informações
}tipo_elemnto;

/*lista estatica sequencial*/
typedef struct no{
    tipo_elemnto info;
    struct no *prox;
}No;

typedef struct {
    No *head;
}Lista;


/*operações*/

void definir            (Lista *L); 
void esvaziar           (Lista *L);  

int inserir_inicio      (Lista *L, tipo_elemnto opc);
int inserir_final       (Lista *L, tipo_elemnto opc);
int inserir_ordenada    (Lista *L, tipo_elemnto opc);
int remover_inicio      (Lista *L);
int remover_final       (Lista *L); 
int remover             (Lista *L, int chave);

void exibir             (Lista *L);  
No* buscar              (Lista *L, int busca); 
int tamanho             (Lista *L);  
// int cheia(Lista *L); 
int vazia               (Lista *L);//retorna 1 se está vazio ou zero, caso contrário
No* busca               (Lista *L, int chave);
// int BuscaSeqOrd(Lista *L,int chave);
int inserirOrdenada     (Lista *L, tipo_elemnto v);
No *buscaRec            (int chave, No *p);
/*

*/
#endif