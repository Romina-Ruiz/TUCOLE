#ifndef FECHA_H
#define FECHA_H
#include <cstring>
#include <iostream>

class Fecha{
    private:
        int _dia, _mes, _anio;

    public:
        int  getDia();
        int  getMes();
        int  getAnio();
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
             Fecha(int dia, int mes, int anio);
             Fecha();
        std::string toString();
        void Mostrar();
        void Cargar();

        Fecha operator++();
};


#endif // FECHA_H
