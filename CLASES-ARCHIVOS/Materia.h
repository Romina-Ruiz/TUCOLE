#ifndef MATERIA_H
#define MATERIA_H
#include <string>



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
    void setNombreMateria(std::string nombre);
    void setId(int id);
    void setidProfesor(int idprofe);
    void setDia1( std::string d1);
    void setHorario1( std::string h1);
    void setDia2( std::string d2);
    void setHorario2( std::string h2);
    void setEliminada(bool eliminada); //true eliminada false activa

    int getAnioLectivo();
    std::string getNombreMateria();
    int getIdMateria();
    int getidProfesor();
    std::string getDia1();
    std::string  getHorario1();
    std::string getDia2();
    std::string getHorario2();
    bool getEliminada();

};

#endif // MATERIA_H
