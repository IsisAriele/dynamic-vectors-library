## Executando

Para compilar os testes, utilize o seguinte formato:

```bash
gcc -Wall -o <teste> teste<numero do teste>.c <arquivo da estrutura>.c
```

Exemplo:

```
gcc -Wall -o teste01 teste01.c linked_list_int.c
```

Após compilar o teste, execute da seguinte forma:

```
./<teste>
```

Exemplo:

```
./teste01
```

Você deverá informar uma quantidade de elementos no terminal para que ele possa iterar e realizar o cálculo do tempo gasto do teste.
