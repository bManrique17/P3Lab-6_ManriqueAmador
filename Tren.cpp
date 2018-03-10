#include <string>
#include "Tren.h"
#include "Escenario.h"

using namespace std;

Tren::Tren() : Escenario(){}

Tren::Tren(string nombre) : Escenario(nombre){
    posicionActualVagon = "4,2";
}

string Tren::getPosicionActualVagon(){
    return posicionActualVagon;
}

void Tren::setPosicionActualVagon(string pos){
    posicionActualVagon = pos;
}
        
      
  