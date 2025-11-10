#include <stdio.h>
#include "menu.h"
#include "usuario.h"

int main() {
    printf("Bienvenido a GarageBiy\n");
    Usuario *usuarioActual = login();
    if (usuarioActual != NULL) {
        mostrarMenuPrincipal(usuarioActual);
    } else {
        printf("Error: no se pudo iniciar sesión.\n");
    }
    return 0;
}

