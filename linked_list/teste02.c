#include "linked_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de buscas de elementos aleatório. (Lista Duplamente Encadeada).
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
    printf("Encontrou? %d\n", linked_list_find(lista, (linked_list_size(lista) - 1)));
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// Encontrou? 9
// 10 elementos em 0,000061 segundos.

// 100
// Encontrou? 99
// 100 elementos em 0,000075 segundos.

// 1000
// Encontrou? 999
// 1000 elementos em 0,000075 segundos.

// 10000
// Encontrou? 9999
// 10000 elementos em 0,000159 segundos.

// 100000
// Encontrou? 99999
// 100000 elementos em 0,000977 segundos.

// 1000000
// Encontrou? 999999
// 1000000 elementos em 0,004118 segundos.

// 10000000
// Encontrou? 9999999
// 10000000 elementos em 0,038950 segundos.

// 100000000
// Encontrou? 99999999
// 100000000 elementos em 0,407303 segundos.

// 1000000000
// Killed