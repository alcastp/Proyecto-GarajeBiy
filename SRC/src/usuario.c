#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario* login() {
    char user[50], pass[50];

    printf("Usuario: ");
    scanf("%49s", user);

    printf("Contraseña: ");
    scanf("%49s", pass);

    Usuario *u = malloc(sizeof(Usuario));
    if (!u) return NULL;

    if (strcmp(user, "coordinador") == 0 && strcmp(pass, "123") == 0) {
        u->id = 1;
        strcpy(u->nombre, "Coordinador General");
        u->rol = COORDINADOR;
        return u;
    }

    if (strcmp(user, "comprador") == 0 && strcmp(pass, "123") == 0) {
        u->id = 2;
        strcpy(u->nombre, "Usuario Comprador");
        u->rol = COMPRADOR;
        return u;
    }

    free(u);
    return NULL;
}
