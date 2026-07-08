# Grafos-compactos

## Requisitos

- **Compilador C++** (recomendado: g++ de MinGW o similar)
- Biblioteca sdsl-lite con `pemb.cpp` configurado según detalles mencionados en el informe

## Compilación manual con g++

Abre una terminal en la raíz del proyecto y ejecuta:

### Compilar el ejecutable principal (`main`):

```sh
cd src
g++ -o main main.cpp turan.cpp lista_adyacencia.cpp -L/mnt/c/Users/chips/lib -I/mnt/c/Users/chips/include -lsdsl
```

### Compilar el ejecutable para transformar formato estándar a K2-Tree:

```sh
cd src
g++ -o format formatear_T.cpp -L/mnt/c/Users/chips/lib -I/mnt/c/Users/chips/include -lsdsl
```

## Ejecución

### Ejecutar el programa principal

Para ejecutar el main, donde se realizan los experimentos sobre degree(u) y neighbors(u,v) sobre nodos aleatorios:
```sh
./main <ruta_del_grafo>
```
- `<ruta_del_grafo>`: Ruta al archivo con formato estándar de grafos planares

### Formatear grafo

Para cambiar el formato de un grafo estándar a uno que pueda ser admitido por la implementación de K2-Tree:
```sh
./format <ruta_del_grafo> <ruta_salida>
```
- `<ruta_del_grafo>`: Ruta al archivo con formato estándar de grafos planares
- `<ruta_salida>`: Ruta donde se inyecta la salida de la transformación de formato

Esto creará un archivo binario el cual es compatible con la implementación K2-Tree de la Universidade da Coruña.
