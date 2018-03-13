#include "Bomba.h"
#include "Item.h"

Bomba::Bomba(int x, int y) : Item(x,y){
    contadorExplosion = 3;
}

int Bomba::getContadorExplosion(){
    return contadorExplosion;
}
 
void Bomba::setContadorExplosion(int numero){
    contadorExplosion = numero;
}
