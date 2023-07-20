#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include"FUNCIONES_USER.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"
#include "../CLASES-ARCHIVOS/Cuota.h"
#include "../CLASES-ARCHIVOS/Alumno.h"
#include"../CLASES-ARCHIVOS/Persona.h"
#include"../MANAGER/AlumnoManager.h"
#include"ProfesorManager.h"
#include"CuotaManager.h"
#include"AlumnoManager.h"

void menuIncio()
{
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 20);

    mostrar_mensaje ("___________________________", 40, 3);
    mostrar_mensaje ("* BIENVENIDO A TU COLE *" ,40, 5);
    mostrar_mensaje ("___________________________", 40, 6);


    AlumnoManager Obj;

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

    else if (Obj.validarIngreso(dni)){

        menuUser(dni);

        system("cls");
    } else {

      rlutil::  locate (30,16);
    cout <<"** EL DNI NO EXISTE EN NUESTROS REGISTROS ** ";
    system("pause>nul");
    system("cls");

    }
menuIncio();

}
void SalirSistemaUser()
{
    rectangulo (2, 2, 100, 20);

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   MUCHAS GRACIAS POR USAR NUESTRO SISTEMA *****", 28, 10);
    mostrar_mensaje ("By ARIANA & ROMINA", 68, 20);
    system("pause>nul");
    system("cls");
    menuIncio();
}

void menuAdmin()
{

    system("cls");

    const char *opciones[] = {"FACTURACION","PAGOS", "ALUMNOS", "PROFESORES","MATERIAS", "CURSOS",
                              "NOTAS","AUSENCIAS", "COMUNICADOS","INFORMES","RESPALDOS","SALIR"
                             };

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        mostrar_mensaje ("*****  BIENVENIDO  ADMINISTRADOR  ***** ", 34, 4);
        mostrar_mensaje ( " ESTAS SON TUS OPCIONES:  ", 40, 6);


        rlutil::saveDefaultColor();
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);
        showItem (opciones[7],30,17,y==7);
        showItem (opciones[8],30,18,y==8);
        showItem (opciones[9],30,19,y==9);
        showItem (opciones[10],30,20,y==10);
        showItem (opciones[11],30,21,y==11);


        rlutil::locate(26,10+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y++;

            if (y>11)
            {
                y=11;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///FACTURACION
            {
                system("cls");
                menuFacturacion();
                system("pause>nul");
                system("cls");
            }
            break;

            case 1:     ///PAGOS

                system("cls");
                menuPagos();
                system("pause>nul");
                system("cls");
                break;

            case 2:     ///CARGAR ALUMNOS
                system("cls");
                menuCargarAlumnos();
                system("pause>nul");
                system("cls");
                break;

            case 3:     ///CARGAR PROFESORES
                system("cls");
                menuCargarProfesor();
                system("pause>nul");
                system("cls");

                break;

            case 4:    ///CARGAR MATERIA
                system("cls");
                menuCargarMateria();
                system("pause>nul");
                system("cls");

                break;

                case 5:     /// CARGAR  CURSOS

                system("cls");
                menuCargarCursos();
                system("pause>nul");
                system("cls");


                break;

            case 6:     /// CARGAR  NOTAS

                system("cls");
                menuCargarNotas();
                system("pause>nul");
                system("cls");


                break;

            case 7:     ///CARGAR  AUSENCIAS

                system("cls");
                menuAusencias();
                system("pause>nul");
                system("cls");

                break;
            case 8:     ///CARGAR COMUNICADO

                system("cls");
                menuComunicados();
                system("pause>nul");
                system("cls");

                break;

            case 9:     /// INFORMES

                system("cls");
                menuInformes();
                system("pause>nul");
                system("cls");

                break;
            case 10:     /// RESPALDOS
                system("cls");
                menuRespaldos();
                system("pause>nul");
                system("cls");


                break;

            case 11:     /// SALIR
            {
                system("cls");
                SalirSistemaUser();
                system("pause>nul");
                system("cls");
            }

            }

        }

    }
    while(op!=0);

    system("pause");

}
