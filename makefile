temp:	mainLab6.o Escenario.o Item.o Jugador.o Invisible.o Tren.o Bomba.o Espina.o Normal.o V.o
	g++ mainLab6.o Escenario.o Item.o Jugador.o Invisible.o Tren.o Bomba.o Espina.o Normal.o V.o -lncurses -o temp

mainLab6.o:	mainLab6.cpp
	g++ -c -std=c++11 mainLab6.cpp

Escenario.o:	Escenario.cpp Escenario.h Item.h
	g++ -c -std=c++11 Escenario.cpp

Item.o:	Item.cpp Item.h
	g++ -c -std=c++11 Item.cpp

Jugador.o:	Jugador.cpp Jugador.h Item.h
	g++ -c -std=c++11 Jugador.cpp

Invisible.o:	Invisible.cpp Invisible.h Escenario.h
	g++ -c -std=c++11 Invisible.cpp

Tren.o:	Tren.cpp Tren.h Escenario.h
	g++ -c -std=c++11 Tren.cpp

Bomba.o:	Bomba.cpp Bomba.h Item.h
	g++ -c -std=c++11 Bomba.cpp

Espina.o:	Espina.cpp Espina.h Bomba.h
	g++ -c -std=c++11 Espina.cpp

Normal.o:	Normal.cpp Normal.h Bomba.h
	g++ -c -std=c++11 Normal.cpp

V.o:	V.cpp V.h Bomba.h
	g++ -c -std=c++11 V.cpp