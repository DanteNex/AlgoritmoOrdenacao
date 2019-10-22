#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function declaration
int bubblesort(int v[], int tamanho);

int main(int argc, char** argv)
{
    int vetor[7] = { 100, 30, 51, 1, 0, 5, 23 };
    cout << "Hello World";
    cout << bubblesort(vetor, 7);
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

void insertionsort(int tamanho, int v[])
{
    int i, j, x;
    for (j = 1; j < tamanho; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; --i)
            v[i + 1] = v[i];
        v[i + 1] = x;
    }
}

void selectionsort(int tamanho, int v[])
{
    int i, j, min, x;
    for (i = 0; i < tamanho - 1; ++i) {
        min = i;
        for (j = i + 1; j < tamanho; ++j)
            if (v[j] < v[min])
                min = j;
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

