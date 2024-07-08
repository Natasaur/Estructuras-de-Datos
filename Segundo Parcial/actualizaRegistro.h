#ifndef ACTUALIZAREGISTRO_H
#define ACTUALIZAREGISTRO_H

#include <stdio.h>
#include <stdlib.h>

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

//#define ACTUALIZAREGISTRO_H
#endif // !ACTUALIZAREGISTRO_H