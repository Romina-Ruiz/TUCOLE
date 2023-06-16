#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "FUNCIONES_USER.h"
#include "MENUS.h"
#include "FUNCIONES_ADMIN.h"
#include "../CLASES-ARCHIVOS/Cuota.h"
#include "../CLASES-ARCHIVOS/Alumno.h"
#include"../CLASES-ARCHIVOS/Persona.h"

void menuAdmin()
{
    const char *opciones[] = {"FACTURACION","PAGOS", "CARGAR ALUMNOS", "CARGAR PROFESORES","CARGAR ADMINISTRADORES",
                              "CARGAR MATERIAS", "CARGAR AUSENCIAS", "CARGAR COMUNICADS","INFORMES","RESPALDOS","SALIR"
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

            if (y>10)
            {
                y=10;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///FACTURACION

                system("cls");
                menuFacturacion();
                system("pause>nul");
                system("cls");
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
            case 7:     /// CARGAR COMUNICADO
                system("cls");

                system("pause>nul");
                system("cls");
                break;

            case 8:     ///INFORMES
                 system("cls");

                system("pause>nul");
                system("cls");
                break;
                 case 9:     ///RESPALDOS
                  system("cls");

                system("pause>nul");
                system("cls");
                break;
                 case 10:     ///SALIR
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("*** ¿ESTAS SEGURO DE SALIR?***", 40, 5);
                system("pause>nul");
                system("cls");
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

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****  FACTURACION  ***** ", 34, 4);

    rlutil::  locate (25,9);
    cout<<"INGRESE DNI DEL ALUMNO: ";
    rlutil::  locate (50,9);
    /// cin>>_dni;
    rlutil::  locate (25,10);
    cout<<"INGRESE FECHA DE LA DEUDA: ";
    rlutil::  locate (58,10);
    ///cin>>_dia;  /// aca chequear como se ingresa la fecha
    rlutil::  locate (25,11);
    cout<<"INGRESE EL IMPORTE DE LA CUOTA: ";
    rlutil::  locate (32,11);
    ///cin>>_monto;
    rlutil::  locate (25,12);
    cout<<"NUMERO DE COMPROBANTE GENERADO: ";
    rlutil::  locate (60,12);
    ///ACA COLOCAR LA FUNCION DE COMPROBANTE AUTOMATICO
///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

}

void menuPagos()
{
    system("cls");

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****  PAGOS  ***** ", 34, 4);

    rlutil::  locate (25,9);
    cout<<"INGRESE DNI DEL ALUMNO: ";
    rlutil::  locate (50,9);
    /// cin>>_dni;
    rlutil::  locate (25,10);
    cout<<"INGRESE FECHA DEL PAGO: ";
    rlutil::  locate (58,10);
    ///cin>>_dia;  /// aca chequear como se ingresa la fecha
    rlutil::  locate (25,11);
    cout<<"INGRESE EL IMPORTE ABONADO: ";
    rlutil::  locate (32,11);
    ///cin>>_monto;

    ///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

}

void menuCargarAlumnos()
{
    system("cls");

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("***** CARGA DE ALUMNO ***** ", 34, 4);

    rlutil::  locate (25,9);
    cout<<"INGRESE DNI: ";
    rlutil::  locate (50,9);
    /// cin>>_dni;
    rlutil::  locate (25,10);
    cout<<"INGRESE NOMBRE ";
    rlutil::  locate (58,10);
    ///cin>>_nombre;
    rlutil::  locate (25,11);
    cout<<"INGRESE APELLIDO: ";
    rlutil::  locate (32,11);
    ///cin>>_apellido;
    rlutil::  locate (25,12);
    cout<<"INGRESE EMAIL: ";
    rlutil::  locate (32,12);
    ///cin>>_email;
    rlutil::  locate (25,13);
    cout<<"INGRESE TELEFONO: ";
    rlutil::  locate (32,13);
    ///cin>>_telefono;
    rlutil::  locate (25,14);
    cout<<"ID ALUMNO: ";
    rlutil::  locate (32,14);
    ///FUNCION AUTOMATICA DEL ALUMNO
    rlutil::  locate (25,15);
    cout<<"ACTIVO : ";
    rlutil::  locate (32,15);
    ///PONER EN ACTIVO EN AUTOMATICO

    ///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

}

void menuCargarProfesor()
{
    system("cls");

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("***** CARGA DE PROFESOR ***** ", 34, 4);

    rlutil::  locate (25,9);
    cout<<"INGRESE DNI: ";
    rlutil::  locate (50,9);
    /// cin>>_dni;
    rlutil::  locate (25,10);
    cout<<"INGRESE NOMBRE ";
    rlutil::  locate (58,10);
    ///cin>>_nombre;
    rlutil::  locate (25,11);
    cout<<"INGRESE APELLIDO: ";
    rlutil::  locate (32,11);
    ///cin>>_apellido;
    rlutil::  locate (25,12);
    cout<<"INGRESE EMAIL: ";
    rlutil::  locate (32,12);
    ///cin>>_email;
    rlutil::  locate (25,13);
    cout<<"INGRESE TELEFONO: ";
    rlutil::  locate (32,13);
    ///cin>>_telefono;
    rlutil::  locate (25,14);
    cout<<"ID PROFESOR: ";
    rlutil::  locate (32,14);
    ///FUNCION AUTOMATICA DEL ALUMNO
    rlutil::  locate (25,15);
    cout<<"MATERIA A CARGO (id) : ";
    rlutil::  locate (32,15);
     ///cin>>_idMateria;
    rlutil::  locate (25,16);
    cout<<"ACTIVO : ";
    rlutil::  locate (32,16);
    ///PONER EN ACTIVO EN AUTOMATICO


    ///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

}
void menuCargarAdmin()
{
    system("cls");

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("***** CARGA DE PROFESOR ***** ", 34, 4);

    rlutil::  locate (25,9);
    cout<<"INGRESE DNI: ";
    rlutil::  locate (50,9);
    /// cin>>_dni;
    rlutil::  locate (25,10);
    cout<<"INGRESE NOMBRE ";
    rlutil::  locate (58,10);
    ///cin>>_nombre;
    rlutil::  locate (25,11);
    cout<<"INGRESE APELLIDO: ";
    rlutil::  locate (32,11);
    ///cin>>_apellido;
    rlutil::  locate (25,12);
    cout<<"INGRESE EMAIL: ";
    rlutil::  locate (32,12);
    ///cin>>_email;
    rlutil::  locate (25,13);
    cout<<"INGRESE TELEFONO: ";
    rlutil::  locate (32,13);
    ///cin>>_telefono;
    rlutil::  locate (25,14);
    cout<<"ID ADMINISTRADOR: ";
    rlutil::  locate (32,14);
    ///FUNCION AUTOMATICA DEL ADMINISTRADOR
    rlutil::  locate (25,15);
    cout<<"ACTIVO : ";
    rlutil::  locate (32,15);
    ///PONER EN ACTIVO EN AUTOMATICO


    ///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

}


void menuCargarMateria()
{
    system("cls");

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("***** CARGA DE MATERIA ***** ", 34, 4);

    rlutil::  locate (25,9);
    cout<<"INGRESE NOMBRE DE LA MATERIA: ";
    rlutil::  locate (50,9);
    /// cin>>_materia;
    rlutil::  locate (25,10);
    cout<<"ID MATERIA: ";
    rlutil::  locate (32,10);
    ///FUNCION AUTOMATICA DEL MATERIA
    rlutil::  locate (25,11);
    cout<<"AÑO DE CURSO ";
    rlutil::  locate (58,11);
    ///cin>>_aniocurso;
    rlutil::  locate (25,12);
    cout<<"INGRESE DNI ALUMNO: ";  ///MODIFICAR ESTO EN LA CLASE MATERIA
    rlutil::  locate (32,12);
    ///cin>>_dni;
    rlutil::  locate (25,13);
    cout<<"INGRESE ID PROFESOR: "; ///MODIFICAR ESTO EN LA CLASE MATERIA
    rlutil::  locate (32,13);
    ///cin>>_email;
    rlutil::  locate (25,14);
    cout<<"INGRESE HORARIO DE CURSADA: "; ///MODIFICAR ESTO EN LA CLASE MATERIA
    rlutil::  locate (32,14);
    ///cin>>_telefono;
     rlutil::  locate (32,15);
    cout<<"ACTIVO : ";
    rlutil::  locate (40,15);
    ///PONER EN ACTIVO EN AUTOMATICO

    ///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

}
void menuCargarNotas()
{
    system("cls");

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("***** CARGA DE NOTAS ***** ", 34, 4);

    rlutil::  locate (25,9);
    cout<<"INGRESE ID DE LA MATERIA: ";
    rlutil::  locate (50,9);
    /// cin>>_materia;
    rlutil::  locate (25,10);
    cout<<"INGRESE DNI DEL ALUMNO: ";
    rlutil::  locate (32,10);
    /// cin>>_dni;
    rlutil::  locate (25,11);
    cout<<"INGRESE ID DEL PROFESOR ";
    rlutil::  locate (58,11);
    ///cin>>_aniocurso;
    rlutil::  locate (25,12);
    cout<<"INGRESE NOTA DEL EXAMEN: ";
    rlutil::  locate (32,12);
    ///cin>>_dni;
    rlutil::  locate (25,13);
    cout<<"INGRESE TIPO DE NOTA: ";
    rlutil::  locate (32,13);
    ///cin>>_email;


    ///CARTEL DE CONFIRMACION Y VOLVER AL MENU ANTERIOR

}
