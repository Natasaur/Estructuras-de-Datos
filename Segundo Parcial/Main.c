//Programa hecho por @Natalia García
//05/07/24
#include <stdio.h>
#include <stdlib.h>

struct datosCliente {
	int numCta;
	char apellido[15];
	char nombre[10];
	double saldo;
};             
 
/* prototipos */
int intOpcion(void);
void archivoTexto(FILE *ptrLee);
void actualizaRegistro(FILE *ptrF);
void nuevoRegistro(FILE *ptrF);
void eliminarRegistro(FILE *ptrF);
void imprimirRegistro(FILE *ptrF);
 
int main() {
	FILE *ptrCf; /* apuntador de archivo credito.dat */
	int eleccion; /* elección del usuario */

	if ((ptrCf = fopen("cuentas.dat", "rb+")) == NULL) {
		printf("No se pudo abrir el archivo credito.dat.\n");
	} else {
		/* permite al usuario especificar una acción */
		system("cls");
		do {
			switch (eleccion) {
				case 1:
					archivoTexto(ptrCf); /* crea el archivo desde el registro */
					break;

				case 2:
					actualizaRegistro(ptrCf); /* actualiza registro */
					break;

				case 3:
					nuevoRegistro(ptrCf); /* crea registro */
					break;

				case 4:
					eliminarRegistro(ptrCf); /* elimina el registro existente */
					break;

				case 5:
					imprimirRegistro(ptrCf); //Imprime todos los regristros

				default:
					if(eleccion != 6 || eleccion != 5 || eleccion != 4 || eleccion != 3 || eleccion != 2 || eleccion != 1){
						printf("Opción incorrecta\n"); /* si el usuario no selecciona una opción válida, despliega un mensaje */
					}					
					break;
			}
		}while ((eleccion = intOpcion()) != 6);
		fclose(ptrCf); /* fclose cierra el archivo */
	}
	return 0; /* indica terminación exitosa */
}

void archivoTexto(FILE *ptrLee) {
	FILE *ptrEscribe; /* apuntador del archivo cuentas.txt */
	struct datosCliente cliente = {0, "", "", 0.0}; /* cliente predeterminado */

	/* fopen abre el archivo; si no se puede abrir, sale del archivo */
	if ((ptrEscribe = fopen("cuentas.dat", "w")) == NULL) {
		printf("No pudo abrirse el archivo cuentas.txt.\n");
		return;
	}else{
		printf("HOLA\n");
	}

	
	rewind(ptrLee); //establece el apuntador en el principio del archivo 
	fprintf(ptrEscribe, "%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre", "Saldo");

	 //copia todos los registros del archivo de acceso aleatorio dentro del archivo de texto
	while (fread(&cliente, sizeof(struct datosCliente), 1, ptrLee) == 1) {
		if (cliente.numCta != 0) { //escribe un registro individual en el archivo de texto
			fprintf(ptrEscribe, "%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
		}
	}
	

	fclose(ptrEscribe); /* fclose cierra el archivo */
}

void actualizaRegistro(FILE *ptrF) {
	int numCuenta, encontrado = 0;
	struct datosCliente cliente;
	system("cls");

	// Solicitar el número de cuenta al usuario
	printf("Ingrese el número de cuenta a actualizar: ");
	scanf("%d", &numCuenta);

	// Buscar el registro en el archivo
	rewind(ptrF);
	while (fread(&cliente, sizeof(struct datosCliente), 1, ptrF) == 1 && !encontrado) {
		if (cliente.numCta == numCuenta) {
			encontrado = 1;
		}
	}

	// Si se encuentra el registro
	if (encontrado) {
		// Modificar los datos del cliente
		printf("Ingrese el nuevo apellido: ");
		scanf("%s", cliente.apellido);

		printf("Ingrese el nuevo nombre: ");
		scanf("%s", cliente.nombre);

		printf("Ingrese el nuevo saldo: ");
		scanf("%lf", &cliente.saldo);

		// Escribir el registro modificado en el archivo
		fseek(ptrF, -sizeof(struct datosCliente), SEEK_CUR);
		fwrite(&cliente, sizeof(struct datosCliente), 1, ptrF);

		printf("Registro actualizado correctamente.\n");
	} else {
		printf("No se encontró el registro con el número de cuenta %d.\n", numCuenta);
	}
}

void nuevoRegistro(FILE *ptrF) {
	struct datosCliente cliente = {0, "", "", 0.0}; /* cliente predeterminado */
	int numCuenta;
	system("cls");

	// Solicitar el número de cuenta al usuario
	printf("Ingrese el número de cuenta (1 - 100): ");
	scanf("%d", &numCuenta);

	// Verificar si el número de cuenta está en el rango válido
	if (numCuenta < 1 || numCuenta > 100) {
		printf("Número de cuenta inválido.\n");
		return;
	}

	// Mover el puntero del archivo a la posición correcta
	fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

	// Leer el registro en la posición dada
	fread(&cliente, sizeof(struct datosCliente), 1, ptrF);

	// Verificar si la cuenta ya existe
	if (cliente.numCta != 0) {
		printf("La cuenta %d ya contiene información.\n", cliente.numCta);
	} else {
		// Solicitar datos del cliente al usuario
		cliente.numCta = numCuenta;
		printf("Ingrese el apellido: ");
		scanf("%s", cliente.apellido);
		printf("Ingrese el nombre: ");
		scanf("%s", cliente.nombre);
		printf("Ingrese el saldo: ");
		scanf("%lf", &cliente.saldo);

		// Mover el puntero del archivo de nuevo a la posición correcta
		fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

		// Escribir el nuevo registro en el archivo
		fwrite(&cliente, sizeof(struct datosCliente), 1, ptrF);

		printf("Registro agregado correctamente.\n");
	}
}

void eliminarRegistro(FILE *ptrF) {
	struct datosCliente cliente = {0, "", "", 0.0}; /* cliente predeterminado */
	int numCuenta;
	system("cls");

	// Solicitar el número de cuenta al usuario
	printf("Ingrese el número de cuenta a eliminar: ");
	scanf("%d", &numCuenta);

	// Mover el puntero del archivo a la posición correcta
	fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

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