#ifndef NOTAS_H
#define NOTAS_H


class Notas
{

private:

    int _DNIalumno;
    char _nombre_materia[30];
    int _Nro_examen; //1- PARCIAL 1/ 2- PARCIAL 2;
    float _nota;


public:

    void setDNIalumno(int dni);
    void setNombreMateria( char* nombremateria);
    void setNroExamen(int nro);
    void setNota(float nota);

    int getDNIalumno();
    char* getNombreMateria();
    int getNroExamen();
    float getNota();


};

#endif // NOTAS_H
