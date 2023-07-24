#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de busca+remoção. Busca elementos aleatório e remove caso encontre (Alocação Dinâmica).
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

/******** Quando o índice é igual a 0 ********/

// 10
// Encontrado!
// Removeu? 0
// 10 elementos em 0.000060 segundos.

// 100
// Encontrado!
// Removeu? 0
// 100 elementos em 0.000085 segundos.

// 1000
// Encontrado!
// Removeu? 0
// 1000 elementos em 0.000080 segundos.

// 10000
// Encontrado!
// Removeu? 0
// 10000 elementos em 0.000185 segundos.

// 100000
// Encontrado!
// Removeu? 0
// 100000 elementos em 0.001399 segundos.

// 1000000
// Encontrado!
// Removeu? 0
// 1000000 elementos em 0.007790 segundos.

// 10000000
// Encontrado!
// Removeu? 0
// 10000000 elementos em 0.057320 segundos.

// 100000000
// Encontrado!
// Removeu? 0
// 100000000 elementos em 0.515562 segundos.

/******** Quando o índice é o último elemento da lista ********/

// 100
// Encontrado!
// Removeu? 99
// 100 elementos em 0.000094 segundos.

// 1000
// Encontrado!
// Removeu? 999
// 1000 elementos em 0.000088 segundos.

// 10000
// Encontrado!
// Removeu? 9999
// 10000 elementos em 0.000192 segundos.

// 100000
// Encontrado!
// Removeu? 99999
// 100000 elementos em 0.001228 segundos.

// 1000000
// Encontrado!
// Removeu? 999999
// 1000000 elementos em 0.007933 segundos.

// 10000000
// Encontrado!
// Removeu? 9999999
// 10000000 elementos em 0.049053 segundos.

// 100000000
// Encontrado!
// Removeu? 99999999
// 100000000 elementos em 0.498059 segundos.

/******** Quando o índice é o elemento no meio da lista ********/
// 10
// Encontrado!
// Removeu? 5
// 10 elementos em 0.000069 segundos.

// 100
// Encontrado!
// Removeu? 50
// 100 elementos em 0.000084 segundos.

// 1000
// Encontrado!
// Removeu? 500
// 1000 elementos em 0.000073 segundos.

// 10000
// Encontrado!
// Removeu? 5000
// 10000 elementos em 0.000095 segundos.

// 100000
// Encontrado!
// Removeu? 50000
// 100000 elementos em 0.001303 segundos.

// 1000000
// Encontrado!
// Removeu? 500000
// 1000000 elementos em 0.007724 segundos.

// 10000000
// Encontrado!
// Removeu? 5000000
// 10000000 elementos em 0.052397 segundos.

// 100000000
// Encontrado!
// Removeu? 50000000
// 100000000 elementos em 0.504987 segundos.