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

    int anuales=6, falta=1, op;
    int dni, dia, mes, anio;

    rlutil::locate(20,8);
    cout << "INGRESE DNI ALUMNO: " <<endl;
    rlutil::locate(41,8);
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

        rlutil::locate(20,10);
        cout << "FALTAS ANUALES: "<<endl;
        rlutil::locate(38,10);
        cout << anuales <<endl;
         cout << "INGRESE DIA DE LA FALTA: "<<endl;
        rlutil::locate(42,14);
        cin >> dia;
        rlutil::locate(20,15);
        cout << "INGRESE MES DE LA FALTA: "<<endl;
        rlutil::locate(45,15);
        cin >> mes;
        rlutil::locate(20,16);
        cout << "INGRESE ANIO DE LA FALTA: "<<endl;
        rlutil::locate(45,16);
        cin >> anio;

        rlutil::locate(20,11);
        cout << "CARGAR FALTA (1-SI/ 2-NO): "<<endl;
        if (op==1){
         rlutil::locate(48,11);
         cout << falta <<endl;

       Falta aux;
        aux.setDNIAlumno(dni);
        aux.setFechaAusencia(Fecha(dia, mes, anio));
        aux.setCantFaltasAnuales(anuales);
        aux.setFalta(falta);

         if (_archivo.agregar(aux))
        {
            rlutil::locate(30,23);
            cout << "** FALTA CORRECTAMENTE CARGADA **" << endl;
            system("pause>nul");
        }
        else
        {
            rlutil::locate(30,25);
            cout << "** UPS! ALGO SALIO MAL :( **" << endl;
            system("pause>nul");
        }

        }



    }
    system("pause");

}
