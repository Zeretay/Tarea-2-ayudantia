//Nombre: Nicolas Alarcon Solis

include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "menu.h"
#include "Matriz.h"

int main(int argc, char** argv) {
    if (argc > 2) {
        std::string archivo_entrada(obtener_entrada(argv, argc));

        if (!archivo_entrada.empty()) {

            std::ifstream entrada(archivo_entrada); //lee el archivo
            std::string linea;
            while (std::getline(entrada, linea)) {
                Matriz matriz(linea);
                
                matriz.multiplicacion();
                linea.clear();
            }

            entrada.close();

            return EXIT_SUCCESS;
        } else {
            std::cerr << std::endl << "Error al determinar las rutas de los archivos de entrada " << archivo_entrada << std::endl;
            return EXIT_FAILURE;
        }
    } else {
        std::cerr << std::endl << "Argumentos insuficientes" << std::endl;
        std::cerr << std::endl << argv[0] << " -m /ruta/archivo/entrada.txt" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

