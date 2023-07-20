#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_USER.h"
#include "FUNCIONES_FRONT.h"
#include "Fecha.h"
#include "CursoManager.h"
#include "MateriaManager.h"
#include "NotaManager.h"
#include"CuotaManager.h"
#include"FaltaManager.h"
#include"ComunicadosManager.h"
#include "MENUS.h"

void menuUser(int dni)
{
    system("cls");

    const char *opciones[] = {"FACTURACION Y PAGOS", "NOTAS", "MATERIAS","ESTADO DE AUSENCIAS",
                              "COMUNICADOS ESPECIALES","SALIR"
                             };

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        mostrar_mensaje ("*****  BIENVENIDO  ALUMNO  ***** ", 34, 4);
        mostrar_mensaje ( " ESTAS SON TUS OPCIONES:  ", 36, 6);


        rlutil::saveDefaultColor();
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);

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

            if (y>5)
            {
                y=5;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///FACTURACION Y PAGOS
            {
                system("cls");
                CuotaManager obj;

                obj.MenuUserPagosyCuotas(dni);

                system("pause>nul");
            }

            break;

            case 1:     ///NOTAS

            {

                system("cls");
                NotaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);

                obj.ListarXdni(dni);

                system("pause>nul");
                system("cls");

            }

            break;

            case 2:     ///MATERIAS
            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);

                MateriaManager obj;

                obj.MenuUserMaterias(dni);

                system("pause>nul");
                system("cls");

            }
                break;
            case 3:     ///ESTADO DE AUSENCIAS
            {
                system("cls");
                FaltaManager obj;
                mostrar_mensaje ("**  6 SON LA CANTIDAD DE FALTAS PERMITIDAS ** ", 23, 6);

                obj.ListarXdni(dni);

                system("pause>nul");
                system("cls");
            }

            break;

            case 4:    ///COMUNICADOS ESPECIALES
                {

                 system("cls");
                ComunicadosManager obj;

                obj.ComunicadoUser(dni);

                system("pause>nul");
                system("cls");
                    }
                break;

            case 5:     /// SALIR
                system("cls");
                mostrar_mensaje ("*** ¿ESTAS SEGURO DE SALIR?***", 40, 5);
                system("pause>nul");
                system("cls");
                menuIncio();

                break;

            }

        }

    }
    while(op!=0);

    system("pause");

}

void menuFactyPagos()
{

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 20);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("*****   FACTURACION Y PAGOS *****", 28, 4);
    mostrar_mensaje ("DESCRIPCION", 5, 5);
    mostrar_mensaje ("FACTURA", 20, 5);
    mostrar_mensaje ("PAGOS", 30, 5);

}

void menuNotas()
{

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 20);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("*****   NOTAS DE MATERIAS  *****", 28, 4);




}
void menuMateriasActivas()
{
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 20);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("*****   MATERIAS EN CURSO  *****", 28, 4);



}
void menuEstadoAusencias()
{
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 20);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("*****   ESTADO DE AUSENCIAS  *****", 28, 4);

}
void menuComunicadosEspeciales()
{
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 20);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("*****   COMUNICADOS ESPECIALES  *****", 28, 4);

}
