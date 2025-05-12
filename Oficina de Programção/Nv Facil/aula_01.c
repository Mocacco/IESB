#include<stdio.h>
#include<stdlib.h>


void menu()
{
    printf("\n===============================");
    printf("\n========= 01 - Soma ===========");
    printf("\n==== 02 - Multiplicacao =======");
    printf("\n======= 03 - Divisao ==========");
    printf("\n======= 04 - Subtacao =========");
    printf("\n========= 05 - Sair ===========");
    printf("\n=============================\n");
}

int soma ()
{
    int a,b,c;    
    printf("insira o primeiro numero: ");
    scanf("%d", &a);
    printf("insira o segundo numero: ");
    scanf("%d", &b);
    printf("\n soma dos dois numeros e: %d", (a+b));\
    printf("\n caso deseje fazer outra operacao digite 0 caso contrario digite 1\n");
    scanf("%d", &c);
    return c;
}

int multiplicacao()
{
    int a,b,c;    
    printf("insira o primeiro numero: ");
    scanf("%d", &a);
    printf("insira o segundo numero: ");
    scanf("%d", &b);
    printf("\n multiplicacao dos dois numeros e: %d", (a*b));\
    printf("\n caso deseje fazer outra operacao digite 0 caso contrario digite 1\n");
    scanf("%d", &c);
    return c;
}

int divisao()
{
    int a,b,c;    
    printf("insira o primeiro numero: ");
    scanf("%d", &a);
    printf("insira o segundo numero: ");
    scanf("%d", &b);
    printf("\n divisao dos dois numeros e: %.2f", (float)a/b);\
    printf("\n caso deseje fazer outra operacao digite 0 caso contrario digite 1\n");
    scanf("%d", &c);
    return c;
}

int subtracao()
{
    int a,b,c;    
    printf("insira o primeiro numero: ");
    scanf("%d", &a);
    printf("insira o segundo numero: ");
    scanf("%d", &b);
    printf("\n subtracao dos dois numeros e: %d", (a-b));\
    printf("\n caso deseje fazer outra operacao digite 0 caso contrario digite 1\n");
    scanf("%d", &c);
    return c;
}

int main ()
{
    int escolha;
    int opcao= 0;  
    
    while (!opcao)
    {
        menu();
        
        scanf("%d", &escolha);
        
        switch(escolha)
        {
            case 1:
                opcao= soma();
                break;
            case 2:
                opcao= multiplicacao();
                break;
            case 3:
                opcao= divisao();
                break;
            case 4:
                opcao= subtracao();
                break;
            case 5:
                opcao= 1;
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
    
    printf("Programa encerrado.\n");
    return 0;
}