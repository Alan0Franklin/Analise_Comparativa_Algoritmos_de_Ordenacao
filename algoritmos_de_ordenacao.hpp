#ifndef ALGORITMOSDEORDENACAO
#define ALGORITMOSDEORDENACAO_HPP

#include <string>
#include <vector>

using namespace std;

// Função para ler um número inteiro do terminal.
int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup);

// Função para criar o vetor à ser analisado.
vector<int> criador_vetor();

// Função para imprimir os elementos dos vetores no terminal.
void imprimir_vetor(vector<int> &vetor, int tamanho_vetor, bool se_resultado);

// Função para comparar os algoritmos de ordenação em relação à um vetor dado.
void comparar_sorts(vector<int> &vetor, int tamanho_vetor);

// Função para trocar a posição de dois elementos em um vetor.
void trocar_de_posicao(vector<int> &vetor, int id1, int id2);

// Algoritmo de ordenação Selection Sort.
void selectionsort(vector<int> &vetor, int tamanho_vetor);

// Algoritmo de ordenação Insertion Sort.
void insertionsort(vector<int> &vetor, int tamanho_vetor);

// Algoritmo de ordenação Bubble Sort.
void bubblesort(vector<int> &vetor, int tamanho_vetor);

// Função para particionar o vetor no algoritmo do Quick Sort.
int partition(vector<int> &vetor, int esquerda, int direita);

// Algoritmo de ordenação Quick Sort (ou Partition Sort).
void quicksort(vector<int>& vetor, int esquerda, int direita);

// Função para fundir os conjuntos no algoritmo do Merge Sort.
void merge(vector<int>& vetor, int esquerda, int meio, int direita);

// Algoritmo de ordenação Merge Sort.
void mergesort(vector<int>& vetor, int esquerda, int direita);

#endif