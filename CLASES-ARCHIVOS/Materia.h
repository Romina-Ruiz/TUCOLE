#ifndef MATERIA_H
#define MATERIA_H


class Materia
{
private:
/// AGREGAR HORARIO + DIA DE CURSADA
    char _nombre[40];
    int _id;
    char _nombre_profesor[40];
    int _anio_lectivo; //1.2.3
    bool _eliminada;


public:

    void setNombreMateria( char* nombre);
    void setId(int id);
    void setNombreProfesor(char* nombreprofe);
    void setAnioLectivo(int aniolectivo);
    void setEliminada(bool eliminada);


    char* getNombreMateria();
    int getIdMateria();
    char* getNombreProfesor();
    int getAnioLectivo();
    bool getEliminada();



};

#endif // MATERIA_H
