#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "archivos.h"
#include "estadisticas.h"
#include "usuario.h"
#include "extra.h"

/* Submenús específicos (Archivos, estadísticas y gestión de usuarios) */

void submenuArchivos() {
    int opcion;
    do {
        printf("\n----------------------------------------\n");
        printf("       Submenú de Archivos\n");
        printf("----------------------------------------\n");
        printf("1. Guardar datos en CSV\n");
        printf("2. Cargar datos desde CSV\n");
        printf("3. Volver al menú principal\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) {
            opcion = -1;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1: 
                guardarDatos(); 
                break;
            case 2: 
                cargarDatos(); 
                break;
            case 3: 
                printf("Volviendo al menú principal...\n"); 
                break;
            default: 
                printf("Opción inválida.\n"); 
                break;
        }
    } while (opcion != 3);
}

void submenuUsuarios() {
    int opcion;
    do {
        printf("\n----------------------------------------\n");
        printf("     Submenú de Gestión de Usuarios\n");
        printf("----------------------------------------\n");
        printf("1. Crear nuevo usuario\n");
        printf("2. Listar usuarios registrados\n");
        printf("3. Eliminar usuario\n");
        printf("4. Volver al menú principal\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) {
            opcion = -1;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1: 
                crearUsuario(); 
                break;
            case 2: 
                listarUsuarios(); 
                break;
            case 3: 
                eliminarUsuario(); 
                break;
            case 4: 
                printf("Volviendo...\n"); 
                break;
            default: 
                printf("Opción inválida.\n"); 
                break;
        }
    } while (opcion != 4);
}

void submenuEstadisticas() {
    int opcion;
    do {
        printf("\n----------------------------------------\n");
        printf("        Submenú de Estadísticas\n");
        printf("----------------------------------------\n");
        printf("1. Total de subastas creadas\n");
        printf("2. Subastas finalizadas exitosamente\n");
        printf("3. Promedio de ofertas por subasta\n");
        printf("4. Usuarios activos\n");
        printf("5. Volver al menú principal\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) {
            opcion = -1;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1:
            case 2:
            case 3:
            case 4:
                /* La función interna mostrará las métricas según corresponda */
                mostrarEstadisticas();
                break;
            case 5:
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 5);
}
