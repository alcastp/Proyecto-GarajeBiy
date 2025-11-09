#include <stdio.h>
#include "usuarios.h"
#include "subastas.h"
#include "archivos.h"
#include "estadisticas.h"

void menuPrincipal(Usuario *usuarioActual) {
    int opcion;
    do {
        printf("----------------------------------------\n");
        printf("           Menú Principal\n");
        printf("----------------------------------------\n");

        // Opciones comunes
        printf("1. Buscar subasta\n");
        printf("2. Ver subastas activas\n");
        printf("3. Ver mejores ofertas\n");

        // Opciones solo para compradores
        if (usuarioActual->rol == COMPRADOR) {
            printf("4. Realizar oferta\n");
        }

        // Opciones solo para coordinadores
        if (usuarioActual->rol == COORDINADOR) {
            printf("5. Registrar subasta\n");
            printf("6. Finalizar subasta\n");
            printf("7. Buscar subasta por etiqueta o ID\n");
            printf("8. Guardar / Cargar desde archivo\n");
            printf("9. Estadísticas del sistema\n");
            printf("10. Gestión de usuarios\n");
        }

        printf("0. Cerrar sesión\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: buscarSubasta(); break;
            case 2: verSubastasActivas(); break;
            case 3: verMejoresOfertas(); break;

            case 4:
                if (usuarioActual->rol == COMPRADOR)
                    realizarOferta(usuarioActual);
                else
                    printf("Opción no permitida.\n");
                break;

            case 5:
                if (usuarioActual->rol == COORDINADOR)
                    registrarSubasta();
                else
                    printf("Opción no permitida.\n");
                break;

            // ... y así con el resto ...
        }

    } while (opcion != 0);
}
