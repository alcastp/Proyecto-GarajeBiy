#include "extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void pausar() {
    printf("\nPresione Enter para continuar...");
    limpiarBuffer();
}

int pedirEntero(const char *mensaje) {
    int valor;
    int ok;
    do {
        printf("%s", mensaje);
        ok = scanf("%d", &valor);
        if (!ok) {
            printf("Entrada inválida. Debe ser un número entero.\n");
            limpiarBuffer();
        }
    } while (!ok);

    limpiarBuffer();
    return valor;
}

float pedirFlotante(const char *mensaje) {
    float valor;
    int ok;
    do {
        printf("%s", mensaje);
        ok = scanf("%f", &valor);
        if (!ok) {
            printf("Entrada inválida. Debe ser un número decimal.\n");
            limpiarBuffer();
        }
    } while (!ok);

    limpiarBuffer();
    return valor;
}

void obtenerFechaActual(char *bufferFecha, int tam) {
    time_t t = time(NULL);
    struct tm *fechaLocal = localtime(&t);

    snprintf(bufferFecha, tam,
             "%02d/%02d/%04d",
             fechaLocal->tm_mday,
             fechaLocal->tm_mon + 1,
             fechaLocal->tm_year + 1900);
}

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 300

char **leer_linea_csv(FILE *archivo, char separador) {
  static char linea[MAX_LINE_LENGTH];
  static char *campos[MAX_FIELDS];
  char *ptr, *start;
  int idx = 0;

  if (fgets(linea, MAX_LINE_LENGTH, archivo) == NULL) {
    return NULL; // No hay más líneas para leer
  }

  // Eliminar salto de linea
  linea[strcspn(linea, "\n")] = '\0';

  ptr = start = linea;
  while (*ptr) {
    if (idx >= MAX_FIELDS - 1)
      break;

    if (*ptr == '\"') { // Inicio de un campo entrecomillado
      start = ++ptr;    // Saltar la comilla inicial
      while (*ptr && !(*ptr == '\"' && *(ptr + 1) == separador))
        ptr++;
    } else { // Campo sin comillas
      start = ptr;
      while (*ptr && *ptr != separador)
        ptr++;
    }

    if (*ptr) {
      *ptr = '\0'; // Reemplazar comilla final o separador por terminación
      ptr++;
      if (*ptr == separador)
        ptr++;
    }

    // Quitar comilla final si existe
    if (*(ptr - 2) == '\"') {
      *(ptr - 2) = '\0';
    }

    campos[idx++] = start;
  }

  campos[idx] = NULL; // Marcar el final del array
  return campos;
}

List *split_string(const char *str, const char *delim) {
  List *result = list_create();
  char *token = strtok((char *)str, delim);

  while (token != NULL) {
    // Eliminar espacios en blanco al inicio del token
    while (*token == ' ') {
      token++;
    }

    // Eliminar espacios en blanco al final del token
    char *end = token + strlen(token) - 1;
    while (*end == ' ' && end > token) {
      *end = '\0';
      end--;
    }

    // Copiar el token en un nuevo string
    char *new_token = strdup(token);

    // Agregar el nuevo string a la lista
    list_pushBack(result, new_token);

    // Obtener el siguiente token
    token = strtok(NULL, delim);
  }

  return result;
}

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}