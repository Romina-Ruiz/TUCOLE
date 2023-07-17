#include <iostream>
#include "FaltaManager.h"
#include"Falta.h"
#include"FaltaArchivo.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"
#include"Alumno.h"
#include"AlumnoArchivo.h"
#include "../MENUS/FUNCIONES_FRONT.h"
#include"../MENUS/FUNCIONES_ADMIN.h"

using namespace std;


void FaltaManager::Cargar()
{
    AlumnoArchivo alumno;

    int anuales=6, falta=0, op;
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

        rlutil::locate(60,9);
        cout << "FALTAS ANUALES PERMITIDAD: "<<endl;
        rlutil::locate(90,9);
        cout << anuales <<endl;
        rlutil::locate(20,11);
        cout << "INGRESE DIA DE LA FALTA: "<<endl;
        rlutil::locate(46,11);
        cin >> dia;
        rlutil::locate(20,12);
        cout << "INGRESE MES DE LA FALTA: "<<endl;
        rlutil::locate(46,12);
        cin >> mes;
        rlutil::locate(20,13);
        cout << "INGRESE ANIO DE LA FALTA: "<<endl;
        rlutil::locate(46,13);
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
            aux.setEliminada(false);


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
void FaltaManager::ListarXdni(int dni)
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****  AUSENCIAS  ***** ", 34, 4);

    Falta obj;
    int cantReg=_archivo.getCantidad();
    int FaltasTotales=0;
    int can=1;
    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);


        if (dni==obj.getDNIAlumno()&&obj.getEliminada()==false)
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

    system("cls");
    rectangulo (2, 2, 100, 26);
    rlutil::locate(30,10);
    cout <<"****FIN DEL REPORTE ****"<<endl;
}

void FaltaManager::Listar(Falta falta)
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,12);
    cout<<"DNI ALUMNO :         " <<falta.getDNIAlumno()<<endl;
    rlutil::locate(20,13);
    cout<<"FECHA DE AUSENCIA :     " <<falta.getFechaAusencia().toString()<<endl;
    rlutil::locate(20,11);
    cout<<" CANTIDAD DE FALTAS ANUALES : " <<falta.getCantFaltasAnuales()<<endl;
    rlutil::locate(20,12);
    cout<<" FALTA : " <<falta.getFalta()<<endl;

    system("pause>nul");
    system("cls");
}

void FaltaManager::Editar()
{

    rectangulo (2, 2, 100, 26);
    mostrar_mensaje ("***** MODIFICAR AUSENCIAS ***** ", 34, 4);
    Falta reg;
    int dni, posicion, dia,mes,anio;
    int CantidadRegistros=_archivo.getCantidad();

    rlutil::locate(20,9);
    cout << "DNI A MODIFICAR: ";
    cin >> dni;
    rlutil::locate(20,12);
    cout<<"INGRESE LA FECHA DE LA FALTA QUE DESEA EDITAR" <<endl;
    rlutil::locate(20,13);
    cout<< "DIA:  ";
    cin>>dia;
    rlutil::locate(20,14);
    cout<<"MES: ";
    cin>>mes;
    rlutil::locate(20,15);
    cout<<"ANIO: ";
    cin>>anio;

    for(int i=0; i<CantidadRegistros; i++)
    {

        reg = _archivo.leerReg(i);

        if(dni==reg.getDNIAlumno()&& reg.getEliminada()==false)
        {

            posicion=BuscarFalta(dni,dia,mes,anio);

            system("cls");
            mostrar_mensaje ("***** MODIFICAR DE FALTA***** ", 34, 4);

            if (posicion >= 0)
            {
                reg = _archivo.leerReg(posicion);

                int nuevoEstado;
                rlutil::locate(20,8);
                cout << "DESEA MODIFICAR ALGUN DATO? (1-SI/2-NO):  ";
                cin >> nuevoEstado;

                if (nuevoEstado==1)
                {
                    ModificarDatos(reg,posicion);

                }

            }

        }

    }

    system("cls");
    rectangulo (2, 2, 100, 26);
    mostrar_mensaje ("***** NO EXISTE UNA AUSENCIA CON ESA FECHA***** ", 20, 15);
    system("pause>nul");
    system("cls");

}

int FaltaManager::BuscarFalta(int dni,int dia,int mes,int anio)

{

    int noexiste=-1;
    FaltaArchivo falta;
    Falta obj;
    int cantReg=falta.getCantidad();


    for(int i=0; i<cantReg; i++)
    {

        obj= falta.leerReg(i);

        if(obj.getDNIAlumno()==dni && obj.getEliminada()== false)
        {

            if(obj.getFechaAusencia().getAnio()==anio&&obj.getFechaAusencia().getMes()==mes&&obj.getFechaAusencia().getDia()==dia)
            {

                return i;

            }


        }


    }

    return noexiste;
}

void FaltaManager::ModificarDatos(Falta obj, int posicion)

{
    system("cls");
    const char *opciones[] = {"FECHA DE AUSENCIA", "ELIMINAR UNA FALTA", "VOLVER AL MENU PRINCIPAL"};

    mostrar_mensaje ("* MODIFICAR DATOS DE LA AUSENCIA *", 40, 4);
    mostrar_mensaje ("--------------------------------", 40, 5);

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);


        rlutil::locate(26,10+y);
        cout <<"==> " <<endl;

        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y--;

            if (y<0)
            {
                y=0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(26,10+y);
            cout <<"   " <<endl;
            y++;

            if (y>3)
            {
                y=3;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      /// CAMBIO DE FECHA
                system("cls");
                {
                    rectangulo (2, 2, 100, 26);
                    mostrar_mensaje ("* MODIFICAR FECHA DE AUSENCIA *", 40, 4);
                    mostrar_mensaje ("--------------------------------", 40, 5);
                    int dia,mes,anio;
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO DIA : "<<endl;
                    rlutil::locate(45,9);
                    cin>>dia;
                    rlutil::locate(20,10);
                    cout << "INGRESE EL NUEVO MES : "<<endl;
                    rlutil::locate(45,10);
                    cin>>mes;
                    rlutil::locate(20,11);
                    cout << "INGRESE EL NUEVO ANIO : "<<endl;
                    rlutil::locate(45,11);
                    cin>>anio;


                    obj.setFechaAusencia(Fecha(dia,mes,anio));

                    if (_archivo.modificar(obj, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "** REGISTRO MODIFICADO **"<<endl;
                    }

                    system("pause>nul");
                    system("cls");
                }

                break;

            case 1:       /// DAR DE BAJA UNA AUSENCIA
                system("cls");
                {
                    rectangulo (2, 2, 100, 26);
                    mostrar_mensaje ("* ELIMINAR UNA AUSENCIA *", 40, 4);
                    mostrar_mensaje ("--------------------------------", 40, 5);

                    int res;
                    rlutil::locate(20,8);
                    cout << "ESTA SEGURO DE ELIMINAR LA AUSENCIA (1-SI / 2-NO)" << endl;
                    rlutil::locate(20,9);
                    cout <<"RESPUESTA: ";
                    cin>>res;

                    if (res==1)
                    {
                        obj = _archivo.leerReg(posicion);

                        obj.setEliminada(true);

                        _archivo.modificar(obj, posicion);
                        rlutil::locate(30,15);
                        cout << "REGISTRO ELIMINADO CORRECTAMENTE" << endl;
                        system("pause>nul");
                        system("cls");
                    }

                }

                break;

            case 2:     /// SALIR
            {
                system("cls");
                menuAusencias();
                system("cls");
            }

            break;
            }
        }
    }
    while(op!=0);

    system("pause>nul");

}


void FaltaManager::AusenciasXfecha()
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    int mes;
    rlutil::locate(10,8);

    rlutil::locate(10,10);
    cout<<"Ingrese MES :" <<endl;
    rlutil::locate(10,11);
    cin>>mes;



    Falta obj;
    int cantReg=_archivo.getCantidad();

    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (obj.getFechaAusencia().getMes()==mes)
        {
            if(obj.getFechaAusencia().getDia()<obj.getFechaAusencia().getDia())
            {

                system("cls");
                rlutil::locate(8,9);
                cout<<"FECHA AUSENCIA: "<<obj.getFechaAusencia().toString()<<endl;
                rlutil::locate(20,10);
                cout <<" DNI "<<obj.getDNIAlumno()<<endl;
                rlutil::locate(22,11);
                cout<<obj.getFalta()<<"FALTA ."<<endl;

                rlutil::locate(33,9);

                system("pause>nul");
                system("cls");
            }

        }
    }
    rlutil::locate(30,9);
    cout <<"FIN DEL LISTADO "<<endl;
}

void FaltaManager::Ordenar(Falta *vec, int cantidadRegistros)
{
    int mayor = 0;

    Falta aux;

    for (int i=0; i<cantidadRegistros; i++)
    {
        mayor = i;

        for (int j = i + 1; j < cantidadRegistros; j++)
        {


            if (vec[j].getFechaAusencia().getAnio() < vec[mayor].getFechaAusencia().getAnio()&&
                    vec[j].getFechaAusencia().getMes() < vec[mayor].getFechaAusencia().getMes()&&
                    vec[j].getFechaAusencia().getDia() < vec[mayor].getFechaAusencia().getDia())
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



void FaltaManager::ListarOrdenadosPorFecha()
{

    int cantidadRegistros =_archivo.getCantidad();
    Falta *vec = new Falta[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Error al visualizar el listado";
        return;
    }

    _archivo.leer(vec, cantidadRegistros);
    Ordenar(vec, cantidadRegistros);

    for(int i=0; i<cantidadRegistros; i++)
    {
        Listar(vec[i]);
        cout << endl;
    }

    delete []vec;

}

void FaltaManager::TotalAusencias(){

Falta obj;
int cantidadRegistros =_archivo.getCantidad();
int MatrizTotales[12][3]={};

for (int x=0; x<cantidadRegistros; x++){

    obj=_archivo.leerReg(x);

    int curso, dni;/// HACER UNA FUNCION PARA QUE LEA EL ARC DE ALUMNO Y EL ARC DE CURSOS Y TRAIGA EL CURSO DONDE ESTA EL DNI
    if(obj.getEliminada()==false&&dni==obj.getDNIAlumno()){

        VecTotales[obj.getFechaAusencia().getMes()][curso] ++;


    }

}




}

void FaltaManager::InformeAusencias(){

system("cls");
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("***** INFORME SOBRE AUSENCIA ANUAL ***** ", 30, 4);

    mostrar_mensaje ("CURSO 1 ", 25, 6);
    mostrar_mensaje ("CURSO 2 ", 45, 6);
    mostrar_mensaje ("CURSO 3 ", 65, 6);
    mostrar_mensaje ("MES: ", 6, 6);
    mostrar_mensaje ("TOTAL / %", 23, 7);
    mostrar_mensaje ("TOTAL / %", 43, 7);
    mostrar_mensaje ("TOTAL / %", 63, 7);

    mostrar_mensaje ("ENERO: ", 6, 9);
    mostrar_mensaje ("FEBRERO: ", 6, 10);
    mostrar_mensaje ("MARZO: ", 6, 11);
    mostrar_mensaje ("ABRIL: ", 6, 12);
    mostrar_mensaje ("MAYO: ", 6, 13);
    mostrar_mensaje ("JUNIO: ", 6, 14);
    mostrar_mensaje ("JULIO: ", 6, 15);
    mostrar_mensaje ("AGOSTO: ", 6, 16);
    mostrar_mensaje ("SEPTIEMBRE: ", 6, 17);
    mostrar_mensaje ("OCTUBRE: ", 6, 18);
    mostrar_mensaje ("NOVIEMBRE: ", 6, 19);
    mostrar_mensaje ("DICIEMBRE: ", 6, 20);




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
