#include <iostream>
#include "FaltaManager.h"
#include"Falta.h"
#include"FaltaArchivo.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"
#include"Alumno.h"
#include"AlumnoArchivo.h"

using namespace std;


FaltaManager::FaltaManager(const char *ruta){

    strcpy(_ruta,ruta);
}
 FaltaManager::FaltaManager(){

    strcpy(_ruta,"FaltaManager.dat");

 }

int FaltaManager::buscarDNI(int dni) {
AlumnoArchivo Archivo(_ruta);
Alumno obj;

 int nroReg=-1;
 int cantRegArchivo=_archivo.getCantidad();


  for (int i = 0; i < cantRegArchivo; i++)
  {
        obj=Archivo.leerReg(i);

                if (obj.getDni()== dni){
                       nroReg=i;
                       break;
                    }
                }

return nroReg;
}
int FaltaManager::Cargar()
{

Falta obj;

int dni, nroReg;

 bool agrego = false;

     rlutil::locate(20,8);
    cout<<"DNI: ";
    rlutil::  locate (26,8);
    cin>>dni;

  nroReg = this->buscarDNI(dni);

    if (nroReg!=-1)
    {
       rlutil::locate(28,9);
        cout<<"EL DNI NO EXISTE!";
        system("pause>null");
        return -1;
    }
 obj.Cargar(dni);

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
