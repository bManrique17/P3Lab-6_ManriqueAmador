
#include "Espina.h"
#include "Bomba.h"
#include <string>

Espina::Espina (int x, int y):Bomba(x,y){}

Espina::Espina (int bombasPuestas ,int x, int y):Bomba(x,y){
        this->bombasPuestas = bombasPuestas;
}
void Espina::setBombasPuestas( int bombasPuestas){
    this->bombasPuestas = bombasPuestas;
}

int Espina::getBombasPuestas(){
    return bombasPuestas;
}