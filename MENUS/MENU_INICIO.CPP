#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"


void menuIncio()
{
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("___________________________", 40, 3);
    mostrar_mensaje ("* BIENVENIDO A TU COLE *" ,40, 5);
    mostrar_mensaje ("___________________________", 40, 6);


    int dni;

    rlutil::  locate (36,12);
    cout <<"INGRESE SU DNI: ";
    rectangulo (51, 11, 10, 1);
    rlutil::  locate (53,12);
    cin >>dni;

    if (dni == 0000){ /// AHORA EL ADM ES EL 0000
        system("cls");

      menuAdmin();
    }
}
