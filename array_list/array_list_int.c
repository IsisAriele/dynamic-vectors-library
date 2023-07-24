#include "array_list_int.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura do array de tamanho fixo, com alocação dinâmica.
struct array_list_int
{
    int *data;
    unsigned int size, capacity;
};

/**
 * \brief  Função para imprimir os valores de todos os nós da lista.
 *
 * Complexidade O(N) => É necessário percorrer toda a lista para imprimir seus elementos.
 *
 * \param list Um ponteiro para a estrutura da lista.
 */
void array_list_print(array_list_int *list)
{
    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

/**
 * \brief  Aumenta a capacidade da lista.
 *  Existem já "pré-configuradas" três formas diferentes de incremento do tamanho da capacidade:
 *      1. Começa com capacidade 100 e aumenta de 100 cada vez que precisar de mais.
 *      2. Começa com capacidade 1000 e aumenta de 1000 cada vez que precisar de mais.
 *      3. Começa com capacidade 8 e duplica cada vez que precisar de mais.
 *
 * Complexidade O(N) => É necessário percorrer toda a lista antiga e inserir os respectivos valores na nova.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \return Caso a capacidade tenha sido aumentada com sucesso será retornado 1, do contrário, será retornado 0.
 */
int increase_memory(array_list_int *list)
{
    int NEW_CAPACITY = list->capacity * 2;
    // int NEW_CAPACITY = list->capacity + 100;
    // int NEW_CAPACITY = list->capacity + 1000;

    // Cria uma nova lista de elementos inteiros que possua o tamanho estipulado por "NEW_CAPACITY".
    int *new_data = (int *)malloc(sizeof(int) * NEW_CAPACITY);
    // Tratamento de erro caso não seja possível criar a nova lista.
    if (new_data == 0)
    {
        return 0;
    }

    // Itera sobre toda a lista antiga e coloca seus respectivos elementos na lista nova.
    for (int i = 0; i < list->capacity; ++i)
    {
        new_data[i] = list->data[i];
    }

    // Libera o espaço de memória da lista antiga.
    free(list->data);

    // Atualiza o ponteiro com o novo 'data' e a nova capacidade.
    list->data = new_data;
    list->capacity = NEW_CAPACITY;

    return 1;
}

/**
 * \brief  Retorna a quantidade de elementos na lista.
 *
 * Complexidade O(1) => Já existe uma propriedade na struct 'array_list_int' que guarda o tamanho da lista,
 * deste modo, não é preciso iterar sobre nada.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \return Tamanho da lista.
 */
unsigned int array_list_size(array_list_int *list)
{
    return list->size;
}

/**
 * \brief  Retorna o espaço efetivamente reservado para a lista.
 *
 * Complexidade O(1) => Já existe uma propriedade na struct 'array_list_int' que guarda a capacidade da lista,
 * deste modo, não é preciso iterar sobre nada.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \return Capacidade reservada da lista.
 */
unsigned int array_list_capacity(array_list_int *list)
{
    return list->capacity;
}

/**
 * \brief  Cria uma nova lista em memória. Retorna um ponteiro para a lista recém criada.
 *  Existem já "pré-configuradas" três formas diferentes de iniciar a capacidade da lista:
 *      1. Começa com capacidade 100 e quando chamada a função 'increase_memory', aumenta de 100 cada vez que precisar de mais.
 *      2. Começa com capacidade 1000 e quando chamada a função 'increase_memory', aumenta de 1000 cada vez que precisar de mais.
 *      3. Começa com capacidade 8 e quando chamada a função 'increase_memory', duplica cada vez que precisar de mais.
 *
 * Complexidade O(1) => Não há nenhuma iteração, apenas criações de ponteiros/variáveis, etc.
 *
 * \return Um ponteiro para a nova estrutura da lista caso não tenha ocorrido nenhum erro, do contrário, NULL.
 */
array_list_int *array_list_create()
{
    int INITIAL_DATA_CAPACITY = 8;
    // int INITIAL_DATA_CAPACITY = 100;
    // int INITIAL_DATA_CAPACITY = 1000;

    array_list_int *new_list = (array_list_int *)malloc(sizeof(array_list_int));
    // Tratamento de erro caso não seja possível criar a nova struct.
    if (new_list == 0)
    {
        return NULL;
    }

    new_list->data = (int *)malloc(sizeof(int) * INITIAL_DATA_CAPACITY);
    // Tratamento de erro caso não seja possível criar a lista da struct.
    if (new_list->data == 0)
    {
        free(new_list);
        return NULL;
    }

    new_list->size = 0;
    new_list->capacity = INITIAL_DATA_CAPACITY;

    return new_list;
}

/**
 * \brief  Retorna um elemento localizado no índice 'index'.
 *
 * Complexidade O(1) => Não há necessidade de iteração na lista, pois o 'data' já permite o acesso direto ao índice.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \param error Um ponteiro de um booleano indicando se houve erro na operação (1) ou não (0).
 * \return Valor armazenado no índice da lista que foi informado no parâmetro.
 */
int array_list_get(array_list_int *list, int index, int *error)
{
    *error = 0;
    if (index < 0 || index >= list->size)
    {
        *error = 1;
        return 0;
    }
    return list->data[index];
}

/**
 * \brief  Adiciona um novo elemento ao final da lista.
 *
 * Complexidade O(N) => No pior caso, pode haver a necessidade de aumentar a capacidade da lista, e se isso ocorrer,
 * a lista toda deverá ser copiada novamente para outra com capacidade maior.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \param value inteiro com o valor que deve ser armazenado no final da lista.
 * \return Tamanho da lista atualizado.
 */
unsigned int array_list_push_back(array_list_int *list, int value)
{
    if (list->capacity == list->size)
    {
        if (!increase_memory(list))
        {
            return array_list_size(list);
        }
    }

    list->data[list->size] = value;
    list->size++;

    return array_list_size(list);
}

/**
 * \brief  Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho-1.
 *
 * Complexidade O(1) => Não há necessidade de reestruturar a lista quando é removido o último elemento dela.
 * O último elemento da lista é facilmente acessado através do 'data' sem precisar percorrer todos os elementos anteriores.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \return Valor que estava no último elemento da lista.
 */
unsigned int array_list_pop_back(array_list_int *list)
{
    if (list->size == 0)
    {
        return 0;
    }

    int last_element = list->data[(list->size) - 1];

    // Como não dá para colocar "NULL" ou algo do gênero, a melhor representação de "nada" é o próprio 0.
    list->data[(list->size) - 1] = 0;
    list->size--;

    return last_element;
}

/**
 * \brief  Busca um elemento na lista. Retorna o índice onde ele se encontra ou '−1' se ele não estiver na lista.
 *
 * Complexidade O(N) => No pior caso o elemento buscado pode ser o último da lista ou não estar na lista, sendo assim, deve-se percorrê-la toda.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \param element Valor que deseja buscar na lista.
 * \return Índice onde o valor esta armazenado, caso não seja possível encontrá-lo, será retornado -1.
 */
int array_list_find(array_list_int *list, int element)
{
    int error, value;

    for (int index = 0; index < list->size; ++index)
    {
        value = array_list_get(list, index, &error);
        if (!error)
        {
            if (value == element)
            {
                return index;
            }
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

/**
 * \brief  Insere um novo elemento na lista, aumentando a quantidade de elementos.
 * O elemento inserido deve se localizar no índice 'index'.
 *
 * Complexidade O(N) => Existem dois cenários que resultam em O(N):
 * 1 - Caso seja necessário aumentar a capacidade da lista: Dessa forma, será necessário copiá-la totalmente novamente;
 * 2 - Caso seja necessário inserir o elemento no começo da lista: Dessa forma, todos os elementos precisarão deslocar um índice para a direita.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \param index Índice que o elemento deverá ser armazenado na lista.
 * \param value Valor do elemento a ser armazenado.
 * \return Valor do elemento a ser armazenado. Caso seja necessário mas não possível de incrementar a capacidade da lista,
 * será retornado o tamanho da mesma.
 */
unsigned int array_list_insert_at(array_list_int *list, int index, int value)
{
    if (index < 0)
    {
        index = 0;
    }

    if (list->size == 0 || index >= list->size)
    {
        return array_list_push_back(list, value);
    }

    if (list->capacity == list->size + 1)
    {
        if (!increase_memory(list))
        {
            // Não foi possível aumentar o tamanho da lista.
            return array_list_size(list);
        }
    }

    // Cria uma nova lista auxiliar com a diferença do tamanho atual e o índice que deve ser armazenado,
    // para que dessa maneira, sejam armazenados os elementos após o índice que precisa receber
    // o novo elemento.
    int *new_data = (int *)malloc(sizeof(int) * list->size - index);

    // Copia os elementos da lista atual que estão a partir do índice informado.
    int aux = 0;
    for (int j = index; j < list->size; ++j)
    {
        new_data[aux] = list->data[j];
        aux += 1;
    }

    // Salva o novo valor no índice informado.
    list->data[index] = value;

    // Coloca os elementos armazenados anteriormente na lista auxiliar na lista atual.
    aux = 0;
    for (int k = index + 1; k < list->size + 1; ++k)
    {
        list->data[k] = new_data[aux];
        aux += 1;
    }

    list->size++;

    return value;
}

/**
 * \brief  Remove elemento localizado no índice 'index'.
 *
 * Complexidade O(N) => No pior caso, se o elemento a ser removido for o primeiro, todos os outros elementos
 * da lista deverão ser deslocados uma casa para a esquerda.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \param index Índice do elemento que deverá ser removido da lista.
 * \return Valor que estava armazenado no elemento removido.
 */
unsigned int array_list_remove_from(array_list_int *list, int index)
{
    if (index < 0)
    {
        index = 0;
    }

    if (index >= list->size)
    {
        return array_list_pop_back(list);
    }

    // Cria uma nova lista auxiliar com a diferença do tamanho atual e o índice que deve ser removido,
    // para que dessa maneira, os valores possam ser reorganizados após a remoção.
    int *new_data = (int *)malloc(sizeof(int) * list->size - index);

    // Copia os elementos da lista atual que estão uma casa a partir do índice informado.
    int aux = 0;
    for (int j = index + 1; j < list->size; ++j)
    {
        new_data[aux] = list->data[j];
        aux += 1;
    }

    // Salva o indice que será removido para retornar no fim da função.
    int value = list->data[index];

    // Coloca os elementos armazenados anteriormente na lista auxiliar na lista atual sobreescrevendo
    // o índice que deve ser removido.
    aux = 0;
    for (int k = index; k < list->size + 1; ++k)
    {
        list->data[k] = new_data[aux];
        aux += 1;
    }

    list->size--;

    return value;
}

/**
 * \brief  Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista.
 * O percentual é um valor entre 0,0 e 1,0.
 *
 * Complexidade O(1) => Como estão sendo salvos os valores da 'capacidade' e do 'tamanho' da lista,
 * apenas é realizada uma operação de divisão básica a fim de encontrar a porcentagem de ocupação da lista.
 *
 * \param list Um ponteiro para a estrutura da lista.
 * \return Porcentagem de ocupação de elementos na lista.
 */
double array_list_percent_occupied(array_list_int *list)
{
    return (double)list->size / (double)list->capacity;
}

/**
 * \brief  Libera memória usado pela lista list.
 *
 * Complexidade O(1) => Chamada da função 'free' é constante.
 *
 * \param list Um ponteiro para a estrutura da lista.
 */
void array_list_destroy(array_list_int *list)
{
    free(list->data);
    free(list);
}
