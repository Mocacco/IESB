#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void encontrar_articulacoes(int matriz[MAX][MAX], int qtd_v);
void dfs(int matriz[MAX][MAX], int u, int parent, int qtd_v, int *disc, int *low, int *articulacao, int *tempo, int *rootChildCount);

int main() {
    int qtd_v, qtd_arestas;
    int matriz[MAX][MAX] = {0};
    scanf("%d %d", &qtd_v, &qtd_arestas);

    for (int i = 0; i < qtd_arestas; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        matriz[a][b] = 1;
        matriz[b][a] = 1;
    }

    printf("\nPontos de Articulação no Grafo:\n");
    encontrar_articulacoes(matriz, qtd_v);

    return 0;
}

void encontrar_articulacoes(int matriz[MAX][MAX], int qtd_v) {
    int disc[MAX], low[MAX], articulacao[MAX] = {0}, tempo = 0;

    for (int i = 1; i <= qtd_v; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    for (int i = 1; i <= qtd_v; i++) {
        if (disc[i] == -1) {
            int rootChildCount = 0;
            dfs(matriz, i, -1, qtd_v, disc, low, articulacao, &tempo, &rootChildCount);
            if (rootChildCount > 1) articulacao[i] = 1;
        }
    }

    for (int i = 1; i <= qtd_v; i++) {
        if (articulacao[i]) {
            printf("Ponto de Articulação: %d\n", i);
        }
    }
}

void dfs(int matriz[MAX][MAX], int u, int parent, int qtd_v, int *disc, int *low, int *articulacao, int *tempo, int *rootChildCount) {
    disc[u] = low[u] = ++(*tempo);
    int childCount = 0;

    for (int v = 1; v <= qtd_v; v++) {
        if (matriz[u][v] == 0) continue;

        if (disc[v] == -1) {
            childCount++;
            if (parent == -1) (*rootChildCount)++;

            dfs(matriz, v, u, qtd_v, disc, low, articulacao, tempo, rootChildCount);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (parent != -1 && low[v] >= disc[u]) articulacao[u] = 1;
        } else if (v != parent) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}