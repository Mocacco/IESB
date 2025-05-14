/*
Nome Funcionário: João Silva Sauro Magalhães - string
Idade: 35 - int
Salário: R$ 24.880,22 - float
Está ativo na empresa: Sim - string
Cargo: “Gerente de Sistemas Web” - string
Número de dependentes: 5 - int
*/
#include <stdio.h>
#include <stdlib.h>

int main()

{
    char nome[40];
    char atv[3];
    char cargo[30];
    int i,d;
    float s;
    
    printf("insira o nome do funcionario\n");
    scanf("%s", &nome);
    printf("insira a idade\n");
    scanf("%d", &i);
    printf("insira o salario\n");
    scanf("%f", &s);
    printf("insira se esta ativo na empresa\n")
    scanf("%s", &atv);
    printf("insira o cargo\n");
    scanf("%s", &cargo);
    printf("insira o numero de dependentes\n");
    scanf("%d", &d);

    printf("\nnome: %s", nome);
    prinft("\nidade: %d", i);
    printf("\nsalario: %0.2f", s)
    if (atv == sim)
    {
        printf("\nStatus %s ativo na empresa", nome);
    }
    else
    {
        printf("\nStatus %s não ativo na empresa", nome);
    }
    printf("cargo: %s", cargo);
    printf("\nnumero de dependentes: %d", d);

    return 0;
}