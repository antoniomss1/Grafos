#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>

Grafo* lerGrafo(const char* nomeArquivo){
    
    //abrindo o arquivo
    FILE *graph;
    graph = fopen(nomeArquivo, "rt");
    if (graph == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return NULL;
    }
    int numV;
    int numA=0;
    fscanf(graph, "%d ", &numV);

    char linha[50];  
    int x, y;
    double z=1;
    int valoresLidos;
    int escolha;
    double **Verts;

    // Lendo a primeira linha do arquivo
    if (fgets(linha, sizeof(linha), graph) != NULL) {
        // Tentando ler 3 valores
        valoresLidos = sscanf(linha, "%d %d %lf", &x, &y, &z);

        if (valoresLidos == 3) {
            // printf("Formato 'x y z' detectado: x=%d, y=%d, z=%lf\n", x, y, z);
            Verts = (double **)malloc(numV * sizeof(double *));
            for (int i = 0; i < numV; i++) {
                Verts[i] = (double *)malloc(numV * sizeof(double));
                for (int j = 0; j < numV; j++) {
                    Verts[i][j] = 0.0;
                }
            }
            Verts[x][y] = z;
            numA++;
            escolha = 3;
        } else if (valoresLidos == 2) {
            // printf("Formato 'x y' detectado: x=%d, y=%d\n", x, y);
            Verts = (double **)malloc(numV * sizeof(double *));
            for (int i = 0; i < numV; i++) {
                Verts[i] = (double *)malloc(numV * sizeof(double));
                for (int j = 0; j < numV; j++) {
                    Verts[i][j] = 0.0;
                }
            }
            Verts[x][y] = z;
            numA++;
            escolha = 2;
        } else {
            printf("Erro: formato inválido na primeira linha:\n");
            printf ("%s\n", linha);
            return NULL;
        }
    }

    //dependendo de escolha, continuamos a leitura do arquivo de forma diferente
    switch(escolha){
        case 3:
        //leitura de grafo ponderado
            while(fscanf(graph, "%d %d %lf", &x, &y, &z) == 3){  
                if (x >= 0 && x < numV && y >= 0 && y < numV) {  
                    Verts[x][y] = z;
                    numA++;
                    // Verts[x][y] = z;  
                } else {  
                    printf("Erro: Aresta (%d, %d) fora dos limites!\n", x, y);  
                    return NULL;
                }  
            }
        break;
        //leitura de grafo NÃO ponderado
        case 2:
            while(fscanf(graph, "%d %d", &x, &y) == 2){  
                if (x >= 0 && x < numV && y >= 0 && y < numV) {  
                    Verts[x][y] = 1;  
                    numA++;
                } else {  
                    printf("Erro: Aresta (%d, %d) fora dos limites!\n", x, y);  
                    return NULL;
                }  
            }
        break;
    }
    
    Grafo *g;
    // printf ("tudo ok\n");

    g = (Grafo *)malloc(sizeof(int)*2 + sizeof(void**));
    g->numArestas = numA;
    g->numVertices = numV;
    g->vertices = Verts;
    fclose(graph);
    
    // printf ("tudo ok 2\n");
    return g;
}

void printGrafo(Grafo *g, int precisao){
    if(precisao<0)
        return;
    for(int i=0; i<g->numVertices; i++){
        for(int j=0; j<g->numVertices; j++){
            printf ("%*.*lf ", precisao+3, precisao, (g->vertices)[i][j]);
        }printf ("\n");
    }
}