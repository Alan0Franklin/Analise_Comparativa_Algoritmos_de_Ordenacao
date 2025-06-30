#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <limits>
#include <chrono>
#include "algoritmos_de_ordenacao.hpp"

using namespace std;
using namespace std::chrono;

long long comparacoes = 0;
long long trocas = 0;
long long recursoes = 0;

// Função para ler um número inteiro do terminal.
int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup){
    float hold;
    while (true){
        cin >> hold;
        /* 1) Se houve erro de conversão (ex.: letra, vazio, etc.);
        Isso pode acontecer quando o usuário digita letras, caracteres especiais, espaços em branco ou quando pressiona Enter sem digitar nada.
        */
        if (cin.fail()){
            cout << "> Entrada invalida!" << endl << mensagem_erro;
            cin.clear(); // reseta o estado de erro do stream de entrada.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta todos os caracteres restantes até encontrar uma quebra de linha. esse numeric_limits é para dizer que limpe o máximo possível (tudo).
            continue; // retorna ao início do loop para solicitar uma nova entrada válida.
        }

        /* 2) Se o número está fora da faixa exigida;
        Verifica se a quantidade informada está dentro do intervalo permitido.
        Se estiver fora desse intervalo, exibe uma mensagem de erro e solicita uma nova entrada através do continue, que retorna ao início do loop.
        */
        if (hold != (int) hold || (hold < lim_inf || (hold > lim_sup && lim_sup != -1))){
            cout << "> Numero invalido!" << endl << mensagem_erro;
            continue; // volta para o início do loop para solicitar uma nova entrada válida.
        }
        break;
    }
    return hold;
}

// Função para criar o vetor à ser analisado.
vector<int> criador_vetor(){
    cout << "> Digite o tamanho do vetor que deseja: ";
    int tamanho_vetor = ler_inteiro("> Digite o numero do tamanho que voce deseja que o vetor tenha: ", 0, -1);

    int tipo_vetor, repetido_vetor;
    if (tamanho_vetor >= 2){
        int lim_sup = 3;
        cout << "> Tabela de tipos de vetores:" << endl;
        cout << ".:==========================:.\n|[     Tipos de Vetores     ]|\n|+--------------------------+|\n|| 1. Aleatorio             ||\n|| 2. Ordenado              ||\n|| 3. Inversamente Ordenado ||" << endl;
        if (tamanho_vetor != 2){
            cout <<"|| 4. Quase Ordenado        ||\n|| 5. Bitonica              ||" << endl;
            lim_sup = 5;
        }
        cout <<"\':==========================:\'" << endl;
        cout << "> Digite o tipo de vetor que deseja (pelo seu numero na tabela): ";
        tipo_vetor = ler_inteiro("> Digite o numero na tabela do vetor que voce deseja testar: ", 1, lim_sup);

        cout << "> Digite se deseja que o vetor possa ter valores repetidos Sim (1) ou Nao (0): ";
        repetido_vetor = ler_inteiro("> Digite se o vetor pode ter valores repetidos Sim (1) ou Nao (0): ", 0, 1);
    }
    else{
        tipo_vetor = 2;
        repetido_vetor = 0;
    }

    vector<int> vetor(tamanho_vetor);   // vetor à ser criado.
    random_device rd;  // gerador de seed aleatória. Em alguns sistemas (especialmente Windows com algumas versões de compiladores), não é realmente aleatório.
    mt19937 gen(rd()); // gerador Mersenne Twister.
    uniform_int_distribution<> dist(1, tamanho_vetor); // intervalo fechado [1, tamanho_vetor].
    
    if (tipo_vetor == 1 || tipo_vetor == 5){
        if (repetido_vetor == 1){for (int i = 0; i < tamanho_vetor; i++){vetor[i] = dist(gen);}}
        else{
            for (int i = 0; i < tamanho_vetor; i++){vetor[i] = i + 1;}
            shuffle(vetor.begin(), vetor.end(), gen);
        }
    }
    else if (tipo_vetor == 2 || tipo_vetor == 4){
        if (repetido_vetor == 1){
            for (int i = 0; i < tamanho_vetor; i++){vetor[i] = dist(gen);}
            sort(vetor.begin(), vetor.end());
        }
        else{for (int i = 0; i < tamanho_vetor; i++){vetor[i] = i + 1;}}
    }
    else if (tipo_vetor == 3){
        if (repetido_vetor == 1){
            for (int i = 0; i < tamanho_vetor; i++){vetor[i] = dist(gen);}
            sort(vetor.begin(), vetor.end(), greater<int>());
        }
        else{for (int i = 0; i < tamanho_vetor; i++){vetor[i] = tamanho_vetor - i;}}
    }
    
    if (tipo_vetor == 4){
        uniform_int_distribution<int> dist1(1, tamanho_vetor - 2);
        int num_trocas = static_cast<int>(0.1 * tamanho_vetor) + 1;
        for (int i = 0; i < num_trocas; ++i){
            int id1 = dist1(gen), lim_inf = id1 - num_trocas, lim_sup = id1 + num_trocas;
            if (lim_inf < 0){lim_inf = 0;}
            if (lim_sup >= tamanho_vetor){lim_sup = tamanho_vetor - 1;}
            uniform_int_distribution<int> dist2(lim_inf, lim_sup);
            int id2 = dist2(gen);
            while (id2 == id1){id2 = dist2(gen);}
            trocar_de_posicao(vetor, id1, id2);
        }
        trocas = 0;
    }
    else if (tipo_vetor == 5){
        uniform_int_distribution<> dist1(2, tamanho_vetor - 1);
        int n = dist1(gen);
        sort(vetor.begin(), vetor.begin() + n);
        sort(vetor.begin() + n - 1, vetor.end(), greater<int>());
    }
    cout << "========================================================//========================================================" << endl;
    return vetor;
}

// Função para imprimir os elementos dos vetores no terminal.
void imprimir_vetor(vector<int> &vetor, int tamanho_vetor, bool se_resultado){
    cout << "> Vetor";
    if (se_resultado){cout << " Ordenado: ";}
    else{cout << " Gerado:   ";}
    cout << "{";
    for (int i = 0; i < tamanho_vetor; i++){
        if (i != 0){cout << ", ";}
        cout << vetor[i];
    }
    cout << '}' << endl;
}

// Função para comparar os algoritmos de ordenação em relação à um vetor dado.
void comparar_sorts(vector<int> &vetor, int tamanho_vetor){
    imprimir_vetor(vetor, tamanho_vetor, false);
    cout << endl;
    vector<int> v = vetor;
    trocas = 0;
    comparacoes = 0;

    cout << "<-----------------------------------------{Resultados de Selection Sort}----------------------------------------->" << endl;
    auto start = chrono::high_resolution_clock::now();
    selectionsort(v, tamanho_vetor);
    auto end = chrono::high_resolution_clock::now();
    cout << "> Qnt. de Comparacoes: " << comparacoes << endl;
    cout << "> Qnt. de Trocas: " << trocas << endl;
    cout << "> Tempo de Execucao: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    imprimir_vetor(v, tamanho_vetor, true);
    cout << endl;
    

    cout << "<-----------------------------------------{Resultados de Insertion Sort}----------------------------------------->" << endl;
    v = vetor;
    trocas = 0;
    comparacoes = 0;
    start = chrono::high_resolution_clock::now();
    insertionsort(v, tamanho_vetor);
    end = chrono::high_resolution_clock::now();
    cout << "> Qnt. de Comparacoes: " << comparacoes << endl;
    cout << "> Qnt. de Trocas: " << trocas << endl;
    cout << "> Tempo de Execucao: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    imprimir_vetor(v, tamanho_vetor, true);
    cout << endl;
    
    cout << "<-------------------------------------------{Resultados de Bubble Sort}------------------------------------------>" << endl;
    v = vetor;
    trocas = 0;
    comparacoes = 0;
    start = chrono::high_resolution_clock::now();
    bubblesort(v, tamanho_vetor);
    end = chrono::high_resolution_clock::now();
    cout << "> Qnt. de Comparacoes: " << comparacoes << endl;
    cout << "> Qnt. de Trocas: " << trocas << endl;
    cout << "> Tempo de Execucao: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    imprimir_vetor(v, tamanho_vetor, true);
    cout << endl;
    
    cout << "<-------------------------------------------{Resultados de Quick Sort}------------------------------------------->" << endl;
    v = vetor;
    trocas = 0;
    comparacoes = 0;
    recursoes = 0;
    start = chrono::high_resolution_clock::now();
    quicksort(v, 0, tamanho_vetor - 1);
    end = chrono::high_resolution_clock::now();
    cout << "> Qnt. de Comparacoes: " << comparacoes << endl;
    cout << "> Qnt. de Trocas: " << trocas << endl;
    cout << "> Qnt. de Recursoes: " << recursoes << endl;
    cout << "> Tempo de Execucao: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    imprimir_vetor(v, tamanho_vetor, true);
    cout << endl;

    cout << "<-------------------------------------------{Resultados de Merge Sort}------------------------------------------->" << endl;
    v = vetor;
    trocas = 0;
    comparacoes = 0;
    recursoes = 0;
    start = chrono::high_resolution_clock::now();
    mergesort(v, 0, tamanho_vetor - 1);
    end = chrono::high_resolution_clock::now();
    cout << "> Qnt. de Comparacoes: " << comparacoes << endl;
    cout << "> Qnt. de Trocas: " << trocas;
    cout << " [ALERTA: como o mergesort nao opera em trocas diretas como os outros algoritmos, esse valor e apenas uma aproximacao da ideia de \"troca\", mas e util e coerente para fins de comparacao.]" << endl;
    cout << "> Qnt. de Recursoes: " << recursoes << endl;
    cout << "> Tempo de Execucao: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    imprimir_vetor(v, tamanho_vetor, true);
    cout << endl;
    
    cout << "<-------------------------------------------{Resultados de std::sort()}------------------------------------------>" << endl;
    v = vetor;
    start = chrono::high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = chrono::high_resolution_clock::now();
    cout << "> Qnt. de Comparacoes: NAO OBTIVEL" << endl;
    cout << "> Qnt. de Trocas: NAO OBTIVEL" << endl;
    cout << "> Tempo de Execucao: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    imprimir_vetor(v, tamanho_vetor, true);
    cout << endl;
}

// Função para trocar a posição de dois elementos em um vetor.
void trocar_de_posicao(vector<int> &vetor, int id1, int id2){
    trocas++;
    int hold = vetor[id1];
    vetor[id1] = vetor[id2];
    vetor[id2] = hold;
}

// Algoritmo de ordenação Selection Sort.
void selectionsort(vector<int> &vetor, int tamanho_vetor){
    for (int id_valor_atual = 0, id_valor_menor; id_valor_atual < tamanho_vetor - 1; id_valor_atual++){
        id_valor_menor = id_valor_atual;
        for (int i = id_valor_atual + 1; i < tamanho_vetor; i++){
            if (vetor[id_valor_atual] > vetor[i] && vetor[id_valor_menor] > vetor[i]){id_valor_menor = i;}
            comparacoes++;
        }
        trocar_de_posicao(vetor, id_valor_menor, id_valor_atual);
    }
}

// Algoritmo de ordenação Insertion Sort.
void insertionsort(vector<int> &vetor, int tamanho_vetor){
    for (int id_valor_atual = 1; id_valor_atual < tamanho_vetor; id_valor_atual++){
        for (int i = id_valor_atual; i > 0; i--){
            if (vetor[i] < vetor[i - 1]){trocar_de_posicao(vetor, i - 1, i);}
            else{
                comparacoes++;
                break;
            }
            comparacoes++;
        }
    }
}

// Algoritmo de ordenação Bubble Sort.
void bubblesort(vector<int> &vetor, int tamanho_vetor){
    bool loop;
    for (int lim_sup = 0; tamanho_vetor - lim_sup > 1; lim_sup++){
        loop = false;
        for (int i = 0; i < tamanho_vetor - lim_sup - 1; i++){
            if (vetor[i] > vetor[i + 1]){
                trocar_de_posicao(vetor, i, i + 1);
                loop = true;
            }
            comparacoes++;
        }
        if (loop == false){break;}
    }
}

// Função para particionar o vetor no algoritmo do Quick Sort.
int partition(vector<int> &vetor, int esquerda, int direita){
    int pivo = vetor[direita];
    int i = esquerda - 1;
    for (int j = esquerda; j <= direita - 1; j++){
        if (vetor[j] <= pivo){
            i++;
            trocar_de_posicao(vetor, i, j);
        }
        comparacoes++;
    }
    trocar_de_posicao(vetor, i + 1, direita);
    return i + 1;
}

// Algoritmo de ordenação Quick Sort (ou Partition Sort).
void quicksort(vector<int>& vetor, int esquerda, int direita){
    if (esquerda < direita){
        int i_pivo = partition(vetor, esquerda, direita);
        recursoes += 2;
        quicksort(vetor, esquerda, i_pivo - 1);
        quicksort(vetor, i_pivo + 1, direita);
    }
}

// Função para fundir os conjuntos no algoritmo do Merge Sort.
void merge(vector<int>& vetor, int esquerda, int meio, int direita){
    int n1 = meio - esquerda + 1, n2 = direita - meio;
    vector<int> E(n1), D(n2);
    for (int i = 0; i < n1; i++){E[i] = vetor[esquerda + i];}
    for (int j = 0; j < n2; j++){D[j] = vetor[meio + 1 + j];}
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2){
        if (E[i] <= D[j]){
            if (vetor[k] != E[i]){trocas++;}
            vetor[k] = E[i];
            i++;
        } 
        else{
            if (vetor[k] != D[j]){trocas++;}
            vetor[k] = D[j];
            j++;
        }
        comparacoes++;
        k++;
    }
    while (i < n1){
        if (vetor[k] != E[i]){trocas++;}
        vetor[k] = E[i];
        i++;
        k++;
    }
    while (j < n2){
        if (vetor[k] != D[j]){trocas++;}
        vetor[k] = D[j];
        j++;
        k++;
    }
}

// Algoritmo de ordenação Merge Sort.
void mergesort(vector<int>& vetor, int esquerda, int direita){
    if (esquerda < direita){
        int meio = esquerda + (direita - esquerda) / 2;
        recursoes += 2;
        mergesort(vetor, esquerda, meio);
        mergesort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
}