#ifndef OFERTA_H
#define OFERTA_H

typedef struct {
    int idOferta;
    int idUsuario;
    float monto;
    char fecha[20];
    int estado; // 0 válida, 1 ganadora, 2 descartada
} Oferta;

Oferta* crearOferta(int idUsuario, float monto);
void destruirOferta(Oferta* o);

#endif
