#pragma once

#include <sdsl/pemb.hpp>
#include <complementary/Graph.hpp>
#include <complementary/utils.hpp>
#include <string>

class Turan {
private:
    sdsl::pemb<> pe;

public:
    explicit Turan(const std::string& archivoGrafo);

    bool neighbors(size_t u, size_t v);

    int degree(size_t v);

    size_t obtenerEspacio();

    int vertices();

    int aristas();
};