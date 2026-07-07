// g++ -o format formatear_T.cpp -L/mnt/c/Users/chips/lib -I/mnt/c/Users/chips/include -lsdsl
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

typedef unsigned long ulong;

int main(int argc, char **argv) {
    if (argc < 3) {
        cerr << "Uso: " << argv[0] << " <grafo.txt> <salida.pg>" << endl;
        return 1;
    }

    ifstream archivo(argv[1]);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo del grafo: " + string(argv[1]));
    }

    ofstream salida(argv[2], ios::binary);
    if (!salida.is_open()) {
        throw runtime_error("No se pudo crear el archivo de salida: " + string(argv[2]));
    }

    int numNodos;
    ulong numAristas;

    archivo >> numNodos;
    archivo >> numAristas;

    // Escribir cabecera
    salida.write(reinterpret_cast<char*>(&numNodos), sizeof(int));
    salida.write(reinterpret_cast<char*>(&numAristas), sizeof(ulong));

    int u, v;
    int ultimoNodo = -1;

    while (archivo >> u >> v) {
        // Escribir listas vacías de los nodos que no aparecen
        while (ultimoNodo < u) {
            ultimoNodo++;

            int marca = -(ultimoNodo + 1);
            salida.write(reinterpret_cast<char*>(&marca), sizeof(int));
        }

        // build_tree hace k--, por eso almacenamos v+1
        int vecino = v + 1;
        salida.write(reinterpret_cast<char*>(&vecino), sizeof(int));
    }

    // Completar los nodos restantes sin vecinos
    while (ultimoNodo < numNodos - 1) {
        ultimoNodo++;

        int marca = -(ultimoNodo + 1);
        salida.write(reinterpret_cast<char*>(&marca), sizeof(int));
    }

    archivo.close();
    salida.close();

    cout << "Archivo convertido correctamente en: " << argv[2] << endl;

    return 0;
}