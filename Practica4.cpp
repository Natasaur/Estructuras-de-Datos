//22/05/2024
//Arreglo de nombres de alumnos (5 Elementos)
//Arreglo para cada materia
//Arreglo de promedio
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;

int main (){
    string Alumnos[5] = {"Garcia Salas Natalia","Hernandez Hernandez Lucia","Ladrillero Hipolito Eduardo","Hernandez Camero Atlai","Aburto Tellez Diana Paola"};
    int ED[5] = {10,8,6,5,9};
    int Inn[5] = {9,7,8,6,10};
    int MetA[5] = {8,9,8,10,10};
    int Ingl[5] = {10,10,10,10,10};
    float Prom[5];
    float prom;
    for(int i=0;i<5;i++){
        prom=(ED[i]+Inn[i]+MetA[i]+Ingl[i])/4;
        Prom[i]=prom;
    }
    cout << left << setw(30) << "Nombre del Alumno" << left << setw(21) << "Estructura de Datos" << left << setw(12) << "Innovacion" << left << setw(21) << "Metodologias Agiles" << left << setw(8) << "Ingles" << left << setw(9) << "Promedio\n";
    for(int i=0;i<5;i++){
        cout << left << setw(40) << Alumnos[i] << left << setw(16) << ED[i] << left << setw(18) << Inn[i] << left << setw(12) << MetA[i] << left << setw(9) << Ingl[i] << left << setw(6) << Prom[i] << "***************\n";
    }
    return 0;
}