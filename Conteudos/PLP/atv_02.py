livros = []
usuarios = []
emprestimos = []

def cadastro_livros():
    livro = {
        'titulo': input('Entre com o título do livro: '),
        'iesbn': input('Entre com o ISBN do livro: '),   
        'autor': input('Entre com o autor do livro: '),
        'genero': input('Entre com o gênero do livro: '),
        'disponivel': 'disponivel'  
    }
    livros.append(livro)
    print(f"Livro '{livro['titulo']}' cadastrado com sucesso!")
    return livro

def cadastro_usuario():
    usuario = {
        'nome': input('Insira o nome do aluno: '),
        'matricula': input('Insira a matrícula do aluno: '),
        'livros_emprestados': 0  
    }
    usuarios.append(usuario)
    print(f"Usuário '{usuario['nome']}' cadastrado com sucesso!")
    return usuario

def emprestimo():
    matricula = input('Digite sua matrícula: ')
    
    
    usuario_encontrado = None
    for usuario in usuarios:
        if usuario['matricula'] == matricula:
            usuario_encontrado = usuario
            break
    
    if not usuario_encontrado:
        print("Matrícula não encontrada!")
        return
    

    if usuario_encontrado['livros_emprestados'] >= 3:
        print(f"Limite de empréstimos atingido! (Máximo: 3 livros)")
        return
    
    
    print("\nLivros disponíveis:")
    disponiveis = [livro for livro in livros if livro['disponivel'] == 'disponivel']
    if not disponiveis:
        print("Nenhum livro disponível no momento.")
        return
    
    for livro in disponiveis:
        print(f"- {livro['titulo']} (ISBN: {livro['iesbn']})")
    
    titulo_desejado = input('\nDigite o título desejado: ')
    
    for livro in livros:
        if livro['titulo'] == titulo_desejado and livro['disponivel'] == 'disponivel':
            livro['disponivel'] = 'emprestado'
            usuario_encontrado['livros_emprestados'] += 1  
            emprestimos.append({
                'matricula': matricula,
                'iesbn': livro['iesbn'],
                'titulo': livro['titulo'],
            })        
            print(f"\nLivro '{titulo_desejado}' emprestado com sucesso!")
            print(f"Livros emprestados atuais: {usuario_encontrado['livros_emprestados']}/3")
            return
    
    print("\nLivro não disponível ou não encontrado.")

def devolucao():
    matricula = input('Digite sua matrícula: ')
    titulo = input('Digite o título do livro a devolver: ')
    
    for emprestimo in emprestimos[:]:
        if emprestimo['matricula'] == matricula and emprestimo['titulo'] == titulo:
            for livro in livros:
                if livro['titulo'] == titulo:
                    livro['disponivel'] = 'disponivel'
                    for usuario in usuarios:
                        if usuario['matricula'] == matricula:
                            usuario['livros_emprestados'] -= 1 
                            break
                    emprestimos.remove(emprestimo)
                    print("Devolução realizada com sucesso!")
                    return
    
    print("Empréstimo não encontrado ou dados incorretos.")

def listar_livros():
    print("\n=== LIVROS CADASTRADOS ===")
    for i, livro in enumerate(livros, 1):
        status = "Disponível" if livro['disponivel'] == 'disponivel' else "Emprestado"
        print(f"{i}. {livro['titulo']} ({livro['autor']}) - {status}")

def listar_usuarios():
    print("\n=== USUÁRIOS CADASTRADOS ===")
    for i, usuario in enumerate(usuarios, 1):
        print(f"{i}. {usuario['nome']} (Matrícula: {usuario['matricula']}) - Livros: {usuario['livros_emprestados']}/3")

def listar_emprestimos():
    print("\n=== EMPRÉSTIMOS ATIVOS ===")
    if not emprestimos:
        print("Nenhum empréstimo ativo.")
        return
    
    for i, emp in enumerate(emprestimos, 1):
        print(f"{i}. Livro: {emp['titulo']} | Matrícula: {emp['matricula']} | Data: {emp['data_emprestimo']}")


def main():
    while True:
        print("\n=== SISTEMA DE BIBLIOTECA ===")
        print("1. Cadastrar Livro")
        print("2. Cadastrar Usuário")
        print("3. Realizar Empréstimo")
        print("4. Realizar Devolução")
        print("5. Listar Livros")
        print("6. Listar Usuários")
        print("7. Listar Empréstimos Ativos")
        print("0. Sair")

        opcao = input("\nEscolha uma opção: ")

        if opcao == "1":
            cadastro_livros()
        elif opcao == "2":
            cadastro_usuario()
        elif opcao == "3":
            emprestimo()
        elif opcao == "4":
            devolucao()
        elif opcao == "5":
            listar_livros()
        elif opcao == "6":
            listar_usuarios()
        elif opcao == "7":
            listar_emprestimos()
        elif opcao == "0":
            print("Saindo do sistema...")
            break
        else:
            print("Opção inválida! Tente novamente.")


if __name__ == "__main__":
    main()