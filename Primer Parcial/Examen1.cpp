//Examen hecho por Natalia García Salas
/*
Una empresa de ventas de productos de belleza desea realizar un estadístico de las ventas realizadas a través de su portal web de cada uno de los productos en el último año. Distribuye un total de 100 productos, por lo que las ventas se piden almacenar en una matriz de 100 filas por 12 columnas, se desea conocer:

a) El total de ventas de cada uno de los productos.
b) El total de ventas de cada mes
c) El producto más vendido en cada mes
d) El nombre el mes y la cantidad del producto más vendido
e) Debe realizar el programa en C++; enviar código en C++ y salida de escritorio del programa en Word en formato PDF.

*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int aux = 5,sum = 0;
    int TotalProducto[aux]={0},TotalMes[12]={0},Productos[aux],Enero[aux],Febrero[aux],Marzo[aux],Abril[aux],Mayo[aux],Junio[aux],Julio[aux],Agosto[aux],Septiembre[aux],Octubre[aux],Noviembre[aux],Diciembre[aux];
    string Meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Ocutbre","Noviembre","Diciembre"};

    //Lectura de datos
    for(int i=0; i<12;i++){
        system("cls");
        cout << "Ventas de " << Meses[i] << "\n";
        for(int j=0; j<aux; j++){
            cout << "Ingrese la cantidad vendida del producto " << j+1 << ":\n";
            cin >> Productos[j];
        }
        switch(i) {
        case 0:
            for(int i=0; i<aux;i++){
                Enero[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 1:
            for(int i=0; i<aux;i++){
                Febrero[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 2:
            for(int i=0; i<aux;i++){
                Marzo[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 3:
            for(int i=0; i<aux;i++){
                Abril[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 4:
            for(int i=0; i<aux;i++){
                Mayo[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 5:
            for(int i=0; i<aux;i++){
                Junio[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 6:
            for(int i=0; i<aux;i++){
                Julio[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 7:
            for(int i=0; i<aux;i++){
                Agosto[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 8:
            for(int i=0; i<aux;i++){
                Septiembre[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 9:
            for(int i=0; i<aux;i++){
                Octubre[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 10:
            for(int i=0; i<aux;i++){
                Noviembre[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        case 11:
            for(int i=0; i<aux;i++){
                Diciembre[i] = Productos[i];
                Productos[i]= 0;
            }
            break;
        default:
            break;
        }
    }

    //Totales
    for(int i=0; i<aux; i++){
        TotalProducto[i] = Enero[i] + Febrero[i] + Marzo[i] + Abril[i] + Mayo[i] + Junio[i] + Julio[i] + Agosto[i] + Septiembre[i] + Octubre[i] + Noviembre[i] + Diciembre[i];
    }
    for(int i=0; i<12; i++){
        sum = sum + Enero[i];
    }
    TotalMes[0] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Febrero[i];
    }
    TotalMes[1] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Marzo[i];
    }
    TotalMes[2] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Abril[i];
    }
    TotalMes[3] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Mayo[i];
    }
    TotalMes[4] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Junio[i];
    }
    TotalMes[5] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Julio[i];
    }
    TotalMes[6] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Agosto[i];
    }
    TotalMes[7] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Septiembre[i];
    }
    TotalMes[8] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Octubre[i];
    }
    TotalMes[9] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Noviembre[i];
    }
    TotalMes[10] = sum;
    sum = 0;
    for(int i=0; i<12; i++){
        sum = sum + Diciembre[i];
    }
    TotalMes[11] = sum;
    sum = 0;

    //Salida de datos
    cout << left << setw(20) << " ";
    for(int i=0;i<12;i++){
        cout << left << setw(15) << Meses[i];
    }
    cout << " Total Producto\n";
    for(int i=0; i<aux; i++){
        cout << left << setw(15) << "Producto " << left << setw(5) << i+1 << left << setw(15) << Enero[i] << left << setw(15) << Febrero[i] << left << setw(15) << Marzo[i] << left << setw(15) << Abril[i] << left << setw(15) << Mayo[i] << left << setw(15) << Junio[i] << left << setw(15) << Julio[i] << left << setw(15) << Agosto[i] << left << setw(15) << Septiembre[i] << left << setw(15) << Octubre[i] << left << setw(15) << Noviembre[i] << left << setw(15) << Diciembre[i] << left << setw(15) << TotalProducto[i] << "\n";
    }
    cout << left << setw(20) << "Total Mes";
    for(int i=0;i<12;i++){
        cout << left << setw(15) << TotalMes[i];
    }
    cout << "\nProducto más vendido";


    

    return 0;
 }