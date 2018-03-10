#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <string>
#include "Item.h"

using namespace std;

class Escenario {
    private:       
        string nombre;
        Item*** matriz;
    public:
        Escenario ();
        Escenario (string);
        void setNombre(string nombre);
        string getNombre();
        Item*** getMatriz();     
};

#endif








