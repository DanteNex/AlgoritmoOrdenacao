#include <iostream>
#include <time.h>
#include <stdio.h>
#include <bits/stdc++.h> 

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function declaration
int bubblesort(int v[], int tamanho);

int main(int argc, char** argv)
{		struct timespec start, end; 


    int vetor10[10] = { 100, 30, 51, 1, 0, 5, 23, 12, 6, 8 };
    int vetor100[100] = {  30,29,31,16,24,29,28,117,42,23,40,15,18,51,15,19,30,25,17,55,20,12,39,25,56,61,77,34,14,8,31,34,22,12,52,50,24,20,91,33,27,25,83,12,21,38,20,24,37,18,56,20,47,51,22,46,24,35,28,12,28,43,50,37,127,11,12,22,25,57,53,38,33,16,35,29,23,21,11,31,12,37,40,29,14,15,38,74,19,121,52,25,14,12,31,25,16,19,54,24};
   	int iteracoesFeitas = 0;
   	
	//Início do contador de tempo
	clock_gettime(CLOCK_MONOTONIC, &start); 
	ios_base::sync_with_stdio(false); 
	//Função para ser executada
	iteracoesFeitas = bubblesort(vetor10, 10);
	
	//Medir tempo de fim de execução
	clock_gettime(CLOCK_MONOTONIC, &end); 
	
	//Cálculo para conseguir o tempo de execução com precisão
    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  	
  	//Mostrar o tempo de execução
    cout << "Tempo de decorrido: " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << " Iteracoes feitas: " << iteracoesFeitas << endl; 
    return 0;
}



int bubblesort(int v[], int tamanho)
{
    int i, j, aux, moves = 0;
    for (i = 0; i < (tamanho - 1); i++) {
        for (j = 1; j < tamanho; j++) {
            if (v[j] < v[j - 1]) {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
                moves++;
            }
        }
    }
    return moves;
}

int insertionsort(int tamanho, int v[])
{
    int i, j, x, moves = 0;
    for (j = 1; j < tamanho; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; --i)
            v[i + 1] = v[i];
            moves++;
        v[i + 1] = x;
    }
    return moves;
}

int selectionsort(int tamanho, int v[])
{
    int i, j, min, x, moves = 0;
    for (i = 0; i < tamanho - 1; ++i) {
        min = i;
        for (j = i + 1; j < tamanho; ++j)
            if (v[j] < v[min]){
            	min = j;
            	moves++;
			} else {
				moves++;
			}
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
    return moves;
}

