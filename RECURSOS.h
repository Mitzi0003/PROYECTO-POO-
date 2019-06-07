#ifndef PRELIMINAR_RECURSOS_H
#define PRELIMINAR_RECURSOS_H

#include <iostream>
using namespace std;
    typedef char juego[7][7];
    typedef char juegoD[9][9];


    void inicializarJuegoIngles(juego tab);
    void mostrarTableroIngles(juego tab);
    void inicializarJuegoFrances(juego tab);
    void mostrarTableroFrances(juego tab);
    void inicializarJuegoDiamante(juegoD tab);
    void mostrarTableroDiamante(juegoD tab);


    int validarMovimiento(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juego tab);
    int validarMovimientoD(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juegoD tab);

    void mover(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juego tab);
    void moverD(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juegoD tab);

    void dejarGanarIngles(juego tab);
    void dejarGanarFrances(juego tab);
    void dejarGanarDiamante(juegoD tab);



    int hazGanado(juego tab);
    int hazGanado2(juegoD tab);

    void opcionesJugar();

void jugarIngles();
void jugarFrances();
void jugarDiamante();




#endif //PRELIMINAR_RECURSOS_H
