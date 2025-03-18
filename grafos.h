#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct g{
    int numV;
    int **pos;
}Grafo;
//funções

Grafo* leGrafo(const char *nome_arquivo);

#endif