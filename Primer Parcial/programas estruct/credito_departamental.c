//Progama hecho por @Natalia García
/*
Desarrolle un programa en C que determine si un cliente de una tienda departamental excede
el límite de crédito de su cuenta. Para cada cliente, se dispone de los siguientes datos:
1. Número de cuenta.
2. Saldo al inicio del mes.
3. Total de elementos cargados al cliente en este mes.
4. El total de los créditos aplicados a la cuenta del cliente durante el mes.
5. El límite de crédito autorizado.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int cuenta;
    float saldo_inicio,elementos,credito_aplicado,limite;
    system("cls");
    printf("Ingrese su número de cuenta: ");
    scanf("%d",&cuenta);
    printf("Ingrese el saldo al inicio del mes: ");
    scanf("%f",&saldo_inicio);
    printf("Ingrese el total de elementos cargados durante el mes: ");
    scanf("%f",&elementos);
    printf("Ingrese el total de créditos aplicados a la cuenta durante el mes: ");
    scanf("%f",&credito_aplicado);
    printf("Ingrese el límite de crédito: ");
    scanf("%f",&limite);
    system("cls");
    if((saldo_inicio + credito_aplicado) > limite){
        printf("El cliente con número de cuenta %d ha excedido su límite de crédito\n");
    }else{
        printf("El cliente con número de cuenta %d está al corriente con su crédito\n");
    }
    return 0;
}
