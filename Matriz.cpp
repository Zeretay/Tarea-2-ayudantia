//Nombre: Nicolas Alarcons Solis

#include "Matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz() {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = 0;
            this->matriz_1[i][j] = 0;
            this->matriz_2[i][j] = 0;
        
        }
    }
}

Matriz::Matriz(const std::string& orig) {
    try {
        Matriz();
        std::string linea(orig.c_str());
        if (!linea.empty()) {
            linea.erase(std::remove(linea.begin(), linea.end(), '['), linea.end());
            linea.erase(std::remove(linea.begin(), linea.end(), ']'), linea.end());
            std::replace(linea.begin(), linea.end(), ';', ' ');
            std::replace(linea.begin(), linea.end(), ':', ' ');

            std::vector<std::string> arreglo;
            std::stringstream ss(linea);
            std::string temp;
            while (ss >> temp) {
                arreglo.push_back(temp);
            }

            for (int i = 0; i < 6; i++) {
                std::string fila = arreglo[i];
                std::replace(fila.begin(), fila.end(), ',', ' ');

                std::vector<std::string> columnas;
                std::stringstream sf(fila);
                std::string tmp;
                while (sf >> tmp) {
                    columnas.push_back(tmp);
                }
                if (i < 3){
                    for (int j = 0; j < LARGO; j++) {
                        std::string valor = columnas[j];
                        int numero = atoi(valor.c_str());
                        this->matriz_1[i][j] = numero;
                    }
                }
                else{
                    for (int j = 0; j < LARGO; j++) {
                        std::string valor = columnas[j];
                        int numero = atoi(valor.c_str());
                        this->matriz_2[i-3][j] = numero;
                    }
                }
                        
    
            }
        }
    } catch (...) {
        Matriz();
    }
}

Matriz::Matriz(const Matriz& orig) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz_1[i][j] = orig.matriz_1[i][j];
            this->matriz_2[i][j] = orig.matriz_2[i][j];
        }
    }
}

Matriz::~Matriz() {
}

void Matriz::multiplicacion() {
    cout << endl;
    cout <<  this->matriz_1[0][0] * this->matriz_2[0][0] + this->matriz_1[0][1] * this->matriz_2[1][0] + this->matriz_1[0][2] * this->matriz_2[2][0] << " ";
    cout <<  this->matriz_1[0][0] * this->matriz_2[0][1] + this->matriz_1[0][1] * this->matriz_2[1][1] + this->matriz_1[0][2] * this->matriz_2[2][1] << " ";
    cout <<  this->matriz_1[0][0] * this->matriz_2[0][2] + this->matriz_1[0][1] * this->matriz_2[1][2] + this->matriz_1[0][2] * this->matriz_2[2][2] << endl;
    cout <<  this->matriz_1[1][0] * this->matriz_2[0][0] + this->matriz_1[1][1] * this->matriz_2[1][0] + this->matriz_1[1][2] * this->matriz_2[2][0] << " ";
    cout <<  this->matriz_1[1][0] * this->matriz_2[0][1] + this->matriz_1[1][1] * this->matriz_2[1][1] + this->matriz_1[1][2] * this->matriz_2[2][1] << " ";
    cout <<  this->matriz_1[1][0] * this->matriz_2[0][2] + this->matriz_1[1][1] * this->matriz_2[1][2] + this->matriz_1[1][2] * this->matriz_2[2][2] << endl;
    cout <<  this->matriz_1[2][0] * this->matriz_2[0][0] + this->matriz_1[2][1] * this->matriz_2[1][0] + this->matriz_1[2][2] * this->matriz_2[2][0] << " ";
    cout <<  this->matriz_1[2][0] * this->matriz_2[0][1] + this->matriz_1[2][1] * this->matriz_2[1][1] + this->matriz_1[2][2] * this->matriz_2[2][1] << " ";
    cout <<  this->matriz_1[2][0] * this->matriz_2[0][2] + this->matriz_1[2][1] * this->matriz_2[1][2] + this->matriz_1[2][2] * this->matriz_2[2][2] << endl;
}
