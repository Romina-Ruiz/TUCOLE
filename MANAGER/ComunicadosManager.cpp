//#include "ComunicadosManager.h"
//
//ComunicadosManager::ComunicadosManager(char *ruta)
//{
//
//    strcpy(_ruta,ruta);
//}
//ComunicadosManager::ComunicadosManager()
//{
//
//    strcpy(_ruta,"ComunicadosManager.dat");
//
//}
//
//void Cargar()
//{
//
//    int id,id_materia,anio_curso,dniAlumno,dia,mes,anio;
//
//    int opcion;
//    do
//    {
//        cout << "---------------" << endl;
//        cout << "--COMUNICADOS--" << endl;
//        cout << "---------------" << endl;
//        cout << "1. CargarXalumno " << endl;
//        cout << "2. CargarXcurso " << endl;
//        cout << "0. SALIR " << endl;
//
//
//        cin >> opcion;
//
//        switch(opcion)
//        {
//        case 1:
//            cout<<"Ingrese DNI del alumno :"<<endl;
//            cin>>dniAlumno;
//
//            id=this->generarId();
//
//            cout<<" COMUNICADO N# :"<<endl;
//            cin>>id<<end;
//
//            id_materia=this->generarId();
//
//            cout<<" ID MATERIA :"<<endl;
//            cin>>id_materia;
//            cout<<" AÑO DE CURSO :"<<endl;
//            cin>>anio_curso;
//            cout<<"INGRESE LA FECHA DE HOY : DIA :"<<endl;
//            cin>>dia;
//            cout<<"INGRESE MES :"<<endl;
//            cin>>mes;
//            cout<<"INGRESE ANIO :"<<endl;
//            cin>>anio;
//
//            Comunicados aux;
//        aux.setDNIalumno(dniAlumno);
//        aux.setIdComunicado(id);
//        aux.setIdMateria(id_materia);
//        aux.setAnioCurso(anio_curso);
//        aux.FechaComunicado(Fecha(dia, mes, anio));
//
//
//        if (_archivo.agregar(aux))
//        {
//            rlutil::locate(30,23);
//            cout << "** Comunicado guardado correctamente **" << endl;
//            system("pause>nul");
//        }
//        else
//        {
//            rlutil::locate(30,25);
//            cout << "** Ups! Algo salio mal :( **" << endl;
//            system("pause>nul");
//        }
//    }
//    system("pause");
//
//
//            break;
//        case 2:
//
//             id=this->generarId();
//
//            cout<<" COMUNICADO N# :"<<endl;
//            cin>>id<<end;
//
//            id_materia=this->generarId();
//
//            cout<<" ID MATERIA :"<<endl;
//            cin>>id_materia;
//            cout<<" AÑO DE CURSO :"<<endl;
//            cin>>anio_curso;
//              cout<<"INGRESE LA FECHA DE HOY : DIA :"<<endl;
//            cin>>dia;
//            cout<<"INGRESE MES :"<<endl;
//            cin>>mes;
//            cout<<"INGRESE ANIO :"<<endl;
//            cin>>anio;
//
//            Comunicados aux;
//        aux.setIdComunicado(id);
//        aux.setIdMateria(id_materia);
//        aux.setAnioCurso(anio_curso);
//        aux.FechaComunicado(Fecha(dia, mes, anio));
//
//
//        if (_archivo.agregar(aux))
//        {
//            rlutil::locate(30,23);
//            cout << "** Comunicado guardado correctamente **" << endl;
//            system("pause>nul");
//        }
//        else
//        {
//            rlutil::locate(30,25);
//            cout << "** Ups! Algo salio mal :( **" << endl;
//            system("pause>nul");
//        }
//    }
//    system("pause");
//
//
//            break;
//
//        }
//        while(opcion != 0);
//

