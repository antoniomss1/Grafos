#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct{
    double peso;
    char cor;
}Vertice;

typedef struct g{
    int numVertices;
    int numArestas;
    Vertice** matriz;
}Grafo;
//funções

Grafo* lerGrafo(const char *nome_arquivo);
void printGrafo(Grafo *g, int precisao);

void freeGrafo(Grafo *g);//função para desalocar espaços do grafo FALTA IMPLEMENTAR
//Busca em Largura (BFS)
//como as buscas não pedem um resultado específico, será impresso a ordem de visita no grafo partindo sempre do 0
void BFSearch(Grafo *g);

#endif