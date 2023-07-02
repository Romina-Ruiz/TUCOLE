#include <iostream>
#include <cstring>
#include "MateriaManager.h"
#include "Materia.h"
#include "MateriaArchivo.h"
#include "Alumno.h"
#include"../MENUS/rlutil.h"
#include "../MENUS/FUNCIONES_FRONT.h"
#include"Curso.h"
#include"CursoArchivo.h"

using namespace std;


void  MateriaManager::cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

void MateriaManager::Cargar()

{

    char nombre_materia[40]={}, dia1[10]={},dia2[10]={},horario1[10]={},horario2[10]={};
    int idMateria,anio_lectivo,idProfe;
    bool estado;

     rlutil::locate(15,9);
    cout<<"ANIO LECTIVO: "<<endl;
    rlutil::locate(31,9);
    cin>>anio_lectivo;
    rlutil::locate(15,10);
    cout << "INGRESE NOMBRE DE LA MATERIA: "<<endl;
    rlutil::locate(48,10);
    this->cargarCadena(nombre_materia,39);
    rlutil::locate(15,11);
    cout << "ID DE MATERIA #: " <<endl;
    idMateria=this->generarId();
    rlutil::locate(35,11);
    cout<<idMateria<<endl;
    rlutil::locate(15,12);
    cout << "INGRESE ID DEL PROFESOR: "<<endl;
    rlutil::locate(50,12);
    cin >>idProfe;
    rlutil::locate(15,13);
    cout << "INGRESE DIA 1 DE LA MATERIA: "<<endl;
    rlutil::locate(50,13);
    this->cargarCadena(dia1,10);
    rlutil::locate(15,14);
    cout << "INGRESE HORARIO 1 DE LA MATERIA: "<<endl;
    rlutil::locate(50,14);
    this->cargarCadena(horario1,10);
    rlutil::locate(15,15);
    cout << "INGRESE DIA 2 DE LA MATERIA: "<<endl;
    rlutil::locate(50,15);
    this->cargarCadena(dia2,10);
    rlutil::locate(15,16);
    cout << "INGRESE HORARIO 2 DE LA MATERIA: "<<endl;
    rlutil::locate(50,16);
    this->cargarCadena(horario2,10);

    Materia aux;
    aux.setAnioLectivo(anio_lectivo);
    aux.setNombreMateria(nombre_materia);
    aux.setId(idMateria);
    aux.setidProfesor(idProfe);
    aux.setDia1(dia1);
    aux.setHorario1(horario1);
    aux.setDia2(dia2);
    aux.setHorario2(horario2);
    aux.setEliminada(false);

    if (_archivo.agregar(aux))
    {
        rlutil::locate(30,23);
        cout << "** MATERIA GUARDADA CORRECTAMENTE **" << endl;
        system("pause>nul");
        system("cls");
    }
    else
    {
        rlutil::locate(30,25);
        cout << "** UPS! ALGO SALIO MAL:( **" << endl;
        system("pause>nul");
        system("cls");
    }
}


int MateriaManager::generarId()
{

    MateriaArchivo _archivo;
    return _archivo.getCantidad()+1;

}

//void MateriaManager::ListarXcurso()
//{
//    int curso;
//    rectangulo (2, 2, 100, 26);
//    rlutil::setColor(rlutil::YELLOW);
//
//    rlutil::locate(20,9);
//    cout << "INGRESE CURSO ";
//    cin >> curso;
//    system("cls");
//
//    int posicion = _archivo.buscarReg(curso);
//    if (posicion >= 0)
//    {
//        Materia reg = _archivo.leerReg(posicion);
//        Listar(reg);
//    }
//    else
//    {
//        rlutil::locate(20,10);
//        cout << "** NO EXISTE ESE NUMERO DE CURSO **" << endl;
//        system("pause>nul");
//    }
//}


//int MateriaManager::buscarDNI(int dni)
//{
//
//    Alumno obj;
//    AlumnoArchivo _archivoalumno;
//    int nroReg=-1;
//    int cantRegArchivo=_archivoalumno.getCantidad();
//
//
//    for (int i = 0; i < cantRegArchivo; i++)
//    {
//        obj=_archivoalumno.leerReg(i);
//
//        if (obj.getDni()== dni)
//        {
//            nroReg=i;
//            break;
//        }
//    }
//
//    return nroReg;
//}


void MateriaManager::ListarTodos()
{

    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Materia reg = _archivo.leerReg(i);

        Listar(reg);
        cout << endl;

    }
}
void MateriaManager::Listar(Materia materia)
{
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout<<"ANIO LECTIVO: " <<materia.getAnioLectivo()<<endl;
    rlutil::locate(20,10);
    cout<<"NOMBRE:     " <<materia.getNombreMateria()<<endl;
    rlutil::locate(20,11);
    cout<<"ID MATERIA :   " <<materia.getIdMateria()<<endl;
    rlutil::locate(20,12);
    cout<<"NOMBRE PROFESOR : " <<materia.getidProfesor()<<endl;
    rlutil::locate(20,13);
    cout<<"DIA 1 : " <<materia.getDia1()<<endl;
   rlutil::locate(20,14);
    cout<<"HORARIO 1 : " <<materia.getHorario1()<<endl;
    rlutil::locate(20,15);
    cout<<"DIA 2 : " <<materia.getDia2()<<endl;
    rlutil::locate(20,16);
    cout<<"HORARIO 2 : " <<materia.getHorario2()<<endl;

    system("pause>nul");
    system("cls");
}


void MateriaManager::ListarXanioLectivo()
{
    int AnioLectivo;

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(20,9);
    cout<<"INGRESE EL ANIO LECTIVO :"<<endl;
    rlutil::locate(30,10);
    cin>>AnioLectivo;
    system("cls");

    Materia obj;
    int cantReg=_archivo.getCantidad();

    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (AnioLectivo==obj.getAnioLectivo())
        {
            rlutil::locate(20,9);
            cout <<"MATERIA:  "<<obj.getNombreMateria()<<endl;
            rlutil::locate(33,9);
            cout <<"PROFESOR :  "<<obj.getidProfesor()<<endl;

            system("pause>nul");
            system("cls");
        }

    }
    rlutil::locate(30,9);
    cout <<"FIN DEL LISTADO "<<endl;
}

void MateriaManager::MenuUserMaterias(int dni)
{

    Materia objMateria;
    MateriaArchivo ArMateria;
    Curso objCurso;
    CursoArchivo ArCurso;

    int cantReg=ArMateria.getCantidad();
    int cantRegCurso=ArCurso.getCantidad();
    int anio=0;

    for (int i=0; i<cantRegCurso; i++)
    {

        objCurso=ArCurso.leerReg(i);

        if(objCurso.getDniAlumno()==dni)
        {

            anio=objCurso.getCurso();
        }

        int d=0;
        for(int x=0; x<cantReg; x++)
        {

            objMateria=ArMateria.leerReg(x);

            if (objMateria.getAnioLectivo()==anio)
            {

                d++;
                rlutil::locate(20,9+d);
                cout <<"MATERIA: " <<objMateria.getNombreMateria();

            }
        }
    }

}
//
//
//void MateriaManager::Editar()
//{
//    Materia reg;
//    int id, posicion;
//
//    rlutil::locate(20,9);
//    cout << "ID A MODIFICAR: ";
//    cin >> id;
//    cout << endl;
//
//    system("cls");
//    mostrar_mensaje ("***** MODIFICAR DE MATERIA***** ", 34, 4);
//    posicion = _archivo.buscarReg(id);
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
//}
//
void MateriaManager::HacerCopiaDeSeguridad()
{

    int cantidadRegistros = _archivo.getCantidad();
    Materia *vec = new Materia[cantidadRegistros];

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

void MateriaManager::RestaurarCopiaDeSeguridad()
{
    int cantidadRegistros = _archivoBkp.getCantidad();
    Materia *vec = new Materia[cantidadRegistros];

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
//
//void MateriaManager::ModificarDatos(Materia materia, int posicion)
//{
//    system("cls");
//    const char *opciones[] = {"NOMBRE DE LA MATERIA", "NOMBRE DEL PROFESOR", "VOLVER AL MENU PRINCIPAL"};
//
//    mostrar_mensaje ("* MODIFICAR DATOS DE LA MATERIA *", 40, 4);
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
//        mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
//        mostrar_mensaje ("--------------------------------", 40, 5);
//
//        showItem (opciones[0],30,10,y==0);
//        showItem (opciones[1],30,11,y==1);
//        showItem (opciones[2],30,12,y==2);
//        showItem (opciones[3],30,13,y==3);
//        showItem (opciones[4],30,14,y==4);
//        showItem (opciones[5],30,15,y==5);
//        showItem (opciones[6],30,16,y==6);
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
//            if (y>7)
//            {
//                y=7;
//            }
//            break;
//
//        case 1:   /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):
//
//            switch(y)
//            {
//            case 0:      /// SETEAR DNI
//                system("cls");
//                {
//                    mostrar_mensaje ("* MODIFICAR DATOS DE LA MATERIA *", 40, 4);
//                    mostrar_mensaje ("--------------------------------", 40, 5);
//                    char nombreMateria[30];
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO NOMBRE DE LA MATERIA "<<endl;
//                    rlutil::locate(39,9);
//                    cin>>nombreMateria;
//                    materia.setNombreMateria(nombreMateria);
//                    if (_archivo.guardar(materia, posicion))
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
//            case 1:       /// SETEAR NOMBRE
//                system("cls");
//                mostrar_mensaje ("* MODIFICAR DATOS DEL PROFESOR *", 40, 4);
//                mostrar_mensaje ("--------------------------------", 40, 5);
//
//                {
//
//                    char nombreProfesor[30];
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO NOMBRE: "<<endl;
//                    rlutil::locate(47,9);
//                    cin>>nombreProfesor;
//                    materia.getNombreProfesor(nombreProfesor);
//                    if (_archivo.guardar(materia, posicion))
//                    {
//
//                        rlutil::locate(30,15);
//                        cout << "** REGISTRO MODIFICADO **"<<endl;
//                        system("pause>nul");
//                        system("cls");
//                    }
//
//                }
//
//                break;
//
//
//}
//
//    }
//    while(op!=0);
//    system("pause>nul");
//
//}
//
//


