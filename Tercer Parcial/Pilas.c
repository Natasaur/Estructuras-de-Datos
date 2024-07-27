//Programa hecho por @Natalia Garcia
//24/07/24
#include <stdio.h>
#include <stdlib.h>

struct Pila {
   int dato[100];
   int cima;
};

// Prototipos de funciones
int intOpcion(void);
void LlenarPila(struct Pila *p);
void MostrarPila(struct Pila *p);
void EliminarPila(struct Pila *p);

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
         case 3: //Eliminar último elemento
            EliminarPila(&pila);
            break;
         default:
            if (eleccion < 1 || eleccion > 6) {
                  printf("Opción incorrecta\n");
               }
            break;
      }
   }while((eleccion = intOpcion()) != 4);
   return 0;
}

void LlenarPila(struct Pila *p) {
   int dato;
   if (p->cima < 100 - 1) {
      printf("Ingresa el dato:\n");
      scanf("%d",&dato);
      p->cima++;
      p->dato[p->cima] = dato;
      
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
         printf("%d\n", p->dato[i]);
      }
   }
}

void EliminarPila(struct Pila *p){
   if (p->cima == -1) {
      printf("\nLa pila está vacía.\n");
   } else {
      p->cima--;
      printf("\nÚltimo elemento eliminado.\n");
   }
}

int intOpcion(void) {
   int opcion;
   printf("\nSeleccione una opción:\n");
   printf("1. Nuevo nodo\n");
   printf("2. Mostrar pila\n");
   printf("3. Eliminar pila\n");
   printf("4. Salir\n");
   scanf("%d", &opcion);
   return opcion;
}
