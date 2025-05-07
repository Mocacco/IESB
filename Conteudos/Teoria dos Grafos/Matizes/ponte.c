#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void encontrar_pontes(int matriz[MAX][MAX], int qtd_v);
void dfs(int matriz[MAX][MAX], int u, int parent, int qtd_v, int *in, int *low, int *tempo);

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

    printf("Pontes no Grafo:\n");
    encontrar_pontes(matriz, qtd_v);

    return 0;
}

void encontrar_pontes(int matriz[MAX][MAX], int qtd_v) {
    int in[MAX], low[MAX], tempo = 0;

    for (int i = 1; i <= qtd_v; i++) {
        in[i] = -1;
        low[i] = -1;
    }

    for (int i = 1; i <= qtd_v; i++) {
        if (in[i] == -1) {
            dfs(matriz, i, -1, qtd_v, in, low, &tempo);
        }
    }
}

void dfs(int matriz[MAX][MAX], int u, int parent, int qtd_v, int *in, int *low, int *tempo) {
    in[u] = low[u] = ++(*tempo);

    for (int v = 1; v <= qtd_v; v++) {
        if (matriz[u][v] == 0) continue;

        if (in[v] == -1) {
            dfs(matriz, v, u, qtd_v, in, low, tempo);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            if (low[v] > in[u]) {
                printf("Ponte encontrada: %d - %d\n", u, v);
            }
        } 
        else if (v != parent) {
            if (low[u] >= in[v]) {
            low[u] = in[v];
        }   
}
    
}