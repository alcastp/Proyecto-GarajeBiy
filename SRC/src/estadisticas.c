#include <stdio.h>

#include "estadisticas.h"
#include "subastas.h"
#include "ofertas.h"
#include "usuario.h"

// ===================================================
//   FUNCIONES DE ESTADÍSTICAS DEL SISTEMA
// ===================================================

void mostrarEstadisticas() {

    int activas = 0;
    int finalizadas = 0;
    float promedioOfertas = 0;

    // Contar subastas activas y finalizadas
    for (int i = 0; i < totalSubastas; i++) {
        if (listaSubastas[i].estado == 1)
            activas++;
        else if (listaSubastas[i].estado == 0)
            finalizadas++;
    }

    // Promedio de ofertas
    if (totalSubastas > 0)
        promedioOfertas = (float) totalOfertas / totalSubastas;

    // Contar usuarios por rol
    int compradores = 0, coordinadores = 0;
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuariosRegistrados[i].rol == COMPRADOR)
            compradores++;
        else if (usuariosRegistrados[i].rol == COORDINADOR)
            coordinadores++;
    }

    printf("\n==============================\n");
    printf("     ESTADÍSTICAS DEL SISTEMA\n");
    printf("==============================\n");

    printf("Total de subastas registradas : %d\n", totalSubastas);
    printf("Subastas activas              : %d\n", activas);
    printf("Subastas finalizadas          : %d\n", finalizadas);
    printf("Total de ofertas realizadas   : %d\n", totalOfertas);
    printf("Promedio de ofertas/subasta   : %.2f\n", promedioOfertas);

    printf("\nUsuarios registrados:\n");
    printf("- Compradores  : %d\n", compradores);
    printf("- Coordinadores: %d\n", coordinadores);

    printf("==============================\n\n");
}
