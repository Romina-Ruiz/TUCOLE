
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



        Pago aux;
        aux.setDNIalumno(dni);
        aux.setNroPago(pag);
        aux.setMonto(importe);
        aux.setFechaDePago(Fecha(dia, mes, anio));
        aux.setEliminado(false);


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

        Listar(reg);

        system("pause>nul");

    }
}
void PagoManager::ListarOrdenadosPorFecha(int mes)
{

    int cantidadRegistros = _archivo.getCantidad();
    Pago *vec = new Pago[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Error al visualizar el listado";
        return;
    }

    for(int x=0; x<cantidadRegistros; x++)
    {
        vec[x]=_archivo.leerReg(x);
    }


    for(int i=0; i<cantidadRegistros; i++)
    {

        if (vec[i].getFechaDePago().getMes()==mes)
        {
            rlutil::locate(20,10);
            Listar(vec[i]);
            cout << endl;
            system("cls");

        }


    }

    delete []vec;

}
/*
void PagoManager::Ordenar(Pago *vec, int cantidadRegistros, int mes)
{
    int mayor = 0;

    Pago aux;

    for (int j=0; j<cantidadRegistros; j++)
    {

        if(vec[j].getFechaDePago().getMes()==mes)
        {

            for (int i=0; i<cantidadRegistros; i++)
            {
                mayor = i;

                for (int j = i + 1; j < cantidadRegistros; j++)
                {


                    if (vec[j].getFechaDePago().getMes()<= vec[mayor].getFechaDePago().getMes()&&
                            vec[j].getFechaDePago().getDia()<= vec[mayor].getFechaDePago().getDia() )
                    {
                        mayor = j;
                    }
                }

                if (i != mayor)
                {
                    aux = vec[i];
                    vec[i] = vec[mayor];
                    vec[mayor] = aux;
                }

            }
        }
    }
}
*/

int PagoManager::generarPago()
{
    PagoArchivo _archivo;
    return _archivo.getCantidad()+1;
}
//void PagoManager::ListarXdni()
//{
//
//    PagoArchivo _archivo;
//
//    int dni;
//    rectangulo (2, 2, 100, 26);
//    rlutil::setColor(rlutil::YELLOW);
//
//    rlutil::locate(20,9);
//    cout << "INGRESE DNI ALUMNO: ";
//    cin >> dni;
//    system("cls");
//
//
//
//    int posicion = _archivo.buscarReg(dni);
//    if (posicion >= 0)
//    {
//        Pago reg = _archivo.leerReg(posicion);
//        Listar(reg);
//    }
//    else
//    {
//        rlutil::locate(20,10);
//        cout << "** NO EXISTE UN PAGO CON ESE DNI **" << endl;
//        system("pause>nul");
//    }
//}



void PagoManager::Listar(Pago pago)
{


    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   LISTA DE PAGOS   *****", 34, 4);

    if(pago.getEliminado()==false){

    rlutil::locate(20,9);
    cout<<"DNI ALUMNO:    " <<pago.getDNIalumno()<<endl;
    rlutil::locate(20,10);
    cout<<"NUMERO DE PAGO :    "<<pago.getNroPago()<<endl;
    rlutil::locate(20,11);
    cout<<"MONTO :    "<<pago.getMonto()<<endl;
    rlutil::locate(20,12);
    cout<<"FECHA DE PAGO :    " <<pago.getFechaDePago().toString()<<endl;
    rlutil::locate(20,13);



    system("pause>nul");
    system("cls");

}
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
//void PagoManager::Editar()
//{
//    Pago reg;
//    int dni, posicion;
//
//    rlutil::locate(20,9);
//    cout << "DNI A MODIFICAR: ";
//    cin >> dni;
//    cout << endl;
//
//    system("cls");
//    mostrar_mensaje ("***** MODIFICAR DE PAGOS ***** ", 34, 4);
//    posicion = _archivo.buscarReg(dni);
//    if (posicion >= 0)
//    {
//        reg = _archivo.leerReg(posicion);
//
//        Listar(reg);
//        cout << endl;
//
//        int nuevoEstado;
//        rlutil::locate(20,10);
//        cout << "DESEA MODIFICAR ALGUN DATO? (1-SI/2-NO): ";
//        rlutil::locate(64,20);
//        cin >> nuevoEstado;
//
//        if (nuevoEstado==1)
//        {
//            ModificarDatos(reg,posicion);
//
//        }
//
//    }
//    else
//    {
//        system("pause>nul");
//    }
//}

void PagoManager::EliminarPago()
{

	Pago reg;
	int NroPago, posicion;
	cout << "Nro de pago a eliminar : ";
	cin >> NroPago;
	cout << endl;

	posicion = _archivo.buscarRegistro(NroPago);
	if (posicion >= 0)
	{
		reg = _archivo.leerReg(posicion);
		Listar(reg);
		cout << endl;
		reg.setEliminado(true);
		_archivo.guardar(reg, posicion);
		cout << "Registro #" << NroPago << " eliminado correctamente" << endl;
	}
	else
	{
		cout << "No existe el Numero de pago #" << NroPago << endl;
	}
}




void PagoManager::MenuInformePagos()
{
    PagoManager obj;

    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 26);
    mostrar_mensaje ("*****   INFORMES DE PAGOS   ***** ", 34, 4);

    int mes;
    rlutil::locate(15,10);
    cout <<"POR FAVOR INGRESE EL MES A CONSULTAR: ";
    rlutil::locate(55,10);
    cin>>mes;
    system("cls");
    if (mes>=0&&mes<=12)
    {

        obj.ListarOrdenadosPorFecha(mes);

    }
    else
    {

        rlutil::locate(30,15);
        cout <<"****  EL MES INGRESADO ES INCORRECTO  *** ";
    }


}
void PagoManager::ListarxDNI(int dni)
{


    int cantidadRegistros = _archivo.getCantidad();
    Pago *vec = new Pago[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Error al visualizar el listado";
        return;
    }

    for(int x=0; x<cantidadRegistros; x++)
    {
        vec[x]=_archivo.leerReg(x);
    }


    for(int i=0; i<cantidadRegistros; i++)
    {

        if (vec[i].getDNIalumno()==dni)
        {
            system("cls");
            Listar(vec[i]);
            cout << endl;
            system("pause>nul");
            system("cls");

        }

    }

    delete []vec;

}
void PagoManager::HacerCopiaDeSeguridad()
{

    int cantidadRegistros = _archivo.getCantidad();
    Pago *vec = new Pago[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    _archivo.leer(vec, cantidadRegistros);
    _archivoBkp.vaciar();
    if (_archivoBkp.guardar(vec, cantidadRegistros))
    {
        cout << "Backup realizado correctamente" << endl;
        system("pause>nul");
    }
    else
    {
        cout << "Falla al realizar backup" << endl;
        system("pause>nul");
    }

    delete []vec;
}

void PagoManager::RestaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidad();
    Pago *vec = new Pago[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    _archivo.vaciar();
    if (_archivo.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
        system("pause>nul");
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
        system("pause>nul");
    }

    delete []vec;
}
