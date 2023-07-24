#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Testes com tempo do size(), destroy(), percent_occuped() (Alocação Dinâmica).
 */
int main()
{
    clock_t tempo_inicial, tempo_final;
    int quantidade_de_entradas;

    scanf("%d", &quantidade_de_entradas);

    array_list_int *lista = array_list_create();

    for (int i = 0; i < quantidade_de_entradas; ++i)
    {
        array_list_push_back(lista, i);
    }

    tempo_inicial = clock();
    // Tempo O(1)
    printf("Tamanho: %d\n", array_list_size(lista));
    // Tempo O(1)
    printf("Percentual de Ocupação: %f\n", array_list_percent_occupied(lista));
    // Tempo O(1)
    array_list_destroy(lista);
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// Tamanho: 10
// Percentual de Ocupação: 0.625000
// 10 elementos em 0.000124 segundos.

// 100
// Tamanho: 100
// Percentual de Ocupação: 0.781250
// 100 elementos em 0.000071 segundos.

// 1000
// Tamanho: 1000
// Percentual de Ocupação: 0.976562
// 1000 elementos em 0.000087 segundos.

// 10000
// Tamanho: 10000
// Percentual de Ocupação: 0.610352
// 10000 elementos em 0.000091 segundos.

// 100000
// Tamanho: 100000
// Percentual de Ocupação: 0.762939
// 100000 elementos em 0.000133 segundos.

// 1000000
// Tamanho: 1000000
// Percentual de Ocupação: 0.953674
// 1000000 elementos em 0.000154 segundos.

// 10000000
// Tamanho: 10000000
// Percentual de Ocupação: 0.596046
// 10000000 elementos em 0.000343 segundos.

// 100000000
// Tamanho: 100000000
// Percentual de Ocupação: 0.745058
// 100000000 elementos em 0.001302 segundos.