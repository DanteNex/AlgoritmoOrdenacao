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
void executarNovamente();

int main(int argc)
{		
	struct timespec start, end; 
    int *vetor;
   	int iteracoesFeitas = 0;
  	int seguraInteiro = 0;
	short loopArquivo = 0;
	string linha;
	int tamanhoVetor;
	int escolhavetor;
	int escolhaordenacao;
	cout << "Selecione o vetor para testes:\n";
	cout << "1 - Vetor com 10 registros\n";
	cout << "2 - Vetor com 100 registros\n";
	cout << "3 - Vetor com 1000 registros\n";
	cin >> escolhavetor;	
	if(escolhavetor == 1) {
		tamanhoVetor = 10;
	} else if(escolhavetor == 2) {
		tamanhoVetor = 100;
	} else if(escolhavetor == 3) {
		tamanhoVetor = 1000;
	} else {
		cout << "Vetor inexistente.";
		executarNovamente();
	}
	
	  vetor = new int[tamanhoVetor];
	
	cout << "Selecione o tipo de ordenacao:\n";
	cout << "1 - Bubblesort\n";
	cout << "2 - Selectionsort\n";
	cout << "3 - Insertionsort\n";
	cin >> escolhaordenacao;
	if(escolhaordenacao != 1 && escolhaordenacao != 2 && escolhaordenacao != 3) {
		cout << "Tipo inexistente.";
		executarNovamente();
	}
	
	
	ifstream arquivoLista ("vetor" + std::to_string(tamanhoVetor) + ".txt"); 	
   	if(arquivoLista.is_open()) {
   		while(!arquivoLista.eof()) {
   			getline(arquivoLista, linha);
   			stringstream geek(linha);
   			geek >> seguraInteiro;
   			
   			vetor[loopArquivo] = seguraInteiro;
   			loopArquivo++; 			
		   }
		   arquivoLista.close();
		   
	//Início do contador de tempo
	clock_gettime(CLOCK_MONOTONIC, &start); 
	ios_base::sync_with_stdio(false); 
	
	//Função para ser executada
	switch(escolhaordenacao) {	
		case 1:
		iteracoesFeitas = bubblesort(vetor, tamanhoVetor);	
			break;			
		case 2:
		iteracoesFeitas = selectionsort(vetor, tamanhoVetor);	
			break;			
		case 3:
		iteracoesFeitas = insertionsort(vetor, tamanhoVetor);	
			break;			
		default:
		cout << "Ordenacao inexistente.";
	}
	
	
	//Medir tempo de fim de execução
	clock_gettime(CLOCK_MONOTONIC, &end); 
	
	//Cálculo para conseguir o tempo de execução com precisao
    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  	time_t rawtime;
  	
  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;     
  
  //variável do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);  

string data_hora = std::to_string(data_hora_atual->tm_hour) + ":" + std::to_string(data_hora_atual->tm_min) + ":" + std::to_string(data_hora_atual->tm_sec) + " - " + std::to_string(data_hora_atual->tm_mday) + "/" + std::to_string(data_hora_atual->tm_mon+1) + "/" + std::to_string(data_hora_atual->tm_year+1900);

  	string filename = "Relatorio_Vetor_" + std::to_string(tamanhoVetor) + "_Ordenado.txt";
  	fstream txtstream;
  	txtstream.open(filename,  std::fstream::in | std::fstream::out | std::fstream::app | fstream::trunc);
  	if(!txtstream) {
  		txtstream.open(filename, fstream::in | fstream::out | fstream::trunc);
  		txtstream << "\n";
  		for(int i = 0;i < tamanhoVetor;i++) {
  			txtstream << vetor[i] << "\n";
		  }
		txtstream << "\n------------------------------------\n---- Relatório: "+ data_hora +" ----\n";
		txtstream << "Tempo de decorrido: " << fixed << time_taken << setprecision(9); 
		txtstream << " sec" << " Iteracoes feitas: " << iteracoesFeitas << endl;
		txtstream.close();
	  } else {
		for(int i = 0;i < tamanhoVetor;i++) {
  			txtstream << vetor[i] << "\n";
		}
		txtstream << "\n------------------------------------\n---- Relatório: "+ data_hora +" ----\n";
		txtstream << "Tempo de decorrido: " << fixed << time_taken << setprecision(9); 
		txtstream << " sec" << " Iteracoes feitas: " << iteracoesFeitas << endl;
		txtstream.close();
	  }
  	
  	
  	//Mostrar o tempo de execução
    cout << "Tempo de decorrido: " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << " Iteracoes feitas: " << iteracoesFeitas << endl; 
		   
	   } else {
	   	cout << "Nao foi possivel abrir o arquivo.";
	   	executarNovamente();
	   }
	executarNovamente();
    return 0;
}

void executarNovamente() {
	int executarnovamente;
	cout << "\nDeseja executar o programa novamente?\n";
	cout << "1 - Sim\n";
	cout << "2 - Nao\n";
	cin >> executarnovamente;
	if(executarnovamente == 1) {
		main(0);
	} else if(executarnovamente == 2) {
		exit(0);
	} else {
		cout << "Opcao inexistente.";
		executarNovamente();
	}
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

