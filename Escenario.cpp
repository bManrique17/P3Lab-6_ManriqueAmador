#include "Escenario.h"
#include <string>
#include <iostream>

using namespace std;

Escenario::Escenario(){
   
}

Escenario::Escenario (string nombre){
        this->nombre = nombre;
        matriz = new Item**[11];
        for(int i=0 ; i<11 ; i++){
            matriz[i] = new Item*[13];
            for(int j = 0 ; j<13 ; j++){
                if(i%2 != 0 && j%2 != 0)
                    matriz[i][j] = NULL;
            }
        }
}

Item* Escenario::getItem(int x,int y){
    return matriz[x][y];
}

void Escenario::setItem(Item* item,int x,int y){
    matriz[x][y] = item;
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
