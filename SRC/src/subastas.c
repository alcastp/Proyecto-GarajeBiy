#include <stdio.h>
#include <string.h>
#include "subastas.h"
#include "archivos.h"

// Estructura de garaje
typedef struct {
    int idProducto;
    char nombre[50];
    char descripcion[100];
    float precioBase;
    int idDueno;
    int estado; // 0 = inactivo, 1 = activo
} Garaje;

void buscarSubasta() {
    printf("Buscar subasta por ID o nombre del vehículo.\n");
    // Aqui buscar desde el archivo CSV o estructura cargada
}

void verSubastasActivas() {
    printf("Mostrando subastas activas:\n");
    FILE *fp = fopen("data/subastas.csv", "r");
    if (!fp) {
        printf("Error: no se pudo abrir el archivo de subastas.\n");
        return;
    }

    char linea[256];
    fgets(linea, sizeof(linea), fp); // Saltar encabezado

    while (fgets(linea, sizeof(linea), fp)) {
        int id, garaje_id, precio;
        char vehiculo[50], estado[20];
        sscanf(linea, "%d,%d,%49[^,],%d,%19s", &id, &garaje_id, vehiculo, &precio, estado);
        if (strcmp(estado, "activa") == 0) {
            printf("ID: %d | Vehículo: %s | Precio inicial: %d\n", id, vehiculo, precio);
        }
    }

    fclose(fp);
}

void verMejoresOfertas() {
    printf("Mejores ofertas registradas:\n");
    FILE *fp = fopen("data/ofertas.csv", "r");
    if (!fp) {
        printf("Error: no se pudo abrir el archivo de ofertas.\n");
        return;
    }

    char linea[256];
    fgets(linea, sizeof(linea), fp);
    while (fgets(linea, sizeof(linea), fp)) {
        int id_oferta, id_subasta, monto;
        char usuario[30];
        sscanf(linea, "%d,%d,%29[^,],%d", &id_oferta, &id_subasta, usuario, &monto);
        printf("Oferta ID %d | Subasta %d | Usuario: %s | Monto: %d\n", id_oferta, id_subasta, usuario, monto);
    }
    fclose(fp);
}

void realizarOferta(Usuario *usuario) {
    int id_subasta, monto;
    printf("Ingrese el ID de la subasta: ");
    scanf("%d", &id_subasta);
    printf("Ingrese el monto de su oferta: ");
    scanf("%d", &monto);

    FILE *fp = fopen("data/ofertas.csv", "a");
    if (!fp) {
        printf("Error al abrir archivo de ofertas.\n");
        return;
    }

    fprintf(fp, "0,%d,%s,%d\n", id_subasta, usuario->usuario, monto);
    fclose(fp);

    printf("Oferta registrada con éxito.\n");
}

void registrarSubasta() {
    FILE *fp = fopen("data/subastas.csv", "a");
    if (!fp) {
        printf("Error al abrir archivo de subastas.\n");
        return;
    }

    int id, garaje_id, precio;
    char vehiculo[50];
    printf("Ingrese ID de subasta: ");
    scanf("%d", &id);
    printf("Ingrese ID de garaje: ");
    scanf("%d", &garaje_id);
    printf("Ingrese vehículo: ");
    scanf("%s", vehiculo);
    printf("Ingrese precio inicial: ");
    scanf("%d", &precio);

    fprintf(fp, "%d,%d,%s,%d,activa\n", id, garaje_id, vehiculo, precio);
    fclose(fp);
    printf("Subasta registrada correctamente.\n");
}

void finalizarSubasta() {
    printf("Finalizar subasta (pendiente de implementación completa con lectura/escritura CSV).\n");
}
