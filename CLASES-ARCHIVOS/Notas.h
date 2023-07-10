#ifndef NOTAS_H
#define NOTAS_H
#include <string>


class Notas
{

private:

    int _DNIalumno;
    int _IDmateria;
    int _Nro_examen; //1- PARCIAL 1/ 2- PARCIAL 2/ 3-final
    float _nota;
    int _IDNota;
    bool _eliminada;


public:

    void setDNIalumno(int dni);
    void setIDMateria(int id);
    void setNroExamen(int nro);
    void setNota(float nota);
    void setIDNota(int idnota);
    void setEliminada(bool eliminada);

    int getDNIalumno();
    int getIDMateria();
    int getNroExamen();
    float getNota();
    int getIDNota();
    bool getEliminada();


};

#endif // NOTAS_H
