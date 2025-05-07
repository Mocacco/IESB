#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct vertice {
    int *adj;       // Vetor de adjacência (vizinhos)
    int *peso;      // Vetor de pesos das arestas
    int grau;       // Número de vizinhos
} vertice;

void incluir_aresta(vertice *v, int origem, int destino, int peso, int qtd_arestas);
void dijkstra(vertice *v, int qtd_v, int origem);
int extrair_minimo(int *dist, int *visitado, int qtd_v);

int main() {
    int qtd_v, qtd_arestas, i, a, b, p;
    vertice *v;

    scanf("%d %d", &qtd_v, &qtd_arestas);
    v = (vertice *)calloc(qtd_v + 1, sizeof(vertice));

    for (i = 1; i <= qtd_v; i++) {
        v[i].adj = (int *)malloc(qtd_arestas * sizeof(int));    // Máximo de arestas
        v[i].peso = (int *)malloc(qtd_arestas * sizeof(int));   // Pesos correspondentes
        v[i].grau = 0;
    }
    for (i = 0; i < qtd_arestas; i++) {
        scanf("%d %d %d", &a, &b, &p);
        incluir_aresta(v, a, b, p, qtd_arestas);
        incluir_aresta(v, b, a, p, qtd_arestas); // Grafo não direcionado
    }
    int origem;
    printf("Digite o vértice de origem: ");
    scanf("%d", &origem);
    dijkstra(v, qtd_v, origem);

    return 0;
}

void incluir_aresta(vertice *v, int origem, int destino, int peso, int qtd_arestas) {
    v[origem].adj[v[origem].grau] = destino;
    v[origem].peso[v[origem].grau] = peso;
    v[origem].grau++;
}

int extrair_minimo(int *dist, int *visitado, int qtd_v) {
    int min_dist = INF;
    int min_index = -1;
    for (int i = 1; i <= qtd_v; i++) {
        if (!visitado[i] && dist[i] < min_dist) {
            min_dist = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(vertice *v, int qtd_v, int origem) {
    int *dist = (int *)calloc(qtd_v + 1, sizeof(int));
    int *visitado = (int *)calloc(qtd_v + 1, sizeof(int));

    for (int i = 1; i <= qtd_v; i++) {
        dist[i] = INF;
    }
    dist[origem] = 0;

    for (int i = 1; i <= qtd_v; i++) {
        int u = extrair_minimo(dist, visitado, qtd_v);
        if (u == -1) break; 

        visitado[u] = 1;

        for (int j = 0; j < v[u].grau; j++) {
            int vizinho = v[u].adj[j];
            int peso = v[u].peso[j];

            if (!visitado[vizinho] && dist[u] != INF && dist[u] + peso < dist[vizinho]) {
                dist[vizinho] = dist[u] + peso;
            }
        }
    }

    printf("Menor distância do vértice %d:\n", origem);
    for (int i = 1; i <= qtd_v; i++) {
        if (dist[i] == INF) {
            printf("Para %d: Infinito\n", i);
        } else {
            printf("Para %d: %d\n", i, dist[i]);
        }
    }
}