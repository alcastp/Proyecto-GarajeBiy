#ifndef SUBASTAS_H
#define SUBASTAS_H
#include "usuario.h"
#include "ofertas.h"
#include "tdas/heap.h"
#include "tdas/map.h"

typedef struct {
    int idSubasta;
    char titulo[60];
    char descripcion[120];
    float precioBase;
    char etiqueta[30];
    int estado; // 0=activa, 1=finalizada
    Heap* ofertas;
} Subasta;

void cargarSubastasCSV();
void guardarSubastasCSV();
Subasta* buscarSubasta(int id);

#endif
