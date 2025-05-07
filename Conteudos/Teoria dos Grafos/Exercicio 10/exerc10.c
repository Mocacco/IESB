#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct registro *ini;
    struct registro *fim;
} lista;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

typedef struct vertice {
    struct lista *adj;
    int visitado;
} vertice;

lista *aloca_lista();
registro *aloca_registro();
void incluir_lista(vertice *v, int valor);
void mostrar_lista(lista *l);
void encontrar_articulacoes(vertice *v, int qtd_v);
void dfs(vertice *v, int u, int parent, int *disc, int *low, int *tempo, int *articulacao, int *rootChildCount);

int main() {
    int qtd_v, qtd_arestas, i, a, b;
    vertice *v;

    scanf("%d %d", &qtd_v, &qtd_arestas);
    v = (vertice *)calloc(qtd_v + 1, sizeof(vertice));

    for (i = 0; i < qtd_arestas; i++) {
        scanf("%d %d", &a, &b);
        incluir_lista(&v[a], b);
        incluir_lista(&v[b], a);
    }

    printf("Lista de Adjacência:\n");
    for (i = 1; i <= qtd_v; i++) {
        printf("Vértice %d -> ", i);
        mostrar_lista(v[i].adj);
        printf("\n");
    }

    printf("\nPontos de Articulação no Grafo:\n");
    encontrar_articulacoes(v, qtd_v);

    return 0;
}

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_lista(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }
    registro *novo = aloca_registro();
    novo->valor = valor;
    if (v->adj->ini == NULL) {
        v->adj->ini = novo;
        v->adj->fim = novo;
    } else {
        v->adj->fim->prox = novo;
        v->adj->fim = novo;
    }
}

void mostrar_lista(lista *l) {
    if (l == NULL || l->ini == NULL) return;
    registro *aux = l->ini;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
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
            // Verificar se o vértice raiz é um ponto de articulação
            if (rootChildCount > 1) {
                articulacao[i] = 1;
            }
        }
    }

    // Exibir os pontos de articulação encontrados
    for (int i = 1; i <= qtd_v; i++) {
        if (articulacao[i]) {
            printf("Ponto de Articulação: %d\n", i);
        }
    }

    free(disc);
    free(low);
    free(articulacao);
}

void dfs(vertice *v, int u, int parent, int *disc, int *low, int *tempo, int *articulacao, int *rootChildCount) {
    disc[u] = low[u] = ++(*tempo);
    registro *adj = v[u].adj->ini;
    int childCount = 0;

    while (adj != NULL) {
        int v_adj = adj->valor;

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

        adj = adj->prox;
    }
}