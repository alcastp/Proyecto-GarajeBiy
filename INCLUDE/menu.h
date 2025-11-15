#ifndef MENU_H
#define MENU_H

#include "usuario.h"
#include "subastas.h"
#include "ofertas.h"
#include "archivos.h"
#include "estadisticas.h"

// Menú principal
void mostrarMenuPrincipal(Usuario *usuarioActual);

// Submenús
void submenuSubastas(Usuario *usuarioActual);
void submenuOfertas(Usuario *usuarioActual);
void submenuUsuarios();
void submenuArchivos();
void submenuEstadisticas();

// Utilidad
void limpiarBuffer();

#endif // MENU_H

