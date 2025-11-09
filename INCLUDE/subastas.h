#ifndef SUBASTAS_H
#define SUBASTAS_H

typedef struct {
    int id;
    char nombre[50];
    float precio_inicial;
    float precio_actual;
    int activa;
} Subasta;

void registrarSubasta();
void buscarSubasta();
void verSubastasActivas();
void finalizarSubasta();

#endif
