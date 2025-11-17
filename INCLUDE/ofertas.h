#ifndef OFERTAS_H
#define OFERTAS_H

#include "usuario.h"
#include "subastas.h"

typedef struct {
    int idOferta;
    int idProducto;        // <-- subasta/garaje al que pertenece
    int idUsuario;
    float monto;
    char fecha[20];
    int estado;            // 0 = válida, 1 = ganadora, 2 = descartada
} Oferta;

void crearOferta(int idProducto, Usuario *usuarioActivo);
void listarOfertas(int idProducto);
void elegirOfertaGanadora(int idProducto);

// Nueva: usada por subastas.c
Oferta* obtenerMejorOferta(int idProducto);

#endif
