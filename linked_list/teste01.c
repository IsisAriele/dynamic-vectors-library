#include "linked_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Teste de inserção consecutiva de elementos (Lista Duplamente Encadeada).
 */
int main()
{
    clock_t tempo_inicial, tempo_final;
    int quantidade_de_entradas;

    scanf("%d", &quantidade_de_entradas);

    linked_list_int *lista = linked_list_create();

    tempo_inicial = clock();
    for (int i = 0; i < quantidade_de_entradas; i++)
    {
        linked_list_push_back(lista, i);
    }
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// 10 elementos em 0,000002 segundos.

// 100
// 100 elementos em 0,000013 segundos.

// 1000
// 1000 elementos em 0,000074 segundos.

// 10000
// 10000 elementos em 0,000679 segundos.

// 100000
// 100000 elementos em 0,005714 segundos.

// 1000000
// 1000000 elementos em 0,047039 segundos.

// 10000000
// 10000000 elementos em 0,325740 segundos.

// 100000000
// 100000000 elementos em 4,430216 segundos.

// 1000000000
// Killed
