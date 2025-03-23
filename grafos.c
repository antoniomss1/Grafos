#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "auxiliares/listaD.h"

void descolorirGrafo(Grafo *g){
    for(int i=0; i<g->numVertices; i++){
        g->cores[i] = 'a';
    }
}

int addEdgeList(Lista *L, int x, int y, double peso){
    tipo_elemnto aux;
    aux.peso = peso;aux.x = x; aux.y = y;
    inserir_ordenada_peso(L, aux);
}

void addAresta(Grafo *g, int x, int y, double peso){
    g->vertices[x][y] = peso;
    g->vertices[y][x] = peso;    
}
Grafo* criarGrafo(int numV){
    Grafo *p = (Grafo *)malloc(sizeof(Grafo));
    double **matr = (double **)malloc(sizeof(double * )*numV);
    for(int i=0; i<numV; i++){
        matr[i] = (double *)calloc(numV, sizeof(double ));
    }
    
    char *cors = (char*)malloc(sizeof(char)*numV);
    for(int i=0; i<numV; i++){
        cors[i]='a';
    }

    p->vertices = matr;
    p->cores = cors;
    p->numArestas = 0;
    p->numVertices = numV;
    return p;
}

int escolheAresta(Lista *arestas, Grafo *tree){
    int x = arestas->head->info.x;
    int y = arestas->head->info.y;
    double peso = arestas->head->info.peso;

    tree->vertices[x][y] = peso;
    tree->vertices[y][x] = peso;

    remover_inicio(arestas);
    return x;
}

Grafo* prim(Grafo* grafo) {
    int numV = grafo->numVertices;
    int pai[numV];   // Armazena a MST resultante
    int chave[numV]; // Chaves usadas para escolher arestas de menor peso
    int visitado[numV]; // Indica se um vértice já está na MST

    for (int i = 0; i < numV; i++) {
        chave[i] = INT_MAX; // Inicializa todas as chaves com infinito
        visitado[i] = 0;    // Nenhum vértice foi incluído na MST
    }
    
    chave[0] = 0;   // Começamos pelo vértice 0
    pai[0] = -1;    // O primeiro nó não tem pai

    for (int count = 0; count < numV - 1; count++) {
        int u = -1, min = INT_MAX;

        // Encontra o vértice com a menor chave ainda não incluído na MST
        for (int v = 0; v < numV; v++) {
            if (!visitado[v] && chave[v] < min) {
                min = chave[v];
                u = v;
            }
        }

        visitado[u] = 1; // Inclui u na MST

        // Atualiza os valores das chaves dos vértices adjacentes a u
        for (int v = 0; v < numV; v++) {
            if (grafo->vertices[u][v] && !visitado[v] && grafo->vertices[u][v] < chave[v]) {
                pai[v] = u;
                chave[v] = grafo->vertices[u][v];
            }
        }
    }

    
    Grafo *tree = criarGrafo(grafo->numVertices);
    for (int i = 1; i < numV; i++) {
        addAresta(tree, pai[i], i, grafo->vertices[i][pai[i]]);
        // printf("%d - %d (Peso: %.1lf)\n", pai[i], i, grafo->vertices[i][pai[i]]);
    }
    return tree;
}

void BFSearch(Grafo *g){//imprime a ordem de travessia no grafo
    
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
    //     		senão se w pertence à Q então 
    //     			visitar (v,w)   /*w alcançado por outro caminho*/        
    //     		/*senão já processou w e portanto (w,v)*/ 
    //     	/*fim_para*/  
    //         retirar v de Q 
    //         /*fim_enquanto*/
    
    //usarei como cores 'm' para marcado e 'a' para não marcado
    if(g==NULL){return;}
    Lista fila;definir(&fila);tipo_elemnto valor;valor.chave=0;
    tipo_elemnto aux;

    printf ("[");
    g->cores[valor.chave] = 'm';//marca s
    inserir_inicio(&fila, valor);

    printf ("%d", valor.chave);
    
    while(vazia(&fila)!=1){
        valor.chave = fila.head->info.chave;//valor é o primeiro valor da fila
        // printf ("no while\n");
        for(int j=0; j<g->numVertices; j++){//para cada w na lista de adjascência de v

            if(g->vertices[valor.chave][j] !=0){//os não nulos são os da lista de adjacência
                if(g->cores[j] != 'm'){//se ele é não marcado
                    // printf ("etrou\n");
                    // printf (" (%d, %d);", valor.chave+1, j+1);//visita v,w
                    g->cores[j] = 'm';
                    printf (", %d", j);
                    aux.chave = j;
                    inserir_final(&fila, aux);
                }
                //a parte de baixo é necessária para o caso de fazer a visita (printf)

                // else if(buscar(&fila, j)!=NULL){
                //     // printf ("ELSE\n");
                //     // printf (" (%d, %d);", valor.chave+1, j+1); 
                // }
                // printf ("dentro\n");
            
            }
        }
        remover_inicio(&fila);
    }
    descolorirGrafo(g);
    printf ("]\n");
}

void DFS(Grafo *g, int vertice) {
    if (g == NULL) return;

    printf(" %d", vertice);
    g->cores[vertice] = 'm'; 

    for (int j = 0; j < g->numVertices; j++) {
        if (g->vertices[vertice][j] != 0 && g->cores[j] != 'm') {  
            DFS(g, j); 
        }
    }
}

void DFSearch(Grafo *g) {
    if (g == NULL) return;

    descolorirGrafo(g); 

    printf("[");
    DFS(g, 0); 
    printf(" ]\n");

    descolorirGrafo(g);
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
                // Verts[i] = (double *)malloc(numV * sizeof(double));
                Verts[i] = (double *)calloc(numV, sizeof(double));
                
                // for (int j = 0; j < numV; j++) {
                //     Verts[i][j] = 0.0;

                // }
            }
            Verts[x][y] = z;
            Verts[y][x] = z;
            numA++;
            escolha = 3;
        } else if (valoresLidos == 2) {
            // printf("Formato 'x y' detectado: x=%d, y=%d\n", x, y);
            Verts = (double **)malloc(numV * sizeof(double *));
            for (int i = 0; i < numV; i++) {
                // Verts[i] = (double *)malloc(numV * sizeof(double));
                Verts[i] = (double *)calloc(numV, sizeof(double));
                
                // for (int j = 0; j < numV; j++) {
                //     Verts[i][j] = 0.0;
                // }
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

void inicializarDist(int numV, double **grafo, double **dist) {
    for (int i = 0; i < numV; i++) {
        for (int j = 0; j < numV; j++) {
            if (i == j) {
                dist[i][j] = 0;  // Distância de um nó para ele mesmo é 0
            } else if (grafo[i][j] != 0) {
                dist[i][j] = grafo[i][j];  // Se há aresta, usa o peso dela
            } else {
                dist[i][j] = INT_MAX;  // Se não há aresta, define como infinito
            }
        }
    }
}

Grafo *FloydW(Grafo *g){
    Grafo *dist;
    dist = criarGrafo(g->numVertices); 
    inicializarDist(g->numVertices, g->vertices, dist->vertices);

    int n = g->numVertices;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist->vertices[i][j] > dist->vertices[i][k] + dist->vertices[k][j])
                dist->vertices[i][j] = dist->vertices[i][k] + dist->vertices[k][j];
            }
        }
    }

    return dist;
}