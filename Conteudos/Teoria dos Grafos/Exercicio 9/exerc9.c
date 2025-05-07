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
void encontrar_pontes(vertice *v, int qtd_v);
void dfs(vertice *v, int u, int parent, int *in, int *low, int *tempo);

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

    printf("\nPontes no Grafo:\n");
    encontrar_pontes(v, qtd_v);

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

void encontrar_pontes(vertice *v, int qtd_v) {
    int *in = (int *)calloc(qtd_v + 1, sizeof(int));
    int *low = (int *)calloc(qtd_v + 1, sizeof(int));
    int *visitado = (int *)calloc(qtd_v + 1, sizeof(int));
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

}

void dfs(vertice *v, int u, int parent, int *in, int *low, int *tempo) {
    in[u] = low[u] = ++(*tempo);
    registro *adj = v[u].adj->ini;

    while (adj != NULL) {
        int v_adj = adj->valor;

        if (in[v_adj] == -1) {
            dfs(v, v_adj, u, in, low, tempo);

            low[u] = (low[u] < low[v_adj]) ? low[u] : low[v_adj];
            if (low[v_adj] > in[u]) {
                printf("Ponte encontrada: %d - %d\n", u, v_adj);
            }
        } else if (v_adj != parent) {
            low[u] = (low[u] < in[v_adj]) ? low[u] : in[v_adj];
        }

        adj = adj->prox;
    }
}