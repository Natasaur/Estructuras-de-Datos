//Programa hecho por @Natalia García
//15/07/24

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct herramienta {
   int id;
   char nombre[50];
   int cantidad;
   float costo;
};

// Prototipos de funciones
int intOpcion(void);
void crearArchivo(void);
void nuevoRegistro(void);
void actualizaRegistro(void);
void eliminarRegistro(void);
void imprimirRegistro(void);

int main() {
   int eleccion;
   system("cls");
   do {
      switch (eleccion) {
         case 1:
            crearArchivo();
            break;
         case 2:
            actualizaRegistro();
            break;
         case 3:
            nuevoRegistro();
            break;
         case 4:
            eliminarRegistro();
            break;
         case 5:
            imprimirRegistro();
            break;
         default:
            if (eleccion < 1 || eleccion > 6) {
               printf("Opción incorrecta\n");
            }
            break;
      }
   } while ((eleccion = intOpcion()) != 6);
   return 0;
}

void crearArchivo(void) {
   FILE *ptrArchivo;
   struct herramienta vacia = {0, "",0 ,0.0};

   if ((ptrArchivo = fopen("herram.dat", "wb")) == NULL) {
      printf("No pudo abrirse el archivo herram.dat.\n");
      return;
   }

   for (int i = 0; i < 100; i++) {
      fwrite(&vacia, sizeof(struct herramienta), 1, ptrArchivo);
   }

   fclose(ptrArchivo);
   printf("Archivo inicializado con 100 registros vacíos.\n");
}

void nuevoRegistro(void) {
   FILE *ptrArchivo;
   struct herramienta nuevaHerramienta;

   if ((ptrArchivo = fopen("herram.dat", "rb+")) == NULL) {
      printf("No pudo abrirse el archivo herram.dat.\n");
      return;
   }

   printf("Ingrese ID: ");
   scanf("%d", &nuevaHerramienta.id);
   printf("Ingrese Nombre: ");
   scanf("%s", nuevaHerramienta.nombre);
   printf("Ingrese la cantidad: ");
   scanf("%d", &nuevaHerramienta.cantidad);
   printf("Ingrese el costo: ");
   scanf("%f", &nuevaHerramienta.costo);

   fseek(ptrArchivo, (nuevaHerramienta.id - 1) * sizeof(struct herramienta), SEEK_SET);
   fwrite(&nuevaHerramienta, sizeof(struct herramienta), 1, ptrArchivo);
   fclose(ptrArchivo);
}

void actualizaRegistro(void) {
   FILE *ptrArchivo;
   struct herramienta herramientaExistente;
   int id;

   if ((ptrArchivo = fopen("herram.dat", "rb+")) == NULL) {
      printf("No pudo abrirse el archivo herram.dat.\n");
      return;
   }

   printf("Ingrese el ID del registro a actualizar: ");
   scanf("%d", &id);

   fseek(ptrArchivo, (id - 1) * sizeof(struct herramienta), SEEK_SET);
   fread(&herramientaExistente, sizeof(struct herramienta), 1, ptrArchivo);

   if (herramientaExistente.id == 0) {
      printf("No hay información en el registro.\n");
   } else {
      printf("Ingrese la nueva Herramienta: ");
      scanf("%s", herramientaExistente.nombre);
      printf("Ingrese la nueva cantidad: ");
      scanf("%d", &herramientaExistente.cantidad);
      printf("Ingrese nueva edad: ");
      scanf("%f", &herramientaExistente.costo);
      fseek(ptrArchivo, (id - 1) * sizeof(struct herramienta), SEEK_SET);
      fwrite(&herramientaExistente, sizeof(struct herramienta), 1, ptrArchivo);
   }
   fclose(ptrArchivo);
}

void eliminarRegistro(void) {
   FILE *ptrArchivo;
   struct herramienta vacia = {0,"",0 ,0.0};
   int id;

   if ((ptrArchivo = fopen("herram.dat", "rb+")) == NULL) {
      printf("No pudo abrirse el archivo herram.dat.\n");
      return;
   }

   printf("Ingrese el ID del registro a eliminar: ");
   scanf("%d", &id);

   fseek(ptrArchivo, (id - 1) * sizeof(struct herramienta), SEEK_SET);
   fwrite(&vacia, sizeof(struct herramienta), 1, ptrArchivo);

   fclose(ptrArchivo);
}

void imprimirRegistro(void) {
   FILE *ptrArchivo;
   struct herramienta herramientaExistente;

   if ((ptrArchivo = fopen("herram.dat", "rb")) == NULL) {
      printf("No pudo abrirse el archivo herram.dat.\n");
      return;
   }

   printf("%-6s%-31s%-6s%-5s\n", "ID", "Nombre de la Herramienta", "Cantidad", "Costo");
   while (fread(&herramientaExistente, sizeof(struct herramienta), 1, ptrArchivo)) {
      if (herramientaExistente.id != 0) {
         printf("%-6d%-31s%-6d%-5f\n", herramientaExistente.id, herramientaExistente.nombre, herramientaExistente.cantidad, herramientaExistente.costo);
      }
   }

   fclose(ptrArchivo);
}

int intOpcion(void) {
   int opcion;
   printf("\nSeleccione una opción:\n");
   printf("1 - Crear archivo de texto con formato para impresión\n");
   printf("2 - Actualizar un registro\n");
   printf("3 - Crear un nuevo registro\n");
   printf("4 - Eliminar un registro\n");
   printf("5 - Mostrar registros\n");
   printf("6 - Salir\n");
   scanf("%d", &opcion);
   return opcion;
}
