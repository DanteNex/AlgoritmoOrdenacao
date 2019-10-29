#include <iostream>
#include <time.h>
#include <stdio.h>
#include <bits/stdc++.h> 
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function declaration
int bubblesort(int v[], int tamanho);
int insertionsort( int v[], int tamanho);
int selectionsort(int v[], int tamanho);

int main(int argc, char** argv)
{		struct timespec start, end; 


    int vetor10[10];
    int vetor100[100];
    int vetor1000[1000];
   	int iteracoesFeitas = 0;
  	int seguraInteiro = 0;
	 short loopArquivo = 0;
	 string linha;
	 ifstream arquivoLista ("vetor100.txt"); 	
   	if(arquivoLista.is_open()) {
   		while(!arquivoLista.eof()) {
   			getline(arquivoLista, linha);
   			stringstream geek(linha);
   			geek >> seguraInteiro;
   			vetor100[loopArquivo] = seguraInteiro;
   			loopArquivo++; 			
		   }
		   arquivoLista.close();
		   
		   	//Início do contador de tempo
	clock_gettime(CLOCK_MONOTONIC, &start); 
	ios_base::sync_with_stdio(false); 
	//Função para ser executada
	iteracoesFeitas = selectionsort(vetor100, 100);
	
	//Medir tempo de fim de execução
	clock_gettime(CLOCK_MONOTONIC, &end); 
	
	//Cálculo para conseguir o tempo de execução com precisÃ£o
    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  	
  	//Mostrar o tempo de execução
    cout << "Tempo de decorrido: " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << " Iteracoes feitas: " << iteracoesFeitas << endl; 
		   
	   } else {
	   	cout << "Não foi possível abrir o arquivo.";
	   }

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

int insertionsort( int v[], int tamanho)
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

int selectionsort(int v[], int tamanho)
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

