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

       Notas aux;
        aux.setDNIalumno(dni);
        aux.setNombreMateria(nombreMateria);
        aux.setNroExamen(NroExamen);
        aux.setNota(nota);

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
void NotaManager::ListarXdni()
{
    int dni;
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout << "INGRESE DNI ALUMNO: ";
    cin >> dni;
    system("cls");

    int posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        Notas reg = _archivo.leerReg(posicion);
        Listar(reg);
    }
    else
    {
        rlutil::locate(20,10);
        cout << "** NO EXISTEN NOTAS CON ESE DNI **" << endl;
        system("pause>nul");
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
