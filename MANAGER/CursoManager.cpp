#include "CursoManager.h"
#include "../MENUS/rlutil.h"
#include "AlumnoArchivo.h"
#include "../MENUS/FUNCIONES_FRONT.h"
using namespace std;



void CursoManager::Cargar()
{
    AlumnoArchivo alumno;

    int dniAlumno,idProfesor,curso,nombreMateria;


    rlutil::locate(10,8);
    cout << "INGRESE DNI #: " <<endl;
    rlutil::locate(25,8);
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

        rlutil::locate(10,9);
        cout << "NOMBRE MATERIA #: "<<endl;
        rlutil::locate(30,9);
        cin>>nombreMateria;

        rlutil::locate(10,10);
        cout << "ID PROFESOR: "<<endl;
        rlutil::locate(30,13);
        idProfesor=generarId();
         rlutil::locate(30,10);
        cout << idProfesor;

        rlutil::locate(10,12);
        cout << "CURSO N#: "<<endl;
        rlutil::locate(30,12);
        cin>> curso;

        Curso aux;
        aux.setDniAlumno(dniAlumno);
        aux.setNombreMateria(nombreMateria);
        aux.setIdProfesor(idProfesor);
        aux.setCurso(curso);


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
        system("pause>nul");
    system("cls");
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
        cout << endl;

    }
}
void CursoManager::Listar(Curso curso)

{
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****      CURSO    ***** ", 34, 4);


    rlutil::locate(20,9);
    cout<<"DNI ALUMNO :    " <<curso.getDniAlumno()<<endl;
    rlutil::locate(20,10);
    cout<<"NOMBRE MATERIA:    "<<curso.getnombreMateria()<<endl;
    rlutil::locate(20,11);
    cout<<"ID PROFESOR:    "<<curso.getIdProfesor()<<endl;
    rlutil::locate(20,12);
    cout<<"CURSO N#:    " <<curso.getCurso()<<endl;

    system("pause>nul");
    system("cls");
}


void CursoManager::ListarAlumnosxCurso(){

    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    int curso;
    rlutil::locate(10,8);
    cout<<"CURSO "<<endl;
    rlutil::locate(15,9);
    cin>>curso;

    Curso obj;
    int cantReg=_archivo.getCantidad();

    for (int x=0; x<cantReg; x++)
    {
        obj=_archivo.leerReg(x);

        if (curso==obj.getCurso())
        {
            rlutil::locate(8,9);
            cout <<"ALUMNOS DEL CURSO :  "<<obj.getDniAlumno()<<endl;
            rlutil::locate(33,9);

             system("pause>nul");
            system("cls");
        }

    }
                rlutil::locate(30,9);
                cout <<"FIN DEL LISTADO "<<endl;
}
//
//
//
//void AlumnoManager::Editar()
//{
//    Alumno reg;
//    int dni, posicion;
//
//    rlutil::locate(20,9);
//    cout << "DNI A MODIFICAR: ";
//    cin >> dni;
//    cout << endl;
//
//    system("cls");
//    mostrar_mensaje ("***** MODIFICAR DE ALUMNO ***** ", 34, 4);
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
//}
//
//void AlumnoManager::Eliminar()
//{
//
//    Alumno reg;
//    int dni, posicion;
//    cout << "DNI a buscar: ";
//    cin >> dni;
//    cout << endl;
//
//    posicion = _archivo.buscarReg(dni);
//    if (posicion >= 0)
//    {
//        reg = _archivo.leerReg(posicion);
//        Listar(reg);
//        cout << endl;
//        reg.setEstado(false);
//        _archivo.guardar(reg, posicion);
//        cout << "Registro #" << dni << " eliminado correctamente" << endl;
//    }
//    else
//    {
//        cout << "No existe el registro con DNI #" << dni << endl;
//    }
//}
//
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

//void AlumnoManager::ModificarDatos(Alumno alumno, int posicion)
//{
//    system("cls");
//    const char *opciones[] = {"DNI", "NOMBRE","APELLIDO", "EMAIL", "TELEFONO", "ANIO EN CURSO", "MODIFICAR ESTADO", "VOLVER AL MENU PRINCIPAL"};
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
