#include <stdio.h>
#include "listaD.h"

void definir(Lista *L){
    L->head = NULL;
}

void destruir(Lista *L){
    No *p;
    while (L->head != NULL){
        p=L->head;
        L->head = (L->head)->prox;
        free(p);
    }
}
// int tamanho(Lista *L){//No *p

//     int cont;
//     No *p;

//     for (cont=0, p=L->head; p!= NULL; p = p->prox, cont++){}
//     return cont;

// }  //ok ok2
int tamanho_rec(No *p){
    if(p==NULL)
         return 0;
    
    return (1 + tamanho_rec(p->prox));

}
int tamanho(Lista *L){
    return (tamanho_rec(L->head));
}

void exibir(Lista *L){

    No *p = L->head;
    for(;p!=NULL; p = p->prox){
        printf ("%d ", p->info.chave);
    }printf ("\n");

}  //ok ok2

int inserir_inicio(Lista *L, tipo_elemnto opc){

/*
typedef No* Head = Lista ->
*/

    No *p = (No *)malloc(sizeof(No));

    if (p==NULL){
        return 0;
    }
    p->info = opc;
    p->prox = L->head;
    L->head = p;
    return 1;

    //proveve que isso funciona com a lista vazia

}  //ok
int remover_inicio(Lista *L){

    if(vazia(L))
        return 0;

    No *p;
    p = L->head;
    L->head = p->prox;
    free (p);
    return 1;

} //ok ok2
int inserir_final(Lista *L, tipo_elemnto opc){

    No *p, *k;

    if(vazia(L))
        inserir_inicio(L, opc);

    for(p=L->head; p->prox!= NULL; p=p->prox){}

    k=(No *)malloc(sizeof(No));

    if(!k)
        return 0;

    k->info = opc;
    k->prox = NULL;
    p->prox = k;
    return 1;

} //ok
int vazia(Lista *L){
    return (!L->head);
}  

No* buscar(Lista *L, int busca){

    No *p = L->head;

    while(p != NULL && p->info.chave != busca)//se tiver ordenada dá pra fazer com o "menor"(<)
        p = p->prox;

    return p;

}

void esvaziar(Lista *L){

    
    No *p;

    while(L->head != NULL){
        p = L->head;
        L->head = (L -> head) -> prox;
        free(p);
    }

}  
int inserir_ordenada(Lista *L, tipo_elemnto opc){//do menor pro maior

    No *q, *p, *k;
    if(vazia(L)){
        return (inserir_inicio(L, opc));
    }

    //busca
    for(q=NULL, p=L->head; p!=NULL && opc.chave>p->info.chave; q=p, p=p->prox){

    }
    if (q==NULL){
        return (inserir_inicio(L, opc));
    }

    k=(No*)malloc(sizeof(No));
    if(!k)  return 0;
    k->info = opc;
    k->prox = p;
    q->prox = k;
    return 1;

}

int inserir_ordenada_peso(Lista *L, tipo_elemnto opc){//do menor pro maior

    No *q, *p, *k;
    if(vazia(L)){
        return (inserir_inicio(L, opc));
    }

    //busca
    for(q=NULL, p=L->head; p!=NULL && opc.peso >p->info.peso; q=p, p=p->prox){ }

    if (q==NULL){
        return (inserir_inicio(L, opc));
    }

    k=(No*)malloc(sizeof(No));
    if(!k)  return 0;
    k->info = opc;
    k->prox = p;
    q->prox = k;
    return 1;
}

int remover_final(Lista *L){
    No *p, *k;
    if(vazia(L))
        return 0;
    
    for(p=L->head, k=NULL; p->prox!=NULL; k=p, p=p->prox){};

    free(p);
    if(k==NULL){
        L->head = NULL;
        // return remover_inicio(&L);
    }
    else{
        k->prox = NULL;
    }
    return 1;

} 

No* buscaRec(int chave, No *p){//recursiva

    if(p==NULL)
        return NULL;
    if(p->info.chave == chave)
        return p;

    return (buscaRec(chave, p->prox));

}
int remover(Lista *L, int chave){}
// int cheia(Lista *L){} //ok ok2
No* busca(Lista *L, int chave){}
// int BuscaSeqOrd(Lista *L,int chave){}
int inserirOrdenada(Lista *L, tipo_elemnto v){}
