#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include"../MENUS/rlutil.h"
using namespace std;
#include "NotaManager.h"


NotaManager::NotaManager(char *ruta)
{

    strcpy(_ruta,ruta);
}

NotaManager::NotaManager()
{

    strcpy(_ruta,"NotasManager.dat");

}


int NotaManager::buscarDNI(int dni)
{

    return _archivo.buscarReg(dni)>=0;

}

void NotaManager::Cargar()

{
    int dni, idMateria, Tipo;
    float nota;

    rlutil::locate(20,8);
    cout << "INGRESE DNI #: " <<endl;
    rlutil::locate(35,8);
    cin>>dni;

    int numerodeRegistro=buscarDNI(dni);

    if(numerodeRegistro<0)
    {

        rlutil::locate(20,10);
        cout<<"EL DNI NO EXISTE !!";
        system("pause>nul");
    }
    else
    {

        rlutil::locate(20,9);
        cout << "INGRESE ID MATERIA: "<<endl;
        rlutil::locate(39,9);
        cin>>idMateria;
        rlutil::locate(20,10);
        cout << "TIPO DE NOTA: "<<endl;
        rlutil::locate(35,10);
        cin >> Tipo;
        rlutil::locate(20,11);
        cout << "INGRESE NOTA: "<<endl;
        rlutil::locate(38,11);
        cin >> nota;

       Notas aux;
        aux.setDNIalumno(dni);
        aux.setIdMateria(idMateria);
        aux.setTipoNota(Tipo);
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
