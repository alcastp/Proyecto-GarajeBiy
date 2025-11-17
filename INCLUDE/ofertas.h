#ifndef OFERTAS_H
#define OFERTAS_H

#include "usuario.h"
#include "subastas.h"

#define MAX_OFERTAS 200

typedef struct {
    int idOferta;
    int idUsuario;
    float monto;
    char fecha[20];
    int estado; // 0 = válida, 1 = ganadora, 2 = descartada
} Oferta;

// Arreglos globales de ofertas (se definen en ofertas.c)
extern Oferta listaOfertas[MAX_OFERTAS];
extern int totalOfertas;

void crearOferta(int idProducto, Usuario *usuarioActivo);
void listarOfertas(int idProducto);
void elegirOfertaGanadora(int idProducto);

#endif
