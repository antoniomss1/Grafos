#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main(){
    Grafo *G;
    G = lerGrafo("graph_1.txt");
    printGrafo(G, 0);
    // fgets(linha , 15,graph);
    // fscanf(graph, "%c", linha);
    
    // puts(linha);

    // fgets(aux, 2,graph);

    // fclose(graph);
    return 0;
}