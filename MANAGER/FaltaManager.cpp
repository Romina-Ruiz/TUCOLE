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
    cout<<"INGRESE EL DNI A CONSULTAR: "<<endl;
    rlutil::locate(40,8);
    cin>>dni;

    Falta obj;
    int cantReg=_archivo.getCantidad();
    int FaltasTotales=0;
    int can=1;
    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);


        if (dni==obj.getDNIAlumno())
        {
            can++;
            rlutil::locate(10,10+can);
            cout <<"FECHA DE LA AUSENCIA :  "<<obj.getFechaAusencia().toString()<<endl;
            rlutil::locate(35,10+can);
            FaltasTotales+=obj.getFalta();
            system("pause>nul");

        }

    }
    rlutil::locate(20,25);
    cout<<"FALTAS TOTALES : " << FaltasTotales<<endl;
    system("pause>nul");

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
//
//void FaltaManager::Editar()
//{
//
//    Falta reg;
//    int dni, posicion;
//
//    rlutil::locate(20,9);
//    cout << "DNI A MODIFICAR: ";
//    cin >> dni;
//    cout << endl;
//
//    system("cls");
//    mostrar_mensaje ("***** MODIFICAR DE FALTA***** ", 34, 4);
//    posicion = _archivo.buscarReg(dni);
//    if (posicion >= 0)
//    {
//        reg = _archivo.leerReg(posicion);
//        Listar(reg);
//        cout << endl;
//
//        int nuevoEstado;
//        rlutil::locate(20,20);
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
//
//
//}
//void FaltaManager::BuscarFalta(int dia,mes,anio){
//
//    FaltaArchivo falta;
//    Falta obj;
//    int cantReg=falta.getCantidad();
//
//    for(int i=0;i<cantReg;i++){
//        obj= falta.leerReg(i);
//
//        if(obj.getFechaAusencia().getAnio()==anio&&obj.getFechaAusencia().getMes()==mes&&obj.getFechaAusencia().getDia()==dia){
//
//
//        }
//    }
//
//}
//
//void FaltaManager::ModificarDatos(Falta obj, int posicion)
//{
//    system("cls");
//    const char *opciones[] = {"FECHA DE AUSENCIA", "ELIMINAR UNA FALTA","CANTIDAD DE FALTAS ANUALES", "VOLVER AL MENU PRINCIPAL"};
//
//    mostrar_mensaje ("* MODIFICAR DATOS DE LA AUSENCIA *", 40, 4);
//    mostrar_mensaje ("--------------------------------", 40, 5);
//
//    rlutil::saveDefaultColor();
//    rectangulo (2, 2, 100, 26);
//    rlutil::setColor(rlutil::YELLOW);
//
//    int op=1, y=0;
//
//    rlutil::hidecursor();
//
//    do
//    {
//        rlutil::saveDefaultColor();
//        rlutil::setColor(rlutil::YELLOW);
//
//        showItem (opciones[0],30,10,y==0);
//        showItem (opciones[1],30,11,y==1);
//        showItem (opciones[2],30,12,y==2);
//        showItem (opciones[3],30,13,y==3);
//
//        rlutil::locate(26,10+y);
//        cout <<"==> " <<endl;
//
//        switch(rlutil::getkey())
//        {
//        case 14: //UP
//            rlutil::locate(26,10+y);
//            cout <<"   " <<endl;
//            y--;
//
//            if (y<0)
//            {
//                y=0;
//            }
//            break;
//
//        case 15: //DOWN
//            rlutil::locate(26,10+y);
//            cout <<"   " <<endl;
//            y++;
//
//            if (y>3)
//            {
//                y=3;
//            }
//            break;
//
//        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):
//
//            switch(y)
//            {
//            case 0:      /// CAMBIO DE FECHA
//                system("cls");
//                {
//                    mostrar_mensaje ("* MODIFICAR FECHA DE AUSENCIA *", 40, 4);
//                    mostrar_mensaje ("--------------------------------", 40, 5);
//                    int dia,mes,anio;
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO DIA : "<<endl;
//                    rlutil::locate(43,9);
//                    cin>>dia;
//                    cout << "INGRESE EL MES : "<<endl;
//                    rlutil::locate(43,9);
//                    cin>>mes;
//                    cout << "INGRESE EL ANIO : "<<endl;
//                    rlutil::locate(43,9);
//                    cin>>anio;
//
//                    obj.setFechaAusencia(Fecha(dia,mes,anio));
//
//                    if (_archivo.guardar(posicion))
//                    {
//
//                        rlutil::locate(30,15);
//                        cout << "** REGISTRO MODIFICADO **"<<endl;
//                    }
//
//                    system("pause>nul");
//                    system("cls");
//                }
//
//                break;
//
//            case 1:       /// DAR DE BAJA UNA AUSENCIA
//                system("cls");
//                mostrar_mensaje ("* ELIMINAR UNA AUSENCIA *", 40, 4);
//                mostrar_mensaje ("--------------------------------", 40, 5);
//
//                {
//
//                    Fecha obj;
//                    rlutil::locate(20,9);
//                    cout << "INGRESE LA FECHA A MODIFICAR: "<<endl;
//                    int dia,mes,anio;
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL  DIA: "<<endl;
//                    rlutil::locate(43,9);
//                    cin>>dia;
//                    cout << "INGRESE EL MES DIA: "<<endl;
//                    rlutil::locate(43,9);
//                    cin>>mes;
//                    cout << "INGRESE EL ANIO: "<<endl;
//                    rlutil::locate(43,9);
//                    cin>>anio;
//
//                    =BuscarFalta(dia,mes,anio);
//
//
//                    system("pause>nul");
//                    system("cls");
//                }
//
//                break;
//
//            case 2:       /// MODIFICAR LAS AUSENCIAS PERMITIDAS
//                system("cls");
//                mostrar_mensaje ("* MODIFICAR AUSENCIAS PERMITIDAS *", 40, 4);
//                mostrar_mensaje ("--------------------------------", 40, 5);
//
//                {
//
//
//
//                }
//
//                system("pause>nul");
//                system("cls");
//            }
//
//            break;
//
//        case 3:     /// SALIR
//
//        {
//
//
//                            system("pause>nul");
//                           system("cls");
//
//
//        }
//
//        break;
//
//        }
//    }
//    while(op!=0);
//
//    system("pause>nul");
//
//

void FaltaManager::AusenciasXfecha(){

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    int dia,mes,anio;
    rlutil::locate(10,8);
    cout<<"Ingrese DIA: "<<endl;
     rlutil::locate(10,9);
    cin>>dia;
     rlutil::locate(10,10);
    cout<<"Ingrese MES :" <<endl;
     rlutil::locate(10,11);
    cin>>mes;
     rlutil::locate(10,12);
    cout<<"Ingrese ANIO :"<<endl;
     rlutil::locate(10,13);
    cin>>anio;


    Falta obj;
    int cantReg=_archivo.getCantidad();

    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (obj.getFechaAusencia().getDia()==dia&&
            obj.getFechaAusencia().getMes()==mes&&
            obj.getFechaAusencia().getAnio()==anio)
        {
            rlutil::locate(8,9);
            cout<<"FECHA AUSENCIA: "<<obj.getFechaAusencia().toString()<<endl;
            cout <<" DNI "<<obj.getDNIAlumno()<<endl;
            cout<<obj.getFalta()<<"FALTA ."<<endl;

            rlutil::locate(33,9);

             system("pause>nul");
            system("cls");
        }

    }
                rlutil::locate(30,9);
                cout <<"FIN DEL LISTADO "<<endl;
}





void FaltaManager::HacerCopiaDeSeguridad()
{

    int cantidadRegistros = _archivo.getCantidad();
    Falta *vec = new Falta[cantidadRegistros];

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

void FaltaManager::RestaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidad();
    Falta *vec = new Falta[cantidadRegistros];

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
