#include <string>
#include "Tren.h"
#include "Escenario.h"

using namespace std;

Tren::Tren() : Escenario("adsfasd"){}

Tren::Tren(string nombre) : Escenario(nombre){    
    vagonX = 2;
    vagonY = 4;
}

int Tren::getVagonX(){
    return vagonX;
}

int Tren::getVagonY(){
    return vagonY;
}

void Tren::setVagonX(int x){
    vagonX = x;
}

void Tren::setVagonY(int y){
    vagonY = y;
}

        
      
  