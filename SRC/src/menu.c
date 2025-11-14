#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

// ------------------------------------------------------------
// Limpieza de buffer para evitar problemas con scanf
// ------------------------------------------------------------
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void mostrarMenuPrincipal(Usuario *usuarioActual) {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("              MENÚ PRINCIPAL\n");
        printf("========================================\n");
        printf("1. Subastas\n");

        if (usuarioActual->rol == COMPRADOR)
            printf("2. Ofertas\n");

        if (usuarioActual->rol == COORDINADOR)
            printf("3. Gestión de Usuarios\n");

        printf("4. Archivos\n");

        if (usuarioActual->rol == COORDINADOR)
            printf("5. Estadísticas\n");

        printf("6. Cerrar sesión\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                mostrarSubmenuSubastas(usuarioActual);
                break;

            case 2:
                if (usuarioActual->rol == COMPRADOR)
                    mostrarSubmenuOfertas(usuarioActual);
                else
                    printf("Solo los compradores pueden acceder a este menú.\n");
                break;

            case 3:
                if (usuarioActual->rol == COORDINADOR)
                    mostrarSubmenuUsuarios(usuarioActual);
                else
                    printf(" Solo coordinadores pueden gestionar usuarios.\n");
                break;

            case 4:
                mostrarSubmenuArchivos(usuarioActual);
                break;

            case 5:
                if (usuarioActual->rol == COORDINADOR)
                    mostrarSubmenuEstadisticas(usuarioActual);
                else
                    printf("No autorizado.\n");
                break;

            case 6:
                printf("Cerrando sesión...\n");
                break;

            default:
                printf(" Opción inválida.\n");
                break;
        }

    } while (opcion != 6);
}

