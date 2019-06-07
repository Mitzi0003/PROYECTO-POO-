#include <iostream>
#include "RECURSOS.h"
using namespace std;

void mostrarOpciones(){
    cout << "Deseas continuar?\n";
    cout << "Para empezar el juego , presiona 1\n";
    cout << "Para salir del juego, presiona 9\n";
}

int main(){
    int opcion, seleccion;

    cout << "\t\t Senku \n\n";


    cout << "Bienvenido al Menu principal" << endl;
    cout << "Por favor seleccione el estilo de tablero:"<<endl<<endl;
    cout << "1. Estilo ingles"<<endl;
    cout << "2. Estilo frances"<<endl;
    cout << "3. Estilo diamante"<<endl<<endl;

    cout << "0. Salir del programa"<< endl<<endl;

    cout << "Seleccionar la opcion: ";
    cin >> seleccion;

    while(seleccion>3 || seleccion<0){
    cout<<"Vuelve a ingresar la seleccion: ";
    cin>>seleccion;
    cout<< endl;
}

    if(seleccion==1){
        mostrarOpciones();
        cin >> opcion;

        while(opcion != 9){
            if (opcion == 1)
            {
                jugarIngles();
                mostrarOpciones();
            }else{
                if (opcion != 9)
                {
                    cout << "Opcion no valida\n";
                }
            }
            cin >> opcion;
        }

        cout << "Hasta pronto, vuelve a jugar cuando quieras :)\n";
    }
    else if(seleccion==2){
        mostrarOpciones();
        cin >> opcion;

        while(opcion != 9){
            if (opcion == 1)
            {
                jugarFrances();
                mostrarOpciones();
            }else{
                if (opcion != 9)
                {
                    cout << "Opcion no valida\n";
                }
            }
            cin >> opcion;
        }

        cout << "Hasta pronto, vuelve a jugar cuando quieras :)\n";
    }
    else if(seleccion==3){
        mostrarOpciones();
        cin >> opcion;

        while(opcion != 9){
            if (opcion == 1)
            {
                jugarDiamante();
                mostrarOpciones();
            }else{
                if (opcion != 9)
                {
                    cout << "Opcion no valida\n";
                }
            }
            cin >> opcion;
        }

        cout << "Hasta pronto, vuelve a jugar cuando quieras :)\n";
    }
    else if(seleccion==0)
        cout << "Hasta pronto, vuelve a jugar cuando quieras :)\n";


    return 0;
}
