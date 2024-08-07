//Programa hecho por @Natalia Garcia
//31/07/24
#include <stdio.h>
#include <stdlib.h>

struct Cola {
   int dato;
   struct Cola *ptrSiguiente;
};

// Prototipos de funciones
int intOpcion(void);
void Ingresar(struct Cola **frente, struct Cola **final);
void MostrarCola(struct Cola *frente);
void Eliminar(struct Cola **frente, struct Cola **final);

int main() {
   struct Cola *frente = NULL;
   struct Cola *final = NULL;
   int opc;
   do{
      switch(opc){
         case 1: //Agregar elementos
            Ingresar(&frente, &final);
            break;
         case 2: //Mostrar cola
            MostrarCola(frente);
            break;
         case 3: //Eliminar primer elemento
            Eliminar(&frente, &final);
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

void Ingresar(struct Cola **frente, struct Cola **final) {
   int dato;
   struct Cola *nuevoNodo = (struct Cola*) malloc(sizeof(struct Cola));
   if(nuevoNodo == NULL) {
      printf("No hay memoria disponible.\n");
      return;
   }
   printf("Ingrese el dato: ");
   scanf("%d",&dato);
   nuevoNodo->dato = dato;
   nuevoNodo->ptrSiguiente = NULL;
   
   if (*final == NULL) {
      *frente = nuevoNodo;
   } else {
      (*final)->ptrSiguiente = nuevoNodo;
   }
   *final = nuevoNodo;
}

void MostrarCola(struct Cola *frente) {
   if (frente == NULL) {
      printf("La cola está vacía.\n");
   } else {
      struct Cola *actual = frente;
      printf("Contenido de la cola:\n");
      while(actual != NULL){
         printf("%d\n", actual->dato);
         actual = actual->ptrSiguiente;
      }
   }
}

void Eliminar(struct Cola **frente, struct Cola **final){
   if (*frente == NULL) {
      printf("\nLa cola está vacía.\n");
   } else {
      struct Cola *ptrTemp = *frente;
      *frente = (*frente)->ptrSiguiente;
      
      if (*frente == NULL) {
         *final = NULL;
      }
      
      free(ptrTemp);
      printf("\nPrimer elemento eliminado.\n");
   }
}

int intOpcion(void) {
   int opcion;
   printf("\nSeleccione una opción:\n");
   printf("1. Ingresar dato\n");
   printf("2. Mostrar cola\n");
   printf("3. Eliminar dato\n");
   printf("4. Salir\n");
   scanf("%d", &opcion);
   return opcion;
}
