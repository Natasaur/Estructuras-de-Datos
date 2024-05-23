//21/05/2024
//La suma de los valores
//El promedio de los valores
#include <stdio.h>
#include <stdlib.h>
int main(){
    int aux,suma=0;
    float prom;
    int Vector[10];
    for(int i=0;i<10;i++){
        printf("Ingresa el valor de la posición %d: \n",i+1);
        scanf("%d",&aux);
        Vector[i]=aux;
        suma=suma+aux;
    }
    printf("Valores: \n");
    for(int i=0;i<10;i++){
        printf("%d : %d\n",i+1,Vector[i]);
    }
    prom=suma/10;
    printf("La suma de los valores es: %d \n",suma);
    printf("El promedio de los valores es: %f \n",prom);
    
    return 0;
}