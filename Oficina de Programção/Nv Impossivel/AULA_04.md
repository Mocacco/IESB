# Problema: A Cidade com Menor Tempo de Viagem

A cidade de Coden é composta por várias intersecções e estradas. As intersecções são numeradas de 1 a N e há M estradas bidirecionais que conectam essas intersecções. Cada estrada possui um tempo de viagem associado. Você foi contratado para ajudar a calcular qual é o menor tempo necessário para viajar de uma intersecção inicial para uma intersecção final. No entanto, nem todas as intersecções estão conectadas diretamente, e algumas estradas podem ter tempo de viagem elevado, então você deve determinar o caminho mais curto.

Você deve implementar um programa que leia os dados de N intersecções, M estradas e calcule o menor tempo de viagem entre uma intersecção inicial e uma intersecção final utilizando o algoritmo de Dijkstra.
Entrada

A primeira linha contém dois inteiros, N (1 ≤ N ≤ 1000) e M (1 ≤ M ≤ 10000), representando o número de intersecções e o número de estradas, respectivamente.
As próximas M linhas contêm três inteiros u, v e w (1 ≤ u, v ≤ N; 1 ≤ w ≤ 1000), onde u e v são intersecções conectadas por uma estrada bidirecional e w é o tempo de viagem entre elas.
A última linha contém dois inteiros, S e T (1 ≤ S, T ≤ N), representando as intersecções inicial e final.

Saída

Imprima o menor tempo de viagem entre S e T. Se não for possível chegar de S a T, imprima -1.

Exemplo de Entrada

    5 6
    1 2 10
    1 3 5
    2 4 1
    3 4 8
    3 5 2
    4 5 6
    1 5

Exemplo de Saída

7
