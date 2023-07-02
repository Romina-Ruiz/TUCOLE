#include <iostream>
#include <iomanip>
#include <cstring>
#include"../MENUS/rlutil.h"
#include"CuotaManager.h"
#include"CuotaArchivo.h"
#include"AlumnoArchivo.h"
#include"Alumno.h"
#include "../MENUS/FUNCIONES_FRONT.h"
#include "Pago.h"
#include"PagoArchivo.h"
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
        aux.settipoDeCuota(tipo);
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

}
int CuotaManager::generarFactura()
{
    CuotaArchivo _archivo;
    return _archivo.getCantidad()+1;
}
void CuotaManager::ListarTodos()
{

    CuotaArchivo _archivo;

    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Cuota reg = _archivo.leerReg(i);

        Listar(reg);

        system("pause>nul");

    }
}

void CuotaManager::Listar(Cuota cuota)
{
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****   FACTURAS EMITIDAS   *****", 34, 4);

    rlutil::locate(20,9);
    cout<<"DNI ALUMNO:    " <<cuota.getDNIalumno()<<endl;
    rlutil::locate(20,10);
    cout<<"TIPO DE CUOTA :    "<<cuota.gettipoDeCuota()<<endl;
    rlutil::locate(20,11);
    cout<<"NUMERO DE FACTURA :    "<<cuota.getNroFact()<<endl;
    rlutil::locate(20,12);
    cout<<"MONTO :    " <<cuota.getMonto()<<endl;
    rlutil::locate(20,13);
    cout<<"FECHA DE FACTURA :    " <<cuota.getFechaDeFact().toString()<<endl;
    rlutil::locate(20,14);
    cout<<"ESTADO :    " <<cuota.getDebe()<<endl;



}

void CuotaManager::MenuInformeCuotas()
{

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

        this->ListarOrdenadosPorFecha(mes);

    }
    else
    {

        rlutil::locate(30,15);
        cout <<"****  EL MES INGRESADO ES INCORRECTO  *** ";
    }


}
void CuotaManager::ListarOrdenadosPorFecha(int mes)
{
    CuotaArchivo _archivo;

    int cantidadRegistros = _archivo.getCantidad();
    Cuota *vec = new Cuota[cantidadRegistros] {};

    if (vec == nullptr)
    {
        cout << "Error al visualizar el listado";
        return;
    }

    for(int x=0; x<cantidadRegistros; x++)
    {
        vec[x]= _archivo.leerReg(x);
    }

    int suma=0;
    int contador=0;
    for(int i=0; i<cantidadRegistros; i++)
    {

        if (vec[i].getFechaDeFact().getMes()==mes&&vec[i].getDebe()==true)
        {
            rlutil::locate(20,10);
            suma+=vec[i].getMonto();
            contador++;
            Listar(vec[i]);
            system("pause>nul");
            cout << endl;
            system("cls");

        }


    }
    rlutil::locate(15,10);
    cout <<"EL TOTAL DE FACTURADO DE ESTE MES ES DE $  "<<suma<<endl;
    rlutil::locate(15,11);
    cout <<"TOTAL DE FACTURAS EMITIDAS  "<<contador<<endl;
    delete []vec;

}

void CuotaManager::MenuUserPagosyCuotas(int dni)
{
    CuotaArchivo _arCuota;
    PagoArchivo _arPago;

    int canRegCuota = _arCuota.getCantidad();
    int canRegPago= _arPago.getCantidad();
    Pago *vecPago= new Pago[canRegPago] {};
    Cuota *vecCuota = new Cuota[canRegCuota] {};

    int sumaCuotas=0;
    int sumaPagos=0;

    if (vecPago ==nullptr)
    {
        cout << "Error al visualizar el listado";
        return;
    }
    if (vecCuota == nullptr)
    {
        cout << "Error al visualizar el listado";
        return;
    }
    rlutil::locate(10,4);
    cout <<"FACTURAS: " <<endl;
    int c=0;
    for(int x=0; x<canRegCuota; x++)
    {
        vecCuota[x]=_arCuota.leerReg(x);

        if (dni==vecCuota[x].getDNIalumno()&&vecCuota[x].getDebe()==true)
        {
            sumaCuotas+=vecCuota[x].getMonto();
            c++;
            rlutil::locate(10,5+c);
            cout <<vecCuota[x].getFechaDeFact().toString();
            rlutil::locate(20,5+c);
            cout <<vecCuota[x].getNroFact();
            rlutil::locate(30,5+c);
            cout <<vecCuota[x].getMonto();
            cout<<endl;
        }
    }
    rlutil::locate(10,13);
    cout <<"-------------------------------------------" <<endl;
    rlutil::locate(10,14);
    cout <<"PAGOS: " <<endl;
    int d=0;

    for (int j=0; j<canRegPago; j++)
    {
        vecPago[j]=_arPago.leerReg(j);

        if (vecPago[j].getDNIalumno()==dni&&vecPago[j].getEliminado()==false)
        {

            sumaPagos+=vecPago[j].getMonto();
            d++;
            rlutil::locate(10,15+d);
            cout <<vecPago[j].getFechaDePago().toString();
            rlutil::locate(20,15+d);
            cout <<vecPago[j].getNroPago();
            rlutil::locate(30,15+d);
            cout <<vecPago[j].getMonto();
            cout<<endl;
        }
    }
    rlutil::locate(15,27);
    cout <<"EL TOTAL A PAGAR $: "<<sumaCuotas-sumaPagos<<endl;

    delete []vecPago;
    delete []vecCuota;

    system("pause>nul");
    cout << endl;
    system("cls");

}


void CuotaManager::HacerCopiaDeSeguridad()
{
    CuotaArchivo _archivoBkp = CuotaArchivo("cuota.bkp");
    CuotaArchivo _archivo;
    int cantidadRegistros = _archivo.getCantidad();
    Cuota *vec = new Cuota[cantidadRegistros];

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

void CuotaManager::RestaurarCopiaDeSeguridad()
{
    CuotaArchivo _archivoBkp = CuotaArchivo("cuota.bkp");
    CuotaArchivo _archivo;
    int cantidadRegistros = _archivoBkp.getCantidad();
    Cuota *vec = new Cuota[cantidadRegistros];

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
void CuotaManager::ListarxDNI(int dni)
{
    CuotaArchivo _archivo;

    int cantidadRegistros = _archivo.getCantidad();
    Cuota *vec = new Cuota[cantidadRegistros];

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

        rlutil::locate(30,10);
        cout <<" NO HAY MAS REGISTROS" << endl;
    }

    delete []vec;

}
