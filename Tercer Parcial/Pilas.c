//Programa hecho por @Natalia Garcia
//24/07/24
#include <stdio.h>
#include <stdlib.h>

struct Pila {
   int dato;
   struct Pila *ptrSiguiente;
};

// Prototipos de funciones
int intOpcion(void);
void LlenarPila(struct Pila **p);
void MostrarPila(struct Pila *p);
void EliminarPila(struct Pila **p);

int main() {
   struct Pila *ptrPila = NULL;
   system("cls");
   int opc;
   do{
      switch(opc){
         case 1: //Agregar elementos
            LlenarPila(&ptrPila);
            break;
         case 2: //Mostrar pila
            MostrarPila(ptrPila);
            break;
         case 3: //Eliminar último elemento
            EliminarPila(&ptrPila);
            break;
         default:
            if (opc < 1 || opc > 4) {
                  printf("Opción incorrecta\n");
            }
            break;
      }
   }while((opc = intOpcion()) != 4);
   return 0;
}

void LlenarPila(struct Pila **p) {
   int dato;
   struct Pila *nuevoNodo = (struct Pila*) malloc(sizeof(struct Pila));
   if(nuevoNodo == NULL) {
      printf("No hay memoria disponible.\n");
      return;
   }
   printf("Ingrese el dato: ");
   scanf("%d",&dato);
   nuevoNodo->dato = dato;
   nuevoNodo->ptrSiguiente = *p;
   *p = nuevoNodo;
}

void MostrarPila(struct Pila *p) {
   if (p == NULL) {
      printf("La pila está vacía.\n");
   } else {
      struct Pila *actual = p;
      printf("Contenido de la pila:\n");
      while(actual != NULL){
         printf("%d\n", actual->dato);
         actual = actual->ptrSiguiente;
      }
   }
}

void EliminarPila(struct Pila **p){
   if (p == NULL) {
      printf("\nLa pila está vacía.\n");
   } else {
      struct Pila *ptrTemp = *p;
      *p = (*p)->ptrSiguiente;
      free(ptrTemp);
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
