#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "archivos.h"
#include "subastas.h"
#include "ofertas.h"
#include "estadisticas.h"
#include "usuario.h"
#include "extra.h"

void mostrarMenuPrincipal(Usuario *usuarioActual) {
    int opcion;
    do {
        printf("----------------------------------------\n");
        printf("           Menú Principal\n");
        printf("----------------------------------------\n");
        printf("1. Registrar subasta\n");
        printf("2. Buscar subasta\n");
        printf("3. Ver subastas activas\n");

        if (usuarioActual->rol == COMPRADOR) {
            printf("4. Realizar oferta\n");
            printf("5. Ver mejores ofertas\n");
        }

        if (usuarioActual->rol == COORDINADOR) {
            printf("6. Finalizar subasta\n");
            printf("7. Buscar subasta por etiqueta o ID\n");
            printf("8. Guardar / Cargar desde archivo\n");
            printf("9. Estadísticas del sistema\n");
            printf("10. Gestión de usuarios\n");
        }

        printf("11. Cerrar sesión\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (usuarioActual->rol == COORDINADOR)
                    registrarSubasta();
                else
                    printf("No tiene permisos para registrar subastas.\n");
                break;

            case 2:
                buscarSubasta();
                break;

            case 3:
                verSubastasActivas();
                break;

            case 4:
                if (usuarioActual->rol == COMPRADOR)
                    realizarOferta(usuarioActual);
                else
                    printf("Solo los compradores pueden ofertar.\n");
                break;

            case 5:
                verMejoresOfertas();
                break;

            case 6:
                if (usuarioActual->rol == COORDINADOR)
                    finalizarSubasta();
                else
                    printf("No tiene permisos para finalizar subastas.\n");
                break;

            case 7:
                buscarSubasta();
                break;

            case 8:
                submenuArchivos();
                break;

            case 9:
                if (usuarioActual->rol == COORDINADOR)
                    submenuEstadisticas();
                else
                    printf("Solo el coordinador puede ver estadísticas globales.\n");
                break;

            case 10:
                if (usuarioActual->rol == COORDINADOR)
                    submenuUsuarios();
                else
                    printf("Solo el coordinador puede gestionar usuarios.\n");
                break;

            case 11:
                printf("Cerrando sesión...\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 11);
}

// ------------------------------------------------------------
// Submenús específicos
// ------------------------------------------------------------

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
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1: guardarDatos(); break;
            case 2: cargarDatos(); break;
            case 3: printf("Volviendo al menú principal...\n"); break;
            default: printf("Opción inválida.\n"); break;
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
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1: crearUsuario(); break;
            case 2: listarUsuarios(); break;
            case 3: eliminarUsuario(); break;
            case 4: printf("Volviendo...\n"); break;
            default: printf("Opción inválida.\n"); break;
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
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
            case 2:
            case 3:
            case 4:
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
