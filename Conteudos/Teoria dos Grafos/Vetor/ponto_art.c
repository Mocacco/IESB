#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int *adj;       // Vetor de adjacências
    int grau;       // Número de adjacências
    int visitado;   // Indica se o vértice foi visitado
} vertice;

void incluir_lista(vertice *v, int origem, int destino);
void encontrar_articulacoes(vertice *v, int qtd_v);
void dfs(vertice *v, int u, int parent, int *disc, int *low, int *tempo, int *articulacao, int *rootChildCount);
void mostrar_lista(vertice *v, int qtd_v);

int main() {
    int qtd_v, qtd_arestas, i, a, b;
    vertice *v;

    scanf("%d %d", &qtd_v, &qtd_arestas);
    v = (vertice *)calloc(qtd_v + 1, sizeof(vertice));

    for (i = 1; i <= qtd_v; i++) {
        v[i].adj = (int *)malloc(qtd_arestas * sizeof(int)); 
        v[i].grau = 0;
    }

    for (i = 0; i < qtd_arestas; i++) {
        scanf("%d %d", &a, &b);
        incluir_lista(v, a, b);
        incluir_lista(v, b, a);
    }

    printf("Lista de Adjacência:\n");
    mostrar_lista(v, qtd_v);

    
    printf("\nPontos de Articulação no Grafo:\n");
    encontrar_articulacoes(v, qtd_v);

    return 0;
}

void incluir_lista(vertice *v, int origem, int destino) {
    v[origem].adj[v[origem].grau] = destino;
    v[origem].grau++;
}

void mostrar_lista(vertice *v, int qtd_v) {
    for (int i = 1; i <= qtd_v; i++) {
        printf("Vértice %d -> ", i);
        for (int j = 0; j < v[i].grau; j++) {
            printf("%d ", v[i].adj[j]);
        }
        printf("\n");
    }
}

void encontrar_articulacoes(vertice *v, int qtd_v) {
    int *disc = (int *)calloc(qtd_v + 1, sizeof(int));
    int *low = (int *)calloc(qtd_v + 1, sizeof(int));
    int *articulacao = (int *)calloc(qtd_v + 1, sizeof(int));
    int tempo = 0;

    for (int i = 1; i <= qtd_v; i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    for (int i = 1; i <= qtd_v; i++) {
        if (disc[i] == -1) {
            int rootChildCount = 0;
            dfs(v, i, -1, disc, low, &tempo, articulacao, &rootChildCount);
            if (rootChildCount > 1) {
                articulacao[i] = 1;
            }
        }
    }
    for (int i = 1; i <= qtd_v; i++) {
        if (articulacao[i]) {
            printf("Ponto de Articulação: %d\n", i);
        }
    }
}

void dfs(vertice *v, int u, int parent, int *disc, int *low, int *tempo, int *articulacao, int *rootChildCount) {
    disc[u] = low[u] = ++(*tempo);
    int childCount = 0;

    for (int i = 0; i < v[u].grau; i++) {
        int v_adj = v[u].adj[i];

        // Se o vértice adjacente não foi visitado
        if (disc[v_adj] == -1) {
            childCount++;
            if (parent == -1) (*rootChildCount)++;

            dfs(v, v_adj, u, disc, low, tempo, articulacao, rootChildCount);

            // Atualizar low[u]
            low[u] = (low[u] < low[v_adj]) ? low[u] : low[v_adj];

            // Verificar se u é um ponto de articulação
            if (parent != -1 && low[v_adj] >= disc[u]) {
                articulacao[u] = 1;
            }
        } else if (v_adj != parent) {
            // Atualizar low[u] para o tempo de descoberta de v_adj
            low[u] = (low[u] < disc[v_adj]) ? low[u] : disc[v_adj];
        }
    }
}