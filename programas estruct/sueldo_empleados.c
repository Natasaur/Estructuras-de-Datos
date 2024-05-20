//Progama hecho por @Natalia García
/*
Desarrolle un programa que determine el pago bruto de cada empleado.
Esta empresa paga “horas completas” por las primeras 40 horas trabajadas por cada empleado
y paga “hora y media” por todas las horas extras trabajadas después de las 40.
Usted tiene una lista de los empleados de la empresa, el número de horas que trabajó cada
empleado la semana pasada y el pago por hora de cada empleado. 
Su programa deberá introducir esta información para cada empleado, y deberá determinar
y desplegar el pago bruto por empleado.
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int num_empleados, horas;
    float pagoxhora, pagobruto;
    system("cls");
    printf("Ingrese el número de empleados: ");
    scanf("%d",&num_empleados);
    int Horas[num_empleados];
    float PagosHora[num_empleados],PagosBruto[num_empleados];
    for(int i = 0 ; i < num_empleados ; i++){
        system("cls");
        printf("Ingrese el número de horas trabajadas del empleado %d: ",i + 1);
        scanf("%d",&horas);
        printf("Ingrese el pago por hora del empleado %d: ",i + 1);
        scanf("%f",&pagoxhora);
        Horas[i] = horas;
        PagosHora[i] = pagoxhora;
    }
    system("cls");
    for(int i = 0 ; i < num_empleados ; i++){
        if(Horas[i] <= 40){
            pagobruto = 0.87*Horas[i]*PagosHora[i];
            PagosBruto[i] = pagobruto;
        }else{
            pagobruto = 0.87*(40*PagosHora[i]+(Horas[i]-40)*PagosHora[i]*1.5);
            PagosBruto[i] = pagobruto;
        }
    }
    for(int i = 0 ; i < num_empleados ; i++){
        printf("El empleado %d trabajó %d y su sueldo será de: $%f.\n",i+1,Horas[i],PagosBruto[i]);
    }
    return 0;
}
