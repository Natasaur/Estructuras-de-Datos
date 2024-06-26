//Programa hecho por @Natalia García    
//21/05/2024
#include <stdio.h>
#include <stdlib.h>
int main(){
    int aux;
    int Vector[10];
    system("cls");
    for(int i=0;i<10;i++){
        printf("Ingresa el valor de la posición %d: ",i+1);
        scanf("%d",&aux);
        Vector[i]=aux;
    }
    printf("Los valores del vector son: \n");
    for(int i=0;i<10;i++){
        printf("%d\n",Vector[i]);
    }
    return 0;
}