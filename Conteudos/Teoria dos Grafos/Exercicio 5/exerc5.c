#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

typedef struct vertice {
    struct lista *adj;
    int visitado;
    int distancia;
} vertice;

typedef struct fila {
    struct registro *ini;
    struct registro *final;
} fila;

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

fila *aloca_fila() {
    fila *novo = (fila *)calloc(1, sizeof(fila));
    return novo;
}

void incluir_final(lista *l, int x) {
    registro *novo = aloca_registro();
    novo->valor = x;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->final = novo;
    } else {
        l->final->prox = novo;
        l->final = novo;
    }
}

void incluir_fila(fila *f, int x) {
    registro *novo = aloca_registro();
    novo->valor = x;
    novo->prox = NULL;

    if (f->ini == NULL) {
        f->ini = novo;
        f->final = novo;
    } else {
        f->final->prox = novo;
        f->final = novo;
    }
}

int remover_fila(fila *f) {
    if (f->ini == NULL) {
        return -1;
    }

    registro *tmp = f->ini;
    int valor = tmp->valor;
    f->ini = f->ini->prox;

    if (f->ini == NULL) {
        f->final = NULL;
    }

    free(tmp);
    return valor;
}

void bfs(int raiz, vertice *vertices, int n) {
    fila *f = aloca_fila();
    incluir_fila(f, raiz);
    vertices[raiz].visitado = 1;
    vertices[raiz].distancia = 0;

    while (f->ini != NULL) {
        int atual = remover_fila(f);
        registro *adjacente = vertices[atual].adj->inicio;

        while (adjacente != NULL) {
            int vizinho = adjacente->valor;
            if (!vertices[vizinho].visitado) {
                vertices[vizinho].visitado = 1;
                vertices[vizinho].distancia = vertices[atual].distancia + 1;
                incluir_fila(f, vizinho);
            }
            adjacente = adjacente->prox;
        }
    }
}

void incluir_vertice_lista_adjacencia(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }

    incluir_final(v->adj, valor);
}

void reset_visitados(vertice *vertices, int qtd_vertices) {
    for (int i = 1; i <= qtd_vertices; i++) {
        vertices[i].visitado = 0;
        vertices[i].distancia = -1;
    }
}

int main() {
    int t;
    scanf("%d", &t); 
    while (t--) {
        int n, m, a, b;
        scanf("%d %d", &n, &m);  

        vertice *vertices = (vertice *)calloc(n + 1, sizeof(vertice)); 
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            incluir_vertice_lista_adjacencia(&vertices[a], b);
            incluir_vertice_lista_adjacencia(&vertices[b], a);
        }


        bfs(1, vertices, n);
        printf("%d\n", vertices[n].distancia);
        for (int i = 1; i <= n; i++) {
            registro *tmp = vertices[i].adj ? vertices[i].adj->inicio : NULL;
            while (tmp != NULL) {
                registro *prox = tmp->prox;
                free(tmp);
                tmp = prox;
            }
            free(vertices[i].adj);
        }
        free(vertices);
    }

    return 0;
}