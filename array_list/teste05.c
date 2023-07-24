#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de inserções+busca+remoção. (Alocação Dinâmica).
 */
int main()
{
    clock_t tempo_inicial, tempo_final;
    int quantidade_de_entradas;

    scanf("%d", &quantidade_de_entradas);

    array_list_int *lista = array_list_create();

    tempo_inicial = clock();
    for (int i = 0; i < quantidade_de_entradas; ++i)
    {
        array_list_push_back(lista, i);
    }

    // int index = array_list_size(lista) - 1;
    // int index = 0;
    int index = (int)(array_list_size(lista) / 2);

    // Foram testados três casos diferentes para avaliar o tempo de execução.
    if (array_list_find(lista, index) != -1)
    {
        printf("Encontrado!\n");
        printf("Removeu? %d\n", array_list_remove_from(lista, index));
    }
    else
    {
        printf("Não encontrado!\n");
    }
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

// 10
// Encontrado!
// Removeu? 5
// 10 elementos em 0.000085 segundos.

// 100
// Encontrado!
// Removeu? 50
// 100 elementos em 0.000098 segundos.

// 1000
// Encontrado!
// Removeu? 500
// 1000 elementos em 0.000147 segundos.

// 10000
// Encontrado!
// Removeu? 5000
// 10000 elementos em 0.000476 segundos.

// 100000
// Encontrado!
// Removeu? 50000
// 100000 elementos em 0.003996 segundos.

// 1000000
// Encontrado!
// Removeu? 500000
// 1000000 elementos em 0.027903 segundos.

// 10000000
// Encontrado!
// Removeu? 5000000
// 10000000 elementos em 0.179564 segundos.

// 100000000
// Encontrado!
// Removeu? 50000000
// 100000000 elementos em 1.582234 segundos.
