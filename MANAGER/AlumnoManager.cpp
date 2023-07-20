#include <iostream>
#include "AlumnoManager.h"
#include "Alumno.h"
#include "AlumnoArchivo.h"
#include "Persona.h"
#include"../MENUS/rlutil.h"
#include "../MENUS/Fecha.h"
#include"../MENUS/FUNCIONES_FRONT.h"

using namespace std;

AlumnoManager::AlumnoManager(char *ruta)
{

    strcpy(_ruta,ruta);
}
AlumnoManager::AlumnoManager()
{

    strcpy(_ruta,"AlumnoManager.dat");

}

bool AlumnoManager::validarIngreso(int dni)
{

    int numerodeRegistro=buscarDNI(dni);

    if(numerodeRegistro>0)
    {

        return true;

    }
    return false;

}



void AlumnoManager::Cargar()

{
    string nombre, apellido, email;
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
        cout << "INGRESE EL NOMBRE: "<<endl;
        rlutil::locate(39,9);
        cin.ignore();
        getline(cin,nombre);
        rlutil::locate(20,10);
        cout << "INGRESE EL APELLIDO: "<<endl;
        rlutil::locate(41,10);
        getline(cin,apellido);
        rlutil::locate(20,11);
        cout << "INGRESE EL MAIL: "<<endl;
        rlutil::locate(38,11);
        getline(cin,email);
        rlutil::locate(20,12);
        cout << "INGRESE EL TELEFONO: "<<endl;
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
        rlutil::locate(20,16);
        cout << "ESTADO: "<< "Activo" <<endl;


        Alumno aux;
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
            cout << "** ALUMNO GUARDADO CORRECTAMENTE **" << endl;
            system("pause>nul");

        }
        else
        {
            rlutil::locate(30,25);
            cout << "** UPS! ALGO SALIO MAL :( **" << endl;
            system("pause>nul");

        }
    }
    system("pause>nul");
    system("cls");
}

int AlumnoManager::buscarDNI(int dni)
{

    return _archivo.buscarReg(dni)>=0;

}

int AlumnoManager::generarLegajo()
{

    return _archivo.getCantidad()+1;
}

void AlumnoManager::ListarTodos()
{
    AlumnoArchivo _archivo;
    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Alumno reg = _archivo.leerReg(i);
        if (reg.getEstado()==true)
        {
            Listar(reg);
             system("cls");
        }
    }
}
void AlumnoManager::Listar(Alumno alumno)
{
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);


    rlutil::locate(20,9);
    cout<<"DNI:    " <<alumno.getDni()<<endl;
    rlutil::locate(20,10);
    cout<<"NOMBRE:    "<<alumno.getNombre()<<endl;
    rlutil::locate(20,11);
    cout<<"APELLIDO:    "<<alumno.getApellido()<<endl;
    rlutil::locate(20,12);
    cout<<"EMAIL:    " <<alumno.getEmail()<<endl;
    rlutil::locate(20,13);
    cout<<"TELEFONO:    "<<alumno.getTelefono()<<endl;
    rlutil::locate(20,14);
    cout <<"FECHA DE INGRESO:    " << alumno.getIngreso().toString()<< endl;
    rlutil::locate(20,15);
    cout <<"LEGAJO:    " << alumno.getLegajo() << endl;

    if (alumno.getEstado()==true)
    {
        rlutil::locate(20,17);
        cout <<"ESTADO:    " << "Activo" << endl;
    }
    else if(alumno.getEstado()==false)
    {
        rlutil::locate(20,17);
        cout <<"ESTADO:    " << "Baja" << endl;
    }


    system("pause>nul");

}


void AlumnoManager::ListarXdni()
{
    int dni;
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout << "INGRESE DNI ALUMNO: ";
     rlutil::locate(43,9);
    cin >> dni;
    system("cls");

    int posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        Alumno reg = _archivo.leerReg(posicion);
        Listar(reg);
    }
    else
    {
        rlutil::locate(20,10);
        cout << "** NO EXISTE UN ALUMNO CON ESE DNI **" << endl;
        system("pause>nul");
    }
}




void AlumnoManager::Editar()
{
    Alumno reg;
    int dni, posicion;

    rlutil::locate(20,9);
    cout << "DNI A MODIFICAR: ";
    cin >> dni;
    cout << endl;

    system("cls");
    mostrar_mensaje ("***** MODIFICAR DE ALUMNO ***** ", 34, 4);
    posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        reg = _archivo.leerReg(posicion);
        Listar(reg);
        cout << endl;

        int nuevoEstado;
        rlutil::locate(20,20);
        cout << "DESEA MODIFICAR ALGUN DATO? (1-SI/2-NO): ";
        rlutil::locate(64,20);
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

void AlumnoManager::Eliminar()
{

    Alumno reg;
    int dni, posicion;
    cout << "DNI a buscar: ";
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
        system("pause>nul");
    }
    else
    {
        cout << "No existe el registro con DNI #" << dni << endl;
        system("pause>nul");
    }
}

void AlumnoManager::HacerCopiaDeSeguridad()
{

    int cantidadRegistros = _archivo.getCantidad();
    Alumno *vec = new Alumno[cantidadRegistros];

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

void AlumnoManager::RestaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidad();
    Alumno *vec = new Alumno[cantidadRegistros];

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

void AlumnoManager::ModificarDatos(Alumno alumno, int posicion)
{
    system("cls");
    const char *opciones[] = {"DNI", "NOMBRE","APELLIDO", "EMAIL", "TELEFONO", "MODIFICAR ESTADO","FECHA ", "VOLVER AL MENU PRINCIPAL"};

    mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
    mostrar_mensaje ("--------------------------------", 40, 5);


    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);
        rectangulo (2, 2, 100, 26);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);
        showItem (opciones[7],30,17,y==7);


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

            if (y>7)
            {
                y=7;
            }
            break;

        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {
            case 0:      /// SETEAR DNI
                system("cls");
                {
                    mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
                    mostrar_mensaje ("--------------------------------", 40, 5);
                    int dni;
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO DNI: "<<endl;
                    rlutil::locate(39,9);
                    cin>>dni;
                    alumno.setDNI(dni);
                    if (_archivo.guardar(alumno, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "** REGISTRO MODIFICADO **"<<endl;
                        system("pause>nul");
                        system("cls");
                    }

                }

                break;

            case 1:       /// SETEAR NOMBRE
                system("cls");
                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
                mostrar_mensaje ("--------------------------------", 40, 5);

                {

                    char nombre[30];
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO NOMBRE: "<<endl;
                    rlutil::locate(47,9);
                    cin>>nombre;
                    alumno.setNombre(nombre);
                    if (_archivo.guardar(alumno, posicion))
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
                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
                mostrar_mensaje ("--------------------------------", 40, 5);

                {
                    char apellido[30];
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO APELLIDO: "<<endl;
                    rlutil::locate(47,9);
                    cin>>apellido;
                    alumno.setApellido(apellido);
                    if (_archivo.guardar(alumno, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "**  REGISTRO MODIFICADO  **"<<endl;
                        system("pause>nul");
                        system("cls");
                    }


                }

                break;

            case 3:     /// SETEAR MAIL
                system("cls");
                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
                mostrar_mensaje ("--------------------------------", 40, 5);

                {

                    char email[30];
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO EMAIL: "<<endl;
                    rlutil::locate(45,9);
                    cin>>email;
                    alumno.setEmail(email);
                    if (_archivo.guardar(alumno, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "**  REGISTRO MODIFICADO  ** "<<endl;
                    }

                    system("pause>nul");
                    system("cls");
                }

                break;

            case 4:     /// SETEAR TELEFONO
                system("cls");
                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
                mostrar_mensaje ("--------------------------------", 40, 5);
                {

                    int tele;
                    rlutil::locate(20,9);
                    cout << "INGRESE EL NUEVO TELEFONO: "<<endl;
                    rlutil::locate(53,9);
                    cin>>tele;
                    alumno.setTelefono(tele);
                    if (_archivo.guardar(alumno, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "**  REGISTRO MODIFICADO  **"<<endl;
                    }

                    system("pause>nul");
                    system("cls");
                    break;

                    case 5:     /// SETEAR DAR DE BAJA
                        system("cls");

                        {
                            mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
                            mostrar_mensaje ("--------------------------------", 40, 5);
                            int op;
                            rlutil::locate(20,9);
                            cout << "DESEA MODIFICAR ESTADO DEL ALUMNO (1-BAJA/2-ALTA): "<<endl;
                            rlutil::locate(72,9);
                            cin>>op;
                            if (op==1)
                            {
                                alumno.setEstado(false);
                                if (_archivo.guardar(alumno, posicion))

                                    rlutil::locate(30,15);
                                cout << "** REGISTRO MODIFICADO ** "<<endl;
                            }
                            else if(op==2)
                            {

                                alumno.setEstado(true);
                                if (_archivo.guardar(alumno, posicion))

                                    rlutil::locate(30,15);
                                cout << "** REGISTRO MODIFICADO ** "<<endl;
                                system("pause>nul");
                                system("cls");

                            }

                        }
                        break;
                    case 6:

                        system("cls");
                {
                    rectangulo (2, 2, 100, 26);
                    mostrar_mensaje ("* MODIFICAR FECHA DE INGRESO *", 40, 4);
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


                    alumno.setIngreso(Fecha(dia,mes,anio));

                    if (_archivo.guardar(alumno, posicion))
                    {

                        rlutil::locate(30,15);
                        cout << "** REGISTRO MODIFICADO **"<<endl;
                    }

                    system("pause>nul");
                    system("cls");
                }



                    case 7:     /// VOLVER AL MENU PRINCIPAL
                        system("cls");
                        {
                            menuCargarAlumnos();

                            system("pause>nul");
                            system("cls");

                        }

                        break;
                    }
                }
            }
        }


    while(op!=0);
    system("pause>nul");
}
