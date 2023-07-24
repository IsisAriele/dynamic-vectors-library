#include "linked_list_int.h"
#include <stdlib.h>
#include <stdio.h>

// Nó para trabalhar com uma lista duplamente encadeada.
struct linked_list_int_node
{
    int value;
    struct linked_list_int_node *prev;
    struct linked_list_int_node *next;
};

// Referência principal da lista duplamente encadeada.
struct linked_list_int
{
    struct linked_list_int_node *first;
    struct linked_list_int_node *last;
    unsigned int size;
};

/**
 * \brief  Função para imprimir os valores de todos os nós da lista duplamente encadeada.
 *
 * Complexidade O(N) => É necessário percorrer toda a lista para imprimir seus elementos.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 */
void linked_list_print(linked_list_int *list)
{
    linked_list_int_node *node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));
    node = list->first;
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", node->value); // Primeiramente, imprimo o valor do primeiro nó e vou atualizando a referência do value de nod epara o proximo nó.
        node = node->next;
    }
    printf("\n");
}

/**
 * \brief  Retorna a quantidade de elementos na lista.
 *
 * Complexidade O(1) => Já existe uma propriedade na struct 'array_list_int' que guarda o tamanho da lista,
 * deste modo, não precisamos iterar sobre nada.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \return Tamanho da lista.
 */
unsigned int linked_list_size(linked_list_int *list)
{
    return list->size;
}

/**
 * \brief  Cria uma nova lista duplamente encadeada em memória. Retorna um ponteiro para a lista recém criada.
 *
 * Complexidade O(1) => Não há nenhuma iteração, apenas criações de ponteiros/variáveis, etc.
 *
 * \return Um ponteiro para a nova estrutura da lista caso não tenha ocorrido nenhum erro, do contrário, NULL.
 */
linked_list_int *linked_list_create()
{
    linked_list_int *new_list = (linked_list_int *)malloc(sizeof(linked_list_int));
    // Tratamento de erro caso não seja possível criar a nova struct.
    if (new_list == 0)
    {
        return NULL;
    }

    new_list->first = 0;
    new_list->last = 0;
    new_list->size = 0;

    return new_list;
}

/**
 * \brief  Adiciona um novo elemento ao final da lista.
 *
 * Complexidade O(1) => Como temos uma referência para o último nó da lista duplamente encadeada, basta apenas
 * realizarmos os apontamentos do penúltimo, do antigo último e do novo nó.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \param value inteiro com o valor que deve ser armazenado no final da lista.
 * \return Tamanho da lista atualizado.
 */
unsigned int linked_list_push_back(linked_list_int *list, int value)
{
    linked_list_int_node *node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));

    node->value = value;
    node->prev = list->last;
    node->next = 0;

    list->last = node;

    if (node->prev == 0) // Para o caso da list estar anteriormente vazia.
    {
        list->first = node; // Assim, node será first e last.
    }
    else
    {
        node->prev->next = node; // No caso de existir um nó anterior, o next deste apontará para node.
    }

    list->size++;

    return linked_list_size(list);
}

/**
 * \brief  Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho-1.
 *
 * Complexidade O(1) => Como temos uma referência para o último nó da lista duplamente encadeada, basta apenas
 * realizarmos os apontamentos do penúltimo nó para ele passar a ser o último.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \return Valor que estava no último elemento da lista.
 */
unsigned int linked_list_pop_back(linked_list_int *list)
{
    linked_list_int_node *node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));
    int value = list->last->value; // Acessando o valor do último

    if (list->last->prev == 0) // Quando existe apenas um elemento na lista.
    {
        list->last = 0;
    }
    else
    {
        node = list->last->prev; // Acesso ao penúltimo elemento
        node->next = 0;          // next do penultimo aponta para zero
        free(list->last);        // free no nó que era o último
        list->last = node;       // Nova referência para último nó. Penúltimo passa a ser último.
    }

    list->size--;

    return value;
}

/**
 * \brief  Retorna um elemento localizado no índice 'index'.
 *
 * Complexidade O(N) => Como essa lista não possuí índices, começamos a procurar um determinado elemento
 * a partir do primeiro nó da lista. No pior caso, essa função pode acabar tendo que buscar um elemento que
 * está no último nó da lista.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \param error Um ponteiro de um booleano indicando se houve erro na operação (1) ou não (0).
 * \return Valor armazenado na lista no índice que foi informado no parâmetro.
 */
int linked_list_get(linked_list_int *list, int index, int *error)
{
    *error = 0;
    if (index < 0 || index >= list->size)
    {
        *error = 1;
        return 0;
    }

    linked_list_int_node *node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));
    node = list->first;

    for (int i = 0; i < index; i++) // Contador para acessar a lista a partir do first que foi atribuído inicialmente em node, e segue para next nas próximas iterações.
    {
        node = node->next;
    }

    return node->value;
}

/**
 * \brief  Busca um elemento na lista. Retorna o índice onde ele se encontra ou '−1' se ele não estiver na lista.
 *
 * Complexidade O(N) => Começamos a procurar um determinado elemento a partir do primeiro nó da lista. No pior caso, essa
 * função pode acabar tendo que buscar um elemento que está no último nó da lista.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \param element Valor que deseja buscar na lista.
 * \return Índice onde o valor esta armazenado, caso não seja possível encontrá-lo, será retornado -1.
 */
int linked_list_find(linked_list_int *list, int element)
{
    linked_list_int_node *node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));
    node = list->first;

    if (node == 0) // Quando a lista é  vazia
    {
        return -1;
    }

    for (int i = 0; i < list->size; i++) // Percorre toda a lista e retorna o i, caso encontre o elemento.
    {
        if (node->value == element)
        {
            return i;
        }
        node = node->next;
    }

    return -1;
}

/**
 * \brief  Insere um novo elemento na lista, aumentando a quantidade de elementos.
 * O elemento inserido deve se localizar no índice 'index'.
 *
 * Complexidade O(N) => No pior caso, como começamos a realizar a busca do elemento a partir do primeiro nó,
 * pode acontecer do índice solicitado para fazer a inserção ser um dos últimos. Deste modo, a função precisa
 * percorrer a lista totalmente até encontrá-lo.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \param index Índice que o elemento deverá ser armazenado na lista.
 * \param value Valor do elemento a ser armazenado.
 * \return Valor do elemento a ser armazenado.
 */
unsigned int linked_list_insert_at(linked_list_int *list, int index, int value)
{
    // Resumindo, é necessário acessar a lista a através do fisrt ou last e, assim, encontrar um nó que será o antigo, ou seja
    // aquele que antes ocupava a posição do índice que desejo. Tendo esse nó salvo, tenho acesso ao anterior dele e sua respectivas referencias,
    // que são para onde meu novo nó vai apontar. Faço com que os antigos apontem para o meu novo nó e o meu novo nó aponte suas referencias
    // para os antigos.
    if (index < 0)
    {
        index = 0;
    }

    if (list->size == 0 || index >= list->size)
    {
        return linked_list_push_back(list, value);
    }

    linked_list_int_node *new_node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));
    linked_list_int_node *old_node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));

    new_node->value = value;

    old_node = list->first;

    // for para contagem dos nós, até que old_node saia do laço com o valor atribuído do 'índice'/contador desejado.
    // Desta forma, tomando o fisrt da lista e acessando o valor (nó) do índice desejado, temos as referências necessárias
    // para manipulaçção e algum nó entre os 'nós'.

    for (int i = 0; i < index; i++) // Percorro a lista e old_node será o nó do index desejado.
    {
        old_node = old_node->next;
    }
    // atualização das referências do nó a ser inserido
    new_node->prev = old_node->prev;
    new_node->next = old_node;

    if (old_node->prev == 0)
    {
        old_node->prev = new_node;
        list->first = new_node;
    }
    else
    {
        old_node->prev->next = new_node; // o próximo do anterior do old_node, que seria o próprio old_node, aponta para new node. kkkkkkkkkkk
        old_node->prev = new_node;
    }

    list->size++;

    return value;
}

/**
 * \brief  Remove elemento localizado no índice 'index'.
 *
 * Complexidade O(N) => No pior caso, como começamos a realizar a busca do elemento a partir do primeiro nó,
 * pode acontecer do índice solicitado para fazer a remoção ser um dos últimos, deste modo, a função precisa
 * percorrer a lista totalmente até encontrá-lo.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \param index Índice do elemento que deverá ser removido da lista.
 * \return Valor que estava armazenado no elemento removido.
 */
unsigned int linked_list_remove_from(linked_list_int *list, int index)
{
    printf("Entrou! Tamanho: %d \n", list->size);
    if (index < 0)
    {
        index = 0;
    }

    if (index >= list->size - 1)
    {
        printf("Caiu nessa condição!\n");
        return linked_list_pop_back(list);
    }

    linked_list_int_node *old_node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));

    old_node = list->first;

    for (int i = 0; i < index; i++)
    {
        old_node = old_node->next;
    }

    int value = old_node->value;

    if (old_node->prev == 0)
    {
        old_node->next->prev = 0;
        list->first = old_node->next;
    }
    else
    {
        old_node->prev->next = old_node->next;
        old_node->next->prev = old_node->prev;
    }

    free(old_node);

    list->size--;

    return value;
}

/**
 * \brief  Libera memória usado pela lista list.
 *
 * Complexidade O(N) => Precisamos chamar a função 'free' para todos os elementos da lista
 * duplamente encadeada.
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 */
void linked_list_destroy(linked_list_int *list)
{
    linked_list_int_node *current_node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));
    linked_list_int_node *node = (linked_list_int_node *)malloc(sizeof(linked_list_int_node));

    current_node = list->first;
    while (current_node != 0)
    {
        node = current_node;
        current_node = node->next;
        free(node);
    }
    free(list);
}

/**
 * \brief  Por se tratar de uma lista duplamente encadeada, a 'capacidade' dela não precisa
 * ser controlada. Essa função foi implementada apenas por preciosismo de compatibilidade com
 * a implementação do código de alocação dinâmica (array_list_int).
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \return Uma constante double com o valor de 1.
 */
double linked_list_percent_occupied(linked_list_int *list)
{
    return 1;
}

/**
 * \brief  Por se tratar de uma lista duplamente encadeada, a 'capacidade' dela não precisa
 * ser controlada. Essa função foi implementada apenas por preciosismo de compatibilidade com
 * a implementação do código de alocação dinâmica (array_list_int).
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \return Tamanho atual da lista duplamente encadeada + 1 (para representar que sempre podemos
 * inserir mais um elemento).
 */
unsigned int linked_list_capacity(linked_list_int *list)
{
    return list->size + 1;
}

/**
 * \brief  Por se tratar de uma lista duplamente encadeada, a 'capacidade' dela não precisa
 * ser controlada. Essa função foi implementada apenas por preciosismo de compatibilidade com
 * a implementação do código de alocação dinâmica (array_list_int).
 *
 * \param list Um ponteiro para a estrutura da lista duplamente encadeada.
 * \return Uma constante inteira com o valor de 0.
 */
int increase_memory(linked_list_int *list)
{
    return 0;
}
