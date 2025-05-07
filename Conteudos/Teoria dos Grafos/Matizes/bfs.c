#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int matriz[MAX][MAX], int qtd_v, int origem);

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
    printf("Digite o vértice de origem para o BFS:\n");
    scanf("%d", &origem);

    bfs(matriz, qtd_v, origem);

    return 0;
}

void bfs(int matriz[MAX][MAX], int qtd_v, int origem) {
    int visitado[MAX] = {0};
    int fila[MAX], inicio = 0, fim = 0;

    printf("Ordem de visita BFS:\n");

    // Adicionar o vértice de origem na fila
    fila[fim++] = origem;
    visitado[origem] = 1;

    while (inicio < fim) {
        int u = fila[inicio++]; // Remove da fila
        printf("%d ", u);

        for (int v = 1; v <= qtd_v; v++) {
            if (matriz[u][v] && !visitado[v]) {
                fila[fim++] = v; // Adiciona à fila
                visitado[v] = 1;
            }
        }
    }
    printf("\n");
}