//Programa hecho por @Natalia García
//05/06/24
//Algoritmo de ordenamiento por burbuja

#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
    int aux,size;

    system("cls");
    cout << "Ingresa el tamaño del arreglo: ";
    cin >> size;

    int Arreglo[size];

    system("cls");
    cout << "Ingresa los valores del arreglo:\n";
    for(int i=0; i < size; i++){
        cin >> Arreglo[i];
    }

    system("cls");
    cout << "Arreglo Inicial:\n" << "[ ";
    for(int i=0; i<size;i++){
        cout << Arreglo[i] << " ";
    }
    cout << "]";

    for(int i=0;i<size;i++){
        for(int j=0;j<=size-(i+1);j++){
            if(Arreglo[j] > Arreglo[j+1]){
                aux = Arreglo[j];
                Arreglo[j] = Arreglo[j+1];
                Arreglo[j+1] = aux;
            }
        }
    }

    cout << "\nArreglo Final:\n" << "[ ";
    for(int i=0; i<size;i++){
        cout << Arreglo[i] << " ";
    }
    cout << "]";
    
    return 0;
}
