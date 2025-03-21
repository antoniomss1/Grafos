#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct g{
    int numVertices;
    int numArestas;
    double **vertices;
}Grafo;
//funções

Grafo* lerGrafo(const char *nome_arquivo);
void printGrafo(Grafo *g, int precisao);

#endif