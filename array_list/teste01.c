#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Teste de inserção consecutiva de elementos (Alocação Dinâmica).
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
    tempo_final = clock();

    fprintf(stderr, "%d elementos em %f segundos.\n", quantidade_de_entradas, ((double)tempo_final - (double)tempo_inicial) / CLOCKS_PER_SEC);

    return 0;
}

/*** Levando em consideração um array_list_int que dobra a capacidade, começando por 8 ***/

// 10
// 10 elementos em 0.000002 segundos.

// 100
// 100 elementos em 0,000005 segundos.

// 1000
// 1000 elementos em 0,000041 segundos.

// 10000
// 10000 elementos em 0,000289 segundos.

// 100000
// 100000 elementos em 0,003559 segundos.

// 1000000
// 1000000 elementos em 0,021512 segundos.

// 10000000
// 10000000 elementos em 0,144823 segundos.

// 100000000
// 100000000 elementos em 1,390148 segundos.

// 1000000000
// 1000000000 elementos em 22.173479 segundos.

/*** Levando em consideração um array_list_int que começa em 100 e soma 100 quando precisa de mais capacidade ***/

// 10
// 10 elementos em 0,000002 segundos.

// 100
// 100 elementos em 0,000003 segundos.

// 1000
// 1000 elementos em 0,000050 segundos.

// 10000
// 10000 elementos em 0,002554 segundos.

// 100000
// 100000 elementos em 0,152327 segundos.

// 1000000
// 1000000 elementos em 13,496814 segundos.

// 10000000
// ^C - Excedeu o tempo de 3 minutos.

/*** Levando em consideração um array_list_int que começa em 1000 e soma 1000 quando precisa de mais capacidade ***/

// 10
// 10 elementos em 0,000001 segundos.

// 100
// 100 elementos em 0,000003 segundos.

// 1000
// 1000 elementos em 0,000017 segundos.

// 10000
// 10000 elementos em 0,000513 segundos.

// 100000
// 100000 elementos em 0,025310 segundos.

// 1000000
// 1000000 elementos em 1,528888 segundos.

// 10000000
// 10000000 elementos em 133,315312 segundos.
