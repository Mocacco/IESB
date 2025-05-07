#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int matriz[MAX][MAX], int qtd_v, int origem, int *visitado);

int main() {
    int qtd_v, qtd_arestas;
    int matriz[MAX][MAX] = {0};

    printf("Digite o número de vértices e arestas:\n");
    scanf("%d %d", &qtd_v, &qtd_arestas);

    printf("Digite as arestas (origem destino):\n");
    for (int i = 0; i < qtd_arestas; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        matriz[a][b] = 1;
        matriz[b][a] = 1; // Grafo não direcionado
    }

    int origem;
    printf("Digite o vértice de origem para o DFS:\n");
    scanf("%d", &origem);

    int visitado[MAX] = {0};
    printf("Ordem de visita DFS:\n");
    dfs(matriz, qtd_v, origem, visitado);
    printf("\n");

    return 0;
}

void dfs(int matriz[MAX][MAX], int qtd_v, int origem, int *visitado) {
    visitado[origem] = 1;
    printf("%d ", origem);

    for (int v = 1; v <= qtd_v; v++) {
        if (matriz[origem][v] && !visitado[v]) {
            dfs(matriz, qtd_v, v, visitado);
        }
    }
}