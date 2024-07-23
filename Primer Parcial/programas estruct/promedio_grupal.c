//Progama hecho por @Natalia García
//Diseñar un programa para calcular el promedio de calificaciones de un grupo.

#include <stdio.h>
#include <stdlib.h>
int main() {
    int alumNum = 0,suma = 0, calif = 0;
    float prom;
    system("cls");
    printf("Ingrese la cantidad de alumnos en el grupo: \n");
    scanf("%d",&alumNum);
    for(int i = 0 ; i < alumNum ; i++){
        system("cls");
        printf("Ingrese la calificación del alumno %d: \n", i + 1);
        scanf("%d",&calif);
        suma = suma + calif;
    }
    prom = suma/alumNum;
    system("cls");
    printf("El promedio de calificaciones del grupo de %d estudiantes es de: %f \n",alumNum,prom);
    return 0;
}
