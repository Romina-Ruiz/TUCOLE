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
#include "PagoManager.h"



void menuFacturacion()
{
    system("cls");
    CuotaManager obj;
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****  FACTURACION  ***** ", 34, 4);
    obj.Cargar();
    system("pause>nul");
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

            {
                system("cls");

                PagoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** CARGA DE PAGOS ***** ", 34, 4);
                obj.Cargar();
                system("pause>nul");
                system("cls");
            }


                ///LLAMAR A LA FUNCION CARGAR

                break;

            case 1:     /// MODIFICAR DATOS
                 {
                system("cls");

                PagoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** MODIFICAR DATOS DEL PAGO ***** ", 34, 4);
                obj.Editar();


                system("pause>nul");
                system("cls");
            }



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

    const char *opciones[] = {"CARGAR ALUMNO","MODIFICAR DATOS","BUSCAR ALUMNO","LISTADO DE ALUMNOS", "VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("***** ALUMNO ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);



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

            if (y>3)
            {
                y=3;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR ALUMNO

            {
                system("cls");

                AlumnoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** CARGA DE ALUMNO ***** ", 34, 4);
                obj.Cargar();
                system("pause>nul");
                system("cls");
            }

            break;

            case 1:     /// MODIFICAR DATOS

            {
                system("cls");

                AlumnoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** MODIFICAR DE ALUMNO ***** ", 34, 4);
                obj.Editar();
                system("pause>nul");
                system("cls");
            }


            break;
            case 2:     ///BUSCAR ALUMNO

            {
                system("cls");

                AlumnoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** BUSCAR ALUMNO ***** ", 34, 4);
                obj.ListarXdni();
                system("pause>nul");
                system("cls");
            }
                ///LLAMAR A LA FUNCION MODIFICAR

            break;
            case 3:     ///LISTADO DE ALUMNOS

            {
                system("cls");

                AlumnoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** LISTADO DE ALUMNO ***** ", 34, 4);
                obj.ListarTodos();
                system("pause>nul");
                system("cls");
            }


            break;


            case 4:     ///SALIR

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


void menuCargarProfesor()
{
    system("cls");

    const char *opciones[] = {"CARGAR PROFESOR","MODIFICAR DATOS","BUSCAR PROFESOR","VOLVER AL MENU PRINCIPAL"};
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
        showItem (opciones[3],30,13,y==3);


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

            if (y>3)
            {
                y=3;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///CARGAR PROFESOR
            {
                system("cls");

                ProfesorManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** CARGAR PROFESOR ***** ", 34, 4);

                obj.Cargar();

                system("pause>nul");
                system("cls");
            }

            break;

            case 1:     /// MODIFICAR DATOS
            {
                system("cls");

                ProfesorManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** MODIFICAR PROFESOR ***** ", 34, 4);

                obj.Editar();

                system("pause>nul");
                system("cls");
            }

            break;
            case 2:     /// BUSCAR PROFESOR
            {
                system("cls");

                ProfesorManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** BUSCAR PROFESOR ***** ", 34, 4);

                obj.ListarXdni();

                system("pause>nul");
                system("cls");
            }
            break;

            case 3:     ///SALIR
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

    const char *opciones[] = {"LISTA DE PAGOS","PAGOS POR FECHA", "PAGOS POR ALUMNOS","AUSENCIAS POR FECHAS",
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
        showItem (opciones[7],30,17,y==7);

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

            case 0:     ///LISTADO DE PAGOS
{

             system("cls");

                PagoManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** LISTA DE PAGOS ***** ", 34, 4);

                obj.ListarTodos();

                system("pause>nul");
                system("cls");

}

                break;

            case 1:



                break;

            case 2:


                break;
            case 3:
                {

             system("cls");

                PagoManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** INFORME DE PAGOS ***** ", 34, 4);

                obj.ListarXdni();

                system("pause>nul");
                system("cls");

}


                break;
            case 4:


                break;
            case 5:


                break;
            case 6:



                break;

            case 7:

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

            case 0:     /// REALIZAR BACKUP

                RealizarBackup();
                system("cls");
                break;

            case 1:     /// RESTAURAR BACKUP
                system("cls");

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


void RealizarBackup()
{

    system("cls");




    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*** REALIZAR RESPALDOS ***", 40, 4);
    mostrar_mensaje ("--------------------------------", 40, 5);
    rlutil::locate(10,9);
    int op;
    AlumnoManager alum;
    ProfesorManager profe;
    cout << "USTED DESEA RESPALDAR TODOS LOS ARCHIVOS? (1-SI / 2- NO): "<<endl;
    rlutil::locate(68,9);
    cin>>op;

    if (op==1)
    {

        alum.HacerCopiaDeSeguridad();
        profe.HacerCopiaDeSeguridad();

        rlutil::locate(30,15);
        cout << "** LOS RESPALDOS SE REALIZARON CON EXITO **"<<endl;
        system("pause>nul");
    }
    else if (op==2)
    {

        system("cls");

    }

}
