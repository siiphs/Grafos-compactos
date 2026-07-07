#include "turan.hpp"

using namespace sdsl;
using namespace std;

Turan::Turan(const std::string& archivoGrafo)
    : pe(read_graph_from_file(archivoGrafo.c_str())) {}

bool Turan::neighbors(size_t u, size_t v) {
    return pe.neighbors(u, v);
}

int Turan::degree(size_t v) {
    return pe.degree(v);
}

size_t Turan::obtenerEspacio() {
    return pe.size_bitvectorA()
         + pe.size_bitvectorB()
         + pe.size_bitvectorm_B_st();
}

int Turan::vertices() {
    return pe.vertices();
}

int Turan::aristas() {
    return pe.edges();
}