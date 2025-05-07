#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int matriz[MAX][MAX], int qtd_v, int origem);

int main() {
    int qtd_v, qtd_arestas;
    int matriz[MAX][MAX] = {0};
    scanf("%d %d", &qtd_v, &qtd_arestas);

    for (int i = 0; i < qtd_arestas; i++) {
        int a, b, peso;
        scanf("%d %d %d", &a, &b, &peso);
        matriz[a][b] = peso;
        matriz[b][a] = peso; // Grafo não direcionado
    }

    int origem;
    printf("Digite o vértice de origem: ");
    scanf("%d", &origem);

    dijkstra(matriz, qtd_v, origem);

    return 0;
}

void dijkstra(int matriz[MAX][MAX], int qtd_v, int origem) {
    int dist[MAX], visitado[MAX] = {0};

    for (int i = 1; i <= qtd_v; i++) dist[i] = INF;
    dist[origem] = 0;

    printf("\nTabela de distâncias iniciais:\n");
    for (int i = 1; i <= qtd_v; i++) {
        if (dist[i] == INF) {
            printf("%10s", "INF");
        } else {
            printf("%10d", dist[i]);
        }
    }
    printf("\n");

    for (int i = 1; i <= qtd_v; i++) {
        int min = INF, u = -1;

        for (int j = 1; j <= qtd_v; j++) {
            if (!visitado[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visitado[u] = 1;

        for (int v = 1; v <= qtd_v; v++) {
            if (matriz[u][v] && !visitado[v] && dist[u] != INF && dist[u] + matriz[u][v] < dist[v]) {
                dist[v] = dist[u] + matriz[u][v];
            }
        }

        // Imprime a tabela de distâncias após cada iteração
        printf("\nTabela de distâncias após visitar o vértice %d:\n", u);
        for (int k = 1; k <= qtd_v; k++) {
            if (dist[k] == INF) {
                printf("%10s", "INF");
            } else {
                printf("%10d", dist[k]);
            }
        }
        printf("\n");
    }

    printf("\nMenor distância do vértice %d:\n", origem);
    for (int i = 1; i <= qtd_v; i++) {
        if (dist[i] == INF) {
            printf("Para %d: Infinito\n", i);
        } else {
            printf("Para %d: %d\n", i, dist[i]);
        }
    }
}