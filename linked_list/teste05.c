#include "linked_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Conjunto de inserções+busca+remoção. (Lista Duplamente Encadeada).
 */
int main()
{
    clock_t tempo_inicial, tempo_final;
    int quantidade_de_entradas;

    scanf("%d", &quantidade_de_entradas);

    linked_list_int *lista = linked_list_create();

    tempo_inicial = clock();
    for (int i = 0; i < quantidade_de_entradas; ++i)
    {
        linked_list_push_back(lista, i);
    }

    // Para busca, o pior caso é o último, contudo, na remoção, o pior caso é o penúltimo elemento.
    int index = linked_list_size(lista) - 2;

    if (linked_list_find(lista, index) != -1)
    {
        printf("Encontrado!\n");
        printf("Removeu? %d\n", linked_list_remove_from(lista, index));
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
// 10 elementos em 0.000100 segundos.

// 100
// Encontrado!
// Entrou! Tamanho: 100
// Removeu? 98
// 100 elementos em 0.000105 segundos.

// 1000
// Encontrado!
// Entrou! Tamanho: 1000
// Removeu? 998
// 1000 elementos em 0.000199 segundos.

// 10000
// Encontrado!
// Entrou! Tamanho: 10000
// Removeu? 9998
// 10000 elementos em 0.000933 segundos.

// 100000
// Encontrado!
// Entrou! Tamanho: 100000
// Removeu? 99998
// 100000 elementos em 0.006375 segundos.

// 1000000
// Encontrado!
// Entrou! Tamanho: 1000000
// Removeu? 999998
// 1000000 elementos em 0.057596 segundos.

// 10000000
// Encontrado!
// Entrou! Tamanho: 10000000
// ^[[ARemoveu? 9999998
// 10000000 elementos em 0.397411 segundos.

// 100000000
// Encontrado!
// Entrou! Tamanho: 100000000
// Removeu? 99999998
// 100000000 elementos em 3.951774 segundos.
