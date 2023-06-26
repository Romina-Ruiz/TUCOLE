#ifndef MATERIA_H
#define MATERIA_H


class Materia
{
private:
/// AGREGAR HORARIO + DIA DE CURSADA
    char _nombre[30];
    int _id;
    char _nombre_profesor[30];


public:

    void setNombreMateria( char* nombre);
    void setId(int id);
    void setNombreProfesor(char* nombreprofe);


    char* getNombreMateria();
    int getIdMateria();
    char* getNombreProfesor();



};

#endif // MATERIA_H
