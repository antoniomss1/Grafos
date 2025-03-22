#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>
#include "auxiliares/listaD.c"

void BFSearch(Grafo *g){
    
    // o Algoritmo que vimos:
    //     Dado G(V,A), conexo: 
    //     escolher uma raiz s de V 
    //     definir uma fila Q, vazia 
    //     marcar s 
    //     inserir s em Q 
    //     enquanto Q não vazia faça 
    //     	seja v o 1°. vértice de Q 
    //     	para cada w pertencente à ListaAdjacencia(v) faça                  
    //     		se w é não marcado então    
    //     			visitar (v,w) 
    //     			marcar w 
    //     			inserir w em Q 
    //     		senão se w  Q então 
    //     			visitar (v,w)   /*w alcançado por outro caminho*/        
    //     		/*senão já processou w e portanto (w,v)*/ 
    //     	/*fim_para*/  
    //         retirar v de Q 
    //         /*fim_enquanto*/
    //     Vou implementar usando uma lista para os marcados, já que não penso em uma forma tão rápida de implementar o TAD e adicionar cores, 
    //     preguiça por hoje pra fazer isso
    
    //usarei como cores 'm' para marcado e 'a' para não marcado
    if(g==NULL){return;}
    Lista fila;definir(&fila);tipo_elemnto valor;valor.chave=0;
    Lista marcados;definir(&marcados);tipo_elemnto elemMarc;elemMarc.chave=0;

    printf ("[");
    inserir_inicio(&fila, valor);
    
    while(vazia(&fila)!=1){
        for(int j=0; j<g->numVertices; j++){//para cada w na lista de adjascência de v
            if(g->vertices[valor.chave][j] !=0){
                
            }
        }
    }

}

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
            Verts[y][x] = z;
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
            Verts[y][x] = z;
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
                    Verts[y][x] = z;
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
                    Verts[y][x] = 1;
                    numA++;
                } else {  
                    printf("Erro: Aresta (%d, %d) fora dos limites!\n", x, y);  
                    return NULL;
                }  
            }
        break;
    }
    
    char *cors = (char*)malloc(sizeof(char)*numV);
    for(int i=0; i<numV; i++){
        cors[i]='a';
    }

    Grafo *g;
    // printf ("tudo ok\n");

    g = (Grafo *)malloc(sizeof(Grafo));
    g->numArestas = numA;
    g->numVertices = numV;
    g->vertices = Verts;
    g->cores = cors;
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
void printCores(Grafo *g){
    for(int i=0; i<g->numVertices; i++){
        printf ("%3c ", g->cores[i]);
    }printf ("\n");
}
