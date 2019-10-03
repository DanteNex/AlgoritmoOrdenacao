#include <iostream>
#include <chrono> 
using namespace std::chrono; 
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function declaration
int bubblesort(int v[], int tamanho);

int main(int argc, char** argv) {
	int viktor[7] = {100, 30, 51, 1, 0, 5, 23};
	cout<< "Hello World";
	cout<< bubblesort(viktor, 7);
	return 0;
}

int bubblesort(int v[], int tamanho){
	int i, j, aux, moves = 0;
	for ( i = 0; i < (tamanho - 1); i++){
		for(j = 1; j < tamanho; j++) {
			if (v[j] < v[j-1]) {
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
				moves++;
			}
		}
	}
	return moves;
}
