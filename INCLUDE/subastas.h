#ifndef SUBASTAS_H
#define SUBASTAS_H
#include "usuario.h"


typedef struct {
    int id;
    char nombre[50];
    float precio_inicial;
    float precio_actual;
    int activa;
} Subasta;

void buscarSubasta();
void verSubastasActivas();
void verMejoresOfertas();
void realizarOferta(Usuario *usuario);
void registrarSubasta();
void finalizarSubasta();

#endif
