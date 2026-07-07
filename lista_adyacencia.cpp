#include "lista_adyacencia.hpp"

using namespace std;

vector<string> ListaAdyacencia::leerPorLineas(const string& nombreArchivo) {
    vector<string> lineas;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo del grafo: " + nombreArchivo);
    }

    string linea;

    if (getline(archivo, linea))
        vertices = stoi(linea);

    if (getline(archivo, linea))
        aristas = stoi(linea);

    while (getline(archivo, linea)) {
        if (!linea.empty())
            lineas.push_back(linea);
    }

    return lineas;
}

ListaAdyacencia::ListaAdyacencia(string archivoGrafo) {
    vector<string> lineas = leerPorLineas(archivoGrafo);

    lista.resize(vertices);

    for (auto linea : lineas) {
        int u, v;
        sscanf(linea.c_str(), "%d %d", &u, &v);
        agregarArista(u, v);
    }

    for (auto &vec : lista)
        sort(vec.begin(), vec.end());
}

void ListaAdyacencia::agregarArista(int u, int v) {
    lista[u].push_back(v);
}

void ListaAdyacencia::imprimirLista() {
    for (size_t i = 0; i < lista.size(); i++) {
        cout << "Vertice " << i << ": ";
        for (int x : lista[i])
            cout << x << " ";
        cout << endl;
    }
}

int ListaAdyacencia::degree(int v) {
    return lista[v].size();
}

bool ListaAdyacencia::neighbors(int u, int v) {
    return binary_search(lista[u].begin(), lista[u].end(), v);
}

size_t ListaAdyacencia::obtenerEspacio() {
    size_t total = 0;
    total += sizeof(lista);

    for (const auto& l : lista) {
        total += sizeof(vector<int>);
        total += l.capacity() * sizeof(int);
    }
    
    return total;
}
