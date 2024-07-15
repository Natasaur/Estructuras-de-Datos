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
#include <string.h>

struct persona {
    int id;
    char apellido[15];
    char nombre[15];
    char edad[4];
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
    struct persona vacia = {0, "sin-asignar", "", "0"};

    if ((ptrArchivo = fopen("personas.dat", "wb")) == NULL) {
        printf("No pudo abrirse el archivo personas.dat.\n");
        return;
    }

    for (int i = 0; i < 100; i++) {
        fwrite(&vacia, sizeof(struct persona), 1, ptrArchivo);
    }

    fclose(ptrArchivo);
    printf("Archivo inicializado con 100 registros vacíos.\n");
}

void nuevoRegistro(void) {
    FILE *ptrArchivo;
    struct persona nuevaPersona;

    if ((ptrArchivo = fopen("personas.dat", "rb+")) == NULL) {
        printf("No pudo abrirse el archivo personas.dat.\n");
        return;
    }

    //for (int i = 0; i < 10; i++) {
        printf("Ingrese ID: ");
        scanf("%d", &nuevaPersona.id);
        printf("Ingrese apellido: ");
        scanf("%s", nuevaPersona.apellido);
        printf("Ingrese nombre: ");
        scanf("%s", nuevaPersona.nombre);
        printf("Ingrese edad: ");
        scanf("%s", nuevaPersona.edad);

        fseek(ptrArchivo, (nuevaPersona.id - 1) * sizeof(struct persona), SEEK_SET);
        fwrite(&nuevaPersona, sizeof(struct persona), 1, ptrArchivo);
    //}

    fclose(ptrArchivo);
}

void actualizaRegistro(void) {
    FILE *ptrArchivo;
    struct persona personaExistente;
    int id;

    if ((ptrArchivo = fopen("personas.dat", "rb+")) == NULL) {
        printf("No pudo abrirse el archivo personas.dat.\n");
        return;
    }

    printf("Ingrese el ID del registro a actualizar: ");
    scanf("%d", &id);

    fseek(ptrArchivo, (id - 1) * sizeof(struct persona), SEEK_SET);
    fread(&personaExistente, sizeof(struct persona), 1, ptrArchivo);

    if (personaExistente.id == 0) {
        printf("No hay información en el registro.\n");
    } else {
        printf("Ingrese nuevo apellido: ");
        scanf("%s", personaExistente.apellido);
        printf("Ingrese nuevo nombre: ");
        scanf("%s", personaExistente.nombre);
        printf("Ingrese nueva edad: ");
        scanf("%s", personaExistente.edad);

        fseek(ptrArchivo, (id - 1) * sizeof(struct persona), SEEK_SET);
        fwrite(&personaExistente, sizeof(struct persona), 1, ptrArchivo);
    }

    fclose(ptrArchivo);
}

void eliminarRegistro(void) {
    FILE *ptrArchivo;
    struct persona vacia = {0, "sin-asignar", "", "0"};
    int id;

    if ((ptrArchivo = fopen("personas.dat", "rb+")) == NULL) {
        printf("No pudo abrirse el archivo personas.dat.\n");
        return;
    }

    printf("Ingrese el ID del registro a eliminar: ");
    scanf("%d", &id);

    fseek(ptrArchivo, (id - 1) * sizeof(struct persona), SEEK_SET);
    fwrite(&vacia, sizeof(struct persona), 1, ptrArchivo);

    fclose(ptrArchivo);
}

// Mostrar registros
void imprimirRegistro(void) {
    FILE *ptrArchivo;
    struct persona personaExistente;

    if ((ptrArchivo = fopen("personas.dat", "rb")) == NULL) {
        printf("No pudo abrirse el archivo personas.dat.\n");
        return;
    }

    printf("%-6s%-16s%-16s%-5s\n", "ID", "Apellido", "Nombre", "Edad");
    while (fread(&personaExistente, sizeof(struct persona), 1, ptrArchivo)) {
        if (personaExistente.id != 0) {
            printf("%-6d%-16s%-16s%-5s\n", personaExistente.id, personaExistente.apellido, personaExistente.nombre, personaExistente.edad);
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
