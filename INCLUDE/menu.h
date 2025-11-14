#ifndef MENU_H
#define MENU_H

#include "usuario.h"
#include "subastas.h"
#include "ofertas.h"
#include "archivos.h"
#include "estadisticas.h"


// Funciones generales

// Limpia el buffer del teclado tras usar scanf
void limpiarBuffer();

// Menú principal (dependiendo del rol)
void mostrarMenuPrincipal(Usuario *usuarioActual);


// Submenús por categoría

// Opciones de subastas (coordinador + comprador)
void mostrarSubmenuSubastas(Usuario *usuarioActual);

// Opciones de ofertas (solo comprador)
void mostrarSubmenuOfertas(Usuario *usuarioActual);

// Gestión de usuarios (solo coordinador)
void mostrarSubmenuUsuarios(Usuario *usuarioActual);

// Guardar / cargar datos
void mostrarSubmenuArchivos(Usuario *usuarioActual);

// Estadísticas globales
void mostrarSubmenuEstadisticas(Usuario *usuarioActual);

#endif

