#include "Escenario.h"
#include <string>
#include "Item.h"
#include <iostream>

using namespace std;

Escenario::Escenario(){}

Escenario::Escenario (string nombre){
        this->nombre = nombre;
        matriz = new Item**[11];
        for(int i=0 ; i<11 ; i++){
            matriz[i] = new Item*[13];
            for(int j = 0 ; j<13 ; j++){
                matriz[i][j] = NULL;
            }
        }
}

void Escenario::setNombre( string nombre ){
    this->nombre = nombre;
}

Item*** Escenario::getMatriz(){
    return matriz;
}

string Escenario::getNombre(){
    return nombre;
}
