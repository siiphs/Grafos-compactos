#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

extern "C" {
    #include "hybrid_k2tree/kTree.h"
}

class k2tree {
   private:
      TREP * trep;

   public:
      explicit k2tree(std::string basename);

      bool neighbors(int u, int v);

      int degree(int v);

      size_t obtenerEspacio();
};
