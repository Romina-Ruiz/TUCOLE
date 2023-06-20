#include <iostream>
#include <cstring>
#include "MateriaManager.h"
#include "Materia.h"
#include "MateriaArchivo.h"

using namespace std;

MateriaManager::MateriaManager(char *ruta){

    strcpy(_ruta,ruta);
}
MateriaManager::MateriaManager(){

    strcpy(_ruta,"MateriaManager.dat");

 }


int MateriaManager::Cargar()
{

    Materia aux;
    MateriaArchivo ArchMateria;

    char nombre, nombre_alumno,nombre_profesor;
    int id, anio_curso, id_profesor;
    bool agrego = false;
//
//    cout<<"NOMBRE : ";
//    cin>>nombre;

    cout<<"ID MATERIA: ";
    cin>>id;

    cout<<"ANIO DE CURSO: ";
    cin>>anio_curso;

//    cout<<"NOMBRE DEL ALUMNO: ";
//    cin>>nombre_alumno;

//    cout<<"NOMBRE DEL PROFESOR :";
//    cin>>nombre_profesor;

    cout<<"ID DEL PROFESOR";
    cin>>id_profesor;

   // aux.setNombreMateria(nombre);
    aux.setId(id);
    aux.setAnioCurso(anio_curso);
   // aux.getNombreAlumno(nombre_alumno);
   // aux.setNombreProfesor(nombre_profesor);
    aux.setidProfesor(id_profesor);

    agrego = ArchMateria.agregar(aux);

    if (agrego == false)
    {
        return -1;
    }
    return 0;
}






