#include "Jugador.h"
#include "Item.h"
#include <string>

using namespace std;

Jugador::Jugador (){

}


Jugador::Jugador (string nombre , int estado , int tipoControlador ,int x , int y) : Item(x,y){
        this->nombre = nombre;
        this->estado = estado;
        this->tipoControlador = tipoControlador;
}
void Jugador::setNombre( string nombre ){
    this->nombre = nombre;
}

void Jugador::setEstado( int estado ){
    this->estado = estado;
}

void Jugador::setTipoControlador( int tipoControlador ){
    this->tipoControlador = tipoControlador;
}

//gfhkjl
string Jugador::getNombre( ){
    return nombre;
}

int Jugador::getEstado(){
    return  estado;
}

int Jugador::getTipoControlador(){
    return tipoControlador;
}
