//Programa hecho por @Natalia García    
//28/05/2024
//Operadores 1
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a;
    int *ptra;
    a = 15;
    ptra = &a; //El amperson regresa la dirección de "a"
    printf("La dirección de a es %p el valor de otra es %p\n",&a,ptra);
    printf("El valor de a es %d el valor de *ptra es %d\n",a,*ptra);
    return 0;
}