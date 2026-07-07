#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cstdio>

class ListaAdyacencia {
private:
    std::vector<std::vector<int>> lista;

    int vertices = 0;
    int aristas = 0;

    std::vector<std::string> leerPorLineas(const std::string& nombreArchivo);

public:
    explicit ListaAdyacencia(std::string archivoGrafo);

    void agregarArista(int u, int v);

    void imprimirLista();

    int degree(int v);

    bool neighbors(int u, int v);

    size_t obtenerEspacio();
};