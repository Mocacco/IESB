def main():
    # Função para ler o array de números inteiros
    def ler_array():
        print("Digite os números do array separados por espaço:")
        entrada = input().split()
        array = []
        for item in entrada:
            try:
                array.append(int(item))
            except ValueError:
                print(f"Valor '{item}' ignorado (não é um número inteiro válido)")
        return array

    # Função para pesquisar um item no array
    def pesquisar_array(arr):
        try:
            numero = int(input("Digite o número que deseja pesquisar: "))
            if numero in arr:
                indices = [i for i, x in enumerate(arr) if x == numero]
                print(f"O número {numero} foi encontrado no array.")
                print(f"Posições onde aparece: {indices}")
                print(f"Quantidade de ocorrências: {len(indices)}")
            else:
                print(f"O número {numero} não foi encontrado no array.")
        except ValueError:
            print("Por favor, digite um número inteiro válido.")

    # Programa principal
    print("=== Leitura e Pesquisa de Array ===")
    array_numeros = ler_array()
    
    if not array_numeros:
        print("O array está vazio. Nenhuma pesquisa pode ser realizada.")
        return
    
    print("\nArray criado:", array_numeros)
    
    while True:
        print("\nOpções:")
        print("1 - Pesquisar um número no array")
        print("2 - Mostrar o array atual")
        print("3 - Sair")
        
        opcao = input("Escolha uma opção: ")
        
        if opcao == '1':
            pesquisar_array(array_numeros)
        elif opcao == '2':
            print("Array atual:", array_numeros)
        elif opcao == '3':
            print("Programa encerrado.")
            break
        else:
            print("Opção inválida. Por favor, escolha 1, 2 ou 3.")

if __name__ == "__main__":
    main()