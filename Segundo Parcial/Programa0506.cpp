#include <iostream>
#include <stdio.h>
using namespace std;
int main (){
	int cuenta;
	char Nom[50];
    double saldo;
    FILE *ptrCF;
    if((ptrCF = fopen("Cliente.dat","w"))==NULL){
        cout << "El archivo no puede abrirse" << endl;
    }else{
        cout << "Introduzca cuenta, nombre, saldo" << endl; 
        cout << "Introduzca EOF al final" << endl; //ctrl Z
        cout << "?" << endl;
        cin >> cuenta;
        cin >> Nom;
        cin >> saldo;
        while(!feof(stdin)){
            fprintf(ptrCF,"%d %s %.2f\n",cuenta,Nom,saldo);
            cout << "?" << endl;
            cin >> cuenta;
            cin >> Nom;
            cin >> saldo;
        }
        fclose(ptrCF);
    }
    return 0;
}