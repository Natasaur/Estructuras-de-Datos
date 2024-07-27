//Programa hecho por @Natalia García
//25/07/24

#include <stdio.h>
#include <string.h>

struct nodoCalificacion {
   char apellido[20];
   double calificacion;
   struct nodoCalificacion *ptrSiguiente;
};

typedef struct nodoCalificacion NodoCalificacion;
typedef NodoCalificacion *ptrNodoCalificacion;

int main() {
   ptrNodoCalificacion ptrInicio = NULL;

   ptrNodoCalificacion ptrNuevo = (ptrNodoCalificacion)malloc(sizeof(NodoCalificacion));
   strcpy(ptrNuevo->apellido, "Perez");
   ptrNuevo->calificacion = 91.5;
   ptrInicio = ptrNuevo;

   ptrNodoCalificacion ptrAnterior = NULL, ptrActual = ptrInicio;
   while (ptrActual != NULL && strcmp(ptrActual->apellido, "Fernandez") < 0) {
      ptrAnterior = ptrActual;
      ptrActual = ptrActual->ptrSiguiente;
   }
   ptrNuevo = (ptrNodoCalificacion)malloc(sizeof(NodoCalificacion));
   strcpy(ptrNuevo->apellido, "Fernandez");
   ptrNuevo->calificacion = 85.0;
   ptrNuevo->ptrSiguiente = ptrActual;
   if (ptrAnterior == NULL) {
      ptrInicio = ptrNuevo;
   } else {
      ptrAnterior->ptrSiguiente = ptrNuevo;
   }

   ptrActual = ptrInicio;
   while (ptrActual != NULL) {
      printf("Apellido: %s, Calificación: %.1f\n", ptrActual->apellido, ptrActual->calificacion);
      ptrActual = ptrActual->ptrSiguiente;
   }

   ptrActual = ptrInicio;
   while (ptrActual != NULL) {
      ptrNodoCalificacion ptrTemp = ptrActual;
      ptrActual = ptrActual->ptrSiguiente;
      free(ptrTemp);
   }
   ptrInicio = NULL;

   return 0;
}