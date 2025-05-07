#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int *adj;       // Vetor de adjacências
    int grau;       // Número de adjacências
    int visitado;
} vertice;

void incluir_lista(vertice *v, int origem, int destino);
void encontrar_pontes(vertice *v, int qtd_v);
void dfs(vertice *v, int u, int parent, int *in, int *low, int *tempo);
void mostrar_lista(vertice *v, int qtd_v);

int main() {
    int qtd_v, qtd_arestas, i, a, b;
    vertice *v;


    scanf("%d %d", &qtd_v, &qtd_arestas);
    v = (vertice *)calloc(qtd_v + 1, sizeof(vertice));

    // Inicializa os vetores de adjacência
    for (i = 1; i <= qtd_v; i++) {
        v[i].adj = (int *)malloc(qtd_arestas * sizeof(int)); // Aloca espaço máximo
        v[i].grau = 0;
    }

    // Leitura das arestas
    for (i = 0; i < qtd_arestas; i++) {
        scanf("%d %d", &a, &b);
        incluir_lista(v, a, b);
        incluir_lista(v, b, a);
    }

    // Mostrar a lista de adjacência
    printf("Lista de Adjacência:\n");
    mostrar_lista(v, qtd_v);

    // Encontrar pontes no grafo
    printf("\nPontes no Grafo:\n");
    encontrar_pontes(v, qtd_v);

    // Liberar memória alocada
    for (i = 1; i <= qtd_v; i++) {
        free(v[i].adj);
    }
    free(v);

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

void encontrar_pontes(vertice *v, int qtd_v) {
    int *in = (int *)calloc(qtd_v + 1, sizeof(int));
    int *low = (int *)calloc(qtd_v + 1, sizeof(int));
    int tempo = 0;

    for (int i = 1; i <= qtd_v; i++) {
        in[i] = -1;
        low[i] = -1;
    }

    for (int i = 1; i <= qtd_v; i++) {
        if (in[i] == -1) {
            dfs(v, i, -1, in, low, &tempo);
        }
    }

    free(in);
    free(low);
}

void dfs(vertice *v, int u, int parent, int *in, int *low, int *tempo) {
    in[u] = low[u] = ++(*tempo);

    for (int i = 0; i < v[u].grau; i++) {
        int v_adj = v[u].adj[i];

        if (in[v_adj] == -1) { // Se o vértice não foi visitado
            dfs(v, v_adj, u, in, low, tempo);

            low[u] = (low[u] < low[v_adj]) ? low[u] : low[v_adj];

            // Verifica se é uma ponte
            if (low[v_adj] > in[u]) {
                printf("Ponte encontrada: %d - %d\n", u, v_adj);
            }
        } else if (v_adj != parent) { // Caso contrário, atualiza o low[u]
            low[u] = (low[u] < in[v_adj]) ? low[u] : in[v_adj];
        }
    }
}