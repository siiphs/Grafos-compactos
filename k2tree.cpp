//    
#include "K2Tree.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>

k2tree::k2tree(std::string basename) {
   trep = loadTreeRepresentation(const_cast<char*>(basename.c_str()));
}

int k2tree::degree(int v) {
   uint* listaady = compactTreeAdjacencyList(trep, v);
   int grado = listaady[0];
   free(listaady);
   return grado;
}

bool k2tree::neighbors(int u, int v) {
   uint* listaady = compactTreeAdjacencyList(trep, u);
   int grado = listaady[0];
   bool esVecino = false;
   for (int i = 1; i <= grado; i++) {
      if (listaady[i] == v) {
         esVecino = true;
         break;
      }
   }
   free(listaady);
   return esVecino;
}

int main(int argc, char **argv) {
   k2tree k2(argv[1]);
   int u = std::atoi(argv[2]);
   int v = std::atoi(argv[3]);

   std::cout << "GRADO U: " << k2.degree(u) << std::endl;
   std::cout << "GRADO V: " << k2.degree(v) << std::endl;
   std::cout << "SON VECINOS: " << k2.neighbors(u, v) << std::endl;
   return 0;
}