#include <ncurses.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

#include "Invisible.h"
#include "Tren.h"
#include "Bomba.h"
#include "Normal.h"
#include "Espina.h"
#include "V.h"
#include "Escenario.h"
#include "Jugador.h"
#include "Item.h"
#include <sstream>

using namespace std;


void imprimirMapaINV(Escenario* mapa);
void imprimirMapaTREN(Escenario* mapa);
void explotarBombas(Escenario* mapa);
int ganar(Escenario* mapa);
void moverBoot(Jugador* boot,Escenario* mapa);
void Vagon(Jugador* boot,Escenario* mapa);


int alcanceActual = 0;
Bomba* bombaActualb = NULL;  

int main(){

    
    clear();
    initscr();
    int yMax,xMax;
	getmaxyx(stdscr,yMax,xMax);
	start_color();
    init_pair(6,COLOR_WHITE,COLOR_BLUE);
    init_pair(4,COLOR_BLACK,COLOR_RED);
    init_pair(5,COLOR_BLUE,COLOR_GREEN);
    attrset(COLOR_PAIR(4));
    printw("LAB_6 Manrique Amador");
    move(5/2,10);
    attrset(COLOR_PAIR(6));
    printw("COLOCAR BOMBAS CON LA BARRA ESPACEADORA");
	move(5,20);
    attrset(COLOR_PAIR(4));
    printw("Ingrese el nombre del escenario: ");
    string nombre;
	stringstream str;
    do{
        if(getch() == 10)
            break;
        
        int digito = getch();
        std::string cadena = "";
        cadena = static_cast<std::ostringstream*>(&(std::ostringstream() << digito))->str();               
        str<<cadena;
    }while(true);
    str>>nombre;
    clear();
    move(40,40);
    
    WINDOW* menuwin = newwin(9,xMax-12,2,5);
	box(menuwin,0,0);
	refresh();
	wrefresh(menuwin);
	
	keypad(menuwin, true);    
    
    attrset(COLOR_PAIR(5));
	string choices[2] = {"Tren","Invisible"};
	int choice;
	int highlight = 0;
	while(1){
		for(int i = 0;i<2;i++){
			if(i==highlight)
				wattron(menuwin, A_REVERSE);

			mvwprintw(menuwin,i+1,1,choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);

		switch(choice){
			case KEY_UP:
				highlight--;
				break;
			case KEY_DOWN:
				highlight++;
				break;
			default: 
				//highlight = 2;
				break;
		}
    printw("%d->",highlight);
        refresh();
		if(choice == 10)
			break;		
		
	}
    
	getch();
	endwin();
    start_color();
    int opcion = 0,tipo = 0;;
    
    Escenario* mapa = NULL;
    switch(highlight){
        case 0:{
            mapa = new Tren();            
            tipo = 1;
        }
        break;
        case 1:{
            mapa = new Invisible();
            tipo = 2;
        }
        break;                
    }
    clear();

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
           
    int tipoBomba = 1;
    int alcance = 2;

    

    if(tipo==1)                    
        imprimirMapaTREN(mapa);
    else
        imprimirMapaINV(mapa);
    refresh();

    Bomba* bombaActual = NULL;      
    


    while(true){
        alcanceActual = 3;
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

                    //poner bomba
                    if(bombaActual != NULL){
                        mapa->setItem(bombaActual,bombaActual->getX(),bombaActual->getY());
                        bombaActual = NULL;
                    }
                    if(tipo==1)                    
                        imprimirMapaTREN(mapa);
                    else
                        imprimirMapaINV(mapa);
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

                    //poner bomba
                    if(bombaActual != NULL){
                        mapa->setItem(bombaActual,bombaActual->getX(),bombaActual->getY());
                        bombaActual = NULL;
                    }

                    if(tipo==1)                    
                        imprimirMapaTREN(mapa);
                    else
                        imprimirMapaINV(mapa);
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

                    //poner bomba
                    if(bombaActual != NULL){
                        mapa->setItem(bombaActual,bombaActual->getX(),bombaActual->getY());
                        bombaActual = NULL;
                    }

                    if(tipo==1)                    
                        imprimirMapaTREN(mapa);
                    else
                        imprimirMapaINV(mapa);                }
            }
            break;
            case 32:{//poner bomba                
                switch(tipoBomba){
                    case 1:{
                        bombaActual = new Normal(jugador->getX(),jugador->getY());                        
                    }
                    break;
                    case 2:{
                        bombaActual = new Espina(jugador->getX(),jugador->getY());
                    }
                    break;
                    case 3:{
                        bombaActual = new V(jugador->getX(),jugador->getY());
                    }
                    mapa->getMatriz()[bombaActual->getX()][bombaActual->getY()] = bombaActual;
                    break;
                }
            }
            
        }//final switch
                
        if(tipo==1)
            Vagon(jugador,mapa);

        bool b1 = false,b2 = false,b3 = false,b4 = false;
        for(int i=0 ; i<11 ; i++){
            for(int j=0 ; j<13 ; j++){            
                Item* objeto = mapa->getItem(i,j);
                if(objeto != NULL){
                    Jugador* objeto2 = dynamic_cast<Jugador*>(objeto);
                    if(objeto2 != NULL){                    
                        string salida = objeto2->getNombre();
                        if(salida == boot1->getNombre())
                            b1=true;
                        if(salida == boot2->getNombre())
                            b2=true;
                        if(salida == boot3->getNombre())
                            b3=true;
                        if(salida == boot4->getNombre())
                            b4=true;
                    }
                }                                
            }
        }
        if(b1){
            if(tipo==1)
                Vagon(boot1,mapa);
            moverBoot(boot1,mapa);            
        }
        
        if(b2){
            if(tipo==1)
                Vagon(boot2,mapa);
            moverBoot(boot2,mapa);
        }
        
        if(b3){
            if(tipo==1)
                Vagon(boot3,mapa);
            moverBoot(boot3,mapa);
        }
        
        if(b4){
            if(tipo==1)
                Vagon(boot4,mapa);
            moverBoot(boot4,mapa);
        }

        explotarBombas(mapa);

        if(tipo==1)                    
            imprimirMapaTREN(mapa);
        else
            imprimirMapaINV(mapa);
        entrada = 0;
        int senuelo = 0;
        switch(ganar(mapa)){
            case 0:
                senuelo=17;
            break;
            case 2:
                move(0,0);
                printw("HA GANADO!");
                getch();
            break;
            case 3:
                move(0,0);
                printw("HA PERDIDO :(");
                getch();
            break;
        }
        if(senuelo!=17)
            break;
    }//fin while
    move(0,0);
    printw("FIN");
    getch();
    endwin();
    exit(1);
    return 0;
}

void imprimirMapaINV(Escenario* mapa){

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
                }else{
                    printw("*bum*");
                }
            }else{
                printw("     ");    
            }
            
            move(i*2,j*5+5);
        }
    }
    
    refresh();

}

void explotarBombas(Escenario* mapa){
    
    init_pair(3,COLOR_RED,COLOR_RED); 
    
    for(int i=0 ; i<11 ; i++){
        for(int j=0 ; j<13 ; j++){ 
            
            move(i*2 + 2,j*5 + 5);
            Item* bomba = mapa->getItem(i,j);
            if(bomba != NULL){   
                                 
                Bomba* bomba2 = dynamic_cast<Bomba*>(bomba);
                if(bomba2 != NULL){
                    
                    bomba2->setContadorExplosion(bomba2->getContadorExplosion() - 1);
                    if(bomba2->getContadorExplosion()==0){
                                                
                        //int alcance = bomba3->getAlcance();
                        int alcance = alcanceActual;
                        int cont=0;
                        attrset(COLOR_PAIR(3));
                        printw("  +  ");
                        mapa->setItem(NULL,i,j);
                        for(int k = 0; k<alcance ; k++){


                            if(i+k<11){     
                                if(mapa->getItem((i+k),j) != NULL)                      
                                    delete mapa->getItem((i+k),j);
                                mapa->setItem(NULL,(i+k),j);                                
                            }

                            if(i-k>=0){
                                if(mapa->getItem((i-k),j) != NULL)
                                    delete mapa->getItem((i-k),j);                           
                                mapa->setItem(NULL,(i-k),j);                                
                            }

                            if(j+k<13){             
                                if(mapa->getItem((i),j+k) != NULL)    
                                    delete mapa->getItem((i),j+k);          
                                mapa->setItem(NULL,i,j+k);                                
                            }

                            if(j-k>=0){                 
                                if(mapa->getItem(i,j-k) != NULL)    
                                    delete mapa->getItem(i,j-k);      
                                mapa->setItem(NULL,i,j-k);                                
                            }                                                                                        
                        }
                            
                        refresh();
                        usleep(1000000/3);
                        
                        
                    }
                                        
                }
            }
            move(i*2,j*5+5);
        }//for j
        
    }    
    //usleep(1000000);
}

int ganar(Escenario* mapa){
    int contJugador = 0,senueloJJ = 0;
    for(int i=0 ; i<11 ; i++){
        for(int j=0 ; j<13 ; j++){
            Item* objeto = mapa->getItem(i,j);
            if(objeto != NULL){
                Jugador* objeto2 = dynamic_cast<Jugador*>(objeto);
                if(objeto2 != NULL){
                    if(objeto2->getNombre() == "  J  "){
                        senueloJJ = 1;                        
                    }else{
                        contJugador++;
                    }
                    
                }                                                       
            }
        }
    }
    if(senueloJJ == 1 && contJugador>0){
        return 0;
    }else{
        if(senueloJJ == 1 && contJugador==0){
            return 2;
        }else{
            return 3;
        }
    }
        
}

void moverBoot(Jugador* jugador, Escenario* mapa){
    int direccion = rand() % 4 +1;
    int ponerBomba = rand() % 7 + 1;
    int futX, futY;
    switch(direccion){
        case 1:{//w
            futX = jugador->getX()-1;   
            futY = jugador->getY();

            if(futX<0 || futX>10 || futY<0 || futY>12)
                break;

            if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){                    
                jugador->setX(futX);
                jugador->setY(futY);
                mapa->setItem(NULL,jugador->getX()+1,jugador->getY());
                mapa->setItem(jugador,jugador->getX(),jugador->getY());
            }          
        }
        break;
        case 2:{//d                
            futX = jugador->getX();   
            futY = jugador->getY()+1;

            if(futX<0 || futX>10 || futY<0 || futY>12)
                break;

            if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){
                jugador->setX(futX);
                jugador->setY(futY);
                mapa->setItem(NULL,jugador->getX(),jugador->getY()-1);
                mapa->setItem(jugador,jugador->getX(),jugador->getY());
                
            }
        }
        break;
        case 3:{//a               
            futX = jugador->getX();   
            futY = jugador->getY()-1;

            if(futX<0 || futX>10 || futY<0 || futY>12)
                break;

            if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){
                jugador->setX(futX);
                jugador->setY(futY);
                mapa->setItem(NULL,jugador->getX(),jugador->getY()+1);
                mapa->setItem(jugador,jugador->getX(),jugador->getY());                                               
            }
        }
        break;
        case 4:{//s   
            futX = jugador->getX()+1;   
            futY = jugador->getY();        

            if(futX<0 || futX>10 || futY<0 || futY>12)
                break;

            if( !(futX%2 != 0 && futY%2 != 0) && mapa->getMatriz()[futX][futY] == NULL){                    
                jugador->setX(futX);
                jugador->setY(futY);
                mapa->setItem(NULL,jugador->getX()-1,jugador->getY());
                mapa->setItem(jugador,jugador->getX(),jugador->getY());                           
            }
        }
        break;
        }
        if(bombaActualb != NULL && mapa->getMatriz()[bombaActualb->getX()][bombaActualb->getY()] == NULL){
            mapa->setItem(bombaActualb,bombaActualb->getX(),bombaActualb->getY());
            bombaActualb = NULL;
        }

        if(ponerBomba == 1){
            int xd = 1;
            switch(xd){
                case 1:{
                    bombaActualb = new Normal(jugador->getX(),jugador->getY());                        
                }
                break;
                case 2:{
                    bombaActualb = new Espina(jugador->getX(),jugador->getY());
                }
                break;
                case 3:{
                    bombaActualb = new V(jugador->getX(),jugador->getY());
                }
                mapa->getMatriz()[bombaActualb->getX()][bombaActualb->getY()] = bombaActualb;
                break;
            }
                
        }
    }

    void Vagon(Jugador* jug,Escenario* mapa){
        if(jug->getX()==2 && jug->getY()==2){
            mapa->setItem(jug,8,2-1);
            jug->setX(8);
            jug->setY(2-1);
            for(int i=0;i<6;i++){
                mapa->setItem(NULL,2,2+i);
            }
            for(int i=0;i<6;i++){
                mapa->setItem(NULL,8,2+i);
            }
            for(int i=0;i<4;i++){
                mapa->setItem(NULL,3+i,8);
            }
        }else{
            if(jug->getX()==8 && jug->getY()==2){
                mapa->setItem(jug,2,2-1);
                jug->setX(2);
                jug->setY(2-1);
                for(int i=0;i<6;i++){
                    mapa->setItem(NULL,2,2+i);
                }
                for(int i=0;i<6;i++){
                    mapa->setItem(NULL,8,2+i);
                }
                for(int i=0;i<4;i++){
                    mapa->setItem(NULL,3+i,8);
                }
            }else{

            }        
        }
    }

    void imprimirMapaTREN(Escenario* mapa){
        init_pair(1,COLOR_YELLOW,COLOR_WHITE);
        init_pair(2,COLOR_RED,COLOR_CYAN);   
        init_pair(3,COLOR_WHITE,COLOR_MAGENTA);

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
                if(   (j>1&&j<8&&i==2) ||
                        (j>1&&j<8&&i==8) ||
                        (i>2&&i<8&&j==8) )                                            
                    attrset(COLOR_PAIR(3));
                else
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
                    }else{
                        printw("*bum*");
                    }
                }else{
                    printw("     ");    
                }
                
                move(i*2,j*5+5);
            }
        }
        
        refresh();

    }   


