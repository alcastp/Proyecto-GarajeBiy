#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ofertas.h"
#include "archivos.h"
#include "extra.h"

#define MAX_OFERTAS 200

Oferta listaOfertas[MAX_OFERTAS];
int totalOfertas = 0;



// ======================================
//   Crear una nueva oferta
// ======================================
void crearOferta(int idProducto, Usuario *usuarioActivo) {
    (void)idProducto;  // por ahora no se usa, pero queda el parámetro

    if (totalOfertas >= MAX_OFERTAS) {
        printf("\n[ERROR] No se pueden registrar más ofertas.\n");
        return;
    }

    Oferta nueva;

    nueva.idOferta  = totalOfertas + 1;
    nueva.idProducto = idProducto;
    nueva.idUsuario = usuarioActivo->idUsuario;

    printf("\nIngrese monto de la oferta: ");
    scanf("%f", &nueva.monto);

    obtenerFechaActual(nueva.fecha, sizeof(nueva.fecha));
    nueva.estado = 0;  // válida

    listaOfertas[totalOfertas] = nueva;
    totalOfertas++;

    printf("\n[OK] Oferta registrada exitosamente.\n");
}

Oferta* obtenerMejorOferta(int idProducto) {
    Oferta *mejor = NULL;

    for (int i = 0; i < totalOfertas; i++) {
        Oferta *act = &listaOfertas[i];

        // Solo ofertas de la subasta indicada y válidas
        if (act->idProducto != idProducto) continue;
        if (act->estado != 0) continue; // 0 = válida

        if (mejor == NULL || act->monto > mejor->monto) {
            mejor = act;
        }
    }

    return mejor;  // Puede ser NULL si no hay ofertas para esa subasta
}
