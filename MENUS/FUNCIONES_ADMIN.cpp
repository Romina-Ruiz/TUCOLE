#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"


void menuAdmin()
{
    const char *opciones[] = {"FACTURACION","PAGOS", "CARGAR ALUMNOS", "CARGAR PROFESORES",
                              "CARGAR MATERIAS", "CARGAR AUSENCIAS","INFORMES","RESPALDOS","SALIR"
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

            if (y>8)
            {
                y=8;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y) {

            case 0:     ///FACTURACION
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** FACTURACION ***", 40, 5);
                {



                }

               break;

            case 1:     ///PAGOS
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** PAGOS***", 40, 5);
                {

                }

                break;

            case 2:     ///CARGAR ALUMNOS
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** CARGAR ALUMNOS***", 40, 5);
                {

                }

                break;

            case 3:     ///CARGAR PROFESORES
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** CARGAR PROFESORES***", 40, 5);



                break;

            case 4:    ///CARGAR MATERIAS
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** CARGAR MATERIAS***", 40, 5);



                break;

            case 5:     ///CARGAR AUSENCIAS
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** CARGAR AUSENCIAS***", 40, 5);



                break;

            case 6:     ///INFORMES
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** INFORMES***", 40, 5);


                break;
            case 7:     ///RESPALDOS
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** RESPALDOS***", 40, 5);

                break;

            case 8:     ///SALIR
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** ¿ESTAS SEGURO DE SALIR?***", 40, 5);

                break;

                        }

                      }

        }   while(op!=0);

    system("pause");

}
