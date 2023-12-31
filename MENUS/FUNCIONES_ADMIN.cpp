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
#include "MateriaManager.h"
#include "FaltaManager.h"
#include "CursoManager.h"
#include "CuotaManager.h"
#include "NotaManager.h"
#include"ComunicadosManager.h"


///MENUS INTERNOS DE ADMIN

///FACTURACION
void menuFacturacion()
{
    system("cls");

    const char *opciones[] = {"CARGAR FACTURACION","BUSCAR FACTURA POR DNI","VOLVER AL MENU PRINCIPAL"};
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("*****  FACTURACION  ***** ", 34, 4);

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

            case 0:     ///cargar facturacion
            {
                system("cls");
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** CARGA DE FACTURACION ***** ", 34, 4);

                CuotaManager obj;
                obj.Cargar();

                system("pause>nul");
                system("cls");
            }
            break;

            case 1:     /// Buscar facturacion por dni
            {
                system("cls");

                CuotaManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** BUSCAR FACTURA POR DNI ***** ", 34, 4);
                int dni;
                rlutil::locate(20,10);
                cout <<"POR FAVOR INGRESE DNI:  " <<endl;
                rlutil::locate(48,10);
                cin>>dni;

                obj.ListarxDNI(dni);

                system("pause>nul");
                system("cls");
            }

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
    system("cls");

}
///PAGOS
void menuPagos()
{
    system("cls");

    const char *opciones[] = {"CARGAR PAGO","ELIMINAR PAGO","BUSCAR PAGO POR DNI","VOLVER AL MENU PRINCIPAL"};
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

            case 0:     ///Cargar pagos

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

            break;

            case 1:     /// eliminar pagos

            {
                system("cls");

                PagoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** ELIMINAR PAGO ***** ", 34, 4);

                obj.EliminarPago();

                system("pause>nul");
                system("cls");
            }


            break;

            case 2:     ///SALIR
            {
                system("cls");
                PagoManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** BUSCAR PAGO POR DNI ***** ", 34, 4);
                int dni;
                rlutil::locate(20,10);
                cout <<"POR FAVOR INGRESE DNI:  " <<endl;
                rlutil::locate(48,10);
                cin>>dni;

                obj.ListarxDNI(dni);

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
///MENU ALUMNOS
void menuCargarAlumnos()
{
    system("cls");

    const char *opciones[] = {"CARGAR ALUMNO","MODIFICAR DATOS","BUSCAR ALUMNO", "LISTA DE ALUMNOS",
                              "VOLVER AL MENU PRINCIPAL"
                             };
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

            if (y>4)
            {
                y=4;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///Cargar alumnos

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

            case 1:     /// Modificar alumnos

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
            case 2:     ///Buscar alumnos por dni

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


            break;
            case 3:     ///Listado de alumnos por  curso
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
            case 4: ///SALIR
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

///PROFESORES

void menuCargarProfesor()
{
    system("cls");

    const char *opciones[] = {"CARGAR PROFESOR","MODIFICAR DATOS","BUSCAR PROFESOR",
                              "LISTA DE PROFESORES","VOLVER AL MENU PRINCIPAL"
                             };
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

            if (y>4)
            {
                y=4;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///Cargar profedores
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

            case 1:     /// Modificar profesores
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
            case 2:     /// Buscar profesores
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

            case 3:  /// lista de profesores
            {
                system("cls");

                ProfesorManager obj;
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);
                mostrar_mensaje ("***** LISTA DE PROFESORES ***** ", 34, 4);

                obj.ListarTodos();

                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** FIN DEL LISTADO ***** ", 34, 12);

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

///MATERIAS
void menuCargarMateria()
{
    system("cls");

    const char *opciones[] = {"CARGAR MATERIA","MODIFICAR DATOS",
                              "BUSCAR POR ID", "LISTAR MATERIAS","VOLVER AL MENU PRINCIPAL"
                             };
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("*****  MATERIAS  ***** ", 34, 4);

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

            if (y>4)
            {
                y=4;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///Cargar materias
            {
                system("cls");

                MateriaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** CARGAR MATERIA ***** ", 34, 4);

                obj.Cargar();

                system("pause>nul");
                system("cls");
            }

            break;

            case 1:     /// Modificar materias
            {
                system("cls");

                MateriaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR MATERIA ***** ", 34, 4);

                obj.ModificarMateria();

                system("pause>nul");
                system("cls");
            }

            break;
            case 2:     /// Buscar por id
            {
                system("cls");

                MateriaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** BUSCAR MATERIA ***** ", 34, 4);
                int id;
                rlutil::locate(20,9);
                cout<<"INGRESE EL ID DE LA MATERIA:"<<endl;
                rlutil::locate(50,9);
                cin>>id;

                obj.BuscarxID(id);

                system("pause>nul");
                system("cls");
            }
            break;

            case 3:     /// Listado de todas las materias
            {
                {
                    system("cls");

                    MateriaManager obj;
                    rlutil::setColor(rlutil::YELLOW);
                    rectangulo (2, 2, 100, 26);
                    mostrar_mensaje ("***** LISTA DE MATERIAS ***** ", 34, 4);

                    obj.ListarTodos();

                    system("pause>nul");
                    system("cls");
                }
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
///CURSOS/A�O ESCOLAR
void menuCargarCursos()
{
    system("cls");

    const char *opciones[] = {"CARGAR CURSO", "MODIFICAR CURSOS","LISTAR MATERIAS POR ANIO LECTIVO",
                              "LISTAR ALUMNOS POR ANIO LECTIVO", "VOLVER AL MENU PRINCIPAL"
                             };
    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("*****   CURSOS   ***** ", 34, 4);

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

            if (y>4)
            {
                y=4;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///Cargar cursos/a�o escolar
            {
                system("cls");

                CursoManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** CARGAR CURSOS ***** ", 34, 4);

                obj.Cargar();

                system("pause>nul");
                system("cls");
            }

            break;

            case 1:     ///  MODIFICAR CURSOS
            {
                system("cls");
                CursoManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR CURSOS ***** ", 34, 4);

                obj.Editar();

                system("cls");
            }
            break;

            case 2:     ///LISTAR CURSO
            {
                system("cls");
                CursoManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** INFORMACION SOBRE CURSO/ANIO  ***** ", 34, 4);
                int anio;
                rlutil::locate(10,9);
                cout<<"INGRESE EL ANIO LECTIVO A CONSULTAR :"<<endl;
                rlutil::locate(55,9);
                cin>>anio;

                obj.ListarMateriasxCurso(anio);

                system("pause>nul");
                system("cls");
            }
            break;
            case 3:     ///LISTAR ALUMNOS POR CURSO
            {
                system("cls");
                CursoManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** LISTA DE ALUMNOS POR CURSO/ANIO  ***** ", 34, 4);
                int anio;
                rlutil::locate(10,9);
                cout<<"INGRESE EL ANIO LECTIVO A CONSULTAR :"<<endl;
                rlutil::locate(55,9);
                cin>>anio;

                obj.ListarAlumnosxCurso(anio);

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


///NOTAS

void menuCargarNotas()
{
    system("cls");

    const char *opciones[] = {"CARGAR NOTAS","MODIFICAR NOTAS","BUSCAR NOTAS POR ALUMNO","VOLVER AL MENU PRINCIPAL"};
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

            case 0:     ///Cargar notas
            {
                system("cls");

                NotaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** CARGAR NOTAS ***** ", 34, 4);

                obj.Cargar();

                system("pause>nul");
                system("cls");
            }
            break;

            case 1:     /// MODIFICAR DATOS
            {
                system("cls");

                NotaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR NOTAS ***** ", 34, 4);

                obj.Editar();

                system("pause>nul");
                system("cls");
            }
            break;

            case 2:     ///BUSCAR NOTAS POR DNI
            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** BUSCAR NOTAS POR DNI ***** ", 34, 4);
                NotaManager obj;

                obj.BuscarNotas();

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

///AUSENCIAS
void menuAusencias()
{
    system("cls");

    const char *opciones[] = {"CARGAR AUSENCIAS","MODIFICAR AUSENCIAS",
                              "BUSCAR POR DNI", "VOLVER AL MENU PRINCIPAL"
                             };
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

            case 0:     ///Cargar ausencias
            {
                system("cls");

                FaltaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** CARGAR AUSENCIAS ***** ", 34, 4);

                obj.Cargar();

                system("pause>nul");
                system("cls");
            }
            break;

            case 1:     /// Modificar ausencias
            {
                system("cls");

                FaltaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR AUSENCIAS ***** ", 34, 4);

                obj.Editar();

                system("pause>nul");
                system("cls");
            }

            break;

            case 2:     ///Buscar ausencias por DNI
            {
                system("cls");

                FaltaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** LISTA DE AUSENCIAS ***** ", 34, 4);
                int dni;
                rlutil::locate(10,8);
                cout<<"INGRESE EL DNI A CONSULTAR: "<<endl;
                rlutil::locate(40,8);
                cin>>dni;

                obj.ListarXdni(dni);

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
///COMUNICADOS

void menuComunicados()
{
    system("cls");

    const char *opciones[] = {"CARGAR COMUNICADOS","MODIFICAR COMUNICADOS","COMUNICADOS ACTIVOS","VOLVER AL MENU PRINCIPAL"};
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

            case 0:     ///Cargar comunicados
            {
                system("cls");
                ComunicadosManager obj;

                obj.Cargar();


                system("cls");
            }

            break;

            case 1:     /// Eliminar comunicados
                system("cls");
                {
                    ComunicadosManager obj;

                    obj.EliminarComunicado();


                    system("cls");
                }
                break;

            case 2:     ///comunicados activos
            {
                system("cls");
                ComunicadosManager obj;

                obj.ComunicadosActivos();

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

///INFORMES
void menuInformes()
{
    system("cls");

    const char *opciones[] = {"INFORME POR CURSO","INFORME DE FACTURACION", "INFORME DE AUSENCIAS ",
                              "VOLVER AL MENU PRINCIPAL"
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

            case 0:     ///Informes por curso
            {
                system("cls");
                CursoManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** INFORMES POR CURSO ***** ", 34, 4);

                obj.InformeCursos();
                system("pause>nul");
                system("cls");

            }

            break;

            case 1: ///Informacion de facturacion
            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** INFORMES DE FACTURACION ***** ", 34, 4);

                CuotaManager obj;

                    obj.InformeFacturacion();

                //obj.MenuInformeCuotas();
                //  obj.MenuInformePagos();

                system("pause>nul");
                system("cls");
            }
            break;

            case 2: ///Informe de ausencias
            {
                system("cls");

                FaltaManager obj;
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** INFORME DE AUSENCIAS ***** ", 34, 4);

                //obj.AusenciasXfecha();
               obj.InformeAusencias();

                system("pause>nul");
                system("cls");
            }
            break;
            case 3: ///Salir
            {
                system("cls");
                menuAdmin();
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


///RESPALDOS
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
                RestaurarBackup();
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
    AlumnoManager alumno;
    ProfesorManager profesor;
    MateriaManager materia;
    CursoManager curso;
    NotaManager nota;
    ComunicadosManager comunicado;
    CuotaManager cuota;
    FaltaManager falta;
    PagoManager pago;

    cout << "USTED DESEA RESPALDAR TODOS LOS ARCHIVOS? (1-SI / 2- NO): "<<endl;
    rlutil::locate(68,9);
    cin>>op;

    if (op==1)
    {

        alumno.HacerCopiaDeSeguridad();
        profesor.HacerCopiaDeSeguridad();
        materia.HacerCopiaDeSeguridad();
        curso.HacerCopiaDeSeguridad();
        falta.HacerCopiaDeSeguridad();
        nota.HacerCopiaDeSeguridad();
        pago.HacerCopiaDeSeguridad();
        cuota.HacerCopiaDeSeguridad();
        comunicado.HacerCopiaDeSeguridad();


        rlutil::locate(30,15);
        cout << "** LOS RESPALDOS SE REALIZARON CON EXITO **"<<endl;
        system("pause>nul");
    }
    else if (op==2)
    {

        system("cls");

    }

}

void RestaurarBackup()
{

    system("cls");




    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*** RESTAURAR RESPALDOS ***", 40, 4);
    mostrar_mensaje ("--------------------------------", 40, 5);
    rlutil::locate(10,9);
    int op;
    AlumnoManager alumno;
    ProfesorManager profesor;
    MateriaManager materia;
    CursoManager curso;
    NotaManager nota;
    ComunicadosManager comunicado;
    CuotaManager cuota;
    FaltaManager falta;
    PagoManager pago;

    cout << "USTED DESEA RESTAURAR TODOS LOS ARCHIVOS? (1-SI / 2- NO): "<<endl;
    rlutil::locate(68,9);
    cin>>op;

    if (op==1)
    {

        alumno.RestaurarCopiaDeSeguridad();
        profesor.RestaurarCopiaDeSeguridad();
        materia.RestaurarCopiaDeSeguridad();
        curso.RestaurarCopiaDeSeguridad();
        falta.RestaurarCopiaDeSeguridad();
        nota.RestaurarCopiaDeSeguridad();
        pago.RestaurarCopiaDeSeguridad();
        cuota.RestaurarCopiaDeSeguridad();
        comunicado.RestaurarCopiaDeSeguridad();


        rlutil::locate(30,15);
        cout << "** LAS RESTAURACIONES SE REALIZARON CON EXITO **"<<endl;
        system("pause>nul");
    }
    else if (op==2)
    {

        system("cls");

    }

}
