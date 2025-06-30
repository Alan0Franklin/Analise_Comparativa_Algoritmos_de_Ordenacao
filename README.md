# Análise Comparativa de Algoritmos de Ordenação
Um projeto desenvolvido com o objetivo de analisar e comparar o desempenho, a efetividade e outras características de seis algoritmos de ordenação: Selection Sort, Insertion Sort, Bubble Sort, Quick Sort, Merge Sort e Intro Sort (std::sort). A análise se baseia em gráficos comparativos que consideram a complexidade, o número de trocas e o uso de espaço auxiliar em função da quantidade de elementos, de acordo com o caso analisado (melhor, médio ou pior). Também são levados em conta o número de comparações, trocas, chamadas recursivas e os tempos de execução de cada algoritmo.


## Sumário

- [1. Estrutura](#1-estrutura)
- [2. Descrição das Funções](#2-descricao_das_funcoes)
- [3. Como Compilar e Executar](#3-como_compilar_e_executar)

---

## Estrutura <a name="1-estrutura"></a>
```
Analise_Comparativa_Algoritmos_de_Ordenacao/
├── Graficos_da_Analise_Comparativa_de_Algoritmos_de_Ordenacao.ipynb
├── Makefile
├── README.md
├── algoritmos_de_ordenacao.cpp
├── algoritmos_de_ordenacao.hpp
└── main.cpp
```

## Descrição das Funções <a name="2-descricao_das_funcoes"></a>

### + int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup)
Função para ler um número inteiro do terminal, bloqueando qualquer entrada que não seja um inteiro. Após validar que a entrada é um número inteiro, verifica-se se o valor pertence ao intervalo fechado \[`lim_inf`, `lim_sup`]. Se pertencer, a função retorna esse valor e é finalizada. Caso contrário, a `mensagem_erro` será exibida e um novo valor deverá ser inserido até que seja uma entrada válida.
- `mensagem_erro`: String correspondente à mensagem de erro que deve ser exposta caso um valor não inteiro seja recebido do dispositivo de entrada.
- `lim_inf`: Inteiro correspondente ao primeiro número de um intervalo fechado o qual o valor que deve pertencer.
- `lim_inf`: Inteiro correspondente ao último número de um intervalo fechado o qual o valor que deve pertencer. Se esse valor for igual à -1, o intervalo para conferência do valor principal será \[`lim_inf`, +∞].

### + vector\<int> criador_vetor()
Função que receber as principais entradas que servirão como parâmetros para a criação do vetor de inteiros, o qual será utilizado nos testes dos algoritmos de ordenação. Primeiro é solicitado um número inteiro que define o tamanho desejado do vetor. Em seguida, pede-se ao usuário que informe o tipo de vetor a ser gerado, também por meio de um número inteiro digitado no terminal, cujos valores possíveis são definidos conforme a seguinte tabela:

| Tipos de Vetores  | Código     | Descrição                        |
|:------------------|:------:|----------------------------------|
| Aleatorio         |   1    | Elementos em ordem aleatória.    |
| Ordenado          |   2    | Elementos em ordem crescente.    |
| Inversamente Ordenado | 3  | Elementos em ordem decrescente.  |
| Quase Ordenado    |   4    | Elementos em ordem quase crescente. |
| Bitonica          |   5    | Elementos em ordem parte crescente e depois segue decrescente. |

No final, é solicitado mais um número inteiro que indica se o vetor deve conter valores que se repetem sim (1) ou não (0). Com todos os parâmetros definidos, o vetor é gerado de acordo com as especificações fornecidas e, ao final da função, é retornado.

### + void imprimir_vetor(vector\<int> &vetor, int tamanho_vetor, bool se_resultado)
Função para imprimir o `vetor` recebido no terminal.
- `vetor`: Vetor de inteiros que deseja ser impresso no terminal.
- `tamanho_vetor`: Inteiro correspondente ao tamanho do vetor.
- `se_resultado`: Booleano que indica se o vetor é o equivalente ao gerado no início do programa ou se ele já foi ordenado por um algoritmo de ordenação.

### + void comparar_sorts(vector\<int> &vetor, int tamanho_vetor)
Função que aplica os seis algoritmos de ordenação sobre o `vetor` fornecido, registrando o número de comparações, trocas e chamadas recursivas realizadas, além da medição do tempo de execução, durante a ordenação. Enfim, exibindo todas essas métricas no terminal.
- `vetor`: Vetor de inteiros que deseja ser realizado as comparações.
- `tamanho_vetor`: Inteiro correspondente ao tamanho do vetor.

### + void trocar_de_posicao(vector\<int> &vetor, int id1, int id2)
Função que troca a posição dos elementos do `vetor` nos índices `id1` e `id2`.
- `vetor`: Vetor de inteiros que deseja ter elementos trocados.
- `id1`: Índice do primeiro número que deseja ser trocado de posição com o número em `id2`.
- `id2`: Índice do segundo número que deseja ser trocado de posição com o número em `id1`.

### + void selectionsort(vector\<int> &vetor, int tamanho_vetor)
Função que segue a implementação do algoritmo de ordenação Selection Sort, aplicando-o sobre o `vetor`. O Selection Sort é um algoritmo simples que percorre o vetor procurando o menor elemento e o coloca na primeira posição, depois repete o processo para as próximas posições.
- `vetor`: Vetor de inteiros que deseja ser ordenado em ordem crescente.
- `tamanho_vetor`: Inteiro correspondente ao tamanho do vetor.

### + void insertionsort(vector\<int> &vetor, int tamanho_vetor)
Função que segue a implementação do algoritmo de ordenação Insertion Sort, aplicando-o sobre o `vetor`. O Insertion Sort constrói o vetor ordenado gradualmente, inserindo cada elemento na posição correta em relação aos anteriores.
- `vetor`: Vetor de inteiros que deseja ser ordenado em ordem crescente.
- `tamanho_vetor`: Inteiro correspondente ao tamanho do vetor.

### + void bubblesort(vector\<int> &vetor, int tamanho_vetor)
Função que segue a implementação do algoritmo de ordenação Bubble Sort, aplicando-o sobre o `vetor`. O Bubble Sort compara elementos adjacentes e os troca se estiverem fora de ordem, "borbulhando" os maiores para o final do vetor a cada passagem.
- `vetor`: Vetor de inteiros que deseja ser ordenado em ordem crescente.
- `tamanho_vetor`: Inteiro correspondente ao tamanho do vetor.

### + int partition(vector\<int> &vetor, int esquerda, int direita)
Função responsável por realizar a partição do `vetor` dentro de `quicksort()`, reorganizando os elementos durante o processo. Ao final, retorna o índice do pivô que será utilizado para dividir o vetor em dois subconjuntos a serem ordenados separadamente em etapas posteriores.

- `vetor`: Vetor de inteiros que deseja ser ordenado em ordem crescente.
- `esquerda`: Índice do elemento mais à esquerda do intervalo que deseja ser ordenado. Começa sendo o item do primeiro elemento do `vetor` (0), mas conforme as partições vão ocorrendo, ele vai alterando de valor.
- `direita`: Índice do elemento mais à direita do intervalo que deseja ser ordenado. Começa sendo o item do último elemento do `vetor` (tamanho do vetor - 1), mas conforme as partições vão ocorrendo, ele vai alterando de valor.

### + void quicksort(vector\<int>& vetor, int esquerda, int direita)
Função que segue a implementação do algoritmo de ordenação Quick Sort, aplicando-o sobre o `vetor`. O Quick Sort é um algoritmo eficiente baseado na estratégia de dividir e conquistar. Escolhe um elemento pivô e particiona o vetor em dois subvetores menores, ordenando-os recursivamente.
- `vetor`: Vetor de inteiros que deseja ser ordenado em ordem crescente.
- `esquerda`: Índice do elemento mais à esquerda do intervalo que deseja ser ordenado. Começa sendo o item do primeiro elemento do `vetor` (0), mas conforme as partições vão ocorrendo, ele vai alterando de valor.
- `direita`: Índice do elemento mais à direita do intervalo que deseja ser ordenado. Começa sendo o item do último elemento do `vetor` (tamanho do vetor - 1), mas conforme as partições vão ocorrendo, ele vai alterando de valor.

### + void merge(vector\<int>& vetor, int esquerda, int meio, int direita)
Função que realiza a junção dos subconjuntos do `vetor` na função `mergesort()`, ordenando-os no processo.
- `vetor`: Vetor de inteiros que deseja ser ordenado em ordem crescente.
- `esquerda`: Índice do elemento mais à esquerda do intervalo que deseja ser ordenado. Começa sendo o item do primeiro elemento do `vetor` (0), mas conforme as partições vão ocorrendo, ele vai alterando de valor.
- `meio`: Índice do elemento que separa dois subconjuntos do `vetor` no meio, a fim de mesclá-los depois.
- `direita`: Índice do elemento mais à direita do intervalo que deseja ser ordenado. Começa sendo o item do último elemento do `vetor` (tamanho do vetor - 1), mas conforme as partições vão ocorrendo, ele vai alterando de valor.

### + void mergesort(vector\<int>& vetor, int esquerda, int direita)
Função que segue a implementação do algoritmo de ordenação Selection Sort, aplicando-o sobre o `vetor`. O Merge Sort, tal como o Quick Sort, utiliza a técnica de dividir e conquistar, dividindo o vetor em partes menores, ordenando-as e depois mesclando as partes ordenadas.
- `vetor`: Vetor de inteiros que deseja ser ordenado em ordem crescente.
- `esquerda`: Índice do elemento mais à esquerda do intervalo que deseja ser ordenado. Começa sendo o item do primeiro elemento do `vetor` (0), mas conforme as partições vão ocorrendo, ele vai alterando de valor.
- `direita`: Índice do elemento mais à direita do intervalo que deseja ser ordenado. Começa sendo o item do último elemento do `vetor` (tamanho do vetor - 1), mas conforme as partições vão ocorrendo, ele vai alterando de valor.

## Como Compilar e Executar <a name="3-como_compilar_e_executar"></a>

1. Compile o projeto com o `g++`, e com ajuda do Makefile:

```bash
make
```

2. Execute o programa:
```bash
./Implementacao_dos_Algoritmos_de_Ordenacao
```
