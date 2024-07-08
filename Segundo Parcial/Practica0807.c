//Programa hecho por @Natalia García
//05/07/24
/*
Desarrollar el siguiente programa.
Escriba instrucciones que realicen cada una de las siguientes tareas. Suponga que se definió la estructura 
struct persona {
	//Se le puede agregar un id
   char apellido[15]; 
   char nombre[15]; 
   char edad[4]; 
};
deben crear el archivo para escritura, y realizar las siguientes tareas.
 
a) Inicialice el archivo “nomedad.dat” de manera que existan 100 registros con apellido = “sin-asignar”, nombre= “” y edad= “0”. 
b) Introduzca 10 apellidos, nombres y edades, y escríbalos en el archivo. 
c) Actualice un registro; si no existe información en el registro, indique al usuario que “No hay información”. 
d) Elimine un registro que tenga información, por medio de la reinicialización de dicho registro en particular.
 
Cada inciso debe estar contenido en una función diferente.
*/

#include <stdio.h>
#include <stdlib.h>

struct persona {
	int id;
	char apellido[15];
	char nombre[15];
	char edad[4];
};             
 
/* prototipos */
int intOpcion(void);
void crearArchivo(FILE *ptrLee);
void nuevoRegistro(FILE *ptrF);
void actualizaRegistro(FILE *ptrF);
void eliminarRegistro(FILE *ptrF);
void imprimirRegistro(FILE *ptrF);
 
int main() {
	FILE *ptrCf;
	int eleccion;
	system("cls");
	do {
		switch (eleccion) {
			case 1:
				crearArchivo(ptrCf);
				break;

			case 2:
				actualizaRegistro(ptrCf);
				break;

			case 3:
				nuevoRegistro(ptrCf);
				break;

			case 4:
				eliminarRegistro(ptrCf);
				break;

			case 5:
				imprimirRegistro(ptrCf);

			default:
				if(eleccion != 6 || eleccion != 5 || eleccion != 4 || eleccion != 3 || eleccion != 2 || eleccion != 1){
					printf("Opción incorrecta\n");
				}					
				break;
		}
	}while ((eleccion = intOpcion()) != 6);
		fclose(ptrCf);
	return 0;
}

void crearArchivo(FILE *ptrLee) {
	FILE *ptrEscribe;
	struct persona nuevaPersona = {0,"","",""};

	if ((ptrEscribe = fopen("nomedad.dat", "w")) == NULL) {
		printf("No pudo abrirse el archivo nomedad.dat.\n");
		return;
	}else{
		printf("Archivo creado\n");
	}

	rewind(ptrLee);
	fprintf(ptrEscribe, "%-16s%-16s%-5s\n","Apellido", "Nombre", "Edad");

	while (fread(&nuevaPersona, sizeof(struct persona), 1, ptrLee) == 1) {
		if (nuevaPersona.id != 0) { 
			fprintf(ptrEscribe, "%-6d%-16s%-16s%-5s\n",nuevaPersona.id,nuevaPersona.apellido,nuevaPersona.nombre,nuevaPersona.edad);
		}
		/*for(int i=0;i<10;i++){
			fprintf(ptrEscribe, "%-16s%-16s%-5s\n",nuevaPersona.apellido,nuevaPersona.nombre,nuevaPersona.edad);
		}*/
	}
	fclose(ptrEscribe); /* fclose cierra el archivo */
}

void actualizaRegistro(FILE *ptrF) {
	int encontrado = 0;
	char apellido[15];
	struct persona nuevaPersona;
	system("cls");

	printf("Ingrese el apellido de la persona a actualizar: ");
	scanf("%s",&apellido);

	rewind(ptrF);
	while (fread(&nuevaPersona, sizeof(struct persona), 1, ptrF) == 1 && !encontrado) {
		if (nuevaPersona.apellido == apellido) {
			encontrado = 1;
		}
	}

	if (encontrado) {
		printf("Ingrese el nuevo apellido: ");
		scanf("%s",nuevaPersona.apellido);

		printf("Ingrese el nuevo nombre: ");
		scanf("%s",nuevaPersona.nombre);

		printf("Ingrese la nueva edad: ");
		scanf("%s",nuevaPersona.edad);

		fseek(ptrF, -sizeof(struct persona), SEEK_CUR);
		fwrite(&nuevaPersona, sizeof(struct persona), 1, ptrF);

		printf("Registro actualizado correctamente.\n");
	} else {
		printf("No se encontró el registro con el apellido %s.\n",apellido);
	}
}

void nuevoRegistro(FILE *ptrF) {
	struct persona nuevaPersona = {"","",""};
	char apellido[15];
	system("cls");

	printf("Ingrese el apellido de la persona a registrar: ");
	scanf("%s",&apellido);

	// Mover el puntero del archivo a la posición correcta
	//fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

	// Leer el registro en la posición dada
	fread(&nuevaPersona, sizeof(struct persona), 1, ptrF);

	// Verificar si la cuenta ya existe
	if (nuevaPersona.apellido == apellido) {
		printf("Ya existe esa persona.\n");
	} else {
		printf("Ingrese el apellido: ");
		scanf("%s",nuevaPersona.apellido);
		printf("Ingrese el nombre: ");
		scanf("%s",nuevaPersona.nombre);
		printf("Ingrese el saldo: ");
		scanf("%s",nuevaPersona.edad);

		// Mover el puntero del archivo de nuevo a la posición correcta
		//fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

		// Escribir el nuevo registro en el archivo
		fwrite(&nuevaPersona, sizeof(struct persona), 1, ptrF);

		printf("Registro agregado correctamente.\n");
	}
}

void eliminarRegistro(FILE *ptrF) {
	struct persona nuevaPersona = {"","",""};
	char apellido[15];
	system("cls");

	printf("Ingrese el apellido de la persona a eliminar: ");
	scanf("%s",&apellido);

	// Mover el puntero del archivo a la posición correcta
	//fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

	// Leer el registro en la posición dada
	fread(&cliente, sizeof(struct datosCliente), 1, ptrF);

	// Verificar si la cuenta existe
	if (cliente.numCta == 0) {
		printf("La cuenta %d no existe.\n", numCuenta);
	} else {
		// Crear un registro vacío para eliminar el actual
		struct datosCliente clienteVacio = {0, "", "", 0.0};

		// Mover el puntero del archivo de nuevo a la posición correcta
		fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

		// Escribir el registro vacío en el archivo
		fwrite(&clienteVacio, sizeof(struct datosCliente), 1, ptrF);

		printf("Registro eliminado correctamente.\n");
	}
}

void imprimirRegistro(FILE *ptrF) {
   struct datosCliente cliente = {0, "", "", 0.0};
	system("cls");

   rewind(ptrF);
   printf("%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre", "Saldo");

    // Lee y muestra cada registro
   while (fread(&cliente, sizeof(struct datosCliente), 1, ptrF) == 1) {
      if (cliente.numCta != 0) { // solo muestra registros válidos
            printf("%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
        }
    }
}

int intOpcion(void) {
	printf("\n");
	int opcion = NULL;
	printf("Seleccione una opción:\n");
	printf("1 - Crear archivo de texto con formato para impresión\n");
	printf("2 - Actualizar un registro\n");
	printf("3 - Crear un nuevo registro\n");
	printf("4 - Eliminar un registro\n");
	printf("5 - Mostrar registros\n");
	printf("6 - Salir\n");
	scanf("%d", &opcion);
	return opcion;
}