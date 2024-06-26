//Programa hecho por @Natalia García
#include <iostream>
#include <string>
using namespace std;
int main() {
    struct Carta {
        string color;
        int num;
    };
    string color_[4] = {"amarillo","verde","azul","rojo"};
    Carta Ncarta;
    for(int i=0; i<4; i++){
        cout << "Color    Número\n";
        for(int j=0; j<10;j++){
            Ncarta = {.color=color_[i], .num=j};
            cout << Ncarta.color << "        " << Ncarta.num << endl;
        }
        cout << endl;
    }
    return 0;
}