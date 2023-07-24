#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de remoções de elementos pelo índice. (Alocação Dinâmica).
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
    // O pior caso da remoção da lista é caso precise remover o primeiro elemento.
    printf("Removeu? %d\n", array_list_remove_from(lista, 0));
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// Removeu? 0
// 10 elementos em 0.000070 segundos.

// 100
// Removeu? 0
// 100 elementos em 0.000086 segundos.

// 1000
// Removeu? 0
// 1000 elementos em 0.000163 segundos.

// 10000
// Removeu? 0
// 10000 elementos em 0.000183 segundos.

// 100000
// Removeu? 0
// 100000 elementos em 0.001151 segundos.

// 1000000
// Removeu? 0
// 1000000 elementos em 0.008637 segundos.

// 10000000
// Removeu? 0
// 10000000 elementos em 0.050332 segundos.

// 100000000
// Removeu? 0
// 100000000 elementos em 0.502011 segundos.

// 1000000000
// Killed