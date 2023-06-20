#include <iostream>
#include <iomanip>
#include <cstring>
#include"../MENUS/rlutil.h"
#include"CuotaManager.h"


using namespace std;



int CuotaManager::buscarDNI(int dni)
{
    CuotaArchivo _archivo;
    Cuota obj;

    int nroReg=-1;
    int cantRegArchivo=_archivo.getCantidad();


    for (int i = 0; i < cantRegArchivo; i++)
    {
        obj=_archivo.leerReg(i);

        if (obj.getDNIalumno()== dni)
        {
            nroReg=i;
            break;
        }
    }

    return nroReg;
}

int CuotaManager::Cargar()
{
    Cuota obj;
    CuotaArchivo _archivo;



    int dni, nroReg;

    rlutil::locate(20,8);
    cout<<"DNI: ";
    rlutil::  locate (26,8);
    cin>>dni;

    nroReg = this->buscarDNI(dni);

    if (nroReg==-1)
    {
        rlutil::locate(28,9);
        cout<<"EL DNI NO EXISTE!";
        system("pause>null");
        return -1;
    }
    obj.Cargar();

    if (_archivo.agregar(obj)==true)
    {
        rlutil::locate(28,20);
        cout << "** Alumno guardado correctamente **" << endl;
        system("pause>nul");
    }
    else
    {
        rlutil::locate(28,20);
        cout << "** Ups! Algo salio mal :( **" << endl;
        system("pause>nul");
    }
}
