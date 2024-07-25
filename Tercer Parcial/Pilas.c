//Programa hecho por @Natalia Garcia
//24/07/24
#include <stdio.h>
#include <stdlib.h>

struct Pila {
   int dato;
   int cima;
};

// Prototipos de funciones
int intOpcion(void);
void LlenarPila(struct Pila *p);
void MostrarPila(struct Pila *p);

int main() {
   struct Pila pila;
   int eleccion;
   pila.cima = -1;
   system("cls");
   do{
      switch(eleccion){
         case 1: //Agregar elementos
            LlenarPila(&pila);
            break;
         case 2: //Mostrar pila
            MostrarPila(&pila);
            break;
         //case 3:
            
            //break;
         
         default:
            if (eleccion < 1 || eleccion > 6) {
                  printf("Opción incorrecta\n");
               }
            break;
      }
   }while((eleccion = intOpcion()) != 3);
   return 0;
}

void LlenarPila(struct Pila *p) {
   int dato;
   printf("Ingresa el dato:\n");
   scanf("%d",&dato);
   if (p->cima < 100 - 1) {
      p->dato = dato;
      p->cima++;
   } else {
      printf("La pila está llena.\n");
   }
}

void MostrarPila(struct Pila *p) {
   if (p->cima == -1) {
      printf("La pila está vacía.\n");
   } else {
      printf("Contenido de la pila:\n");
      for (int i = p->cima; i >= 0; i--) {
         printf("%d\n", p->dato);
      }
   }
}

int intOpcion(void) {
   int opcion;
   printf("\nSeleccione una opción:\n");
   printf("1. Nuevo nodo\n");
   printf("2. Mostrar pila\n");
   printf("3. Salir\n");
   scanf("%d", &opcion);
   return opcion;
}
