
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include "PagoManager.h"
#include"Pago.h"
#include"PagoArchivo.h"
#include"../MENUS/rlutil.h"
#include"../MENUS/FUNCIONES_FRONT.h"
#include"AlumnoArchivo.h"
using namespace std;


int PagoManager::buscarReg(int dni)   /// ACA  TIENE QUE VALIDAR EL DNI EN EL ARCHIVO DE ALUMNOS
{

    Pago obj;
    PagoArchivo _archivoalumno;
    int nroReg=-1;
    int cantRegArchivo=_archivoalumno.getCantidad();


    for (int i = 0; i < cantRegArchivo; i++)
    {
        obj=_archivoalumno.leerReg(i);

        if (obj.getDNIalumno()== dni)
        {
            nroReg=i;
            break;
        }
    }

    return nroReg;
}




void  PagoManager::Cargar()
{
   float importe;
    int pag;
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
        cout << "NUMERO DE PAGO: "<<endl;
        pag=generarPago();
        rlutil::locate(30,9);
        cout << pag <<endl;
        rlutil::locate(10,10);
        cout << "MONTO: "<<endl;
        rlutil::locate(20,10);
        cin >> importe;
        rlutil::locate(10,12);
        cout << "DIA DE PAGO: "<<endl;
        rlutil::locate(25,12);
        cin >> dia;
        rlutil::locate(10,13);
        cout << "MES DE PAGO: "<<endl;
        rlutil::locate(25,13);
        cin >> mes;
        rlutil::locate(10,14);
        cout << "ANIO DE PAGO: "<<endl;
        rlutil::locate(25,14);
        cin >> anio;



        PagoArchivo _archivo;
        Pago aux;
        aux.setDNIalumno(dni);
        aux.setNroPago(pag);
        aux.setMonto(importe);
        aux.setFechaDePago(Fecha(dia, mes, anio));
        aux.setAbonado(true);

        if (_archivo.agregar(aux))
        {
            rlutil::locate(30,20);
            cout << "** PAGO GUARDADO CORRECTAMENTE **" << endl;
                  system("pause>nul");
        }
        else
        {
            rlutil::locate(30,20);
            cout << "**  UPS! ALGO SALIO MAL :(  **" << endl;
            system("pause>nul");

        }
        system("pause");
    }

}
void PagoManager::ListarTodos()
{
    PagoArchivo _archivo;
    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Pago reg = _archivo.leerReg(i);
        if (reg.getAbonado()==true)
        {
            Listar(reg);
            cout << endl;
        }
    }
}

int PagoManager::generarPago()
{
    PagoArchivo _archivo;
    return _archivo.getCantidad()+1;
}
void PagoManager::ListarXdni(Pago pago){

PagoArchivo _archivo;

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
        Pago reg = _archivo.leerReg(posicion);
        Listar(reg);
    }
    else
    {
        rlutil::locate(20,10);
        cout << "** NO EXISTE UN PAGO CON ESE DNI **" << endl;
        system("pause>nul");
    }
}


void PagoManager::Listar(Pago pago)
{
int NumeroPago;
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout<<"DNI ALUMNO:    " <<pago.getDNIalumno()<<endl;
    rlutil::locate(20,10);
    NumeroPago=this->generarPago();
    cout<<"NUMERO DE PAGO :    "<<NumeroPago<<endl;
    rlutil::locate(20,11);
    cout<<"MONTO :    "<<pago.getMonto()<<endl;
    rlutil::locate(20,12);
    cout<<"FECHA DE PAGO :    " <<pago.getFechaDePago().toString()<<endl;
    rlutil::locate(20,13);
    cout<<" ABONADO :    "<<true;

}


 int PagoManager::buscarDNI(int dni)
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
