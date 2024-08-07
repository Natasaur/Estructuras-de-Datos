//Programa hecho por @Natalia Garcia
//07/08/24

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
struct nodoArbol {
   int dato;
   struct nodoArbol *ptrIzq;
   struct nodoArbol *ptrDer;
};

int main(){
   int opc, d;
   system("cls");
   typedef struct nodoArbol;
   typedef nodoArbol *ptrNodoArbol;
   ptrArbol = ptrNodoArbol;
   do{
      switch (opc){
      case 1: //Crear nodo
         system("cls");
         printf("Ingrese el dato: ");
         scanf("%d",d);
         crearNodo(&ptrArbol, d);
         break;
      case 2: //In orden
         break;
      case 3: //Pre orden
         break;
      case 4: //Post orden
         break;
      case 5: //Eliminar
         break;

      default:
         if (opc < 1 || opc > 6) {
            printf("Opción incorrecta\n");
         }
         break;
      }
   }while((opc = intOpcion()) != 6);

   /*
   struct Nodo *raiz = crearNodo(10);
   raiz->ptrIzquierda = crearNodo(5);
   raiz->ptrDerecha = crearNodo(15);
   raiz->ptrIzquierda->ptrIzquierda = crearNodo(3);
   raiz->ptrIzquierda->ptrDerecha = crearNodo(7);
   */

   return 0;
}

void crearNodo(ptrNodoArbol *ptrArbol,int d){
   if(*ptrArbol == NULL){
      *ptrArbol = malloc(sizeof(struct nodoArbol));
   }
   
   if (*ptrArbol != NULL){
      (*ptrArbol)->dato = d;
      (*ptrArbol)->ptrIzquierda = NULL;
      (*ptrArbol)->ptrDerecha = NULL;
   }else if(){
      printf("No hay espacio de memoria.\n");
   }

   if(d < (*ptrArbol)->dato){

   }
}

void insertarNodo(){

}

void inOrden(ptrNodoArbol ptrArbol){
   if (ptrArbol != NULL) {
      inOrden(ptrArbol->ptrIzq);
      printf("%d ", ptrArbol->dato);
      inOrden(ptrArbol->ptrDer);
   }
}

int intOpcion(void)
{
   int opcion;
   printf("\nSeleccione una opción:\n");
   printf("1. Nuevo nodo\n");
   printf("2. Mostar In Orden\n");
   //printf("3. Mostar Pre Orden\n");
   //printf("4. Mostar Post Orden\n");
   //printf("5. Eliminar pila\n");
   printf("6. Salir\n");
   scanf("%d", &opcion);
   return opcion;
}