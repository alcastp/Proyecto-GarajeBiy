#ifndef MENU_H
#define MENU_H

#include "usuario.h"
#include "subastas.h"
#include "ofertas.h"
#include "archivos.h"
#include "estadisticas.h"

void mostrarMenuPrincipal(Usuario *usuarioActual);
void mostrarSubmenuSubastas(Usuario *usuarioActual);
void mostrarSubmenuOfertas(Usuario *usuarioActual);
void mostrarSubmenuUsuarios(Usuario *usuarioActual);
void mostrarSubmenuArchivos(Usuario *usuarioActual);
void mostrarSubmenuEstadisticas(Usuario *usuarioActual);

#endif
