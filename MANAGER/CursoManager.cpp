#include "CursoManager.h"
#include "../MENUS/rlutil.h"
#include "AlumnoArchivo.h"
#include "../MENUS/FUNCIONES_FRONT.h"
#include "AlumnoManager.h"
#include"Materia.h"
#include"MateriaArchivo.h"
#include"MateriaManager.h"
#include"Notas.h"
#include"NotasArchivo.h"

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
                system("cls");
            }
            break;
            }
        }

    }
    while(op!=0);
    system("pause>nul");

}

void CursoManager::InformeCursos()
{

    system("cls");


    const char *opciones[] = {"PROMEDIO NOTAS POR CURSOS", "PROMEDIO MATERIAS APROBADAS",
                              "PROMEDIO POR ALUMNO", "VOLVER AL MENU ANTERIOR"
                             };

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {

    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("***** INFORME SOBRE ANIOS/CURSOS ***** ", 30, 4);

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
            case 0:      /// PROMEDIO NOTAS POR CURSOS
            {
                system("cls");

                this->InformePromedioCursos();

                system("cls");
            }

            break;

            case 1:       /// PROMEDIO MATERIAS APROBADAS
            {
                system("cls");
                this->InformeMateriasAprobadas();
                system("cls");
            }
            break;

            case 2:       ///  PROMEDIO POR ALUMNO
            {
                system("cls");

                rlutil::saveDefaultColor();
                rectangulo (2, 2, 100, 26);
                rlutil::setColor(rlutil::YELLOW);

                this->InformePromedioAlumno();
                system("cls");
            }
            break;
            case 3:     /// SALIR
            {
                system("cls");
                menuInformes();
                system("cls");
            }
            break;
            }
        }

    }
    while(op!=0);
    system("pause>nul");

}


void CursoManager::InformePromedioCursos()
{
    system("cls");
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("***** INFORME SOBRE PROMEDIO DE CURSOS ***** ", 30, 4);


    mostrar_mensaje ("CURSO 1 ", 35, 6);
    mostrar_mensaje ("CURSO 2 ", 52, 6);
    mostrar_mensaje ("CURSO 3 ", 72, 6);
    mostrar_mensaje ("PROMEDIO GRAL DEL ALUMNADO: ", 4, 8);

    float Curso1, Curso2, Curso3=0;

    rlutil::locate(36,8);
    Curso1=this->InformePromedioCurso1();
    cout<<Curso1<<" % " <<endl;

    rlutil::locate(53,8);
    Curso2=this->InformePromedioCurso2();
    cout<<Curso2<<" % " <<endl;

    rlutil::locate(73,8);
    Curso3=this->InformePromedioCurso3();
    cout<<Curso3<<" % " <<endl;

    system("pause>nul");
}

void CursoManager::InformeMateriasAprobadas()
{

    system("cls");
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("***** INFORME SOBRE MATERIAS APROBADAS ***** ", 30, 4);

    mostrar_mensaje ("CURSO 1 ", 30, 6);
    mostrar_mensaje ("CURSO 2 ", 50, 6);
    mostrar_mensaje ("CURSO 3 ", 70, 6);


    this->InformePromedioNotas1();
    this->InformePromedioNotas2();
    this->InformePromedioNotas3();


    system("pause>nul");
}

void CursoManager::InformePromedioAlumno()
{
    system("cls");
    rlutil::saveDefaultColor();
    rectangulo (2, 2, 100, 26);
    rlutil::setColor(rlutil::YELLOW);

    mostrar_mensaje ("***** INFORME SOBRE PROMEDIO POR ALUMNO ***** ", 30, 4);
    int dni;
    rlutil::locate(5,8);
    cout <<" POR FAVOR INGRESE EL DNI A CONSULTAR: ";
    rlutil::locate(50,8);
    cin>>dni;

    Notas Aux;
    NotasArchivo ArNotas;

    int canRegNotas=ArNotas.getCantidad();

    float Totales=0;
    int Cantidad=0;


    for(int i=0; i<canRegNotas; i++)
    {

        Aux=ArNotas.leerReg(i);

        if (Aux.getDNIalumno()==dni&&Aux.getEliminada()==false)
        {

            Totales+=Aux.getNota();
            Cantidad++;
        }
    }

    mostrar_mensaje ("PROMEDIO GENERAL:", 10, 10);
    rlutil::locate(30,10);
    cout<<Totales/Cantidad <<" % "<<endl;
     rlutil::locate(10,11);
    cout<<"CANTIDAD DE MATERIAS CURSADAS:  " <<Cantidad<<endl;


    system("pause>nul");
}

float CursoManager::InformePromedioCurso1()
{

    Materia obj;
    MateriaArchivo ArMate;

    Notas Aux;
    NotasArchivo ArNotas;

    int canRegMate=ArMate.getCantidad();
    int canRegNotas=ArNotas.getCantidad();

    float Totales=0;
    int Cantidad=0;

    for(int x=0; x<canRegMate; x++)
    {

        obj=ArMate.leerReg(x);

        for(int i=0; i<canRegNotas; i++)
        {

            Aux=ArNotas.leerReg(i);

            if (obj.getAnioLectivo()==1&& obj.getIdMateria()==Aux.getIDMateria())
            {

                Totales+=Aux.getNota();
                Cantidad++;
            }
        }
    }

    return Totales/Cantidad;

}

float CursoManager::InformePromedioCurso2()
{

    Materia obj;
    MateriaArchivo ArMate;

    Notas Aux;
    NotasArchivo ArNotas;

    int canRegMate=ArMate.getCantidad();
    int canRegNotas=ArNotas.getCantidad();

    float Totales=0;
    int Cantidad=0;

    for(int x=0; x<canRegMate; x++)
    {

        obj=ArMate.leerReg(x);

        for(int i=0; i<canRegNotas; i++)
        {

            Aux=ArNotas.leerReg(i);

            if (obj.getAnioLectivo()==2&& obj.getIdMateria()==Aux.getIDMateria())
            {

                Totales+=Aux.getNota();
                Cantidad++;
            }
        }
    }

    return Totales/Cantidad;

}

float CursoManager::InformePromedioCurso3()
{

    Materia obj;
    MateriaArchivo ArMate;

    Notas Aux;
    NotasArchivo ArNotas;

    int canRegMate=ArMate.getCantidad();
    int canRegNotas=ArNotas.getCantidad();

    float Totales=0;
    int Cantidad=0;

    for(int x=0; x<canRegMate; x++)
    {

        obj=ArMate.leerReg(x);

        for(int i=0; i<canRegNotas; i++)
        {

            Aux=ArNotas.leerReg(i);

            if (obj.getAnioLectivo()==3&& obj.getIdMateria()==Aux.getIDMateria())
            {

                Totales+=Aux.getNota();
                Cantidad++;
            }
        }
    }

    return Totales/Cantidad;

}

void CursoManager::InformePromedioNotas1()
{

    Materia obj;
    MateriaArchivo ArMate;

    Notas Aux;
    NotasArchivo ArNotas;

    int canRegMate=ArMate.getCantidad();
    int canRegNotas=ArNotas.getCantidad();


    int Cantidad1=0;
    int Cantidad2=0;
    int Cantidad3=0;
    float Prome10=0;
    float Prome8=0;
    float Prome6=0;

    for(int x=0; x<canRegMate; x++){

                obj=ArMate.leerReg(x);

            for(int i=0; i<canRegNotas; i++){

                        Aux=ArNotas.leerReg(i);

                             if (obj.getAnioLectivo()==1&& obj.getIdMateria()==Aux.getIDMateria()){

                                          if (Aux.getNota()>8&& Aux.getNota()<=10){

                                          Cantidad1++;
                                             }
                                         else { if (Aux.getNota()>=6 && Aux.getNota()<=8){

                                             Cantidad2++;

                                                        }
                                          else {

                                            Cantidad3++;
                                                    }
                                         }
                                        }
                                }
                }

                int totalesnotas=Cantidad1+Cantidad2+Cantidad3;
                Prome10=Cantidad1*100/totalesnotas;
                Prome8=Cantidad2*100/totalesnotas;
                Prome6=Cantidad3*100/totalesnotas;


    mostrar_mensaje ("Notas de 1 A 6: ", 6, 9);
    mostrar_mensaje ("Notas de 6 A 8: ", 6, 10);
    mostrar_mensaje ("Notas de 8 A 10:  ", 6, 11);

    rlutil::locate(30,9);
    cout<<Prome10<<endl;
    rlutil::locate(30,10);
    cout<<Prome8<<endl;
    rlutil::locate(30,11);
    cout<<Prome6<<endl;

}

void CursoManager::InformePromedioNotas2()
{

    Materia obj;
    MateriaArchivo ArMate;

    Notas Aux;
    NotasArchivo ArNotas;

    int canRegMate=ArMate.getCantidad();
    int canRegNotas=ArNotas.getCantidad();


    int Cantidad1=0;
    int Cantidad2=0;
    int Cantidad3=0;
    float Prome10=0;
    float Prome8=0;
    float Prome6=0;

    for(int x=0; x<canRegMate; x++){

                obj=ArMate.leerReg(x);

            for(int i=0; i<canRegNotas; i++){

                        Aux=ArNotas.leerReg(i);

                             if (obj.getAnioLectivo()==2 && obj.getIdMateria()==Aux.getIDMateria()){

                                          if (Aux.getNota()>8&& Aux.getNota()<=10){

                                            Cantidad1++;
                                             }
                                         else { if (Aux.getNota()>=6 && Aux.getNota()<=8){

                                            Cantidad2++;

                                                        }
                                          else {

                                            Cantidad3++;
                                                    }
                                         }
                                        }
                                }
                }

                int totalesnotas=Cantidad1+Cantidad2+Cantidad3;
                Prome10=Cantidad1*100/totalesnotas;
                Prome8=Cantidad2*100/totalesnotas;
                Prome6=Cantidad3*100/totalesnotas;


    rlutil::locate(30,15);
    cout<<Prome10<<endl;
    rlutil::locate(30,16);
    cout<<Prome8<<endl;
    rlutil::locate(30,17);
    cout<<Prome6<<endl;


}

void CursoManager::InformePromedioNotas3()
{

    Materia obj;
    MateriaArchivo ArMate;

    Notas Aux;
    NotasArchivo ArNotas;

    int canRegMate=ArMate.getCantidad();
    int canRegNotas=ArNotas.getCantidad();

      int Cantidad1=0;
      int Cantidad2=0;
      int Cantidad3=0;
    float Prome10=0;
    float Prome8=0;
    float Prome6=0;

    for(int x=0; x<canRegMate; x++){

                obj=ArMate.leerReg(x);

            for(int i=0; i<canRegNotas; i++){

                        Aux=ArNotas.leerReg(i);

                             if (obj.getAnioLectivo()==3&& obj.getIdMateria()==Aux.getIDMateria()){

                                          if (Aux.getNota()>8&& Aux.getNota()<=10){

                                              Cantidad1++;
                                             }
                                         else { if (Aux.getNota()>=6 && Aux.getNota()<=8){

                                              Cantidad2++;

                                                        }
                                          else {

                                            Cantidad3++;
                                                    }
                                         }
                                        }
                                }
                }

                int totalesnotas=Cantidad1+Cantidad2+Cantidad3;
                Prome10=Cantidad1*100/totalesnotas;
                Prome8=Cantidad2*100/totalesnotas;
                Prome6=Cantidad3*100/totalesnotas;

    rlutil::locate(30,19);
    cout<<Prome10<<endl;
    rlutil::locate(30,20);
    cout<<Prome8<<endl;
    rlutil::locate(30,11);
    cout<<Prome6<<endl;


}



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
