
#include "Invisible.h"
#include <string>
#include "Escenario.h"
#include <iostream>

using namespace std;

Invisible::Invisible(){}

Invisible::Invisible (string nombre, int numeroVidas , int tipoBomba) : Escenario(nombre){
    this->numeroVidas = numeroVidas;
    this->tipoBomba = tipoBomba;
}

void Invisible::setNumeroVidas( int numeroVidas ){
    this->numeroVidas = numeroVidas;
}

void Invisible::setTipoBomba( int tipoBomba ){
    this->tipoBomba = tipoBomba;
}

int Invisible::getNumeroVidas(){
    return numeroVidas;
}

int Invisible::getTipoBomba(){
    return tipoBomba;
}