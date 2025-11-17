#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 100

typedef enum {
    COMPRADOR = 1,
    COORDINADOR = 2
} Rol;

typedef struct {
    int idUsuario;
    char nombre[50];
    char contrasena[30];
    Rol rol;
} Usuario;

extern Usuario usuariosRegistrados[MAX_USUARIOS];
extern int totalUsuarios;

Usuario* iniciarSesion();
Usuario* login();
void crearUsuario();
void listarUsuarios();
void eliminarUsuario();

#endif
