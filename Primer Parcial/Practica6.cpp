//Programa hecho por @Natalia García
//29/05/2024
//Nombre edad fecha de nacimiento email telefono
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main (){
    int aux = 1;
    string Nombre[aux], Fecha[aux], Email[aux],Tel[aux];
    int Edad[aux];
    
    int* edad;
    string* nombre;
    string* fecha;
    string* email;
    string* tel;

    for(int i=0; i<aux; i++){
        system("cls");
        cout << "Ingrese su nombre completo:" << endl;
        getline(cin,Nombre[i]);
        cout << "Ingrese su edad:" << endl;
        cin >> Edad[i];
        cout << "Ingrese su fecha de nacimiento: (Use el siguiente formato: 09/07/2000)" << endl;
        cin.ignore();
        getline(cin,Fecha[i]);
        cout << "Ingrese su dirección de correo electrónico:" << endl;
        cin >> Email[i];
        cout << "Ingrese su número de Teléfono:" << endl;
        cin >> Tel[i];
    }

    cout << left << setw(40) << "Nombre" << left << setw(10) << "Edad" << left << setw(25) << "Fecha de nacimiento" << left << setw(30) << "Correo electrónico" << left << setw(20) << "Número" << endl;
    for(int i=0; i<aux; i++){
        edad = &Edad[i];
        nombre = &Nombre[i];
        fecha = &Fecha[i];
        email = &Email[i];
        tel = &Tel[i];
        cout << left << setw(30) << *nombre << left << setw(10) << *edad << left << setw(21) << *fecha << left << setw(30) << *email << left << setw(20) << *tel << endl;    
    }
    
    return 0;
}