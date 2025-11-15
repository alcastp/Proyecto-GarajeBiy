#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario usuariosRegistrados[MAX_USUARIOS];
int totalUsuarios = 0;

// --------------------------------------------------------
//             FUNCIÓN PARA INICIAR SESIÓN
// --------------------------------------------------------
Usuario* iniciarSesion() {
    char nombre[50];
    char contrasena[30];

    printf("\n===== INICIO DE SESIÓN =====\n");
    printf("Usuario: ");
    scanf("%49s", nombre);
    printf("Contraseña: ");
    scanf("%29s", contrasena);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuariosRegistrados[i].nombre, nombre) == 0 &&
            strcmp(usuariosRegistrados[i].contrasena, contrasena) == 0) {
            printf("Inicio de sesión exitoso. Bienvenido, %s.\n", nombre);
            return &usuariosRegistrados[i];
        }
    }

    printf("Credenciales incorrectas.\n");
    return NULL;
}

// --------------------------------------------------------
//                CREAR USUARIO
// --------------------------------------------------------
void crearUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Error: límite de usuarios alcanzado.\n");
        return;
    }

    Usuario nuevo;
    nuevo.idUsuario = totalUsuarios + 1;

    printf("\n===== CREAR USUARIO =====\n");

    printf("Nombre de usuario: ");
    scanf("%49s", nuevo.nombre);

    printf("Contraseña: ");
    scanf("%29s", nuevo.contrasena);

    int rol;
    printf("Seleccione rol:\n");
    printf("1. Comprador\n");
    printf("2. Coordinador\n");
    printf("Rol: ");
    scanf("%d", &rol);

    if (rol == 1) nuevo.rol = COMPRADOR;
    else if (rol == 2) nuevo.rol = COORDINADOR;
    else {
        printf("Rol inválido. Usuario no creado.\n");
        return;
    }

    usuariosRegistrados[totalUsuarios] = nuevo;
    totalUsuarios++;

    printf("Usuario creado exitosamente (ID %d)\n", nuevo.idUsuario);
}

// --------------------------------------------------------
//                  LISTAR USUARIOS
// --------------------------------------------------------
void listarUsuarios() {
    printf("\n===== LISTA DE USUARIOS =====\n");

    if (totalUsuarios == 0) {
        printf("No hay usuarios registrados.\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d | Usuario: %s | Rol: %s\n",
            usuariosRegistrados[i].idUsuario,
            usuariosRegistrados[i].nombre,
            usuariosRegistrados[i].rol == COMPRADOR ? "Comprador" : "Coordinador");
    }
}

// --------------------------------------------------------
//   ELIMINAR USUARIO  (definido en el header, no en el .md)
//   (puedes implementarlo en otro commit si corresponde)
// --------------------------------------------------------
void eliminarUsuario() {
    printf("Función eliminarUsuario() aún no implementada.\n");
}
