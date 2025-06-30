#include <iostream>
#include <algorithm>
#include <vector>
#include "algoritmos_de_ordenacao.hpp"

using namespace std;

int main(){
    vector<int> vetor = criador_vetor();
    int tamanho_vetor = vetor.size();

    comparar_sorts(vetor, tamanho_vetor);
    //selectionsort(vetor, tamanho_vetor);
    //insertionsort(vetor, tamanho_vetor);
    //bubblesort(vetor, tamanho_vetor);
    //quicksort(vetor, 0, tamanho_vetor - 1);
    //mergesort(vetor, 0, tamanho_vetor - 1);
    //sort(vetor.begin(), vetor.end());

    return 0;
}
