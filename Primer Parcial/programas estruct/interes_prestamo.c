//Progama hecho por @Natalia García
/*
El interés simple para un préstamo se calcula mediante la fórmula:
interés = préstamo * tasa * días / 365;
La fórmula anterior asume que tasa es la tasa de interés anual, y por lo tanto incluye 
la división entre 365 (días). Desarrolle un programa que introduzca préstamo, tasa y días
para varios préstamos, y que calcule y despliegue el interés simple para cada préstamo,
utilizando la fórmula anterior.
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int prestamo,tasa,dias,cont;
    float interes;
    system("cls");
    printf("Ingrese el número de préstamos que desea calcular: ");
    scanf("%d",&cont);
    float Interes[cont];
    for(int i = 0 ; i < cont ; i++){
        system("cls");
        printf("Ingrese el monto del préstamo: ");
        scanf("%d",&prestamo);
        printf("Ingrese la tasa de interes anual: ");
        scanf("%f",&interes);
        printf("Ingrese los días: ");
        scanf("%d",&dias);
        interes = prestamo*tasa*dias;
        Interes[i] = interes;
    }
    for(int i = 0 ; i < cont ; i++){
        printf("El interes para el préstamo %d es : %f",i+1,Interes[i]);
    }
    return 0;
}