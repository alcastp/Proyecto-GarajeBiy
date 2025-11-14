#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "archivos.h"
#include "subastas.h"
#include "ofertas.h"
#include "estadisticas.h"
#include "usuario.h"
#include "extra.h"

// Limpia buffer tras usar scanf
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mostrarMenuPrincipal(Usuario *usuarioActual) {
    int opcion = 0;

    if (usuarioActual == NULL) {
        printf("Error: usuarioActual es NULL.\n");
        return;
    }

    do {
        printf("\n========================================\n");
        printf("              MENÚ PRINCIPAL\n");
        printf("========================================\n");
        printf("1. Registrar subasta\n");
        printf("2. Buscar subasta\n");
        printf("3. Ver subastas activas\n");

        // Opciones del comprador
        if (usuarioActual->rol == COMPRADOR) {
            printf("4. Realizar oferta\n");
            printf("5. Ver mejores ofertas\n");
        }

        // Opciones del coordinador
        if (usuarioActual->rol == COORDINADOR) {
            printf("6. Finalizar subasta\n");
            printf("7. Buscar por etiqueta o ID\n");
            printf("8. Guardar / Cargar archivos\n");
            printf("9. Estadísticas del sistema\n");
            printf("10. Gestión de usuarios\n");
        }

        printf("11. Cerrar sesión\n");
        printf("========================================\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida.\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1:
                (usuarioActual->rol == COORDINADOR)
                    ? registrarSubasta()
                    : printf("No tiene permisos para registrar subastas.\n");
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
                if (usuarioActual->rol == COMPRADOR)
                    verMejoresOfertas();
                else
                    printf("Solo los compradores pueden ver ofertas.\n");
                break;

            case 6:
                (usuarioActual->rol == COORDINADOR)
                    ? finalizarSubasta()
                    : printf("No tiene permisos para finalizar subastas.\n");
                break;

            case 7:
                buscarSubastaAvanzada();
                break;

            case 8:
                submenuArchivos();
                break;

            case 9:
                (usuarioActual->rol == COORDINADOR)
                    ? submenuEstadisticas()
                    : printf("Solo el coordinador puede ver estadísticas.\n");
                break;

            case 10:
                (usuarioActual->rol == COORDINADOR)
                    ? submenuUsuarios()
                    : printf("Solo el coordinador puede gestionar usuarios.\n");
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
// SUBMENÚ ARCHIVOS
// ------------------------------------------------------------

void submenuArchivos() {
    int opcion;

    do {
        printf("\n============== ARCHIVOS ==============\n");
        printf("1. Guardar datos en CSV\n");
        printf("2. Cargar datos desde CSV\n");
        printf("3. Volver\n");
        printf("======================================\n");
        printf("Opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida.\n");
            limpiarBuffer();
            continue;
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
                printf("Volviendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 3);
}

// ------------------------------------------------------------
// SUBMENÚ USUARIOS
// ------------------------------------------------------------

void submenuUsuarios() {
    int opcion;

    do {
        printf("\n========== GESTIÓN DE USUARIOS ==========\n");
        printf("1. Crear nuevo usuario\n");
        printf("2. Listar usuarios\n");
        printf("3. Eliminar usuario\n");
        printf("4. Volver\n");
        printf("=========================================\n");
        printf("Opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida.\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1: crearUsuario(); break;
            case 2: listarUsuarios(); break;
            case 3: eliminarUsuario(); break;
            case 4: printf("Volviendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 4);
}

// ------------------------------------------------------------
// SUBMENÚ ESTADÍSTICAS
// ------------------------------------------------------------

void submenuEstadisticas() {
    int opcion;

    do {
        printf("\n============= ESTADÍSTICAS =============\n");
        printf("1. Total de subastas creadas\n");
        printf("2. Subastas finalizadas\n");
        printf("3. Promedio de ofertas por subasta\n");
        printf("4. Usuarios activos\n");
        printf("5. Volver\n");
        printf("========================================\n");
        printf("Opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida.\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1:
            case 2:
            case 3:
            case 4:
                mostrarEstadisticas(opcion);
                break;

            case 5:
                printf("Volviendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 5);
}
