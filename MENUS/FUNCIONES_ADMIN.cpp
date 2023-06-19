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



void menuAdmin()
{
    const char *opciones[] = {"FACTURACION","PAGOS", "ALUMNOS", "PROFESORES","CARGAR ADMINISTRADORES",
                              "MATERIAS", "NOTAS","AUSENCIAS", "COMUNICADOS","INFORMES","RESPALDOS","SALIR"
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

            case 4:    ///CARGAR ADMINISTRADORES
                system("cls");
                menuCargarAdmin();
                system("pause>nul");
                system("cls");

                break;

            case 5:     /// CARGAR MATERIA
                system("cls");
                menuCargarMateria();
                system("pause>nul");
                system("cls");

                break;

            case 6:     ///CARGAR NOTAS
                system("cls");
                menuCargarNotas();
                system("pause>nul");
                system("cls");

                break;
            case 7:     ///CARGAR AUSENCIAS
                system("cls");
                menuAusencias();
                system("pause>nul");
                system("cls");
                break;

            case 8:     /// CARGAR COMUNICADO
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

            case 11:     ///SALIR
            {
                system("cls");
                SalirSistemaUser();
                system("pause>nul");
                system("cls");
            }
            break;


            }

        }

    }
    while(op!=0);

    system("pause");

}

void menuFacturacion()
{
    system("cls");
    Cuota obj;
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****  FACTURACION  ***** ", 34, 4);
   obj.Cargar();
    system("cls");

}

void menuPagos()
{
    system("cls");

    const char *opciones[] = {"CARGAR PAGO","MODIFICAR PAGO","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGA DE PAGOS ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR PAGOS


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR DATOS


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR
            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");


}

void menuCargarAlumnos()
{
    system("cls");

    const char *opciones[] = {"CARGAR ALUMNO","MODIFICAR DATOS","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGA DE ALUMNO ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR ALUMNO


                ///LLAMAR A LA FUNCION CARGAR
            {
                system("cls");

                AlumnoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** CARGA DE ALUMNO ***** ", 34, 4);
                obj.Cargar();
                system("cls");
            }

            break;

            case 1:     /// MODIFICAR DATOS


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR

            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");
}
/// EN LA PANTALLA DE CARGAR
///PONER EN ACTIVO EN AUTOMATICO
///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

void menuCargarProfesor()
{
    system("cls");

    const char *opciones[] = {"CARGAR PROFESOR","MODIFICAR DATOS","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGA DE PROFESOR ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR PROFESOR


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR DATOS


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR
            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");

}

void menuCargarAdmin()
{
    system("cls");

    const char *opciones[] = {"CARGAR ADMINISTRADOR","MODIFICAR DATOS","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGA DE ADMINISTRADOR ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR ADMINISTRADOR


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR DATOS


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR

            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");
}


void menuCargarMateria()
{
    system("cls");

    const char *opciones[] = {"CARGAR MATERIA","MODIFICAR DATOS","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGA DE MATERIAS ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR MATERIAS


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR DATOS


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR
            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");

}
void menuCargarNotas()
{
    system("cls");

    const char *opciones[] = {"CARGAR NOTAS","MODIFICAR DATOS","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGA DE NOTAS ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR NOTAS


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR DATOS


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR
            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");

}

void menuAusencias()
{

    system("cls");

    const char *opciones[] = {"CARGAR AUSENCIAS","MODIFICAR AUSENCIAS","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGA DE AUSENCIAS ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR AUSENCIAS


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR AUSENCIAS


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR
            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");


}
void menuComunicados()
{

    system("cls");

    const char *opciones[] = {"CARGAR COMUNICADOS","MODIFICAR COMUNICADOS","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** CARGAR DE COMUNICADOS ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR DE COMUNICADOS


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR COMUNICADO


                ///LLAMAR A LA FUNCION MODIFICAR

                break;

            case 2:     ///SALIR
            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");

}


void menuInformes()
{
    system("cls");

    const char *opciones[] = {"PAGOS POR FECHA", "PAGOS POR ALUMNOS","AUSENCIAS POR FECHAS",
                              "AUSENCIAS POR ALUMNOS","NOTAS POR ALUMNOS","ALUMNOS POR MATERIA","VOLVER AL MENU PRINCIPAL"
                             };
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** INFORMES ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);

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

            if (y>6)
            {
                y=6;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///




                break;

            case 1:     ///



                break;

            case 2:     ///


                break;
            case 3:     ///


                break;
            case 4:     ///


                break;
            case 5:     ///


                break;
            case 6:     ///
            {
                system("cls");
                menuAdmin();
                system("cls");
            }

            break;
            }
        }
    }
    while(op!=0);

    system("pause");

}
void menuRespaldos()
{
    system("cls");

    const char *opciones[] = {"REALIZAR BACKUP","RESTAURAR BACKUP","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** RESPALDOS ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///


                break;

            case 1:     ///


                break;

            case 2:     ///SALIR
            {
                system("cls");
                menuAdmin();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");

}
