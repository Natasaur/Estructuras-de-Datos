//Lectura e impresión de un rachivo secuencial
#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
   int cuenta;
   char Nombre[30];
   double saldo;
   FILE *ptrCF;
   if((ptrCF=fopen("Clientes.dat","r"))==NULL){
      cout << "El archivo no puede abrirse" << endl;
   } else {
      cout << "Cuenta, Nombre, Saldo" << endl;
      fscanf(ptrCF,"%d %s %2d",&cuenta,Nombre,&saldo);
      while(!feof(ptrCF)){
         cout << "Cuenta, Nombre, Saldo" << endl;
         fscanf(ptrCF,"%d %s %2d",&cuenta,Nombre,&saldo);
      }
      fclose(ptrCF);
   }
   return 0;
}