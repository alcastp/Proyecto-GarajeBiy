#ifndef SUBASTAS_H
#define SUBASTAS_H

#include "usuario.h"

#define MAX_SUBASTAS 200

/* Estructura base de una subasta en el sistema.
   Esta es la que usan los commits de subastas.c, archivos.c y estadisticas.c. */
typedef struct {
    int  idProducto;               // identificador de la subasta / producto
    char nombre[50];               // nombre del producto
    char descripcion[100];         // descripcion corta
    float precioBase;              // precio base inicial
    int  idDueno;                  // id del usuario dueño de la subasta
    int  estado;                   // 1 = activa, 2 = finalizada, 0 = inactiva (según uso del proyecto)
} Garaje;

/* Arreglo global de subastas y contador total.
   Se DEFINEN en subastas.c y se usan en otros módulos (estadisticas, archivos, etc.). */
extern Garaje listaSubastas[MAX_SUBASTAS];
extern int totalSubastas;

/* Busca una subasta por ID y devuelve un puntero a ella, o NULL si no existe. */
Garaje* obtenerSubastaPorID(int id);

/* Registra una nueva subasta asociada a un usuario dueño. */
void registrarSubasta(Usuario *dueno);

/* Funciones de manejo de subastas usadas en menús y estadísticas. */
void buscarSubasta(void);
void verSubastasActivas(void);
void finalizarSubasta(void);

#endif /* SUBASTAS_H */

