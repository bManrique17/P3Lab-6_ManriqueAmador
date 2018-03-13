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
    Jugador* jugador = new Jugador("  J  ",0,1,0,0);
    Jugador* boot1 = new Jugador(" B 1 ",0,0,0,12);
    Jugador* boot2 = new Jugador(" B 2 ",0,0,6,6);
    Jugador* boot3 = new Jugador(" B 3 ",0,0,10,0);
    Jugador* boot4 = new Jugador(" B 4 ",0,0,10,12);
    mapa->setItem(jugador,jugador->getX(),jugador->getY());    
    mapa->setItem(boot1,boot1->getX(),boot1->getY());
    mapa->setItem(boot2,boot2->getX(),boot2->getY());
    mapa->setItem(boot3,boot3->getX(),boot3->getY());
    mapa->setItem(boot4,boot4->getX(),boot4->getY());
       
    imprimirMapa(mapa);
    refresh();
    while(true){
        int entrada = getch();
        int futX,futY;
        switch(entrada){
            case 119:{//w
                futX = jugador->getX()-1;   
                futY = jugador->getY();

                if(futX<0 || futX>10 || futY<0 || futY>12)
                    break;

                if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){                    
                    jugador->setX(futX);
                    jugador->setY(futY);
                    mapa->setItem(NULL,jugador->getX()+1,jugador->getY());
                    mapa->setItem(jugador,jugador->getX(),jugador->getY());
                    imprimirMapa(mapa);      
                }          
            }
            break;
            case 100:{//d                
                futX = jugador->getX();   
                futY = jugador->getY()+1;

                if(futX<0 || futX>10 || futY<0 || futY>12)
                    break;

                if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){
                    jugador->setX(futX);
                    jugador->setY(futY);
                    mapa->setItem(NULL,jugador->getX(),jugador->getY()-1);
                    mapa->setItem(jugador,jugador->getX(),jugador->getY());
                    imprimirMapa(mapa);
                }
            }
            break;
            case 97:{//a               
                futX = jugador->getX();   
                futY = jugador->getY()-1;

                if(futX<0 || futX>10 || futY<0 || futY>12)
                    break;

                if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){
                    jugador->setX(futX);
                    jugador->setY(futY);
                    mapa->setItem(NULL,jugador->getX(),jugador->getY()+1);
                    mapa->setItem(jugador,jugador->getX(),jugador->getY());
                    imprimirMapa(mapa);
                }
            }
            break;
            case 115:{//s   
                futX = jugador->getX()+1;   
                futY = jugador->getY();        

                if(futX<0 || futX>10 || futY<0 || futY>12)
                    break;

                if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){                    
                    jugador->setX(futX);
                    jugador->setY(futY);
                    mapa->setItem(NULL,jugador->getX()-1,jugador->getY());
                    mapa->setItem(jugador,jugador->getX(),jugador->getY());
                    imprimirMapa(mapa);            
                }
            }
            break;

        }
        entrada = 0;
    }
    getch();
    
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
            
                printw("     ");    
            
            
            move(i*2,j*5+5);
        }
    }


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
                if(objeto2 != NULL){
                
                    string salida = objeto2->getNombre();
                    for(int k=0 ; k<5 ; k++){
                        char l = salida[k];
                        printw("%c",l);
                    }                    
                }
            }else{
                printw("     ");    
            }
            
            move(i*2,j*5+5);
        }
    }
    
    refresh();

}

