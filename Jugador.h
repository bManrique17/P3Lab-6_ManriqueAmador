
#include <string>
#include "Item.h"

#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;

class Jugador : public Item{
    public:
        Jugador();
        Jugador (string , int , int , int , int);
        void setNombre(string);
        void setEstado(int);
        void setTipoControlador(int);
        string getNombre();
        int getEstado();
        int getTipoControlador();
    private:
        string nombre;
        int estado;
        int tipoControlador;
};

#endif




