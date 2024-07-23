//Progama hecho por @Natalia García
//Diseñar un programa para determinar si un numero ingresado es primo o no.

//Nota: Un número es considerado primo cuando es divisible solamente entre sí mismo y el 1.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    int num = 0;
    bool flag = 0;
    system("cls");
    printf("Ingrese un número: \n");
    scanf("%d",&num);
    for(int i = 2 ; i < num ; i++) {
        if(num % i == 0){
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("El número %d es primo \n",num);
    }else{
        printf("El número %d NO es primo \n",num);
    }
    return 0;
}
