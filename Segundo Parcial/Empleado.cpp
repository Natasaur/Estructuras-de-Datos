//Programa hecho por @Natalia García
//Calcular los datos de un empleado apartir de una estructura
/*
El empleado Jose tiene 40 años
gana 150 x hora trabajo 45 horas
su salario semanal es:
Si con 40 hrs o menos se paga a 150 la hora
Si son más de 40, cada hora extra se paga al 1.5 del valor
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    struct Empleado {
        string nombre;
        string direccion;
        int telefono;
        int fecha[3];
        int pagoxhora = 150;
        int horasxsemana;
        int pagoxsemana;
    };
    Empleado Nempleado;
    cout << "Ingresa el nombre del empleado: \n";
    cin >> Nempleado.nombre;
    cout << "Ingresa la dirección\n";
    cin >> Nempleado.direccion;
    cout << "Ingrese el número de teléfono\n";
    cin >> Nempleado.telefono;
    cout << "Ingresa el DIA de nacimiento\n";
    cin >> Nempleado.fecha[0];
    cout << "Ingresa el MES de nacimiento\n";
    cin >> Nempleado.fecha[1];
    cout << "Ingresa el AÑO de nacimiento\n";
    cin >> Nempleado.fecha[2];
    cout << "Ingresa las horas trabajadas\n";
    cin >> Nempleado.horasxsemana;

    if(Nempleado.horasxsemana <= 40){
        Nempleado.pagoxsemana = Nempleado.pagoxhora * Nempleado.horasxsemana;
    }else{
        Nempleado.pagoxsemana = 40 * Nempleado.pagoxhora + (Nempleado.horasxsemana - 40) * Nempleado.pagoxhora * 1.5;
    }

    cout << "El empleado " << Nempleado.nombre << " tiene años.\n";
    cout << "Gana " << Nempleado.pagoxhora << " por hora y esta semana trabajó " << Nempleado.horasxsemana << " horas\n";
    cout << "Su salario por semana es: " << Nempleado.pagoxsemana


    return 0;
}