# 🚗 GarageBiy

**Pontificia Universidad Católica de Valparaíso**  
**Escuela de Ingeniería Informática**  
**Asignatura:** ICI2240 – Estructuras de Datos  
**Profesor:** Fabián Pizarro  
**Fecha:** Noviembre 2025  

**Integrantes del equipo:**  
- Yael Astorga Valenzuela  
- Cristian Baeza López  
- Felipe Poirier Valdivia  
- Benjamín Estay Zamora  

---

## 🧩 Descripción General

**GarageBiy** es una aplicación de consola desarrollada en lenguaje **C**, que simula un sistema de **subastas digitales**.  
El proyecto busca demostrar la aplicación práctica de **Tipos de Datos Abstractos (TDAs)** en la gestión de información dinámica, asegurando eficiencia y modularidad en las operaciones de búsqueda, registro y actualización.

El sistema permite:
- Administrar usuarios (coordinadores y compradores).  
- Crear, visualizar y cerrar subastas.  
- Realizar y registrar ofertas.  
- Determinar automáticamente la oferta ganadora.  
- Mantener persistencia de datos mediante archivos CSV.

El diseño se basa en una arquitectura **Modelo–Vista–Controlador (MVC)**, separando la lógica de negocio, la gestión de datos y la interacción con el usuario.

---

## 👥 Tipos de Usuario

- **Coordinador:**  
  Administra las subastas y los usuarios. Puede crear, modificar o eliminar subastas, revisar estadísticas y cerrar procesos manualmente.

- **Comprador:**  
  Participa en subastas activas realizando ofertas, visualizando su historial y consultando productos ganados.

---

## 🧭 Flujo General de Uso

1. El usuario ingresa como **coordinador** o **comprador**.  
2. Accede al **menú principal**, que muestra las opciones correspondientes según su rol.  
3. Realiza acciones como crear subastas, ofertar o guardar datos.  
4. El sistema valida la entrada, muestra mensajes informativos y actualiza los TDAs internos.  
5. Antes de salir, se ofrece la opción de guardar el estado actual en archivos CSV.

---

## 📂 Estructura Técnica

### Arquitectura MVC

- **Modelo:**  
  Contiene los TDAs (listas, mapas hash, heap, pila) y estructuras (`struct`) que representan usuarios, subastas, productos y ofertas.  
- **Vista:**  
  Menús de consola jerárquicos que facilitan la interacción con el usuario.  
- **Controlador:**  
  Procesa las entradas del usuario y actualiza los datos del modelo, garantizando una comunicación fluida con la vista.

---

## 🧱 Estructuras de Datos (TDAs)

| TDA | Uso Principal | Complejidad Promedio |
|-----|----------------|----------------------|
| **HashMap** | Gestión de usuarios, subastas y etiquetas | O(1) |
| **Heap (cola con prioridad)** | Manejo de ofertas y selección del ganador | O(log n) |
| **List (lista enlazada)** | Historial de subastas y ofertas | O(n) |
| **Stack (pila)** | Control de acciones o función *undo* | O(1) |

**Justificación:**  
La combinación de estas estructuras permite mantener eficiencia, escalabilidad y claridad en el manejo de datos.  
El *HashMap* optimiza las búsquedas, el *Heap* prioriza las ofertas más altas, la *List* facilita la iteración dinámica y el *Stack* ofrece control temporal para futuras funcionalidades.

---

## 🧮 Principales Funcionalidades

- **Registrar subasta:** Crea una nueva subasta asociada a un producto.  
- **Buscar subasta:** Permite localizar subastas por ID o etiqueta.  
- **Realizar oferta:** Inserta una oferta en el *heap* de la subasta correspondiente.  
- **Finalizar subasta:** Determina el ganador automáticamente y actualiza el historial.  
- **Guardar/Cargar datos:** Persistencia mediante archivos CSV.  
- **Ver estadísticas:** Muestra métricas como total de subastas, promedio de ofertas y usuarios activos.

---

## 🗂️ Interacción con Archivos

Los datos se almacenan y cargan en formato **CSV**, lo que permite conservar el estado del sistema entre ejecuciones.

- `guardarCSV()`: exporta subastas, usuarios y ofertas.  
- `cargarCSV()`: reconstruye las estructuras en memoria.

---

## ⚙️ Complejidad Global del Sistema

| Operación | Complejidad |
|------------|-------------|
| Creación y registro de subasta | O(1) |
| Inserción y búsqueda de oferta | O(log n) |
| Búsqueda por ID o etiqueta | O(1) |
| Finalización de subasta | O(1) |

Estas características garantizan un rendimiento estable incluso ante un alto número de usuarios o subastas activas.

---

## 🧠 Planificación del Proyecto

### Etapas
1. **Análisis y planificación inicial**  
2. **Diseño de TDAs y estructuras**  
3. **Implementación modular (MVC)**  
4. **Diseño de menús e interacción**  
5. **Persistencia y manejo de archivos**  
6. **Optimización y depuración**  
7. **Documentación y validación final**

### Herramientas
- **Lenguaje:** C  
- **Control de versiones:** Git/GitHub  
- **Compilador:** GCC  
- **Entorno de desarrollo:** Visual Studio Code  

---

## 📈 Posibles Mejoras Futuras

- Incorporar **interfaz gráfica (GUI)** con GTK o Qt.  
- Conectar con una **base de datos SQL** para persistencia avanzada.  
- Implementar autenticación segura (hashing de contraseñas).  
- Ampliar estadísticas y reportes.  
- Añadir función **deshacer/rehacer** mediante *stack* de acciones.

---

## 🧾 Conclusión

El desarrollo de *GarageBiy* permitió aplicar conceptos teóricos de **estructuras de datos y algoritmos** en un contexto práctico, evidenciando cómo la elección de TDAs adecuados puede transformar la eficiencia de un sistema.  
El proyecto logró un balance entre claridad de diseño, eficiencia operativa y potencial de expansión, sirviendo como base sólida para futuras versiones con interfaz gráfica y soporte de bases de datos.

---

## 📚 Referencias

- Cormen, T. H. *Introduction to Algorithms*. MIT Press.  
- Weiss, M. A. *Data Structures and Algorithm Analysis in C*. Pearson.  
- Documentation C Standard Library: [https://en.cppreference.com/w/c](https://en.cppreference.com/w/c)

---

