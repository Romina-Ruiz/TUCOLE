#ifndef NOTAS_H
#define NOTAS_H


class Notas
{

private:

    int _DNIalumno;
    int _idMateria;
    int _tipoNota;
    float _nota;


public:

    void setDNIalumno(int dni);
    void setIdMateria(int materia);
    void setTipoNota(int tipo);
    void setNota(float nota);

    int getDNIalumno();
    int getIdMateria();
    int getTipoNota();
    float getNota();


};

#endif // NOTAS_H
