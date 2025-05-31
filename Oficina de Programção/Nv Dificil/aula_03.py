class No:
    """Classe que representa um nó da lista ligada"""
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None

class ListaLigada:
    """Classe que implementa uma lista ligada"""
    def __init__(self):
        self.cabeca = None
    
    def adicionar(self, valor):
        """Adiciona um novo nó no final da lista"""
        novo_no = No(valor)
        if self.cabeca is None:
            self.cabeca = novo_no
        else:
            atual = self.cabeca
            while atual.proximo is not None:
                atual = atual.proximo
            atual.proximo = novo_no
    
    def __str__(self):
        """Retorna uma representação em string da lista ligada"""
        valores = []
        atual = self.cabeca
        while atual is not None:
            valores.append(str(atual.valor))
            atual = atual.proximo
        return " -> ".join(valores) + " -> None"

def main():
    print("=== Lista Ligada de Números ===")
    
    # Solicita o número N (quantidade de elementos)
    while True:
        try:
            N = int(input("Digite um número inteiro positivo N: "))
            if N <= 0:
                print("Por favor, digite um número positivo.")
                continue
            break
        except ValueError:
            print("Entrada inválida. Digite um número inteiro.")
    
    # Cria a lista ligada
    lista = ListaLigada()
    
    # Solicita os N números ao usuário
    print(f"\nDigite os {N} números:")
    for i in range(1, N+1):
        while True:
            try:
                numero = int(input(f"Número {i}/{N}: "))
                lista.adicionar(numero)
                break
            except ValueError:
                print("Valor inválido. Digite um número inteiro.")
    
    # Exibe a lista ligada
    print("\nLista ligada criada:")
    print(lista)

if __name__ == "__main__":
    main()