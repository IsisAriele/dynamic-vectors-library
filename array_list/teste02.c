#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de buscas de elementos aleatório. (Alocação Dinâmica).
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
    printf("Encontrou? %d\n", array_list_find(lista, (array_list_size(lista) - 1)));
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// Encontrou? 9
// 10 elementos em 0,000067 segundos.

// 100
// Encontrou? 99
// 100 elementos em 0,000067 segundos.

// 1000
// Encontrou? 999
// 1000 elementos em 0,000086 segundos.

// 10000
// Encontrou? 9999
// 10000 elementos em 0,000121 segundos.

// 100000
// Encontrou? 99999
// 100000 elementos em 0,001241 segundos.

// 1000000
// Encontrou? 999999
// 1000000 elementos em 0,007263 segundos.

// 10000000
// Encontrou? 9999999
// 10000000 elementos em 0,053258 segundos.

// 100000000
// Encontrou? 99999999
// 100000000 elementos em 0,506631 segundos.

// 1000000000
// Killed
