#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include"../MENUS/rlutil.h"
using namespace std;
#include "NotaManager.h"
#include "../MENUS/FUNCIONES_FRONT.h"
#include "AlumnoArchivo.h"
#include "Alumno.h"



int NotaManager::buscarDNI(int dni)
{

    return _archivo.buscarReg(dni)>=0;

}

void NotaManager::Cargar()

{
    AlumnoArchivo alumno;

    int dni, NroExamen;
    char nombreMateria[30];
    float nota;


    rlutil::locate(20,8);
    cout << "INGRESE DNI #: " <<endl;
    rlutil::locate(35,8);
    cin>>dni;

    int numerodeRegistro=alumno.buscarReg(dni);

    if(numerodeRegistro<0)
    {

        rlutil::locate(20,10);
        cout<<"EL DNI NO EXISTE !!";
        system("pause>nul");
    }
    else
    {

        rlutil::locate(20,9);
        cout << "NOMBRE DE MATERIA: "<<endl;
        rlutil::locate(39,9);
        cin>>nombreMateria;
        rlutil::locate(20,10);
        cout << "Nro EXAMEN: "<<endl;
        rlutil::locate(35,10);
        cin >> NroExamen;
        rlutil::locate(20,11);
        cout << "INGRESE NOTA: "<<endl;
        rlutil::locate(38,11);
        cin >> nota;
        rlutil::locate(20,12);


        Notas aux;
        aux.setDNIalumno(dni);
        aux.setNombreMateria(nombreMateria);
        aux.setNroExamen(NroExamen);
        aux.setNota(nota);
        aux.setEliminada(0);

        if (_archivo.agregar(aux))
        {
            rlutil::locate(30,23);
            cout << "** NOTA CORRECTAMENTE GUARDADA **" << endl;
            system("pause>nul");
        }
        else
        {
            rlutil::locate(30,25);
            cout << "** UPS! ALGO SALIO MAL :( **" << endl;
            system("pause>nul");
        }
    }
    system("pause");

}
void NotaManager::ListarTodos()
{

    NotasArchivo _archivo;

    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Notas reg = _archivo.leerReg(i);

        Listar(reg);

        system("pause>nul");

    }
}

void NotaManager::Listar(Notas nota)
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   LISTA DE NOTAS   *****", 34, 4);

    rlutil::locate(20,9);
    cout<<"DNI ALUMNO:    " <<nota.getDNIalumno()<<endl;
    rlutil::locate(20,10);
    cout<<"NOMBRE DE MATERIA :    "<<nota.getNombreMateria()<<endl;
    rlutil::locate(20,11);
    cout<<"NUMERO DE EXAMEN:    "<<nota.getNroExamen()<<endl;
    rlutil::locate(20,12);
    cout<<"NOTA  :    " <<nota.getNota()<<endl;
    rlutil::locate(20,13);

    system("pause>nul");
    system("cls");

}
void NotaManager::ListarXdni(int dni)
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    Notas obj;
    int cantReg=_archivo.getCantidad();
    int can=1;
    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (dni==obj.getDNIalumno())
        {
            can++;
            rlutil::locate(8,9+can);
            cout <<"MATERIA:  "<<obj.getNombreMateria()<<endl;
            rlutil::locate(33,9+can);
            cout <<"Nro. DE EXAMEN:   "<<obj.getNroExamen()<<endl;
            rlutil::locate(60,9+can);
            cout <<"NOTA:   "<<obj.getNota()<<endl;
            system("pause>nul");
           // system("cls");
        }

    }
    rlutil::locate(30,25);
    cout <<"FIN DEL LISTADO "<<endl;
}

void NotaManager::Editar()
{

    Notas reg;
    int dni, posicion;

    rlutil::locate(20,9);
    cout << "DNI A MODIFICAR: ";
    cin >> dni;
    cout << endl;

    system("cls");
    mostrar_mensaje ("***** MODIFICAR DE NOTAS***** ", 34, 4);
    posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        reg = _archivo.leerReg(posicion);

        int nuevoEstado;
        rlutil::locate(20,11);
        cout << "DESEA MODIFICAR ALGUN DATO? (1-SI/2-NO): ";
        rlutil::locate(64,11);
        cin >> nuevoEstado;

        if (nuevoEstado==1)
        {
            ModificarDatos(dni);

        }

    }
    else
    {
        system("pause>nul");
    }


}

void NotaManager::ModificarDatos(int dni)
{
    system("cls");

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("* MODIFICAR NOTAS *", 40, 4);
    mostrar_mensaje ("--------------------------------", 40, 5);

    Notas aux;
    NotasArchivo arNotas;

    int tipo;
    float nota;
    char nombre[30];

    rlutil::locate(10,9);
    cout << "INGRESE EL NOMBRE DE LA MATERIA: "<<endl;
    rlutil::locate(43,9);
    cin>>nombre;

    int canReg=arNotas.getCantidad();

    for(int x=0; x<canReg; x++)
    {

        aux=arNotas.leerReg(x);

        if(strcmp(nombre,aux.getNombreMateria())==0 &&dni==aux.getDNIalumno())
        {
            rlutil::locate(10,10);
            cout << "INGRESE TIPO DE NOTA (1-PARCIAL 1/ 2-PARCIAL2): "<<endl;
            rlutil::locate(60,10);
            cin>>tipo;
            if (tipo==1 || tipo==2)
            {
                rlutil::locate(10,11);
                cout << "INGRESE LA NUEVA NOTA: "<<endl;
                rlutil::locate(35,11);
                cin>>nota;
                aux.setNota(nota);

                if(arNotas.modificar(aux,x))
                {

                    rlutil::locate(30,15);
                    cout << "** REGISTRO MODIFICADO **"<<endl;
                }
            }
        }

    }
    system("pause>nul");
    system("cls");

}
void NotaManager::BuscarNotas()
{
    system("cls");
    Notas obj;
    NotasArchivo arNotas;
    int dni;
    int canReg= arNotas.getCantidad();
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 26);
    mostrar_mensaje ("***** BUSCAR NOTAS POR DNI ***** ", 34, 4);
    rlutil::locate(20,9);
    cout << "DNI: ";
    rlutil::locate(28,9);
    cin >> dni;
    cout << endl;

    int can=1;
    for (int x=0; x<canReg; x++)
    {

        obj=arNotas.leerReg(x);

        if(dni==obj.getDNIalumno())
        {
            can++;
            rlutil::locate(28,10+can);
            this->ListarXdni(dni);

        }
    }
}



/*
void NotaManager::HacerCopiaDeSeguridad()
{

    int cantidadRegistros = _archivo.getCantidad();
    Notas *vec = new Notas[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    _archivo.leerTodos(vec, cantidadRegistros);
    _archivoBkp.vaciar();
  //  if (_archivoBkp(vec, cantidadRegistros))
    {
        cout << "Backup realizado correctamente" << endl;
    }
    else
    {
        cout << "Falla al realizar backup" << endl;
    }

    delete []vec;
}

void AlumnoManager::RestaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidad();
    Alumno *vec = new Alumno[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al restaurar backup" << endl;
        return;
    }

    _archivoBkp.(vec, cantidadRegistros);
    _archivo.vaciar();
    if (_archivo.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;
}
*/
