//Programa hecho por @Natalia Garcia
//18/07/24
/*
Usted es el dueño de una Farmacia y necesita mantener un inventario que le pueda decir cuáles medicamentos tiene,
cuántos tiene y el costo de cada uno.
Escriba un programa que inicialice el archivo “Medicat.dat” con 100 registros vacíos, 
que le permita introducir los datos relacionados con cada medicamento, que le permita listar todos los medicamentos,
que le permita eliminar un registro de uno de ellos que ya no tiene, y que le permita actualizar 
cualquier información en el archivo. El número de identificación de cada medicamento debe ser su número de registro
comenzando con el 00 y terminando con el 99.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicamento {
   int id;
   char nombre[30];
   int cantidad;
   float costo;
};

int intOpcion(void);
void crearArchivo(void);
void nuevoRegistro(void);
void actualizaRegistro(void);
void eliminarRegistro(void);
void mostrarRegistro(void);

int main() {
   int eleccion;
   system("cls");
   do {
      switch (eleccion) {
         case 1:
            system("cls");
            crearArchivo();
            break;
         case 2:
            system("cls");
            actualizaRegistro();
            break;
         case 3:
            system("cls");
            nuevoRegistro();
            break;
         case 4:
            system("cls");
            eliminarRegistro();
            break;
         case 5:
            system("cls");
            mostrarRegistro();
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
   struct medicamento vacio = {0, "", 0, 0.0};

   if ((ptrArchivo = fopen("Medicat.dat", "wb")) == NULL) {
      printf("No pudo abrirse el archivo Medicat.dat.\n");
      return;
   }

   for (int i = 0; i < 100; i++) {
      fwrite(&vacio, sizeof(struct medicamento), 1, ptrArchivo);
   }

   fclose(ptrArchivo);
   printf("Archivo inicializado con 100 registros vacíos.\n");
}

void nuevoRegistro(void) {
   FILE *ptrArchivo;
   struct medicamento nuevoMedicamento;

   if ((ptrArchivo = fopen("Medicat.dat", "rb+")) == NULL) {
      printf("No pudo abrirse el archivo Medicat.dat.\n");
      return;
   }

   printf("Ingrese ID (0-99): ");
   scanf("%d", &nuevoMedicamento.id);
   printf("Ingrese el nombre del medicamento: ");
   scanf("%s", nuevoMedicamento.nombre);
   printf("Ingrese la cantidad: ");
   scanf("%d", &nuevoMedicamento.cantidad);
   printf("Ingrese el costo: ");
   scanf("%f", &nuevoMedicamento.costo);

   fseek(ptrArchivo, nuevoMedicamento.id * sizeof(struct medicamento), SEEK_SET);
   fwrite(&nuevoMedicamento, sizeof(struct medicamento), 1, ptrArchivo);

   fclose(ptrArchivo);
}

void actualizaRegistro(void) {
   FILE *ptrArchivo;
   struct medicamento medicamentoExistente;
   int id;

   if ((ptrArchivo = fopen("Medicat.dat", "rb+")) == NULL) {
      printf("No pudo abrirse el archivo Medicat.dat.\n");
      return;
   }

   printf("Ingrese el ID del medicamento a actualizar: \n");
   scanf("%d", &id);

   fseek(ptrArchivo, id * sizeof(struct medicamento), SEEK_SET);
   fread(&medicamentoExistente, sizeof(struct medicamento), 1, ptrArchivo);

   if (medicamentoExistente.id == 0) {
      printf("No hay información en el registro.\n");
   } else {
      printf("Ingrese nuevo nombre del medicamento: ");
      scanf("%s", medicamentoExistente.nombre);
      printf("Ingrese nueva cantidad: ");
      scanf("%d", &medicamentoExistente.cantidad);
      printf("Ingrese nuevo costo: ");
      scanf("%f", &medicamentoExistente.costo);

      fseek(ptrArchivo, id * sizeof(struct medicamento), SEEK_SET);
      fwrite(&medicamentoExistente, sizeof(struct medicamento), 1, ptrArchivo);
   }

   fclose(ptrArchivo);
}

void eliminarRegistro(void) {
   FILE *ptrArchivo;
   struct medicamento medicamentoExistente;
   struct medicamento vacio = {0, "", 0, 0.0};
   int id;

   if ((ptrArchivo = fopen("Medicat.dat", "rb+")) == NULL) {
      printf("No pudo abrirse el archivo Medicat.dat.\n");
      return;
   }

   printf("Ingrese el ID del medicamento a eliminar: ");
   scanf("%d", &id);

   fseek(ptrArchivo, id * sizeof(struct medicamento), SEEK_SET);
   fread(&medicamentoExistente, sizeof(struct medicamento), 1, ptrArchivo);

   if (medicamentoExistente.cantidad != 0) {
      printf("No se puede eliminar el registro.\n Aún tiene productos.\n");
   } else {
      fseek(ptrArchivo, id * sizeof(struct medicamento), SEEK_SET);
      fwrite(&vacio, sizeof(struct medicamento), 1, ptrArchivo);
   }

   fclose(ptrArchivo);
}

void mostrarRegistro(void) {
   FILE *ptrArchivo;
   struct medicamento medicamentoExistente;

   if ((ptrArchivo = fopen("Medicat.dat", "rb")) == NULL) {
      printf("No pudo abrirse el archivo Medicat.dat.\n");
      return;
   }

   printf("%-6s%-30s%-10s%-10s\n", "ID", "Nombre", "Cantidad", "Costo");
   while (fread(&medicamentoExistente, sizeof(struct medicamento), 1, ptrArchivo)) {
      if (medicamentoExistente.id != 0) {
         printf("%-6d%-30s%-10d $%-10.2f\n", medicamentoExistente.id, medicamentoExistente.nombre, medicamentoExistente.cantidad, medicamentoExistente.costo);
      }
   }

   fclose(ptrArchivo);
}

int intOpcion(void) {
   int opcion = 0;
   printf("\nSeleccione una opción:\n");
   printf("1. Crear el archivo de texto\n");
   printf("2. Actualizar un registro\n");
   printf("3. Crear un nuevo registro\n");
   printf("4. Eliminar un registro\n");
   printf("5. Mostrar registros\n");
   printf("6. Salir\n");
   scanf("%d", &opcion);
   return opcion;
}
