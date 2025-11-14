#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "menu.h"
#include "archivos.h"
#include "extra.h"

int main() {
    int opcionInicio;
    Usuario *usuarioActual = NULL;

    // ==============================
    //  MENÚ DE INICIO DEL SISTEMA
    // ==============================
    do {
        printf("========================================\n");
        printf("           Bienvenido a GarageBiy       \n");
        printf("========================================\n");
        printf("1. Iniciar sesión\n");
        printf("2. Cargar datos desde archivo\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");

        scanf("%d", &opcionInicio);
        limpiarBuffer();

        switch (opcionInicio) {
            case 1:
                usuarioActual = iniciarSesion();
                if (usuarioActual != NULL) {
                    printf("\nInicio de sesión exitoso. Bienvenido %s!\n\n",
                           usuarioActual->nombre);
                    mostrarMenuPrincipal(usuarioActual);
                } else {
                    printf("Credenciales incorrectas. Intente nuevamente.\n");
                }
                break;

            case 2:
                cargarDatos();
                printf("Datos cargados correctamente.\n\n");
                break;

            case 3:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }

    } while (opcionInicio != 3);

    printf("Gracias por usar GarageBiy.\n");
    return 0;
}

