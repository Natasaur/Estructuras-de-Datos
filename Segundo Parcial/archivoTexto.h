#ifndef ARCHIVOTEXTO_H
#define ARCHIVOTEXTO_H

#include <stdio.h>
#include <stdlib.h>

void archivoTexto(FILE *ptrLee) {
	FILE *ptrEscribe; /* apuntador del archivo cuentas.txt */
	struct datosCliente {
		int numCta;
		char apellido[15];
		char nombre[10];
		double saldo;
	};
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

#endif // !ARCHIVOTEXTO_H