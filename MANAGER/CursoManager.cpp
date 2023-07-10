#include "CursoManager.h"
#include "../MENUS/rlutil.h"
#include "AlumnoArchivo.h"
#include "../MENUS/FUNCIONES_FRONT.h"
#include "AlumnoManager.h"
#include"Materia.h"
#include"MateriaArchivo.h"
#include"MateriaManager.h"

using namespace std;

void CursoManager::Cargar()
{
    AlumnoArchivo alumno;

    int dniAlumno,curso;
    int idcurso;


    rlutil::locate(20,8);
    cout << "INGRESE DNI #: " <<endl;
    rlutil::locate(38,8);
    cin>>dniAlumno;

    int numerodeRegistro=alumno.buscarReg(dniAlumno);

    if(numerodeRegistro<0)
    {

        rlutil::locate(20,10);
        cout<<"EL DNI FUE DADO DE BAJA O NO EXISTE !!";
        system("pause>nul");
        system("cls");
    }
    else
    {
        rlutil::locate(20,9);
        cout << "CURSO N#: "<<endl;
        rlutil::locate(30,9);
        cin>> curso;

        rlutil::locate(20,10);
        cout << "ID CURSO #: "<<endl;
        idcurso=this->generarId();
        rlutil::locate(37,10);
        cout <<idcurso;

        Curso aux;
        aux.setDniAlumno(dniAlumno);
        aux.setidCurso(idcurso);
        aux.setCurso(curso);
        aux.setEstado(true);

        if (_archivo.agregar(aux))
        {
            rlutil::locate(30,20);
            cout << "** CURSO GUARDADO CORRECTAMENTE **" << endl;
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


int CursoManager::generarId()
{

    return _archivo.getCantidad()+100;
}

void CursoManager::ListarTodos()
{
    CursoArchivo _archivo;
    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Curso reg = _archivo.leerReg(i);

        Listar(reg);

    }
}

void CursoManager::Listar(Curso curso)
{
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****      CURSO    ***** ", 34, 4);


    rlutil::locate(20,9);
    cout<<"ID CURSO:    "<<curso.getIdCurso()<<endl;
    rlutil::locate(20,10);
    cout<<"ANIO N#:    " <<curso.getCurso()<<endl;
    rlutil::locate(20,11);
    cout<<"DNI ALUMNO :    " <<curso.getDniAlumno()<<endl;
    rlutil::locate(20,12);
    cout<<"ID PROFESOR:    "<<curso.getIdProfesor()<<endl;

    system("pause>nul");
    system("cls");
}

void CursoManager::ListarMateriasxCurso(int anio)
{

    system("cls");
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    Materia aux;
    MateriaArchivo Armate;
    MateriaManager obj;

    int canRegmate=Armate.getCantidad();

    int con=1;
    for (int j=0; j<canRegmate; j++)
    {
        aux=Armate.leerReg(j);

        if (anio==aux.getAnioLectivo()&&aux.getEliminada()==false)
        {

            mostrar_mensaje ("***** INFORMACION SOBRE CURSO/ANIO  ***** ", 34, 4);
            rlutil::locate(40,6);
            cout <<"MATERIA DEL CURSO N#: " <<con<<endl;
            obj.Listar(aux);
            con++;

        }

    }
    rectangulo (2, 2, 100, 26);
    rlutil::locate(35,10);
    cout <<"***  FIN DEL LISTADO  ***"<<endl;
}


void CursoManager::ListarAlumnosxCurso(int anio)
{
    system("cls");
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    Alumno alumno;
    AlumnoArchivo reg;
    AlumnoManager alumanager;
    Curso obj;
    int cantReg=_archivo.getCantidad();
    int cantAlu=reg.getCantidad();
    int can=1;

    for (int i=0; i<cantAlu; i++)
    {
        alumno=reg.leerReg(i);

        bool encontro=false;

        for (int j=0; j<cantReg; j++)
        {

            obj=_archivo.leerReg(j);

            if(encontro==false&&obj.getCurso()==anio&&alumno.getDni()==obj.getDniAlumno())
            {
                rlutil::locate(30,4);
                cout<<"***      ALUMNOS DEL CURSO "<<anio <<"      ***";
                rlutil::locate(41,6);
                cout<<"REGISTRO N#: "<<can;

                encontro=true;
                alumanager.Listar(alumno);

                can++;
                system("pause>nul");
                system("cls");
            }

        }

    }
    system("cls");
    rectangulo (2, 2, 100, 26);
    rlutil::locate(40,12);
    cout <<"***  FIN DEL LISTADO  *** "<<endl;
    system("pause>nul");

}


void CursoManager::Editar()
{

    system("cls");
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("***** MODIFICAR DE DATOS DEL CURSO ***** ", 30, 4);

    const char *opciones[] = {"DAR DE BAJA UN ALUMNO", "MODIFICAR ID DEL CURSO",
                              "MODIFICAR CURSO/ANIO", "VOLVER AL MENU ANTERIOR"
                             };

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);

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
            case 0:      /// DAR DE BAJA ALUMNO DEL CURSO
                system("cls");
                {
                    Curso aux;
                    rectangulo (2, 2, 100, 26);
                    mostrar_mensaje ("***  DAR DE BAJA A UN ALUMNO  ***", 34, 4);
                    int dni;
                    rlutil::locate(20,9);
                    cout << "INGRESE EL DNI A DAR DE BAJA: "<<endl;
                    rlutil::locate(55,9);
                    cin>>dni;

                    int posicion =_archivo.buscarReg(dni);
                    if (posicion >= 0)
                    {
                        int resp;
                        mostrar_mensaje ("DESEA DAR DE BAJA AL ALUMNO DEL CURSO (1-SI/ 2-NO) ", 15, 6);
                        rlutil::locate(20,7);
                        cout <<"RESPUESTA: ";
                        rlutil::locate(35,7);
                        cin>>resp;

                        if(resp==1)
                        {
                            aux.setEstado(false);
                            _archivo.modificarReg(aux, posicion);
                            mostrar_mensaje ("REGISTRO MODIFICADO", 30, 10);
                            system("pause>nul");
                            system("cls");
                        }
                    }
                }

                break;

            case 1:       /// MODIFICAR ID CURSO
            {
                system("cls");
                Curso aux;
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("* MODIFICAR DATOS DEL CURSO *", 30, 4);
                int dni;
                rlutil::locate(20,9);
                cout << "INGRESE EL DNI A MODIFICAR: "<<endl;
                rlutil::locate(55,9);
                cin>>dni;

                int posicion =_archivo.buscarReg(dni);
                if (posicion >= 0)
                {
                    int resp;
                    rlutil::locate(20,12);
                    cout <<"INGRESE EL NUEVO ID DEL CURSO: ";
                    rlutil::locate(55,12);
                    cin>>resp;
                    aux.setidCurso(resp);
                    _archivo.modificarReg(aux, posicion);
                    mostrar_mensaje ("REGISTRO MODIFICADO", 30, 15);
                    system("pause>nul");
                    system("cls");

                }

            }
            break;

            case 2:       ///  MODIFICAR CURSO/ANIO
            {
                system("cls");
                Curso aux;
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("* MODIFICAR DATOS DEL CURSO *", 30, 4);
                int dni;
                rlutil::locate(20,9);
                cout << "INGRESE EL DNI A MODIFICAR: "<<endl;
                rlutil::locate(55,9);
                cin>>dni;

                int posicion =_archivo.buscarReg(dni);

                if (posicion >= 0)
                {
                    int resp;
                    rlutil::locate(20,12);
                    cout <<"INGRESE EL NUEVO CURSO/ANIO: ";
                    rlutil::locate(50,12);
                    cin>>resp;
                    aux.setCurso(resp);
                    _archivo.modificarReg(aux, posicion);
                    mostrar_mensaje ("REGISTRO MODIFICADO", 30, 15);
                    system("pause>nul");
                    system("cls");

                }
                else
                {
                    system("cls");
                    mostrar_mensaje ("NO EXISTE UN REGISTRO CON ESE DNI", 30, 15);
                }
                system("cls");
            }
            break;
            case 3:     /// SALIR
            {
                system("cls");
                menuCargarCursos();

            }
            break;
            }
        }

    }
    while(op!=0);
    system("pause>nul");

}

//
//       reg = _archivo.leerReg(posicion);
//       Listar(reg);
//       cout << endl;
//
//       int nuevoEstado;
//       rlutil::locate(20,20);
//       cout << "DESEA MODIFICAR ALGUN DATO? (1-SI/2-NO): ";
//       rlutil::locate(64,20);
//       cin >> nuevoEstado;
//
//       if (nuevoEstado==1)
//       {
//           ModificarDatos(reg,posicion);
//
//       }
//
//   }
//   else
//   {
//       system("pause>nul");
//   }

//void CursoManager::ModificarDatos(Curso curso, int posicion)
//{
//    int _dniAlumno;
//    char _nombre_materia[30];
//    int _id_profesor;
//    int _curso;
//
//
//    system("cls");
//    const char *opciones[] = {"DNI", "NOMBRE MATERIA","ID APELLIDO"};
//
//    mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
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
//        showItem (opciones[4],30,14,y==4);
//        showItem (opciones[5],30,15,y==5);
//        showItem (opciones[6],30,16,y==6);
//        showItem (opciones[7],30,17,y==7);
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
//                    mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
//                    mostrar_mensaje ("--------------------------------", 40, 5);
//                    int dni;
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO DNI: "<<endl;
//                    rlutil::locate(39,9);
//                    cin>>dni;
//                    alumno.setDNI(dni);
//                    if (_archivo.guardar(alumno, posicion))
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
//                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
//                mostrar_mensaje ("--------------------------------", 40, 5);
//
//                {
//
//                    char nombre[30];
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO NOMBRE: "<<endl;
//                    rlutil::locate(47,9);
//                    cin>>nombre;
//                    alumno.setNombre(nombre);
//                    if (_archivo.guardar(alumno, posicion))
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
//            case 2:       /// SETEAR APELLIDO
//                system("cls");
//                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
//                mostrar_mensaje ("--------------------------------", 40, 5);
//
//                {
//                    char apellido[30];
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO APELLIDO: "<<endl;
//                    rlutil::locate(47,9);
//                    cin>>apellido;
//                    alumno.setApellido(apellido);
//                    if (_archivo.guardar(alumno, posicion))
//                    {
//
//                        rlutil::locate(30,15);
//                        cout << "**  REGISTRO MODIFICADO  **"<<endl;
//                    }
//
//                    system("pause>nul");
//                    system("cls");
//                }
//
//                break;
//
//            case 3:     /// SETEAR MAIL
//                system("cls");
//                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
//                mostrar_mensaje ("--------------------------------", 40, 5);
//
//                {
//
//                    char email[30];
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO EMAIL: "<<endl;
//                    rlutil::locate(45,9);
//                    cin>>email;
//                    alumno.setEmail(email);
//                    if (_archivo.guardar(alumno, posicion))
//                    {
//
//                        rlutil::locate(30,15);
//                        cout << "**  REGISTRO MODIFICADO  ** "<<endl;
//                    }
//
//                    system("pause>nul");
//                    system("cls");
//                }
//
//                break;
//
//            case 4:     /// SETEAR TELEFONO
//                system("cls");
//                mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
//                mostrar_mensaje ("--------------------------------", 40, 5);
//                {
//
//                    int tele;
//                    rlutil::locate(20,9);
//                    cout << "INGRESE EL NUEVO TELEFONO: "<<endl;
//                    rlutil::locate(53,9);
//                    cin>>tele;
//                    alumno.setTelefono(tele);
//                    if (_archivo.guardar(alumno, posicion))
//                    {
//
//                        rlutil::locate(30,15);
//                        cout << "**  REGISTRO MODIFICADO  **"<<endl;
//                    }
//
//                    system("pause>nul");
//                    system("cls");
//                    break;
//                case 5:     /// SETEAR ANIO EN CURSO
//                    system("cls");
//
//                    mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
//                    mostrar_mensaje ("--------------------------------", 40, 5);
//                    {
//
//                        int anio;
//                        rlutil::locate(20,9);
//                        cout << "INGRESE EL NUEVO ANIO EN CURSO: "<<endl;
//                        rlutil::locate(53,9);
//                        cin>>anio;
//                        alumno.setAnioCurso(anio);
//                        if (_archivo.guardar(alumno, posicion))
//                        {
//
//                            rlutil::locate(30,15);
//                            cout << "**  REGISTRO MODIFICADO **"<<endl;
//                        }
//                        system("pause>nul");
//                        system("cls");
//
//                        break;
//                    case 6:     /// SETEAR DAR DE BAJA
//                        system("cls");
//
//                        {
//                            mostrar_mensaje ("* MODIFICAR DATOS DEL ALUMNO *", 40, 4);
//                            mostrar_mensaje ("--------------------------------", 40, 5);
//                            int op;
//                            rlutil::locate(20,9);
//                            cout << "DESEA MODIFICAR ESTADO DEL ALUMNO (1-BAJA/2-ALTA): "<<endl;
//                            rlutil::locate(72,9);
//                            cin>>op;
//                            if (op==1)
//                            {
//                                alumno.setEstado(false);
//                                if (_archivo.guardar(alumno, posicion))
//
//                                    rlutil::locate(30,15);
//                                cout << "** REGISTRO MODIFICADO ** "<<endl;
//                            }
//                            else if(op==2)
//                            {
//
//                                alumno.setEstado(true);
//                                if (_archivo.guardar(alumno, posicion))
//
//                                    rlutil::locate(30,15);
//                                cout << "** REGISTRO MODIFICADO ** "<<endl;
//                            }
//                            system("pause>nul");
//                            system("cls");
//
//                        }
//                        break;
//
//                    case 7:     /// VOLVER AL MENU PRINCIPAL
//                        system("cls");
//                        {
//                            system("pause>nul");
//                            system("cls");
//
//                        }
//
//                        break;
//                    }
//                }
//            }
//        }
//
//    }
//    while(op!=0);
//    system("pause>nul");
//}
void CursoManager::HacerCopiaDeSeguridad()
{

    int cantidadRegistros = _archivo.getCantidad();
    Curso *vec = new Curso[cantidadRegistros];

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

void CursoManager::RestaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidad();
    Curso *vec = new Curso[cantidadRegistros];

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
