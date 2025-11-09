#include <stdio.h>
#include <string.h>
#include "usuario.h"

int login(Usuario *usuario) {
    char user[20], pass[20];
    printf("Usuario: ");
    scanf("%s", user);
    printf("Contraseña: ");
    scanf("%s", pass);

    // Lectura básica desde CSV simulado
    if (strcmp(user, "coordinador") == 0 && strcmp(pass, "123") == 0) {
        strcpy(usuario->nombre, "Coordinador General");
        usuario->rol = COORDINADOR;
        return 1;
    } else if (strcmp(user, "comprador") == 0 && strcmp(pass, "123") == 0) {
        strcpy(usuario->nombre, "Usuario Comprador");
        usuario->rol = COMPRADOR;
        return 1;
    }

    return 0;
}
