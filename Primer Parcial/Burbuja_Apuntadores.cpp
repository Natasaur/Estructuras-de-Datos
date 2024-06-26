//Programa hecho por @Natalia García
//05/06/24
//Algoritmo de ordenamiento por burbuja

#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
    int aux;
    int size;
    //int *ptrA = NULL;

    system("cls");
    cout << "Ingresa el tamaño del arreglo: ";
    cin >> size;

    int *Arreglo = new int[size];

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

    //ptrA = &Arreglo[0];
    //cout << "\n" << *ptrA << "\n" << *(ptrA+1) << "\n" << ptrA << "\n" << ptrA+1;
    
    for(int i=0;i<size;i++){
        for(int j=0;j<=size-(i+1);j++){
            if(Arreglo[j] > Arreglo[j+1]){
                aux = Arreglo[j];
                Arreglo[j] = Arreglo[j+1];
                Arreglo[j+1] = aux;
            }
        }
    }

    /*
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(*(ptrA+j) > *(ptrA+j+1)){
                aux = (ptrA+j);
                *(ptrA+j) = *(ptrA+j+1);
                *(ptrA+j+1) = *aux;
            }
        }
    }
    */
    

    cout << "\nArreglo Final:\n" << "[ ";
    for(int i=0; i<size;i++){
        cout << Arreglo[i] << " ";
    }
    cout << "]";
    
    return 0;
}
