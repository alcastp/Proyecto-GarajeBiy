#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "subastas.h"
#include "ofertas.h"

// ---------------------------------------------------------
//   ARREGLO GLOBAL DE SUBASTAS Y CONTADOR
// ---------------------------------------------------------

Garaje listaSubastas[MAX_SUBASTAS];
int totalSubastas = 0;

// ---------------------------------------------------------
//   OBTENER SUBASTA POR ID
// ---------------------------------------------------------

Garaje* obtenerSubastaPorID(int id) {
    for (int i = 0; i < totalSubastas; i++) {
        if (listaSubastas[i].idProducto == id) {
            return &listaSubastas[i];
        }
    }
    return NULL;
}

// ---------------------------------------------------------
//   REGISTRAR SUBASTA
// ---------------------------------------------------------

void registrarSubasta(Usuario *dueno) {
    if (totalSubastas >= MAX_SUBASTAS) {
        printf("Error: límite máximo de subastas alcanzado.\n");
        return;
    }

    printf("\n===== REGISTRAR NUEVA SUBASTA =====\n");

    Garaje nueva;
    nueva.idProducto = totalSubastas + 1;

    printf("Nombre del producto: ");
    scanf(" %49[^\n]", nueva.nombre);

    printf("Descripción: ");
    scanf(" %99[^\n]", nueva.descripcion);

    printf("Precio base: ");
    scanf("%f", &nueva.precioBase);

    nueva.estado = 1;          // 1 = ACTIVA
    nueva.idDueno = dueno->idUsuario;

    listaSubastas[totalSubastas] = nueva;
    totalSubastas++;

    printf("Subasta registrada exitosamente. ID asignado: %d\n", nueva.idProducto);
}

// ---------------------------------------------------------
//   BUSCAR SUBASTA POR ID (INTERACTIVO)
// ---------------------------------------------------------

void buscarSubasta() {
    int id;
    printf("\nIngrese ID de subasta a buscar: ");
    scanf("%d", &id);

    Garaje *s = obtenerSubastaPorID(id);

    if (!s) {
        printf("No se encontró una subasta con ID %d.\n", id);
        return;
    }

    printf("\n===== RESULTADO DE BÚSQUEDA =====\n");
    printf("ID: %d\n", s->idProducto);
    printf("Nombre: %s\n", s->nombre);
    printf("Descripción: %s\n", s->descripcion);
    printf("Precio base: %.2f\n", s->precioBase);

    if (s->estado == 1)
        printf("Estado: ACTIVA\n");
    else if (s->estado == 2)
        printf("Estado: FINALIZADA\n");
    else
        printf("Estado: INACTIVA\n");
}

// ---------------------------------------------------------
//   MOSTRAR SUBASTAS ACTIVAS
// ---------------------------------------------------------

void verSubastasActivas() {
    printf("\n===== SUBASTAS ACTIVAS =====\n");

    int count = 0;

    for (int i = 0; i < totalSubastas; i++) {
        if (listaSubastas[i].estado == 1) {
            printf("ID: %d | %s | Precio base: %.2f\n",
                   listaSubastas[i].idProducto,
                   listaSubastas[i].nombre,
                   listaSubastas[i].precioBase);
            count++;
        }
    }

    if (count == 0) {
        printf("No hay subastas activas actualmente.\n");
    }
}

// ---------------------------------------------------------
//   FINALIZAR SUBASTA
// ---------------------------------------------------------

void finalizarSubasta() {
    int id;
    printf("\nIngrese ID de subasta a finalizar: ");
    scanf("%d", &id);

    Garaje *s = obtenerSubastaPorID(id);

    if (!s) {
        printf("No existe una subasta con ese ID.\n");
        return;
    }

    if (s->estado != 1) {
        printf("La subasta no está activa, no se puede finalizar.\n");
        return;
    }

    s->estado = 2; // finalizada

    printf("\n===== SUBASTA FINALIZADA =====\n");
    printf("Producto: %s\n", s->nombre);

    // Esta función la vamos a definir en ofertas.c en el siguiente paso
    Oferta *ganadora = obtenerMejorOferta(id);

    if (ganadora != NULL) {
        printf("Oferta ganadora: %.2f por usuario %d\n",
               ganadora->monto, ganadora->idUsuario);

        // marcar estado de la oferta ganadora
        ganadora->estado = 1;
    } else {
        printf("No hubo ofertas. La subasta queda sin comprador.\n");
    }
}
