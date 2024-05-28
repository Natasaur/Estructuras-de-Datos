//Programa hecho por @Natalia García
//24/05/2024
//Calificaciones ingresadas por el usuario
//Gráfica de asteriscos de acuerdo al promedio
//Arreglo de nombres de alumnos (20 Elementos)
//Arreglo para cada materia
//Arreglo de promedio
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main (){
    int aux = 5;
    string Alumnos[aux];
    int ED[aux], Inn[aux], MetA[aux], Ingl[aux],Frecuencia[10]={0},frec=0;
    float Prom[aux], prom;

    for(int i=0; i<aux; i++){
        system("cls");
        cout << "Ingrese el nombre del alumno " << i+1 << ": ";
        cin >> Alumnos[i];
        cout << "Ingrese su calificación para Estructura de Datos: ";
        cin >> ED[i];
        cout << "Ingrese su calificación para Innovación: ";
        cin >> Inn[i];
        cout << "Ingrese su calificación para Metodologías Ágiles: ";
        cin >> MetA[i];
        cout << "Ingrese su calificación para Inglés: ";
        cin >> Ingl[i];
        prom=(ED[i]+Inn[i]+MetA[i]+Ingl[i])/4;
        Prom[i]=prom;
    }

    system("cls");
    cout << left << setw(30) << "Nombre del Alumno" << left << setw(21) << "Estructura de Datos" << left << setw(12) << "Innovacion" << left << setw(21) << "Metodologias Agiles" << left << setw(8) << "Ingles" << left << setw(9) << "Promedio\n";
    for(int i=0; i<aux; i++){
        cout << left << setw(40) << Alumnos[i] << left << setw(16) << ED[i] << left << setw(18) << Inn[i] << left << setw(12) << MetA[i] << left << setw(9) << Ingl[i] << left << setw(6) << Prom[i];
        for(int j=0; j<Prom[i];j++){
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 0; i < aux; i++) { // Calcular frecuencias
        int range = static_cast<int>(Prom[i]);  // Convertir float a int
        if (range >= 1 && range <= 10) { // Asegurar rango válido
            Frecuencia[range - 1]++;
        }
    }

    
    cout << "\n" << left << setw(21) << "Rango" << "Frecuencia\n";
    for(int i=0; i<10; i++){
        if(i != 9){
            cout << "Calificación " << i+1 << "        ";
        }else{
            cout << "Calificación " << i+1 << "       ";
        }
        if(Frecuencia[i] != 0){
            for(int j=0; j<Frecuencia[i]; j++){
                cout << "*";
            }
        }
        cout << "\n";
    }
    
    return 0;
}