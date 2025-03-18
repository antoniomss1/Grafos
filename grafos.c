#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>


Grafo* leGrafo(const char* nomeArquivo){
    printf ("entrou na funcao\n");
    FILE *graph;
    graph = fopen(nomeArquivo, "rt");
    if (graph == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return NULL;
    }
    int numV;
    fscanf(graph, "%d", &numV);
    printf ("leu\n");

    int Verts[numV][numV];
    
    for(int i=0; i<numV; i++){
        for(int j=0; j<numV; j++){
            Verts[i][j] = 0;
        }
    }
    printf ("loop1\n");

    int x, y;
    while(fscanf(graph, "%d %d", &x, &y)==2){
        Verts[x][y]=1;
    }
    
    printf ("loop 2\n");
    printf ("saiu\n");
    for(int i=0; i<numV; i++){
        for(int j=0; j<numV; j++){
            printf ("%d ", Verts[i][j]);
        }printf ("\n");
    }

    fclose(graph);
}
