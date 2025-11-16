#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ofertas.h"
#include "archivos.h"

#define MAX_OFERTAS 200

Oferta listaOfertas[MAX_OFERTAS];
int totalOfertas = 0;

// ============================================================
//   Función auxiliar: obtiene fecha actual en formato DD/MM/AAAA
// ============================================================
void obtenerFechaActual(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    sprintf(buffer, "%02d/%02d/%04d",
            tm_info->tm_mday,
            tm_info->tm_mon + 1,
            tm_info->tm_year + 1900);
}

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
    nueva.idUsuario = usuarioActivo->idUsuario;

    printf("\nIngrese monto de la oferta: ");
    scanf("%f", &nueva.monto);

    obtenerFechaActual(nueva.fecha);
    nueva.estado = 0;  // válida

    listaOfertas[totalOfertas] = nueva;
    totalOfertas++;

    printf("\n[OK] Oferta registrada exitosamente.\n");
}
