#include <string>
#include "Item.h"

#ifndef ESCENARIO_H
#define ESCENARIO_H

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
        Item* getItem(int,int);
        void setItem(Item*,int,int);
        Item*** getMatriz();     
};

#endif








