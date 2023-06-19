#include <iostream>
#include <iomanip>
#include <cstring>
#include"../MENUS/rlutil.h"
#include"CuotaManager.h"


using namespace std;
#include"Cuota.h"
#include"CuotaArchivo.h"
//const char *RUTA_CUOTA = "Cuota.dat";

int CuotaManager::buscarDNI(int dni)
{

    CuotaArchivo Archivo ("Cuota.dat");
    Cuota obj;

    int nroReg=-1;
    int cantRegArchivo=Archivo.getCantidad();


    for (int i = 0; i < cantRegArchivo; i++)
    {
        obj=Archivo.leerReg(i);

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
    CuotaArchivo Archivo ("Cuota.dat");
    int dni, nroReg;


    bool agrego = false;

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
    obj.Cargar(dni);

    if (Archivo.agregar(obj)==true)
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
