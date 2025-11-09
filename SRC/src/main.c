#include <stdio.h>
#include "usuarios.h"
#include "subastas.h"
#include "ofertas.h"
#include "archivos.h"
#include "estadisticas.h"

int main() {
    int opcion;
    int rol; // 1 = coordinador, 2 = comprador

    printf("=== SISTEMA DE SUBASTAS ===\n");
    printf("Seleccione su rol:\n1. Coordinador\n2. Comprador\n> ");
    scanf("%d", &rol);

    do {
        if (rol == 1) {
            printf("\n--- Menú Coordinador ---\n");
            printf("1. Registrar subasta\n2. Buscar subasta\n3. Ver subastas activas\n");
            printf("4. Finalizar subasta\n5. Guardar/Cargar desde archivo\n");
            printf("6. Estadísticas del sistema\n7. Gestión de usuarios\n8. Cerrar sesión\n> ");
        } else {
            printf("\n--- Menú Comprador ---\n");
            printf("1. Buscar subasta\n2. Ver subastas activas\n3. Realizar oferta\n");
            printf("4. Ver mejores ofertas\n5. Cerrar sesión\n> ");
        }
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: printf("Función en desarrollo...\n"); break;
            default: printf("Opción no válida.\n");
        }

    } while (opcion != 8 && rol == 1 || opcion != 5 && rol == 2);

    printf("Sesión finalizada.\n");
    return 0;
}
