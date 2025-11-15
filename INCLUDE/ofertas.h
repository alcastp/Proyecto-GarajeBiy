#ifndef OFERTAS_H
#define OFERTAS_H

#include "usuario.h"
#include "subastas.h"

typedef struct {
    int idOferta;
    int idUsuario;
    float monto;
    char fecha[20];
    int estado;   // 0 = válida, 1 = ganadora, 2 = descartada
} Oferta;

// Crear una oferta para un producto (idProducto) usando el usuario actual
void crearOferta(int idProducto, Usuario *usuarioActivo);

// Listar todas las ofertas asociadas a un id de producto
void listarOfertas(int idProducto);

// Elegir oferta ganadora entre las ofertas existentes
void elegirOfertaGanadora(int idProducto);

#endif
