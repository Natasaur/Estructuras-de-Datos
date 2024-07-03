#include <stdio.h>
 
/* definición de la estructura datosCliente */
struct datosCliente {
		 int numCta;              /* número de cuenta */
		 char apellido[ 15 ];       /* apellido */
		 char nombre[ 10 ];         /* nombre */
		 double saldo;              /* saldo */
};             
 
/* prototipos */
int intOpcion( void );
void archivoTexto( FILE *ptrLee );
void actualizaRegistro( FILE *ptrF );
void nuevoRegistro( FILE *ptrF );
void eliminaRegistro( FILE *ptrF );
 
int main() {
	FILE *ptrCf; /* apuntador de archivo credito.dat */
	int eleccion; /* elección del usuario */

	/* fopen abre el archivo; si no se puede abrir, sale del archivo */
	if ( ( ptrCf = fopen( "credito.dat", "rb+" ) ) == NULL ) {
		printf( "" );
	} else {
		/* permite al usuario especificar una acción */
		while ( ( eleccion = intOpcion() ) != 5 ) {
			switch ( eleccion ) {
				case 1:
					archivoTexto( ptrCf ); /* crea el archivo desde el registro */
			  	break;

			  	case 2:
					actualizaRegistro( ptrCf ); /* actualiza registro */
			  	break;

			  	case 3:
					nuevoRegistro( ptrCf ); /* crea registro */
			  	break;

			  	case 4:
					eliminaRegistro( ptrCf ); /* elimina el registro existente */
			  	break;
			  
			  	default:
					printf( "Opcion incorrecta\n" ); /* si el usuario no selecciona una opción válida, despliega un mensaje */
			  	break;
			}
		}
		fclose( ptrCf ); /* fclose cierra el archivo */
	}
	return 0; /* indica terminación exitosa */
}
 
/* crea un archivo de texto con formato para impresión */
void archivoTexto( FILE *ptrLee ){
	FILE *ptrEscribe; /* apuntador del archivo cuentas.txt */

	/* crea datosCliente con información predeterminada */
	struct datosCliente cliente = { 0, " ", " ", 0.0 };

	/* fopen abre el archivo; si no se puede abrir, sale del archivo */
	if ( ( ptrEscribe = fopen( "cuentas.txt", "w" ) ) == NULL ) {
		printf( "No pudo abrirse el archivo.\n" );
	} else {
		rewind( ptrLee ); /* establece el apuntador en el principio del archivo */
		fprintf( ptrEscribe, "%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre","Saldo" );

		/* copia todos los registros del archivo de acceso aleatorio dentro del archivo de texto */
		while ( !feof( ptrLee ) ) {
			fread( &cliente, sizeof( struct datosCliente ), 1, ptrLee );

			/* escribe un registro individual en el archivo de texto */
			if ( cliente.numCta != 0 ) {
				fprintf( ptrEscribe, "%-6d%-16s%-11s%10.2f\n",cliente.numCta, cliente.apellido,cliente.nombre, cliente.saldo );
			}
		}
		fclose( ptrEscribe ); /* fclose cierra el archivo */
	}
}