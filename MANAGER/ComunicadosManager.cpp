#include "ComunicadosManager.h"
#include"Comunicados.h"
#include"ComunicadosArchivo.h"
#include"../MENUS/rlutil.h"
#include"../MENUS/FUNCIONES_ADMIN.h"
#include"../MENUS/FUNCIONES_FRONT.h"
#include"../MENUS/FUNCIONES_USER.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/MENUS.h"
#include"Curso.h"
#include"CursoArchivo.h"

using namespace std;


int ComunicadosManager::generarID()
{
    ComunicadosArchivo _archivo;
    return _archivo.getCantidad()+1;
}


void ComunicadosManager::Cargar()
{
    system("cls");

    const char *opciones[] = {"COMUNICADOS POR ALUMNO", "COMUNICADOS POR CURSO",
                              "VOLVER AL MENU PRINCIPAL"
                             };

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        mostrar_mensaje ("*****  COMUNICADOS  ***** ", 34, 4);
        mostrar_mensaje ( "ESTAS SON TUS OPCIONES:  ", 37, 6);


        rlutil::saveDefaultColor();
        rectangulo (2, 2, 100, 26);
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

            if (y>2)
            {
                y=2;
            }
            break;

        case 1:     /// OPCIONES AL INGRESAR ENTER (EL ENTER ES LA TECLA 1):

            switch(y)
            {

            case 0:     ///COMUNICADOS POR DNI/ALUMNO
            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** COMUNICADOS POR ALUMNOS ***** ", 34, 4);

                ComunicadosManager obj;

                obj.ComunicadoxDNI();

                system("pause>nul");
                system("cls");
            }

            break;

            case 1:     ///COMUNICADOS POR CURSO

            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** COMUNICADOS POR CURSOS ***** ", 34, 4);
                ComunicadosManager obj;

                obj.ComunicadoxCurso();

                system("pause>nul");
                system("cls");

            }

            break;

            case 2:     /// SALIR
                system("cls");
                menuAdmin();
                system("pause>nul");

                break;

            }

        }

    }
    while(op!=0);

    system("pause");

}

void ComunicadosManager::listar(Comunicados obj)
{

    rlutil::setColor(rlutil::YELLOW);
    mostrar_mensaje ("*****      COMUNICADO    ***** ", 34, 4);
    mostrar_mensaje ("------------------------------------ ", 34, 5);

    rlutil::locate(15,10);
    cout<<"ID COMUNICADO:    "<<obj.getIdComunicado()<<endl;

    rlutil::locate(15,12);
    cout<<"COMUNICADO:    " <<endl;
    rlutil::locate(20,15);
    cout<<obj.getComunicado()<<endl;

mostrar_mensaje ("*****      SALUDOS   ***** ", 40, 25);

    system("pause>nul");

}
int ComunicadosManager::BuscarCurso(int dni){

Curso aux;
CursoArchivo ArCurso;
int curso=-1;

int canReg=ArCurso.getCantidad();

for (int x=0; x<canReg; x++){

    aux=ArCurso.leerReg(x);

    if(aux.getDniAlumno()==dni&&aux.getEstado()==true)
           return  aux.getCurso();


}



}


void ComunicadosManager::ComunicadoUser(int dni){

Comunicados aux;

int cantReg=_archivo.getCantidad();


for (int x=0; x<cantReg; x++){

            aux=_archivo.leerReg(x);

            int curso1=this->BuscarCurso(dni);


            if(aux.getDni()==dni || aux.getAnioCurso()==curso1 &&aux.getEliminado()==true){
                rlutil::setColor(rlutil::YELLOW);
                              rlutil::locate(20,10);
                                 this->listar(aux);
                                 system("pause>nul");

                        }



                }

            system("cls");
            rlutil::locate(20,10);
            cout <<"*** FIN DE LOS COMUNICADOS  ***";
            system("pause>nul");

}


void  ComunicadosManager::ComunicadoxDNI()
{


    string comunicado;
    int DNI;
    int dia,mes,anio;


    rlutil::locate(20,9);
    cout << "INGRESE EL DNI DEL ALUMNO: "<<endl;
    rlutil::locate(50,9);
    cin>>DNI;

    int id=this->generarID();
    rlutil::locate(20,10);
    cout<<"COMUNICADO N# : "<<endl;
    rlutil::locate(38,10);
    cout <<id <<endl;
    rlutil::locate(20,12);
    cout<<"INGRESE LA FECHA DE HOY";
    rlutil::locate(20,13);
    cout<< "DIA :"<<endl;
    rlutil::locate(28,13);
    cin>>dia;
    rlutil::locate(20,14);
    cout<<"INGRESE MES :"<<endl;
    rlutil::locate(36,14);
    cin>>mes;
    rlutil::locate(20,15);
    cout<<"INGRESE ANIO :"<<endl;
    rlutil::locate(36,15);
    cin>>anio;
    rlutil::locate(20,17);
    cout<<"INGRESE EL COMUNICADO :"<<endl;
    rlutil::locate(45,17);
    cin.ignore();
    getline(cin,comunicado);

    Comunicados aux;
    aux.setDNIalumno(DNI);
    aux.setAnioCurso(0);
    aux.setIdComunicado(id);
    aux.setFechaComunicado(Fecha(dia, mes, anio));
    aux.setComunicado(comunicado);
    aux.setEliminado(true);

    if (_archivo.agregar(aux))
    {
        rlutil::locate(30,23);
        cout << "** Comunicado guardado correctamente **" << endl;
        system("pause>nul");

    }
    else
    {
        rlutil::locate(30,25);
        cout << "** Ups! Algo salio mal :( **" << endl;
        system("pause>nul");

    }
}

void ComunicadosManager::ComunicadoxCurso()
{

    string comunicado;
    int CURSO;
    int dia,mes,anio;


    rlutil::locate(20,9);
    cout << "INGRESE EL CURSO: "<<endl;
    rlutil::locate(38,9);
    cin>>CURSO;

    int id=this->generarID();
    rlutil::locate(20,10);
    cout<<"COMUNICADO N# :"<<endl;
    rlutil::locate(38,10);
    cout <<id <<endl;
    rlutil::locate(20,12);
    cout<<"INGRESE LA FECHA DE HOY";
    rlutil::locate(20,13);
    cout<< "DIA :"<<endl;
    rlutil::locate(28,13);
    cin>>dia;
    rlutil::locate(20,14);
    cout<<"INGRESE MES :"<<endl;
    rlutil::locate(36,14);
    cin>>mes;
    rlutil::locate(20,15);
    cout<<"INGRESE ANIO :"<<endl;
    rlutil::locate(36,15);
    cin>>anio;
    rlutil::locate(20,17);
    cout<<"INGRESE EL COMUNICADO :"<<endl;
    rlutil::locate(45,17);
    cin.ignore();
    getline(cin,comunicado);

    Comunicados aux;
    aux.setDNIalumno(0);
    aux.setAnioCurso(CURSO);
    aux.setIdComunicado(id);
    aux.setFechaComunicado(Fecha(dia, mes, anio));
    aux.setComunicado(comunicado);
    aux.setEliminado(true);

    if (_archivo.agregar(aux))
    {
        rlutil::locate(30,23);
        cout << "** Comunicado guardado correctamente **" << endl;
        system("pause>nul");

    }
    else
    {
        rlutil::locate(30,25);
        cout << "** Ups! Algo salio mal :( **" << endl;
        system("pause>nul");
    }
}
void ComunicadosManager::EliminarComunicado()
{

    Comunicados reg;
    int comunicado, posicion;
    rlutil::locate(20,10);
    cout << "INGRESE EL ID DEL COMUNICADO: ";
    rlutil::locate(51,10);
    cin >> comunicado;


    posicion =_archivo.buscarReg(comunicado);
    if (posicion >= 0)
    {
        reg = _archivo.leerReg(posicion);

         int res;
         rlutil::locate(20,12);
         cout << "DESEA DAR DE BAJA EL COMUNICADO (1-SI/2-NO): ";
         rlutil::locate(60,12);
         cin >> res;

         if (res==1)
         {
        reg.setEliminado(false);
        _archivo.modificarReg(reg, posicion);
        rlutil::locate(35,15);
        cout << "** COMUNICADO N#  " << comunicado<< " ELIMINADO CORRECTAMENTE ***" << endl;
        system("pause>nul");

        }
    }
    else
    {
      rlutil::locate(35,10);
        cout << "**  NO EXISTE UN COMUNICADO CON ESE ID  **"  << endl;
        system("pause>nul");
    }


}


void ComunicadosManager::ComunicadosActivos()
{


    int cantidadRegistros = _archivo.getCantidad();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Comunicados reg = _archivo.leerReg(i);
        if (reg.getEliminado()==true)
        {
            rlutil::setColor(rlutil::YELLOW);

            mostrar_mensaje ("***** COMUNICADOS ACTIVOS ***** ", 38, 4);

            rlutil::locate(10,9);
            cout<<"COMUNICADO N#:  "<<reg.getIdComunicado()<< endl;
            rlutil::locate(10,10);
            cout<<"FECHA:  "<<reg.getFechaComunicado().toString()<< endl;
            rlutil::locate(10,12);
            cout << reg.getComunicado()<< endl;
            rlutil::locate(30,20);
            cout << "---------------------  SALUDOS  -------------------------"<< endl;
            system("pause>nul");
            system("cls");
        }
    }
    rectangulo (2, 2, 100, 26);
    mostrar_mensaje ("***** FIN DE LOS COMUNICADOS ***** ", 34, 10);

}


void ComunicadosManager::HacerCopiaDeSeguridad()
{
    ComunicadosArchivo _archivoBkp = ComunicadosArchivo("comunicados.bkp");
    ComunicadosArchivo _archivo;
    int cantidadRegistros = _archivo.getCantidad();
    Comunicados *vec = new Comunicados[cantidadRegistros];

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

void ComunicadosManager::RestaurarCopiaDeSeguridad()
{
    ComunicadosArchivo _archivoBkp = ComunicadosArchivo("comunicados.bkp");
    ComunicadosArchivo _archivo;
    int cantidadRegistros = _archivoBkp.getCantidad();
    Comunicados *vec = new Comunicados[cantidadRegistros];

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
