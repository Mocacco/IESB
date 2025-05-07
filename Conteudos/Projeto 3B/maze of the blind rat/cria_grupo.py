import requests
import json

API_URL = "5b05-2804-14c-65a1-83de-2c25-1590-316a-4c70.ngrok-free.app"

def registrar_grupo(nome_grupo):
    """
    Função para criar um novo grupo via POST e receber o UUID do grupo criado.
    
    Parâmetros:
        nome_grupo (str): O nome do novo grupo.
        
    Retorna:
        str: O UUID do grupo criado, ou None em caso de erro.
    """
    url = f"http://{API_URL}/grupo"  
    payload = {"nome": nome_grupo}  

    try:
        # Enviando a requisição POST
        response = requests.post(url, json=payload)

        if response.status_code == 200:
        
            data = response.json()
            grupo_id = data.get("GrupoId")
            if grupo_id:
                print(f"Grupo criado com sucesso! ID do grupo: {grupo_id}")
                return grupo_id
            else:
                print("Erro: Resposta sem 'GrupoId'.")
        else:
            print(f"Erro ao criar o grupo: {response.status_code}, {response.text}")
    
    except Exception as e:
        print(f"Erro na requisição: {e}")
    return None


if __name__ == "__main__":
    nome_grupo = input("Digite o nome do grupo: ").strip()

    grupo_id = registrar_grupo(nome_grupo)

    if grupo_id:
        print(f"UUID do grupo criado: {grupo_id}")
    else:
        print("Falha ao criar o grupo.")