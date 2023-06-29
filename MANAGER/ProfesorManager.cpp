#include <iostream>
#include "ProfesorManager.h"
#include "Profesor.h"
#include "ProfesorArchivo.h"
#include"../MENUS/rlutil.h"
#include "../MENUS/Fecha.h"
#include"../MENUS/FUNCIONES_FRONT.h"
#include"../MENUS/FUNCIONES_ADMIN.h"
using namespace std;


void ProfesorManager::Cargar()

{
    char nombre[30], apellido[30], email[30];
    int Legajo, telefono;
    int dni, dia, mes, anio;

    rlutil::locate(20,8);
    cout << "INGRESE DNI #: " <<endl;
    rlutil::locate(35,8);
    cin>>dni;

    int numerodeRegistro=buscarDNI(dni);

    if(numerodeRegistro>0)
    {

        rlutil::locate(20,10);
        cout<<"EL DNI YA EXISTE !!";
        system("pause>nul");
    }
    else
    {

        rlutil::locate(20,9);
        cout << "INGRESE NOMBRE: "<<endl;
        rlutil::locate(39,9);
        cin>>nombre;
        rlutil::locate(20,10);
        cout << "INGRESE APELLIDO: "<<endl;
        rlutil::locate(41,10);
        cin >> apellido;
        rlutil::locate(20,11);
        cout << "INGRESE EMAIL: "<<endl;
        rlutil::locate(38,11);
        cin >> email;
        rlutil::locate(20,12);
        cout << "INGRESE TELEFONO: "<<endl;
        rlutil::locate(41,12);
        cin >> telefono;
        rlutil::locate(20,13);
        cout << "INGRESE DIA DE INGRESO: "<<endl;
        rlutil::locate(45,13);
        cin >> dia;
        rlutil::locate(20,14);
        cout << "INGRESE MES DE INGRESO: "<<endl;
        rlutil::locate(45,14);
        cin >> mes;
        rlutil::locate(20,15);
        cout << "INGRESE ANIO DE INGRESO: "<<endl;
        rlutil::locate(45,15);
        cin >> anio;
        Legajo=this->generarLegajo();
        rlutil::locate(20,16);
        cout << "LEGAJO: "<<  Legajo <<endl;
        rlutil::locate(30,17);
        cout << "ESTADO: "<< "Activo" <<endl;

        Profesor aux;
        aux.setDNI(dni);
        aux.setNombre(nombre);
        aux.setApellido(apellido);
        aux.setEmail(email);
        aux.setTelefono(telefono);
        aux.setIngreso(Fecha(dia, mes, anio));
        aux.setLegajo(Legajo);
        aux.setEstado(1);


        if (_archivo.agregar(aux))
        {
            rlutil::locate(30,23);
            cout << "** PROFESOR GUARDADO CORRECTAMENTE **" << endl;
            system("pause>nul");
            // system("cls");
        }
        else
        {
            rlutil::locate(30,25);
            cout << "** UPS! ALGO SALIO MAL:( **" << endl;
            system("pause>nul");
        }
    }

}

int ProfesorManager::buscarDNI(int dni)
{

    return _archivo.buscarReg(dni)>=0;

}

int ProfesorManager::generarLegajo()
{

    return _archivo.getCantidad()+1;
}

void ProfesorManager::ListarTodos()
{

    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Profesor reg = _archivo.leerReg(i);
        if (reg.getEstado()==true)
        {
            Listar(reg);
            cout << endl;
        }
    }
}
void ProfesorManager::Listar(Profesor profesor)
{
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout<<"DNI:    " <<profesor.getDni()<<endl;
    rlutil::locate(20,10);
    cout<<"NOMBRE:    "<<profesor.getNombre()<<endl;
    rlutil::locate(20,11);
    cout<<"APELLIDO:    "<<profesor.getApellido()<<endl;
    rlutil::locate(20,12);
    cout<<"EMAIL:    " <<profesor.getEmail()<<endl;
    rlutil::locate(20,13);
    cout<<"TELEFONO:    "<<profesor.getTelefono()<<endl;
    rlutil::locate(20,14);
    cout <<"FECHA DE INGRESO:    " << profesor.getIngreso().toString()<< endl;
    rlutil::locate(20,15);
    cout <<"LEGAJO:    " << profesor.getLegajo() << endl;

    if (profesor.getEstado()==true)
    {
        rlutil::locate(20,16);
        cout <<"ESTADO:    " << "Activo" << endl;
    }
    else if(profesor.getEstado()==false)
    {
        rlutil::locate(20,16);
        cout <<"ESTADO:    " << "Baja" << endl;
    }
    rlutil::locate(20,18);
    cout <<"--------------------------------------------------------------" << endl;

    system("pause>nul");
    system("cls");


}


void ProfesorManager::ListarXdni()
{
    int dni;
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout << "INGRESE DNI PROFESOR: ";
    cin >> dni;
    system("cls");

    int posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        Profesor reg = _archivo.leerReg(posicion);
        Listar(reg);
    }
    else
    {
        rlutil::locate(20,10);
        cout << "** NO EXISTE UN PROFESOR CON ESE DNI **" << endl;
        system("pause>nul");
    }
}




void ProfesorManager::Editar()
{
    Profesor reg;
    int dni, posicion;

    rlutil::locate(20,9);
    cout << "DNI A MODIFICAR: ";
    cin >> dni;
    cout << endl;

    system("cls");
    mostrar_mensaje ("***** MODIFICAR DE PROFESOR ***** ", 34, 4);
    posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        reg = _archivo.leerReg(posicion);
        Listar(reg);
        cout << endl;

        int nuevoEstado;
        rlutil::locate(20,10);
        cout << "DESEA MODIFICAR ALGUN DATO? (1-SI/2-NO): ";
        rlutil::locate(64,10);
        cin >> nuevoEstado;

        if (nuevoEstado==1)
        {
            ModificarDatos(reg,posicion);

        }

    }
    else
    {
        system("pause>nul");
    }
}

void ProfesorManager::Eliminar()
{

    Profesor reg;
    int dni, posicion;
    cout << "DNI A BUSCAR: ";
    cin >> dni;
    cout << endl;

    posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        reg = _archivo.leerReg(posicion);
        Listar(reg);
        cout << endl;
        reg.setEstado(false);
        _archivo.guardar(reg, posicion);
        cout << "Registro #" << dni << " eliminado correctamente" << endl;
    }
    else
    {
        cout << "No existe el registro con DNI #" << dni << endl;
    }
}

void ProfesorManager::HacerCopiaDeSeguridad()
{

    int cantidadRegistros = _archivo.getCantidad();
    Profesor *vec = new Profesor[cantidadRegistros];

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
    }
    else
    {
        cout << "Falla al realizar backup" << endl;
    }

    delete []vec;
}

void ProfesorManager::RestaurarCopiaDeSeguridad()
{


    int cantidadRegistros = _archivoBkp.getCantidad();
    Profesor *vec = new Profesor[cantidadRegistros];

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
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;
}

void ProfesorManager::ModificarDatos(Profesor profesor, int posicion)
{
    system("cls");
    const char *opciones[] = {"DNI", "NOMBRE","APELLIDO", "EMAIL", "TELEFONO",
                                            "MODIFICAR ESTADO", "VOLVER AL MENU PRINCIPAL"};

    mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
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
        mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
        mostrar_mensaje ("--------------------------------", 40, 5);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);

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

            if (y>6)
            {
                y=6;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      /// SETEAR DNI
                system("cls");
                {
                    mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
                    mostrar_mensaje ("--------------------------------", 40, 5);
                    int dni;
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO DNI: "<<endl;
                    rlutil::locate(39,9);
                    cin>>dni;
                    profesor.setDNI(dni);
                    if (_archivo.guardar(profesor, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "** REGISTRO MODIFICADO **"<<endl;
                    }

                    system("pause>nul");
                    system("cls");
                }

                break;

            case 1:       /// SETEAR NOMBRE
                system("cls");
                mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
                mostrar_mensaje ("--------------------------------", 40, 5);

                {

                    char nombre[30];
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO NOMBRE: "<<endl;
                    rlutil::locate(47,9);
                    cin>>nombre;
                    profesor.setNombre(nombre);
                    if (_archivo.guardar(profesor, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "** REGISTRO MODIFICADO **"<<endl;
                        system("pause>nul");
                        system("cls");
                    }

                }

                break;

            case 2:       /// SETEAR APELLIDO
                system("cls");
                mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
                mostrar_mensaje ("--------------------------------", 40, 5);

                {
                    char apellido[30];
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO APELLIDO: "<<endl;
                    rlutil::locate(47,9);
                    cin>>apellido;
                    profesor.setApellido(apellido);
                    if (_archivo.guardar(profesor, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "**  REGISTRO MODIFICADO  **"<<endl;
                    }

                    system("pause>nul");
                    system("cls");
                }

                break;

            case 3:     /// SETEAR MAIL
                system("cls");
                mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
                mostrar_mensaje ("--------------------------------", 40, 5);

                {

                    char email[30];
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO EMAIL: "<<endl;
                    rlutil::locate(45,9);
                    cin>>email;
                    profesor.setEmail(email);
                    if (_archivo.guardar(profesor, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "**  REGISTRO MODIFICADO  ** "<<endl;
                        system("pause>nul");
                        system("cls");
                    }

                }

                break;

            case 4:     /// SETEAR TELEFONO
                system("cls");

                {
                    mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
                    mostrar_mensaje ("--------------------------------", 40, 5);
                    int tele;
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO TELEFONO: "<<endl;
                    rlutil::locate(53,9);
                    cin>>tele;
                    profesor.setTelefono(tele);
                    if (_archivo.guardar(profesor, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "**  REGISTRO MODIFICADO  **"<<endl;
                    }

                    system("pause>nul");
                    system("cls");
                }
                break;

            case 5:     /// SETEAR ESTADO

                {
                    system("cls");
                    mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
                    mostrar_mensaje ("--------------------------------", 40, 5);
                    int op;
                    rlutil::locate(20,9);
                    cout << "DESEA MODIFICAR ESTADO DEL PROFESOR (1-BAJA/2-ALTA): "<<endl;
                    rlutil::locate(72,9);
                    cin>>op;
                    if (op==1)
                    {
                        profesor.setEstado(false);
                        if (_archivo.guardar(profesor, posicion))
                        {

                            rlutil::locate(30,15);
                            cout << "** REGISTRO MODIFICADO ** "<<endl;
                        }
                        else if(op==2)
                        {

                            profesor.setEstado(true);
                            if (_archivo.guardar(profesor, posicion))
                            {

                                rlutil::locate(30,15);
                                cout << "** REGISTRO MODIFICADO ** "<<endl;
                            }
                            system("pause>nul");
                            system("cls");

                        }
                        break;

                    case 6:     /// VOLVER AL MENU PRINCIPAL
                       menuCargarProfesor();

                        break;
                    }
                }
            }
        }

    }
    while(op!=0);
    system("pause>nul");

}
