import heapq

def dijkstra(n, adj, start, end):
    # Inicializa as distâncias com infinito
    dist = [float('inf')] * (n + 1)
    dist[start] = 0
    
    # Fila de prioridade (heap) para processar os nós
    heap = []
    heapq.heappush(heap, (0, start))
    
    while heap:
        current_dist, u = heapq.heappop(heap)
        
        # Se já encontramos um caminho melhor, ignoramos
        if current_dist > dist[u]:
            continue
        
        # Para cada vizinho do nó atual
        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(heap, (dist[v], v))
    
    return dist[end] if dist[end] != float('inf') else -1

def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    
    # Leitura dos dados de entrada
    N, M = int(input[ptr]), int(input[ptr+1])
    ptr += 2
    
    # Criação da lista de adjacência
    adj = [[] for _ in range(N+1)]
    
    for _ in range(M):
        u, v, w = int(input[ptr]), int(input[ptr+1]), int(input[ptr+2])
        ptr += 3
        adj[u].append((v, w))
        adj[v].append((u, w))  # Estrada bidirecional
    
    S, T = int(input[ptr]), int(input[ptr+1])
    
    # Executa o algoritmo de Dijkstra
    result = dijkstra(N, adj, S, T)
    
    # Imprime o resultado
    print(result)

if __name__ == "__main__":
    main()