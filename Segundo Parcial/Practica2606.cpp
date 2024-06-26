#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*Un programa con un archivo cochiloco donde se colocan los registros de empleados
num empleado
nombre
dirección
teléfono
fecha de nacimiento
departamento
puesto
salario
*/
using namespace std;
int main (){
	int num_empleado,tel,aux = 50;
	char Nombre[aux],dir[aux],F_nac[aux],dep[aux],puesto[aux];
    double salario;
    FILE *ptrCF;
    system("cls");
    if((ptrCF = fopen("Cochiloco.dat","w"))==NULL){
        cout << "El archivo no puede abrirse" << endl;
    }else{
        cout << "Introduzca Número de empleado, Nombre, Puesto, Departamento, Salario," << endl; 
        cout << "Introduzca EOF al final" << endl; //ctrl Z
        cout << "?" << endl;
        cin >> num_empleado;
        cin.ignore();
        cin.getline(Nombre,aux,'\n');
        cin.getline(puesto,aux,'\n');
        cin.getline(dep,aux,'\n');
        cin >> salario;
        while(!feof(stdin)){
            fprintf(ptrCF,"%d %s %s %s %.2f\n",num_empleado,Nombre,puesto,dep,salario);
            cout << "?" << endl;
            cin >> num_empleado;
            cin.ignore();
            cin.getline(Nombre,aux,'\n');
            cin.getline(puesto,aux,'\n');
            cin.getline(dep,aux,'\n');
            cin >> salario;
        }
        fclose(ptrCF);
    }
    return 0;
}