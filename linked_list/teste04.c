#include "linked_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de busca+remoção. Busca elementos aleatório e remove caso encontre (Lista Duplamente Encadeada).
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
    // Considerando pior caso, não é necessário fazer um if e pegar elementos aleatórios.
    // O pior caso está no penúltimo elemento, uma vez que existe uma verificação caso seja o último índice.
    if (linked_list_find(lista, (linked_list_size(lista) - 2)) != -1)
    {
        printf("Encontrado!\n");
        printf("Removeu? %d\n", linked_list_remove_from(lista, linked_list_size(lista) - 2));
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
// Entrou! Tamanho: 10
// Removeu? 8
// 10 elementos em 0.000084 segundos.

// 100
// Encontrado!
// Entrou! Tamanho: 100
// Removeu? 98
// 100 elementos em 0.000102 segundos.

// 1000
// Encontrado!
// Entrou! Tamanho: 1000
// Removeu? 998
// 1000 elementos em 0.000151 segundos.

// 10000
// Encontrado!
// Entrou! Tamanho: 10000
// Removeu? 9998
// 10000 elementos em 0.000338 segundos.

// 100000
// Encontrado!
// Entrou! Tamanho: 100000
// Removeu? 99998
// 100000 elementos em 0.001626 segundos.

// 1000000
// Encontrado!
// Entrou! Tamanho: 1000000
// Removeu? 999998
// 1000000 elementos em 0.007442 segundos.

// 10000000
// Encontrado!
// Entrou! Tamanho: 10000000
// Removeu? 9999998
// 10000000 elementos em 0.080344 segundos.

// 100000000
// Encontrado!
// Entrou! Tamanho: 100000000
// Removeu? 99999998
// 100000000 elementos em 0.735720 segundos.

// 1000000000
// Killed