#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


// ========================================================
//                    MENÚ PRINCIPAL
// ========================================================
void mostrarMenuPrincipal(Usuario *usuarioActual) {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("            MENÚ PRINCIPAL\n");
        printf("========================================\n");
        printf("1. Subastas\n");
        printf("2. Ofertas\n");

        if (usuarioActual->rol == COORDINADOR) {
            printf("3. Usuarios\n");
            printf("4. Archivos\n");
            printf("5. Estadísticas\n");
        }

        printf("0. Cerrar sesión\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                submenuSubastas(usuarioActual);
                break;

            case 2:
                submenuOfertas(usuarioActual);
                break;

            case 3:
                if (usuarioActual->rol == COORDINADOR)
                    submenuUsuarios();
                else
                    printf("No tiene permisos.\n");
                break;

            case 4:
                if (usuarioActual->rol == COORDINADOR)
                    submenuArchivos();
                else
                    printf("No tiene permisos.\n");
                break;

            case 5:
                if (usuarioActual->rol == COORDINADOR)
                    submenuEstadisticas();
                else
                    printf("No tiene permisos.\n");
                break;

            case 0:
                printf("Cerrando sesión...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}
