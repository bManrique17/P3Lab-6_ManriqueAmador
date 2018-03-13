#include <ncurses.h>
#include <string>
#include <iostream>


#include "Invisible.h"
#include "Tren.h"
#include "Bomba.h"
#include "Normal.h"
#include "Espina.h"
#include "V.h"
#include "Escenario.h"
#include "Jugador.h"
#include "Item.h"


using namespace std;


void imprimirMapa(Escenario* mapa);

int main(){

    initscr();

    start_color();

    

    Escenario* mapa = new Escenario("ASDGFJDH");
    Jugador* jugador = new Jugador("JUlicho",0,1,0,0);
    Jugador* boot1 = new Jugador("boot1",0,0,0,12);
    Jugador* boot2 = new Jugador("boot2",0,0,6,6);
    Jugador* boot3 = new Jugador("boot3",0,0,10,0);
    Jugador* boot4 = new Jugador("boot4",0,0,10,12);
    mapa->setItem(jugador,jugador->getX(),jugador->getY());    
    mapa->setItem(boot1,boot1->getX(),boot1->getY());
    mapa->setItem(boot2,boot2->getX(),boot2->getY());
    mapa->setItem(boot3,boot3->getX(),boot3->getY());
    mapa->setItem(boot4,boot4->getX(),boot4->getY());

    imprimirMapa(mapa);
    /*
    move(10,20);
    printw("asd");
    */
    getch();
    refresh();
    endwin();
    exit(1);
    return 0;
}

void imprimirMapa(Escenario* mapa){

    init_pair(1,COLOR_WHITE,COLOR_GREEN);
    init_pair(2,COLOR_WHITE,COLOR_WHITE);   

    for(int i=0 ; i<11 ; i++){
        for(int j=0 ; j<13 ; j++){
            attrset(COLOR_PAIR(1));
            move(i*2 + 2,j*5 + 5);
            if(i%2 != 0 && j%2 != 0){
                attrset(COLOR_PAIR(2));
            }
            Item* objeto = mapa->getItem(i,j);
            if(objeto != NULL){
                Jugador* objeto2 = dynamic_cast<Jugador*>(objeto);
                if(objeto2 != NULL)
                    if(objeto2->getTipoControlador() == 0)
                        printw("  B  ");
                    else
                        printw("  J  ");
            }else{
                printw("     ");    
            }
            
            move(i*2,j*5+5);
        }
    }
    


}

