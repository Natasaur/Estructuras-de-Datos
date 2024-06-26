//30/05/24
#include <stdio.h>
#include <iostream>

using namespace std;
 
int cuboentero( int n );
 
int main() {
    int num = 5;
    cout<< "El valor origial el numero es: " << num <<endl;
    num = cuboentero( num );
    cout<< "El nuevo valor de numero es: " << num <<endl;
    return 0;
}

int cuboentero( int n ) {
    return n * n * n;
}