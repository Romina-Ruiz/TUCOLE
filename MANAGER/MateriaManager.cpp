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
#include"../MENUS/FUNCIONES_ADMIN.h"

using namespace std;


void MateriaManager::Cargar()

{

    string nombre_materia, dia1,dia2,horario1,horario2;
    int idMateria,anio_lectivo,idProfe;


    rlutil::locate(15,9);
    cout<<"ANIO LECTIVO: "<<endl;
    rlutil::locate(35,9);
    cin>>anio_lectivo;
    rlutil::locate(15,10);
    cout << "INGRESE NOMBRE DE LA MATERIA: "<<endl;
    rlutil::locate(48,10);
    cin.ignore();
    getline(cin,nombre_materia);
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
    cin.ignore();
    getline(cin,dia1);
    rlutil::locate(15,14);
    cout << "INGRESE HORARIO 1 DE LA MATERIA: "<<endl;
    rlutil::locate(50,14);
    cin.ignore();
    getline(cin,horario1);
    rlutil::locate(15,15);
    cout << "INGRESE DIA 2 DE LA MATERIA: "<<endl;
    rlutil::locate(50,15);
    cin.ignore();
    getline(cin,dia2);
    rlutil::locate(15,16);
    cout << "INGRESE HORARIO 2 DE LA MATERIA: "<<endl;
    rlutil::locate(50,16);
    cin.ignore();
    getline(cin,horario2);


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

void MateriaManager::ModificarMateria()
{
    int mate;
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("***** MODIFICAR MATERIA ***** ", 34, 4);

    rlutil::locate(20,9);
    cout << "INGRESE EL ID DE LA MATERIA:  ";
    rlutil::locate(49,9);
    cin >> mate;
    system("cls");

    int posicion = _archivo.buscarReg(mate);
    if (posicion >= 0)
    {
        Materia reg = _archivo.leerReg(posicion);
        Listar(reg);
        rectangulo (2, 2, 100, 26);
        mostrar_mensaje ("*** DESEA MODIFICAR LA MATERIA (1-SI/ 2- NO)***** ", 20, 9);
        int resp;
        rlutil::locate(20,12);
        cout << "RESPUESTA:  ";
        rlutil::locate(30,12);
        cin >> resp;
        if(resp==1)
        {
            OpModificar(reg,posicion);

        }

    }
    else
    {
        rlutil::locate(20,10);
        cout << "** NO EXISTE ESE NUMERO DE CURSO **" << endl;
        system("pause>nul");
    }


}

void MateriaManager::OpModificar(Materia reg, int pos)
{

    system("cls");

    const char *opciones[] = {"MODIFICAR NOMBRE","MODIFICAR ANIO LECTIVO", "MODIFICAR ID PROFESOR",
                              "MODIFICAR DIA 1", "MODIFICAR HORARIO 1",  "MODIFICAR DIA 2","MODIFICAR HORARIO 2", "MODIFICAR ESTADO", "VOLVER AL MENU ANTERIOR"
                             };

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);
        mostrar_mensaje ("*****  MODIFICAR MATERIAS  ***** ", 34, 4);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);
        showItem (opciones[5],30,15,y==5);
        showItem (opciones[6],30,16,y==6);
        showItem (opciones[7],30,17,y==7);
        showItem (opciones[8],30,18,y==8);

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

            if (y>8)
            {
                y=8;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///NOMBRE
            {
                system("cls");

                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR NOMBRE DE LA MATERIA ***** ", 34, 4);
                string nombre;
                rlutil::locate(20,9);
                cout<<"INGRESE NUEVO NOMBRE"<<endl;
                rlutil::locate(48,9);
                cin.ignore();
                getline(cin,nombre);

                reg.setNombreMateria(nombre);
                _archivo.modificar(reg,pos);

                mostrar_mensaje ("***** MATERIA MODIFICADA ***** ", 34, 15);
                system("pause>nul");
                system("cls");
            }

            break;

            case 1:     /// ANIO LECTIVO

            {
                system("cls");

                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR ANIO LECTIVO ***** ", 34, 4);
                int anio;
                rlutil::locate(20,9);
                cout<<"INGRESE NUEVO ANIO"<<endl;
                rlutil::locate(48,9);
                cin>>anio;

                reg.setAnioLectivo(anio);
                _archivo.modificar(reg,pos);

                mostrar_mensaje ("***** MATERIA MODIFICADA ***** ", 34, 15);
                system("pause>nul");
                system("cls");

            }

            break;
            case 2:     /// ID PROFESOR
            {
                system("cls");

                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR ID PROFESOR ***** ", 34, 4);
                int id;
                rlutil::locate(20,9);
                cout<<"INGRESE EL NUEVO ID DEL PROFESOR:"<<endl;
                rlutil::locate(48,9);
                cin>>id;

                reg.setidProfesor(id);
                _archivo.modificar(reg,pos);

                mostrar_mensaje ("***** MATERIA MODIFICADA ***** ", 34, 15);
                system("pause>nul");
                system("cls");
            }
            break;

            case 3:     /// DIA 1

            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR DIA 1***** ", 34, 4);
                string dia1;
                rlutil::locate(20,9);
                cout<<"INGRESE NUEVO DIA:"<<endl;
                rlutil::locate(48,9);
                cin.ignore();
                getline(cin,dia1);

                reg.setDia1(dia1);
                _archivo.modificar(reg,pos);

                mostrar_mensaje ("***** MATERIA MODIFICADA ***** ", 34, 15);
                system("pause>nul");
                system("cls");
            }

            break;

            case 4:     /// HORARIO 1
            {
                system("cls");

                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR HORARIO 1 ***** ", 34, 4);
                string horario1;
                rlutil::locate(20,9);
                cout<<"INGRESE HORARIO 1: "<<endl;
                rlutil::locate(48,9);
                cin.ignore();
                getline(cin,horario1);

                reg.setHorario1(horario1);
                _archivo.modificar(reg,pos);

                mostrar_mensaje ("***** MATERIA MODIFICADA ***** ", 34, 15);
                system("pause>nul");
                system("cls");
            }

            break;
            case 5:     /// DIA 2
            {
                system("cls");

                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR DIA 2***** ", 34, 4);
                string dia2;
                rlutil::locate(20,9);
                cout<<"INGRESE NUEVO DIA:"<<endl;
                rlutil::locate(48,9);
                cin.ignore();
                getline(cin,dia2);

                reg.setDia2(dia2);
                _archivo.modificar(reg,pos);

                mostrar_mensaje ("***** MATERIA MODIFICADA ***** ", 34, 15);
                system("pause>nul");
                system("cls");
            }

            break;
            case 6:     /// HORARIO 2
            {
                system("cls");

                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR HORARIO 2***** ", 34, 4);
                string horario2;
                rlutil::locate(20,9);
                cout<<"INGRESE HORARIO 1: "<<endl;
                rlutil::locate(48,9);
                cin.ignore();
                getline(cin,horario2);

                reg.setHorario2(horario2);
                _archivo.modificar(reg,pos);

                mostrar_mensaje ("***** MATERIA MODIFICADA ***** ", 34, 15);
                system("pause>nul");
                system("cls");
            }

            break;
            case 7:     /// ESTADO
            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** MODIFICAR ESTADO ***** ", 34, 4);
                int resp;
                rlutil::locate(15,9);
                cout<<"DESEA DAR DE BAJA LA MATERIA (1-SI/2-NO): "<<endl;
                rlutil::locate(60,9);
                cin >>resp;
                if(resp==1)
                {

                    reg.setEliminada(true);
                    _archivo.modificar(reg,pos);
                }

                mostrar_mensaje ("***** VUELVE AL MENU ANTERIOR***** ", 34, 15);

                system("pause>nul");
                system("cls");
            }

            break;

            case 8:     /// SALIR
            {
                system("cls");
                menuCargarMateria();
                system("cls");
            }
            break;
            }
        }
    }
    while(op!=0);

    system("pause");

}



void MateriaManager::ListarTodos()
{

    int cantidadRegistros = _archivo.getCantidad();

    int cont;

    for (int i = 0; i<cantidadRegistros; i++)
    {
        rlutil::locate(46,5);
        cout<< cont+1<<"  / " <<cantidadRegistros;

        Materia reg = _archivo.leerReg(i);

        Listar(reg);
        cont++;
    }
     rectangulo (2, 2, 100, 26);
    mostrar_mensaje ("***** FIN DEL LISTADO ***** ", 34, 10);

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
    cout<<"ID MATERIA:   " <<materia.getIdMateria()<<endl;
    rlutil::locate(20,12);
    cout<<"NOMBRE PROFESOR: " <<materia.getidProfesor()<<endl;
    rlutil::locate(20,13);
    cout<<"DIA 1: " <<materia.getDia1()<<endl;
    rlutil::locate(20,14);
    cout<<"HORARIO 1: " <<materia.getHorario1()<<endl;
    rlutil::locate(20,15);
    cout<<"DIA 2: " <<materia.getDia2()<<endl;
    rlutil::locate(20,16);
    cout<<"HORARIO 2: " <<materia.getHorario2()<<endl;

    system("pause>nul");
    system("cls");
}


void MateriaManager::BuscarxID(int id)
{


    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    Materia obj;
    int cantReg=_archivo.getCantidad();


    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (id==obj.getIdMateria()&&obj.getEliminada()==false)
        {
            rlutil::locate(20,11);
            cout <<"NOMBRE:  "<<obj.getNombreMateria()<< "          " <<"PROFESOR ID:  "<<obj.getidProfesor()<<endl;
            rlutil::locate(20,12);
            cout <<"DIA 1:  "<<obj.getDia1()<< "           " <<"HORARIO 1:  "<<obj.getHorario1()<<endl;
            rlutil::locate(20,13);
            cout <<"DIA 2:  "<<obj.getDia2()<< "         " <<"HORARIO 2:  "<<obj.getHorario2()<<endl;
            system("pause>nul");
        }

    }

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

        if(objCurso.getDniAlumno()==dni&& objCurso.getEstado()==true)
        {

            anio=objCurso.getCurso();
        }
    }

    int d=0;
    for(int x=0; x<cantReg; x++)
    {

        objMateria=ArMateria.leerReg(x);

       if (objMateria.getAnioLectivo()==anio)
        {
            rlutil::setColor(rlutil::YELLOW);
            rectangulo (2, 2, 100, 26);
            mostrar_mensaje ("***** ESTAS SON TUS MATERIAS ***** ", 34, 4);

            d++;
            rlutil::locate(50,6);
            cout <<d <<"  /6";
            rlutil::locate(10,9);
            cout <<"MATERIA: " <<objMateria.getNombreMateria();
            rlutil::locate(10,11);
            cout <<"DIA 1: " <<objMateria.getDia1() <<"          "<<"HORARIO: " <<objMateria.getHorario1()<<endl;
            rlutil::locate(10,12);
            cout <<"DIA 2: " <<objMateria.getDia2() <<"          "<<"HORARIO: " <<objMateria.getHorario2()<<endl;
            system("pause>nul");
            system("cls");

        }
    }
mostrar_mensaje ("***** FIN DEL REPORTE***** ", 34, 10);

}

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


