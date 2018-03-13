#include <string>
#include "Bomba.h"
#include "Normal.h"
#include "Item.h"

Normal::Normal (int x, int y):Bomba(x,y){

}


int Normal::getAlcance(){
    //generar alatorio
    //BORRAR
    alcance = 3;
    return alcance;
}