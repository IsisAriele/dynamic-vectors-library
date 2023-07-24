#include "linked_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Testes com tempo do size(), destroy(), percent_occuped() (Lista Duplamente Encadeada).
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
    // Tempo O(1)
    printf("Tamanho: %d\n", linked_list_size(lista));
    // Tempo O(1)
    printf("Percentual de Ocupação: %f\n", linked_list_percent_occupied(lista));
    // Tempo O(N)
    linked_list_destroy(lista);
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// Tamanho: 10
// Percentual de Ocupação: 1.000000
// 10 elementos em 0.000068 segundos.

// 100
// Tamanho: 100
// Percentual de Ocupação: 1.000000
// 100 elementos em 0.000097 segundos.

// 1000
// Tamanho: 1000
// Percentual de Ocupação: 1.000000
// 1000 elementos em 0.000110 segundos.

// 10000
// Tamanho: 10000
// Percentual de Ocupação: 1.000000
// 10000 elementos em 0.000262 segundos.

// 100000
// Tamanho: 100000
// Percentual de Ocupação: 1.000000
// 100000 elementos em 0.001533 segundos.

// 1000000
// Tamanho: 1000000
// Percentual de Ocupação: 1.000000
// 1000000 elementos em 0.009943 segundos.

// 10000000
// Tamanho: 10000000
// Percentual de Ocupação: 1.000000
// 10000000 elementos em 0.095562 segundos.

// 100000000
// Tamanho: 100000000
// Percentual de Ocupação: 1.000000
// 100000000 elementos em 1.185471 segundos.