#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "MENUS.h"
#include"FUNCIONES_USER.h"
#include"AlumnoArchivo.h"

void menuIncio()
{
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("___________________________", 40, 3);
    mostrar_mensaje ("* BIENVENIDO A TU COLE *" ,40, 5);
    mostrar_mensaje ("___________________________", 40, 6);


    AlumnoArchivo Obj;

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

    else if (Obj.buscarReg(dni)){

        menuUser(dni);

        system("cls");
    } else {

      rlutil::  locate (30,16);
    cout <<"** EL DNI NO EXISTE EN NUESTROS REGISTROS ** ";
    system("pause>nul");
    system("cls");

    }


}
void SalirSistemaUser()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   MUCHAS GRACIAS POR USAR NUESTRO SISTEMA *****", 28, 10);
    mostrar_mensaje ("By ARIADNA & ROMINA", 68, 20);
}
