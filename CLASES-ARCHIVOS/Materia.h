#ifndef MATERIA_H
#define MATERIA_H


class Materia
{
private:
/// AGREGAR HORARIO + DIA DE CURSADA
    int _anio_lectivo; //1.2.3
    char _nombre[40];
    int _id;
    int _idprofesor;
    char _dia1[10];
    char _horario1[10];
    char _dia2[10];
    char _horario2[10];
    bool _eliminada;


public:

    void setAnioLectivo(int aniolectivo);
    void setNombreMateria( char* nombre);
    void setId(int id);
    void setidProfesor(int idprofe);
    void setDia1( char* d1);
    void setHorario1( char* h1);
    void setDia2( char* d2);
    void setHorario2( char* h2);
    void setEliminada(bool eliminada); //true eliminada false activa

    int getAnioLectivo();
    char* getNombreMateria();
    int getIdMateria();
    int getidProfesor();
    char* getDia1();
    char* getHorario1();
    char* getDia2();
    char* getHorario2();
    bool getEliminada();

};

#endif // MATERIA_H
