#include "RECURSOS.h"
#include <iostream>

using namespace std;

    typedef char juego[7][7];
    typedef char juegoD[9][9];


    void inicializarJuegoIngles(juego tab){
        int fila, columna;

        for (fila = 0; fila < 7; fila++)
        {
            for (columna = 0; columna < 7; columna++)
            {
                if (fila == 3 && columna == 3)
                {
                    tab[fila][columna] = ' ';
                }else{
                    if( (fila < 2 || fila > 4)&&(columna < 2 || columna > 4) ){
                        tab[fila][columna] = '"';
                    }else{
                        tab[fila][columna] = 'O';
                    }
                }
            }
        }
    }

    void inicializarJuegoFrances(juego tab) {
        int fila, columna;

        for (fila = 0; fila < 7; fila++) {
            for (columna = 0; columna < 7; columna++) {
                tab[fila][columna] = 'O';
            }
        }
        for (fila = 0; fila < 7; fila++) {
            for (columna = 0; columna < 7; columna++) {
                if (fila == 2 && columna == 3) {
                    tab[fila][columna] = ' ';
                }
                else {
                    if ((fila == 1 || fila == 5)) {
                        if (columna == 0 || columna == 6) {
                            tab[fila][columna] = '"';
                        }
                    }
                    if ((fila == 0 || fila == 6)) {
                        if (columna < 2 || columna > 4) {
                            tab[fila][columna] = '"';
                        }
                    }
                }
            }

        }
    }

    void inicializarJuegoDiamante(juegoD tab) {
    int fila, columna;

    for (fila = 0; fila < 9; fila++) {
        for (columna = 0; columna < 9; columna++) {
            tab[fila][columna] = 'O';
        }
    }
    for (fila = 0; fila < 9; fila++) {
        for (columna = 0; columna < 9; columna++) {
            if (fila == 4 && columna == 4) {
                tab[fila][columna] = ' ';
            }
            else {
                if ((fila == 0 || fila == 8)) {
                    if (columna != 4) {
                        tab[fila][columna] = '"';
                    }
                }
                if ((fila == 1 || fila == 7)) {
                    if (columna < 3 || columna > 5) {
                        tab[fila][columna] = '"';
                    }
                }
                if ((fila == 2 || fila == 6)) {
                    if (columna < 2 || columna > 6) {
                        tab[fila][columna] = '"';
                    }
                }
                if ((fila == 3 || fila == 5)) {
                    if (columna == 0 || columna == 8) {
                        tab[fila][columna] = '"';
                    }
                }
            }
        }

    }
}



void mostrarTableroIngles(juego tab){
        int fila, columna, aux;

        for (fila = 0; fila < 7; fila++)
        {
            if (fila == 0)
            {
                for (aux = 0; aux <= 7; aux++)
                {
                    if (aux == 0)
                    {
                        cout<<"-" ;
                    }else{
                        cout << "   " << aux;
                    }
                }
                cout <<"\n";
            }
            cout << fila + 1;
            for (columna = 0; columna < 7; columna++)
            {
                cout << "   " << tab[fila][columna];
            }
            cout << "\n";
        }
    }

void mostrarTableroFrances(juego tab){
    int fila, columna, aux;

    for (fila = 0; fila < 7; fila++)
    {
        if (fila == 0)
        {
            for (aux = 0; aux <= 7; aux++)
            {
                if (aux == 0)
                {
                    cout <<"-";
                }else{
                    cout << "   " << aux;
                }
            }
            cout <<"\n";
        }
        cout << fila + 1;
        for (columna = 0; columna < 7; columna++)
        {
            cout << "   " << tab[fila][columna];
        }
        cout << "\n";
    }
}

void mostrarTableroDiamante(juegoD tab){
    int fila, columna, aux;

    for (fila = 0; fila < 9; fila++)
    {
        if (fila == 0)
        {
            for (aux = 0; aux <= 9; aux++)
            {
                if (aux == 0)
                {
                    cout <<"-";
                }else{
                    cout << "   " << aux;
                }
            }
            cout <<"\n";
        }
        cout << fila + 1;
        for (columna = 0; columna < 9; columna++)
        {
            cout << "   " << tab[fila][columna];
        }
        cout << "\n";
    }
}


int validarMovimiento(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juego tab){
        if (tab[moverFila-1][moverColumna-1] == 'O')
        {
            if ((moverFila < 1 || moverFila > 7) && (destinoFila < 1 ||  destinoColumna > 7))
            {
                return 0;
            }else{
                if (moverFila == destinoFila && moverColumna == destinoColumna)
                {
                    return 0;
                }else{
                    if (moverFila == destinoFila || moverColumna == destinoColumna)
                    {
                        if ((moverFila - destinoFila == 2 || moverFila - destinoFila == -2) || (moverColumna - destinoColumna == 2 || moverColumna - destinoColumna == -2))
                        {
                            if (tab[destinoFila - 1][destinoColumna - 1] == 'O' || tab[destinoFila - 1][destinoColumna - 1] == '"')
                            {
                                return 0;
                            }else{
                                return 1;
                            }
                        }else{
                            return 0;
                        }
                    }else{
                        return 0;
                    }
                }
            }
        }else{
            return 0;
        }
    }

int validarMovimientoD(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juegoD tab){
    if (tab[moverFila-1][moverColumna-1] == 'O')
    {
        if ((moverFila < 1 || moverFila > 9) && (destinoFila < 1 ||  destinoColumna > 9))
        {
            return 0;
        }else{
            if (moverFila == destinoFila && moverColumna == destinoColumna)
            {
                return 0;
            }else{
                if (moverFila == destinoFila || moverColumna == destinoColumna)
                    if ((moverFila - destinoFila == 2 || moverFila - destinoFila == -2) || (moverColumna - destinoColumna == 2 || moverColumna - destinoColumna == -2))
                    {
                        if (tab[destinoFila - 1][destinoColumna - 1] == 'O' || tab[destinoFila - 1][destinoColumna - 1] == '"')
                        {
                            return 0;
                        }else{
                            return 1;
                        }
                    }else{
                        return 0;
                    }
                }else{
                    return 0;
                }
            }
        }
    }else{
        return 0;
    }
}


    void mover(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juego tab){
        tab[moverFila - 1][moverColumna - 1] = ' ';
        tab[destinoFila - 1][destinoColumna - 1] = 'O';

        if (moverFila == destinoFila)
        {
            if (moverColumna < destinoColumna)
            {
                tab[moverFila - 1][moverColumna] = ' ';
            }else{
                tab[moverFila - 1][moverColumna - 2] = ' ';
            }
        }else{
            if (moverColumna == destinoColumna)
            {
                if (moverFila < destinoFila)
                {
                    tab[moverFila][moverColumna - 1] = ' ';
                }else{
                    tab[moverFila - 2][moverColumna - 1] = ' ';
                }
            }
        }
    }

    void moverD(int moverFila, int moverColumna, int destinoFila, int destinoColumna, juegoD tab){
    tab[moverFila - 1][moverColumna - 1] = ' ';
    tab[destinoFila - 1][destinoColumna - 1] = 'O';

    if (moverFila == destinoFila)
    {
        if (moverColumna < destinoColumna)
        {
            tab[moverFila - 1][moverColumna] = ' ';
        }else{
            tab[moverFila - 1][moverColumna - 2] = ' ';
        }
    }else{
        if (moverColumna == destinoColumna)
        {
            if (moverFila < destinoFila)
            {
                tab[moverFila][moverColumna - 1] = ' ';
            }else{
                tab[moverFila - 2][moverColumna - 1] = ' ';
            }
        }
    }
}


void dejarGanarIngles(juego tab){
        int fila, columna;

        for (fila = 0; fila < 7; fila++)
        {
            for (columna = 0; columna < 7; columna++)
            {
                if (fila == 3 && columna == 3)
                {
                    tab[fila][columna] = ' ';
                }else{
                    if( (fila < 2 || fila > 4)&&(columna < 2 || columna > 4) ){
                        tab[fila][columna] = '"';
                    }else{
                        if ((fila == 3 && columna == 2) || (fila == 3 && columna == 1))
                        {
                            tab[fila][columna] = 'O';
                        }else{
                            tab[fila][columna] = ' ';
                        }
                    }
                }
            }
        }
    }

void dejarGanarFrances(juego tab){
    int fila, columna;

    for (fila = 0; fila < 7; fila++)
    {
        for (columna = 0; columna < 7; columna++)
        {
            tab[fila][columna] = ' ';
        }
    }
    for (fila = 0; fila < 7; fila++) {
        for (columna = 0; columna < 7; columna++) {
            if ((fila == 1 || fila == 5) && (columna == 0 || columna == 6)) {
                tab[fila][columna] = '"';
            }
            else if ((fila == 0 || fila == 6) && (columna < 2 || columna > 4)) {
                tab[fila][columna] = '"';}
            else{
                if ((fila == 3 && columna == 2) || (fila == 3 && columna == 3))
                {
                    tab[fila][columna] = 'O';
                }else{
                    tab[fila][columna] = ' ';
                }
            }
        }
    }}

void dejarGanarDiamante(juegoD tab){
    int fila, columna;

    for (fila = 0; fila < 9; fila++) {
        for (columna = 0; columna < 9; columna++) {
            if ((fila == 0 || fila == 8) && (columna != 4)) {
                tab[fila][columna] = '"';
            }
            else if ((fila == 1 || fila == 7) && (columna < 3 || columna > 5) ){
                tab[fila][columna] = '"';}
            else if ((fila == 2 || fila == 6) && (columna < 2 || columna > 6)) {
                tab[fila][columna] = '"';
            }
            else if ((fila == 3 || fila == 5) && (columna == 0 || columna == 8)) {
                tab[fila][columna] = '"';}

            else if ((fila == 3 && columna == 2) || (fila == 3 && columna == 3)){
                tab[fila][columna] = 'O';
            }
            else {
                tab[fila][columna] = ' ';
            }
        }
    }}

    int hazGanado(juego tab){
        int fila, columna, cuentaFichas = 0;

        for (fila= 0; fila < 7; fila++)
        {
            for (columna = 0; columna < 7; columna++)
            {
                if(tab[fila][columna] == 'O')
                {
                    cuentaFichas++;
                }
            }
        }

        if (cuentaFichas == 1)
        {
            return 1;
        }else{
            return 0;
        }
    }

    int hazGanado2(juegoD tab){
    int fila, columna, cuentaFichas = 0;

    for (fila= 0; fila < 9; fila++)
    {
        for (columna = 0; columna < 9; columna++)
        {
            if(tab[fila][columna] == 'O')
            {
                cuentaFichas++;
            }
        }
    }

    if (cuentaFichas == 1)
    {
        return 1;
    }else{
        return 0;
    }
}

    void opcionesJugar(){
        cout<< "\n";
        cout << "Para jugar, debes ingresar primero la pieza que quieres mover, y luego el lugar donde quieres moverla\n";
        cout << "Opciones Extras: \n";
        cout << "Para llegar de forma inmediata al ultimo movimiento, debes ingresar '9' en todos los campos.\n";
        cout << "Para reiniciar el tablero, debes ingresar '8' en todos los campos\n";
        cout << "\n";
        cout << "ES HORA DE JUGAR \n\n";
    }

     void jugarIngles(){
        int moverFila, moverColumna, destinoFila, destinoColumna, movimientoValido, salida = 0, ganado;
        juego tab;
        inicializarJuegoIngles(tab);
        mostrarTableroIngles(tab);

        opcionesJugar();

        while (salida != 1){
            cout << "Ingresa las coordenadas de la ficha que deseas mover\n";
            cout << "fila: ";
            cin >> moverFila;
            cout << "columna: ";
            cin >> moverColumna;
            cout << "\n";

            cout << "Ingresa las coordenadas donde deseas mover la ficha\n";
            cout << "fila: ";
            cin >> destinoFila;
            cout << "columna: ";
            cin >> destinoColumna;
            cout << "\n";


            if (moverFila == 9 && moverColumna == 9 && destinoFila == 9 && destinoColumna == 9)
            {
                dejarGanarIngles(tab);
                cout << "Haz decidido llegar al final del juego. Haz el ultimo movimiento!\n";
                mostrarTableroIngles(tab);
            }else{
                    if (moverFila == 8 && moverColumna == 8 && destinoFila == 8 && destinoColumna == 8)
                    {
                        inicializarJuegoIngles(tab);
                        cout << "Haz reiniciado el tablero! Vuelve a intentarlo \n\n";
                        mostrarTableroIngles(tab);
                        opcionesJugar();
                    }else{
                        movimientoValido = validarMovimiento(moverFila, moverColumna, destinoFila, destinoColumna, tab);
                        if (movimientoValido == 1)
                        {
                            cout << "Genial! Continuemos... \n";
                            mover(moverFila, moverColumna, destinoFila, destinoColumna, tab);
                            mostrarTableroIngles(tab);
                        }else{
                            cout << "Movimiento no valido\n";
                        }
                    }
            }

            ganado = hazGanado(tab);
            if (salida != 1)
            {
                if (ganado == 1)
                {
                    salida = 1;
                    cout << "\n Haz ganado :)!!!!\n\n";
                }
            }else{
                cout << "\n Volvemos a empezar!\n\n";
            }
        }

    }
    void jugarFrances(){
    int moverFila, moverColumna, destinoFila, destinoColumna, movimientoValido, salida = 0, ganado;
    juego tab;
    inicializarJuegoFrances(tab);
    mostrarTableroFrances(tab);

    opcionesJugar();

    while (salida != 1){
        cout << "Ingresa las coordenadas de la ficha que deseas mover\n";
        cout << "fila: ";
        cin >> moverFila;
        cout << "columna: ";
        cin >> moverColumna;
        cout << "\n";

        cout << "Ingresa las coordenadas donde deseas mover la ficha\n";
        cout << "fila: ";
        cin >> destinoFila;
        cout << "columna: ";
        cin >> destinoColumna;
        cout << "\n";


        if (moverFila == 9 && moverColumna == 9 && destinoFila == 9 && destinoColumna == 9)
        {
            dejarGanarFrances(tab);
            cout << "Haz decidido llegar al final del juego. Haz el ultimo movimiento!\n";
            mostrarTableroFrances(tab);
        }else{
                if (moverFila == 8 && moverColumna == 8 && destinoFila == 8 && destinoColumna == 8)
                {
                    inicializarJuegoFrances(tab);
                    cout << "Haz reiniciado el tablero! Vuelve a intentarlo \n\n";
                    mostrarTableroFrances(tab);
                    opcionesJugar();
                }else{
                    movimientoValido = validarMovimiento(moverFila, moverColumna, destinoFila, destinoColumna, tab);
                    if (movimientoValido == 1)
                    {
                        cout << "Genial! Continuemos... \n";
                        mover(moverFila, moverColumna, destinoFila, destinoColumna, tab);
                        mostrarTableroFrances(tab);
                    }else{
                        cout << "Movimiento no valido\n";
                    }
                }
        }

        ganado = hazGanado(tab);
        if (salida != 1)
        {
            if (ganado == 1)
            {
                salida = 1;
                cout << "\n Haz ganado :)!!!!\n\n";
            }
        }else{
            cout << "\nVolvemos a empezar!\n\n";
        }
    }

}
    void jugarDiamante(){
    int moverFila, moverColumna, destinoFila, destinoColumna, movimientoValido, salida = 0, ganado;
    juegoD tab;
    inicializarJuegoDiamante(tab);
    mostrarTableroDiamante(tab);

    opcionesJugar();

    while (salida != 1){
        cout << "Ingresa las coordenadas de la ficha que deseas mover\n";
        cout << "fila: ";
        cin >> moverFila;
        cout << "columna: ";
        cin >> moverColumna;
        cout << "\n";

        cout << "Ingresa las coordenadas donde deseas mover la ficha\n";
        cout << "fila: ";
        cin >> destinoFila;
        cout << "columna: ";
        cin >> destinoColumna;
        cout << "\n";


        if (moverFila == 9 && moverColumna == 9 && destinoFila == 9 && destinoColumna == 9)
        {
            dejarGanarDiamante(tab);
            cout << "Haz decidido llegar al final del juego. Haz el ultimo movimiento!\n";
            mostrarTableroDiamante(tab);
        }
        else{
                if (moverFila == 8 && moverColumna == 8 && destinoFila == 8 && destinoColumna == 8)
                {
                    inicializarJuegoDiamante(tab);
                    cout << "Haz reiniciado el tablero! Vuelve a intentarlo \n\n";
                    mostrarTableroDiamante(tab);
                    opcionesJugar();
                }else{
                    movimientoValido = validarMovimientoD(moverFila, moverColumna, destinoFila, destinoColumna, tab);
                    if (movimientoValido == 1)
                    {
                        cout << "Genial! Continuemos... \n";
                        moverD(moverFila, moverColumna, destinoFila, destinoColumna, tab);
                        mostrarTableroDiamante(tab);
                    }else{
                        cout << "Movimiento no valido\n";
                    }
                }
        }

        ganado = hazGanado2(tab);
        if (salida != 1)
        {
            if (ganado == 1)
            {
                salida = 1;
                cout << "\n Haz ganado :)!!!!\n\n";
            }
        }else{
            cout << "\nVolvemos a empezar!\n\n";
        }
    }

}
