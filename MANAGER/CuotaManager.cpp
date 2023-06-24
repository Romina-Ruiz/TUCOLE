#include <iostream>
#include <iomanip>
#include <cstring>
#include"../MENUS/rlutil.h"
#include"CuotaManager.h"
#include"CuotaArchivo.h"
#include"AlumnoArchivo.h"
#include"Alumno.h"

using namespace std;


int CuotaManager::buscarDNI(int dni)   /// ACA  TIENE QUE VALIDAR EL DNI EN EL ARCHIVO DE ALUMNOS
{

    Alumno obj;
    AlumnoArchivo _archivoalumno;
    int nroReg=-1;
    int cantRegArchivo=_archivoalumno.getCantidad();


    for (int i = 0; i < cantRegArchivo; i++)
    {
        obj=_archivoalumno.leerReg(i);

        if (obj.getDni()== dni)
        {
            nroReg=i;
            break;
        }
    }

    return nroReg;
}

void CuotaManager::Cargar()
{
    float importe;
    int tipo, fact;
    int dni, dia, mes, anio;

    rlutil::locate(10,8);
    cout << "INGRESE DNI #: " <<endl;
    rlutil::locate(25,8);
    cin>>dni;

    int numerodeRegistro=buscarDNI(dni);

    if(numerodeRegistro<0)
    {

        rlutil::locate(20,10);
        cout<<"EL DNI NO EXISTE !!";
        system("pause>nul");
        system("cls");
    }
    else
    {

        rlutil::locate(10,9);
        cout << "TIPO DE CUOTA (1-cuota/2-matricula/3-extraordinaria): "<<endl;
        rlutil::locate(65,9);
        cin>>tipo;
        rlutil::locate(10,10);
        cout << "NUMERO DE FACTURA: "<<endl;
        fact=generarFactura();
        rlutil::locate(30,10);
        cout << fact <<endl;
        rlutil::locate(10,11);


        cout << "MONTO: "<<endl;
        rlutil::locate(20,11);
        cin >> importe;
        rlutil::locate(10,12);
        cout << "DIA DE FACT: "<<endl;
        rlutil::locate(25,12);
        cin >> dia;
        rlutil::locate(10,13);
        cout << "MES DE FACT: "<<endl;
        rlutil::locate(25,13);
        cin >> mes;
        rlutil::locate(10,14);
        cout << "ANIO DE FACT: "<<endl;
        rlutil::locate(25,14);
        cin >> anio;
        rlutil::locate(10,15);
        cout << "DEBE: "<< "SI" <<endl;


        CuotaArchivo _archivo;
        Cuota aux;
        aux.setDNIalumno(dni);
        aux.setNroFact(fact);
        aux.setMonto(importe);
        aux.setFechaDeFact(Fecha(dia, mes, anio));
        aux.setDebe(true);

        if (_archivo.agregar(aux))
        {
            rlutil::locate(30,20);
            cout << "** FACTURA GUARDADA CORRECTAMENTE **" << endl;
                  system("pause>nul");
        }
        else
        {
            rlutil::locate(30,20);
            cout << "**  UPS! ALGO SALIO MAL :(  **" << endl;
            system("pause>nul");

        }
    }
    system("pause");
}
int CuotaManager::generarFactura()
{
    CuotaArchivo _archivo;
    return _archivo.getCantidad()+1;
}
