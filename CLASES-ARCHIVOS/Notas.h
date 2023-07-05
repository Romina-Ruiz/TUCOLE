#ifndef NOTAS_H
#define NOTAS_H
#include <string>


class Notas
{

private:

    int _DNIalumno;
    char _nombre_materia[30];
    int _Nro_examen; //1- PARCIAL 1/ 2- PARCIAL 2;
    float _nota;
    bool _eliminada;


public:

    void setDNIalumno(int dni);
    void setNombreMateria( std::string nombre_materia);
    void setNroExamen(int nro);
    void setNota(float nota);
    void setEliminada(bool eliminada);

    int getDNIalumno();
    std::string getNombreMateria();
    int getNroExamen();
    float getNota();
    bool getEliminada();


};

#endif // NOTAS_H
