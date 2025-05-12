#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30

int array[MAX_SIZE];
int size = 0;

void menu()
{
    printf("\n============================\n");
    printf("===== 1 - Inserir array =====\n");
    printf("===== 2 - Visualizar array ==\n");
    printf("===== 3 - Pesquisar no array \n");
    printf("===== 4 - Sair ==============\n");
    printf("============================\n");
}

void insert_array()
{
    printf("\nQuantos elementos deseja inserir (máximo %d)? ", MAX_SIZE);
    scanf("%d", &size);
    
    if(size <= 0 || size > MAX_SIZE) {
        printf("Tamanho inválido!\n");
        size = 0;
        return;
    }
    
    printf("Insira %d elementos:\n", size);
    for(int i = 0; i < size; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &array[i]);
    }
}

void view_array()
{
    if(size == 0) {
        printf("Array vazio!\n");
        return;
    }
    
    printf("\nArray atual (%d elementos):\n", size);
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void search_array()
{
    if(size == 0) {
        printf("Array vazio! Não é possível pesquisar.\n");
        return;
    }
    
    int target;
    printf("\nDigite o valor a ser pesquisado: ");
    scanf("%d", &target);
    
    printf("Valor %d encontrado na posicao: ", target);
    int found = 0;
    for(int i = 0; i < size; i++) {
        if(array[i] == target) {
            printf("%d ", i);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Nenhuma ocorrência encontrada.");
    }
    printf("\n");
}

int main()
{
    int escolha;
    
    do {
        menu();
        scanf("%d", &escolha);
        
        switch(escolha) {
            case 1:
                insert_array();
                break;
            case 2:
                view_array();
                break;
            case 3:
                search_array();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(escolha != 4);
    
    return 0;
}