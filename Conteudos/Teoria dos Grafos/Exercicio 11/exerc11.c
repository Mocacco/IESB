#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

typedef struct registro {
    int valor;
    int peso;
    struct registro *prox;
} registro;

typedef struct lista {
    registro *ini;
    registro *fim;
} lista;

typedef struct vertice {
    lista *adj;
    int visitado;
} vertice;

typedef struct aresta {
    int u, v, peso;
} aresta;

lista *aloca_lista();
registro *aloca_registro(int valor, int peso);
void incluir_lista(vertice *v, int valor, int peso);
void kruskal(aresta *arestas, int qtd_v, int qtd_arestas);
void prim(vertice *v, int qtd_v);
int find(int parent[], int i);
void union_sets(int parent[], int rank[], int x, int y);
int compare_arestas(const void *a, const void *b);

int main() {
    int qtd_v, qtd_arestas, a, b, w;
    scanf("%d %d", &qtd_v, &qtd_arestas);

    vertice *v = (vertice *)calloc(qtd_v + 1, sizeof(vertice));
    aresta *arestas = (aresta *)malloc(qtd_arestas * sizeof(aresta));

    for (int i = 0; i < qtd_arestas; i++) {
        scanf("%d %d %d", &a, &b, &w);
        incluir_lista(&v[a], b, w);
        incluir_lista(&v[b], a, w);
        arestas[i].u = a;
        arestas[i].v = b;
        arestas[i].peso = w;
    }

    printf("Algoritmo de Kruskal:\n");
    kruskal(arestas, qtd_v, qtd_arestas);

    printf("\nAlgoritmo de Prim:\n");
    prim(v, qtd_v);

    free(arestas);
    free(v);
    return 0;
}

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro(int valor, int peso) {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    novo->valor = valor;
    novo->peso = peso;
    return novo;
}

void incluir_lista(vertice *v, int valor, int peso) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }
    registro *novo = aloca_registro(valor, peso);
    if (v->adj->ini == NULL) {
        v->adj->ini = novo;
        v->adj->fim = novo;
    } else {
        v->adj->fim->prox = novo;
        v->adj->fim = novo;
    }
}

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

void union_sets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int compare_arestas(const void *a, const void *b) {
    return ((aresta *)a)->peso - ((aresta *)b)->peso;
}

void kruskal(aresta *arestas, int qtd_v, int qtd_arestas) {
    int *parent = (int *)malloc((qtd_v + 1) * sizeof(int));
    int *rank = (int *)calloc((qtd_v + 1), sizeof(int));

    for (int i = 1; i <= qtd_v; i++)
        parent[i] = i;

    qsort(arestas, qtd_arestas, sizeof(aresta), compare_arestas);

    int total_peso = 0;
    printf("Arestas da MST (Kruskal):\n");
    for (int i = 0; i < qtd_arestas; i++) {
        int u = arestas[i].u;
        int v = arestas[i].v;
        int peso = arestas[i].peso;

        if (find(parent, u) != find(parent, v)) {
            printf("Aresta %d-%d (Peso: %d)\n", u, v, peso);
            total_peso += peso;
            union_sets(parent, rank, u, v);
        }
    }
    printf("Peso total da MST: %d\n", total_peso);

}

// Funções para o algoritmo de Prim
void prim(vertice *v, int qtd_v) {
    int *dist = (int *)malloc((qtd_v + 1) * sizeof(int));
    int *visitado = (int *)calloc(qtd_v + 1, sizeof(int));
    for (int i = 1; i <= qtd_v; i++)
        dist[i] = INF;

    dist[1] = 0;
    int total_peso = 0;

    for (int i = 1; i <= qtd_v; i++) {
        int u = -1;
        for (int j = 1; j <= qtd_v; j++) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;

        visitado[u] = 1;
        total_peso += dist[u];

        registro *adj = v[u].adj->ini;
        while (adj != NULL) {
            if (!visitado[adj->valor] && adj->peso < dist[adj->valor]) {
                dist[adj->valor] = adj->peso;
            }
            adj = adj->prox;
        }
    }

    printf("Peso total da MST (Prim): %d\n", total_peso);

}