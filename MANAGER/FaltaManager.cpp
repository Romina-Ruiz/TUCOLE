#include <iostream>
#include "FaltaManager.h"
#include"Falta.h"
#include"FaltaArchivo.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"
#include"Alumno.h"
#include"AlumnoArchivo.h"
#include "../MENUS/FUNCIONES_FRONT.h"

using namespace std;


void FaltaManager::Cargar()
{
    AlumnoArchivo alumno;

    int anuales=0, falta=0, op;
    int dni, dia, mes, anio;

    rlutil::locate(20,8);
    cout << "INGRESE DNI ALUMNO: " <<endl;
    rlutil::locate(41,8);
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

        rlutil::locate(60,10);
        cout << "FALTAS ANUALES PERMITIDAD: "<<endl;
        rlutil::locate(90,10);
        cout << anuales <<endl;
        rlutil::locate(20,11);
        cout << "INGRESE DIA DE LA FALTA: "<<endl;
        rlutil::locate(45,11);
        cin >> dia;
        rlutil::locate(20,12);
        cout << "INGRESE MES DE LA FALTA: "<<endl;
        rlutil::locate(45,12);
        cin >> mes;
        rlutil::locate(20,13);
        cout << "INGRESE ANIO DE LA FALTA: "<<endl;
        rlutil::locate(45,13);
        cin >> anio;

        rlutil::locate(20,15);
        cout << "CARGAR FALTA (1-SI/ 2-NO): "<<endl;
        rlutil::locate(47,15);
        cin>>op;
        if (op==1)
        {
            rlutil::locate(55,17);
            falta++;

            cout<<falta<<endl;



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

void FaltaManager::ListarTodos()
{

    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Falta reg = _archivo.leerReg(i);

        Listar(reg);
        cout << endl;

    }
}
void FaltaManager::ListarXdni()
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    int dni;
    rlutil::locate(10,8);
    cout<<"DNI "<<endl;
    rlutil::locate(15,9);
    cin>>dni;

    Falta obj;
    int cantReg=_archivo.getCantidad();
    int FaltasTotales=0;

    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (dni==obj.getDNIAlumno())
        {
            rlutil::locate(8,10);
            cout <<"FECHA DE LA AUSENCIA :  "<<obj.getFechaAusencia().toString()<<endl;
            rlutil::locate(33,11);
            FaltasTotales+=obj.getFalta();

            system("pause>nul");
            system("cls");
        }

    }
    rlutil::locate(20,10);
    cout<<"FALTAS TOTALES : " << FaltasTotales<<endl;
    system("pause>nul");
    system("cls");

    if(FaltasTotales>=6)
    {
        rlutil::locate(10,10);
        cout<<"ATENCION ! "<<endl;
        rlutil::locate(10,12);
        cout<<"TIENE EL MAXIMO DE FALTAS PERMITIDAS,POR FAVOR, COMUNIQUESE CON LAS AUTORIDADES DEL COLEGIO. "<<endl;
    }
    system("pause>nul");
    system("cls");
    rlutil::locate(45,17);
    cout <<"****FIN DEL COMUNICADO ****"<<endl;
}
void FaltaManager::Listar(Falta falta)
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout<<"DNI ALUMNO :         " <<falta.getDNIAlumno()<<endl;
    rlutil::locate(20,10);
    cout<<"FECHA DE AUSENCIA :     " <<falta.getFechaAusencia().toString()<<endl;
    rlutil::locate(20,11);
    cout<<" CANTIDAD DE FALTAS ANUALES : " <<falta.getCantFaltasAnuales()<<endl;
    rlutil::locate(20,12);
    cout<<" FALTA : " <<falta.getFalta()<<endl;

    system("pause>nul");
    system("cls");
}
