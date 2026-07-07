// g++ -o main main.cpp turan.cpp lista_adyacencia.cpp -L/mnt/c/Users/chips/lib -I/mnt/c/Users/chips/include -lsdsl
#include "turan.hpp"
#include "lista_adyacencia.hpp"
#include <random>
#include <iostream>
#include <chrono>
#include <numeric>

using namespace sdsl;
using namespace std;

int main(int argc, char **argv) {
  Turan pe(argv[1]);
  ListaAdyacencia lista(argv[1]);

  vector<double> tiempos_degree_turan;
  vector<double> tiempos_neighbor_turan;

   cout << "Implementación;Operación;Dataset;Tiempo(microsegundos);Espacio(bytes)" << endl;

   // Tomar el tiempo de degree
   for(int i = 0; i < 30; i++){
      auto start = chrono::high_resolution_clock::now();
      for(int j = 0; j < 1000; j++){
         int vertice_seleccionado = rand() % pe.vertices();
         pe.degree(vertice_seleccionado);     
      }
      auto end = chrono::high_resolution_clock::now();
      double duracion_promedio = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
      tiempos_degree_turan.push_back(duracion_promedio);
      cout << "Turán" << ";" << "degree" << ";" << argv[1] << ";" << duracion_promedio << ";" << pe.obtenerEspacio() << endl;
   }
   double tiempo_promedio_degree_T = accumulate(tiempos_degree_turan.begin(), tiempos_degree_turan.end(), 0.0) / 30;
   //cout << "Tiempo promedio de degree (Turán): " << tiempo_promedio_degree << " microsegundos" << endl;

   // Tomar el tiempo de neighbor
   for(int i = 0; i < 30; i++){
      auto start = chrono::high_resolution_clock::now();
      for(int j = 0; j < 1000; j++){
         int vertice_seleccionado1 = rand() % pe.vertices();
         int vertice_seleccionado2 = rand() % pe.vertices();
         pe.neighbors(vertice_seleccionado1, vertice_seleccionado2);
      }
      auto end = chrono::high_resolution_clock::now();
      double duracion_promedio = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
      tiempos_neighbor_turan.push_back(duracion_promedio);
      cout << "Turán" << ";" << "neighbor" << ";" << argv[1] << ";" << duracion_promedio << ";" << pe.obtenerEspacio() << endl;
   }
   double tiempo_promedio_neighbor_T = accumulate(tiempos_neighbor_turan.begin(), tiempos_neighbor_turan.end(), 0.0) / 30;
   //cout << "Tiempo promedio de neighbor (Turán): " << tiempo_promedio_neighbor << " microsegundos" << endl;

   vector<double> tiempos_degree_lista;
   vector<double> tiempos_neighbor_lista;

   for(int i = 0; i < 30; i++){
      auto start = chrono::high_resolution_clock::now();
      for(int j = 0; j < 1000; j++){
         int vertice_seleccionado = rand() % pe.vertices();
         lista.degree(vertice_seleccionado);     
      }
      auto end = chrono::high_resolution_clock::now();
      double duracion_promedio = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
      tiempos_degree_lista.push_back(duracion_promedio);
      cout << "Lista de Adyacencia" << ";" << "degree" << ";" << argv[1] << ";" << duracion_promedio << ";" << lista.obtenerEspacio() << endl;
   }
   double tiempo_promedio_degree_LA = accumulate(tiempos_degree_lista.begin(), tiempos_degree_lista.end(), 0.0) / 30;
   //cout << "Tiempo promedio de degree (Lista de Adyacencia): " << tiempo_promedio_degree << " microsegundos" << endl;

   // Tomar el tiempo de neighbor
   for(int i = 0; i < 30; i++){
      auto start = chrono::high_resolution_clock::now();
      for(int j = 0; j < 1000; j++){
         int vertice_seleccionado1 = rand() % pe.vertices();
         int vertice_seleccionado2 = rand() % pe.vertices();
         lista.neighbors(vertice_seleccionado1, vertice_seleccionado2);
      }
      auto end = chrono::high_resolution_clock::now();
      double duracion_promedio = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
      tiempos_neighbor_lista.push_back(duracion_promedio);
      cout << "Lista de Adyacencia" << ";" << "neighbor" << ";" << argv[1] << ";" << duracion_promedio << ";" << lista.obtenerEspacio() << endl;
   }
   double tiempo_promedio_neighbor_LA = accumulate(tiempos_neighbor_lista.begin(), tiempos_neighbor_lista.end(), 0.0) / 30;
   //cout << "Tiempo promedio de neighbor (Lista de Adyacencia): " << tiempo_promedio_neighbor << " microsegundos" << endl;
}