#include<stdio.h>
#include<iostream>
using namespace std;
int main (){
    int a;
    int *ptra;
    a=15;
    //ptra = a;//no se puede hacer
    ptra = &a;//si se puede hacer
    cout<<"La direccionde a es; " << &a << "la direccion de ptra es; " << ptra <<endl;
    cout<<"el valor de a es; " <<  a << "El valor de *ptra es; " << *ptra <<endl;
    return 0;
}