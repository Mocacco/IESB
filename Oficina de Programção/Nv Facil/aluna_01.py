def calculadora():
    print("Calculadora Básica")
    print("Operações disponíveis:")
    print("1 - Soma")
    print("2 - Subtração")
    print("3 - Multiplicação")
    print("4 - Divisão")
    
    while True:
        try:
            operacao = int(input("Digite o número da operação desejada (1/2/3/4): "))
            if operacao not in [1, 2, 3, 4]:
                print("Opção inválida. Por favor, escolha 1, 2, 3 ou 4.")
                continue
                
            num1 = float(input("Digite o primeiro número: "))
            num2 = float(input("Digite o segundo número: "))
            
            if operacao == 1:
                resultado = num1 + num2
                print(f"Resultado: {num1} + {num2} = {resultado}")
            elif operacao == 2:
                resultado = num1 - num2
                print(f"Resultado: {num1} - {num2} = {resultado}")
            elif operacao == 3:
                resultado = num1 * num2
                print(f"Resultado: {num1} * {num2} = {resultado}")
            elif operacao == 4:
                if num2 == 0:
                    print("Erro: Divisão por zero!")
                else:
                    resultado = num1 / num2
                    print(f"Resultado: {num1} / {num2} = {resultado}")
            
            continuar = input("Deseja fazer outra operação? (s/n): ").lower()
            if continuar != 's':
                print("Calculadora encerrada.")
                break
                
        except ValueError:
            print("Erro: Por favor, digite números válidos.")

# Chamando a função da calculadora
calculadora()