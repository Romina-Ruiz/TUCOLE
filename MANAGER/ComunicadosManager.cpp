#include "ComunicadosManager.h"
#include"Comunicados.h"
#include"ComunicadosArchivo.h"
#include"../MENUS/rlutil.h"
#include"../MENUS/FUNCIONES_ADMIN.h"
#include"../MENUS/FUNCIONES_FRONT.h"
#include"../MENUS/FUNCIONES_USER.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/MENUS.h"

using namespace std;

void  ComunicadosManager::cargarCadena(char *pal, int tam)
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
int ComunicadosManager::generarID()
{
    ComunicadosArchivo _archivo;
    return _archivo.getCantidad()+1;
}


void ComunicadosManager::Cargar()
{
    system("cls");

    const char *opciones[] = {"COMUNICADOS POR ALUMNO", "COMUNICADOS POR CURSO",
                              "COMUNICADOS ACTIVOS","ELIMINAR UN COMUNICADO","SALIR"
                             };

    int op=1, y=0;

    rlutil::hidecursor();

    do
    {
        mostrar_mensaje ("*****  COMUNICADOS  ***** ", 34, 4);
        mostrar_mensaje ( " ESTAS SON TUS OPCIONES:  ", 40, 6);


        rlutil::saveDefaultColor();
        rectangulo (2, 2, 100, 26);
        rlutil::setColor(rlutil::YELLOW);

        showItem (opciones[0],30,10,y==0);
        showItem (opciones[1],30,11,y==1);
        showItem (opciones[2],30,12,y==2);
        showItem (opciones[3],30,13,y==3);
        showItem (opciones[4],30,14,y==4);

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

            if (y>4)
            {
                y=4;
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



                system("pause>nul");
                system("cls");

            }

            break;

            case 2:     /// LISTADO DE COMUNICADOS ACTIVOS
            {

                system("cls");

                rlutil::setColor(rlutil::YELLOW);
                rectangulo (2, 2, 100, 26);
                mostrar_mensaje ("***** COMUNICADOS POR CURSO ***** ", 34, 4);



                system("pause>nul");
                system("cls");

            }

            case 3:     ///ELIMINAR UN COMUNICADO
                system("cls");

                system("pause>nul");
                system("cls");

                break;

            case 4:    ///COMUNICADOS
                system("cls");

                system("pause>nul");
                system("cls");

                break;

            case 5:     /// SALIR
                system("cls");

                system("pause>nul");
                system("cls");

                break;

            }

        }

    }
    while(op!=0);

    system("pause");



}


void  ComunicadosManager::ComunicadoxDNI()
{

    char comunicado[100];
    int DNI;
    int dia,mes,anio;
    bool activo;

    rlutil::locate(20,9);
    cout << "INGRESE EL DNI DEL ALUMNO: "<<endl;
    rlutil::locate(50,9);
    cin>>DNI;

    int id=this->generarID();
    rlutil::locate(20,10);
    cout<<" COMUNICADO N# :"<<endl;
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
    rlutil::locate(20,16);
    cout<<"INGRESE EL COMUNICADO :"<<endl;
    rlutil::locate(45,16);
    this->cargarCadena(comunicado,99);

    Comunicados aux;
    aux.setDNIalumno(DNI);
    aux.setIdComunicado(id);
    aux.setFechaComunicado(Fecha(dia, mes, anio));
    aux.setIdComunicado(*comunicado);
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


