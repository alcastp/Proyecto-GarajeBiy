#ifndef USUARIO_H
#define USUARIO_H

typedef enum {COORDINADOR, COMPRADOR} Rol;

typedef struct {
    int id;
    char nombre[50];
    char correo[50];
    char clave[30];
    Rol rol;
} Usuario;

void cargarUsuariosCSV();
void guardarUsuariosCSV();
Usuario* login();

#endif
