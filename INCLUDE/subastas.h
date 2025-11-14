#ifndef SUBASTAS_H
#define SUBASTAS_H

#include "usuario.h"

#define MAX_SUBASTAS 200

typedef struct {
    int idProducto;
    char nombre[50];
    char descripcion[100];
    float precioBase;
    int idDueno;
    int estado; // 0 = inactiva, 1 = activa, 2 = finalizada
} Garaje;

extern Garaje listaSubastas[MAX_SUBASTAS];
extern int totalSubastas;

void registrarSubasta(Usuario *dueno);
void buscarSubasta();
void verSubastasActivas();
void finalizarSubasta();

Garaje* obtenerSubastaPorID(int id);

#endif
