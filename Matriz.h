#ifndef MATRIZ_H
#define MATRIZ_H

#define LARGO 3

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

class Matriz {
public:
    Matriz();
    Matriz(const std::string& orig);
    Matriz(const Matriz& orig);
    virtual ~Matriz();

    void multiplicacion();
private:
    int matriz[LARGO][LARGO];
    int matriz_1[LARGO][LARGO];
    int matriz_2[LARGO][LARGO];
    int matriz_resultado[LARGO][LARGO];
};

#endif /* MATRIZ_H */

