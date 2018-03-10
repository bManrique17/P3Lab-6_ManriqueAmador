temp:	mainLab6.o Escenario.o Item.o Jugador.o Invisible.o Tren.o Bomba.o Espina.o Normal.o V.o
	g++ mainLab6.o Escenario.o Item.o Jugador.o Invisible.o Tren.o Bomba.o Espina.o Normal.o V.o -o temp

mainLab6.o:	mainLab6.cpp Escenario.h Item.h Jugador.h Invisible.h Tren.h Bomba.h Espina.h Normal.h V.h
	g++ mainLab6.cpp

Escenario.o:	Escenario.cpp Escenario.h
	g++ Escenario.cpp

Item.o:	Item.cpp Item.h
	g++ Item.cpp

Jugador.o:	Jugador.cpp Jugador.h Item.h
	g++ Jugador.cpp

Invisible.o:	Invisible.cpp Invisible.h Escenario.h
	g++ Invisible.cpp

Tren.o:	Tren.cpp Tren.h Escenario.h
	g++ Tren.cpp

Bomba.o:	Bomba.cpp Bomba.h Item.h
	g++ Bomba.cpp

Espina.o:	Espina.cpp Espina.h Bomba.h
	g++ Espina.cpp

Normal.o:	Normal.cpp Normal.h Bomba.h
	g++ Normal.cpp

V.o:	V.cpp V.h Bomba.h
	g++ V.cpp
