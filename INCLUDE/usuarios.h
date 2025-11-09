typedef enum {
    COMPRADOR,
    COORDINADOR
} Rol;

typedef struct {     
    int id;
    char nombre[50];
    char usuario[20];
    char clave[30];
    Rol rol;
} Usuario;
