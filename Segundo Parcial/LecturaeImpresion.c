//Lectura e impresión de un rachivo secuencial
//#include <iostream>
#include <stdio.h>
//using namespace std;

int main () {
   int cuenta;
   char Nombre[30];
   double saldo;
   FILE *ptrCF;
   if((ptrCF=fopen("cuentas.dat","r"))==NULL){
      printf("El archivo no puede abrirse\n");
   } else {
      printf("Cuenta, Nombre, Saldo\n");
      fscanf(ptrCF,"%d %s %.2f",&cuenta,Nombre,&saldo);
      while(!feof(ptrCF)){
         printf("Cuenta, Nombre, Saldo\n");
         fscanf(ptrCF,"%d %s %.2f",&cuenta,Nombre,&saldo);
      }
      fclose(ptrCF);
   }
   return 0;
}