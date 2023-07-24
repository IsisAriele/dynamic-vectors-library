#include "linked_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de remoções de elementos pelo índice. (Lista Duplamente Encadeada).
 */
int main()
{
    clock_t tempo_inicial, tempo_final;
    int quantidade_de_entradas;

    scanf("%d", &quantidade_de_entradas);

    linked_list_int *lista = linked_list_create();

    for (int i = 0; i < quantidade_de_entradas; ++i)
    {
        linked_list_push_back(lista, i);
    }

    tempo_inicial = clock();
    // Pegamos o penúltimo elemento da lista, pois o "linked_list_remove_from" verifica se o índice é o último elemento,
    // e se for, ele chama a função "linked_list_pop_back", que é O(1);
    printf("Removeu? %d\n", linked_list_remove_from(lista, linked_list_size(lista) - 2));
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// Entrou! Tamanho: 10
// Removeu? 8
// 10 elementos em 0.000097 segundos.

// 100
// Entrou! Tamanho: 100
// Removeu? 98
// 100 elementos em 0.000114 segundos.

// 1000
// Entrou! Tamanho: 1000
// Removeu? 998
// 1000 elementos em 0.000048 segundos.

// 10000
// Entrou! Tamanho: 10000
// Removeu? 9998
// 10000 elementos em 0.000148 segundos.

// 100000
// Entrou! Tamanho: 100000
// Removeu? 99998
// 100000 elementos em 0.000567 segundos.

// 1000000
// Entrou! Tamanho: 1000000
// Removeu? 999998
// 1000000 elementos em 0.004401 segundos.

// 10000000
// Entrou! Tamanho: 10000000
// Removeu? 9999998
// 10000000 elementos em 0.035955 segundos.

// 100000000
// Entrou! Tamanho: 100000000
// Removeu? 99999998
// 100000000 elementos em 0.461268 segundos.

// 1000000000
// Killed
