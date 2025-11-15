#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "usuario.h"

// ========================================================
//                   SUBMENÚ DE SUBASTAS
// ========================================================
void submenuSubastas(Usuario *usuarioActual) {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("             SUBMENÚ SUBASTAS\n");
        printf("========================================\n");
        printf("1. Ver subastas activas\n");
        printf("2. Participar en subasta\n");

        if (usuarioActual->rol == COORDINADOR) {
            printf("3. Crear subasta\n");
            printf("4. Cerrar subasta\n");
        }

        printf("0. Volver\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Función: Ver subastas activas.\n");
                break;

            case 2:
                printf("Función: Participar en subasta.\n");
                break;

            case 3:
                if (usuarioActual->rol == COORDINADOR)
                    printf("Función: Crear subasta.\n");
                else
                    printf("No tiene permisos.\n");
                break;

            case 4:
                if (usuarioActual->rol == COORDINADOR)
                    printf("Función: Cerrar subasta.\n");
                else
                    printf("No tiene permisos.\n");
                break;

            case 0:
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);
}

// ========================================================
//                    SUBMENÚ DE OFERTAS
// ========================================================
void submenuOfertas(Usuario *usuarioActual) {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("              SUBMENÚ OFERTAS\n");
        printf("========================================\n");
        printf("1. Realizar oferta\n");
        printf("2. Ver mejores ofertas\n");
        printf("3. Historial de ofertas\n");
        printf("0. Volver\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Función: Realizar oferta.\n");
                break;

            case 2:
                printf("Función: Ver mejores ofertas.\n");
                break;

            case 3:
                printf("Función: Historial de ofertas.\n");
                break;

            case 0:
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);
}

// ========================================================
//                SUBMENÚ DE USUARIOS (COORDINADOR)
// ========================================================
void submenuUsuarios() {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("            SUBMENÚ USUARIOS\n");
        printf("========================================\n");
        printf("1. Crear usuario\n");
        printf("2. Listar usuarios\n");
        printf("3. Eliminar usuario\n");
        printf("0. Volver\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Función: Crear usuario.\n");
                break;

            case 2:
                printf("Función: Listar usuarios.\n");
                break;

            case 3:
                printf("Función: Eliminar usuario.\n");
                break;

            case 0:
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);
}

// ========================================================
//                   SUBMENÚ DE ARCHIVOS
// ========================================================
void submenuArchivos() {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("           SUBMENÚ ARCHIVOS (CSV)\n");
        printf("========================================\n");
        printf("1. Cargar datos desde archivo\n");
        printf("2. Guardar datos en archivo\n");
        printf("0. Volver\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Función: Cargar datos.\n");
                break;

            case 2:
                printf("Función: Guardar datos.\n");
                break;

            case 0:
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);
}

// ========================================================
//                   SUBMENÚ DE ESTADÍSTICAS
// ========================================================
void submenuEstadisticas() {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("            SUBMENÚ ESTADÍSTICAS\n");
        printf("========================================\n");
        printf("1. Totales\n");
        printf("2. Promedios\n");
        printf("3. Finalizadas\n");
        printf("0. Volver\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Función: Estadísticas totales.\n");
                break;

            case 2:
                printf("Función: Estadísticas promedios.\n");
                break;

            case 3:
                printf("Función: Estadísticas finalizadas.\n");
                break;

            case 0:
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);
}
