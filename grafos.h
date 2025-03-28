#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct g{
    int numVertices;
    int numArestas;
    double **vertices;
    char *cores;
}Grafo;

//funções
Grafo* lerGrafo(const char *nome_arquivo);
void printGrafo(Grafo *g, int precisao);
void freeGrafo(Grafo *g);//função para desalocar espaços do grafo FALTA IMPLEMENTAR
//Busca em Largura (BFS)
//como as buscas não pedem um resultado específico, será impresso a ordem de visita no grafo partindo sempre do 0

void BFSearch(Grafo *g);
void DFSearch(Grafo *g);
void printCores(Grafo *g);

Grafo* prim(Grafo* grafo);

Grafo *FloydW(Grafo *g);

#endif