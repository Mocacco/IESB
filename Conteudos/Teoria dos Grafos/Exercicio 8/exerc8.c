#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct registro {
    int destino;
    int peso;
    struct registro *prox;
} registro;

typedef struct lista {
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct vertice {
    struct lista *adj;
    int visitado;
    int distancia;
} vertice;

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_final(lista *l, int destino, int peso) {
    registro *novo = aloca_registro();
    novo->destino = destino;
    novo->peso = peso;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->final = novo;
    } else {
        l->final->prox = novo;
        l->final = novo;
    }
}

void incluir_vertice_lista_adjacencia(vertice *v, int destino, int peso) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }
    incluir_final(v->adj, destino, peso);
}

void dijkstra(vertice *vertices, int n, int origem, int destino) {
    int *distancia = (int *)malloc((n + 1) * sizeof(int));
    int *visitado = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        distancia[i] = INF;
        visitado[i] = 0;
    }

    distancia[origem] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u])) {
                u = j;
            }
        }

        if (distancia[u] == INF) {
            break;
        }

        visitado[u] = 1;


        registro *adj = vertices[u].adj->inicio;
        while (adj != NULL) {
            int v = adj->destino;
            int peso = adj->peso;

            if (distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
            }

            adj = adj->prox;
        }
    }

    if (distancia[destino] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", distancia[destino]);
    }

    free(distancia);
    free(visitado);
}

int main() {
    int n, m, u, v, w, s, t;
    scanf("%d %d", &n, &m);

    vertice *vertices = (vertice *)calloc(n + 1, sizeof(vertice));

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        incluir_vertice_lista_adjacencia(&vertices[u], v, w);
        incluir_vertice_lista_adjacencia(&vertices[v], u, w);
    }

    scanf("%d %d", &s, &t);

    dijkstra(vertices, n, s, t);


    return 0;
}