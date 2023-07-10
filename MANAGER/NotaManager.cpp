#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include"../MENUS/rlutil.h"
using namespace std;
#include "NotaManager.h"
#include "../MENUS/FUNCIONES_FRONT.h"
#include "AlumnoArchivo.h"
#include "Alumno.h"
#include"Materia.h"
#include"MateriaArchivo.h"

int NotaManager::buscarDNI(int dni)
{

    return _archivo.buscarReg(dni)>=0;

}

int NotaManager::GenerarID()
{

    return _archivo.getCantidad()+1;
}


void NotaManager::Cargar()

{
    AlumnoArchivo alumno;

    int dni, NroExamen;
    string nombreMateria;
    float nota;


    rlutil::locate(20,8);
    cout << "INGRESE DNI #: " <<endl;
    rlutil::locate(35,8);
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
        rlutil::locate(10,10);
        cout << "NOMBRE DE MATERIA: "<<endl;
        rlutil::locate(35,10);
        cin.ignore();
        getline(cin,nombreMateria);

        int id=BuscarMaterias(nombreMateria);
        int nume;

        rlutil::locate(10,11);
        cout << "Nro EXAMEN (1-Primer examen/2-Segundo Examen/3-Final): "<<endl;
        rlutil::locate(65,11);
        cin >> NroExamen;
        rlutil::locate(10,12);
        cout << "INGRESE NOTA: "<<endl;
        rlutil::locate(28,12);
        cin >> nota;
        rlutil::locate(10,13);
        cout << "ID DE LA NOTA: "<<endl;
        nume=this->GenerarID();
        rlutil::locate(28,13);
        cout << nume<<endl;

        Notas aux;
        aux.setDNIalumno(dni);
        aux.setIDMateria(id);
        aux.setNroExamen(NroExamen);
        aux.setNota(nota);
        aux.setIDNota(nume);
        aux.setEliminada(0);

        if (_archivo.agregar(aux))
        {
            rlutil::locate(30,23);
            cout << "** NOTA CORRECTAMENTE GUARDADA **" << endl;
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

int NotaManager::BuscarMaterias(std::string nombremateria)
{
    Materia aux;
    MateriaArchivo ArMateria;

    int canReg=ArMateria.getCantidad();

    for (int x=0; x<canReg; x++)
    {

        aux=ArMateria.leerReg(x);

        if(nombremateria==aux.getNombreMateria())
        {

            return aux.getIdMateria();
        }

    }

    return 0;
}
std::string NotaManager::BuscarMateriaxID(int id)
{

    Materia aux;
    MateriaArchivo ArMateria;

    int canReg=ArMateria.getCantidad();

    for (int x=0; x<canReg; x++)
    {

        aux=ArMateria.leerReg(x);

        if(id==aux.getIdMateria())
        {

            return aux.getNombreMateria();
        }

    }

}


void NotaManager::ListarTodos()
{

    NotasArchivo _archivo;

    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Notas reg = _archivo.leerReg(i);

        Listar(reg);

        system("pause>nul");

    }
}

void NotaManager::Listar(Notas nota)
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    std::string materia;

    rlutil::locate(20,9);
    cout<<"DNI ALUMNO:    " <<nota.getDNIalumno()<<endl;

    materia=this->BuscarMateriaxID(nota.getIDMateria());
    rlutil::locate(20,10);
    cout<<"NOMBRE DE MATERIA :    "<<materia<<endl;

    rlutil::locate(20,11);
    cout<<"NUMERO DE EXAMEN:    "<<nota.getNroExamen()<<endl;
    rlutil::locate(20,12);
    cout<<"NOTA  :    " <<nota.getNota()<<endl;

    system("pause>nul");
    system("cls");

}
void NotaManager::ListarXdni(int dni)
{

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    Notas obj;
    int cantReg=_archivo.getCantidad();
    int can=1;
    std::string materia;
    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (dni==obj.getDNIalumno())
        {
            can++;
            materia=this->BuscarMateriaxID(obj.getIDMateria());
            rlutil::locate(5,10+can);
            cout <<"MATERIA: "<<materia<<endl;
            rlutil::locate(30,10+can);
            cout <<"Nro. DE EXAMEN:  "<<obj.getNroExamen()<<endl;
            rlutil::locate(53,10+can);
            cout <<"NOTA:  "<<obj.getNota()<<endl;
            rlutil::locate(66,10+can);
            cout <<"ID NOTA: "<<obj.getIDNota()<<endl;
            system("pause>nul");

        }

    }
    system("cls");
    rectangulo (2, 2, 100, 26);
    rlutil::locate(40,12);
    cout <<"** FIN DEL LISTADO **"<<endl;
}

void NotaManager::Editar()
{

    Notas reg;
    int dni, ID, posicion;

    rlutil::locate(20,9);
    cout << "DNI A MODIFICAR: ";
    cin >> dni;
    rlutil::locate(20,10);
    cout << "INGRESE EL ID DE LA NOTA A MODIFICAR: ";
    cin >> ID;

    posicion = _archivo.buscarReg(dni);
    if (posicion >= 0)
    {
        reg = _archivo.leerReg(posicion);

        int nuevoEstado;
        rlutil::locate(20,13);
        cout << "DESEA MODIFICAR ALGUN DATO? (1-SI/2-NO): ";
        cin >> nuevoEstado;

        if (nuevoEstado==1)
        {
            ModificarDatos(dni,ID,posicion);

        }

    }
    else
    {
        mostrar_mensaje ("**  NO EXISTE ESE REGISTRO  ** ", 34, 10);
        system("pause>nul");
    }


}

void NotaManager::ModificarDatos(int dni, int id, int pos)
{
    system("cls");

   rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("***   MODIFICAR NOTAS   ***", 40, 4);

    Notas aux;
    NotasArchivo arNotas;

    float nota;

    int canReg=arNotas.getCantidad();

    for(int x=0; x<canReg; x++)
    {
        aux=arNotas.leerReg(x);

        if(id==aux.getIDMateria()&&dni==aux.getDNIalumno()&&aux.getEliminada()==false)
        {
            rlutil::locate(10,10);
            cout << "INGRESE LA NUEVA NOTA DEL EXAMEN: "<<endl;
            rlutil::locate(50,10);
            cin>>nota;

            aux.setNota(nota);
            if(arNotas.modificar(aux,pos))
            {

                rlutil::locate(30,15);
                rectangulo (2, 2, 100, 26);
                cout << "** REGISTRO MODIFICADO **"<<endl;
                system("pause>nul");
            }
        }
    }

}


void NotaManager::BuscarNotas()
{
    system("cls");
    Notas obj;
    NotasArchivo arNotas;
    int dni;
    int canReg= arNotas.getCantidad();
    rlutil::setColor(rlutil::YELLOW);
    rectangulo (2, 2, 100, 26);
    mostrar_mensaje ("***** BUSCAR NOTAS POR DNI ***** ", 34, 4);
    rlutil::locate(10,9);
    cout << "DNI: ";
    rlutil::locate(18,9);
    cin >> dni;

    this->ListarXdni(dni);


}

void NotaManager::HacerCopiaDeSeguridad()
{
    NotasArchivo _archivoBkp = NotasArchivo("comunicados.bkp");
    NotasArchivo _archivo;
    int cantidadRegistros = _archivo.getCantidad();
    Notas *vec = new Notas [cantidadRegistros];

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

void NotaManager::RestaurarCopiaDeSeguridad()
{
    NotasArchivo _archivoBkp = NotasArchivo ("notas.bkp");
    NotasArchivo _archivo;
    int cantidadRegistros = _archivoBkp.getCantidad();
    Notas *vec = new Notas[cantidadRegistros];

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



