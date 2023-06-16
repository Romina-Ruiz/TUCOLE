#include "Fecha.h"
#include<ctime>
#include<cstring>
#include <iostream>

using namespace std;

//CONSTRUCTOR:
Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int  Fecha::getDia(){
    return _dia;
}
int  Fecha::getMes(){
    return _mes;
}
int  Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}
void Fecha::setMes(int mes){
    _mes = mes;
}
void Fecha::setAnio(int anio){
    _anio = anio;
}

Fecha::Fecha(){
    time_t rawtime;
    struct tm timeinfo;

    time (&rawtime);
    timeinfo = *(localtime (&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;
}


void Fecha::Mostrar(){

    if(_mes>=10&&_anio>=10){
        cout<<getDia()<<"/"<<getMes()<<"/"<<getAnio()<<endl;
    }
    else if(_mes<10&&_anio>=10){
        cout<<getDia()<<"/"<<"0"<<getMes()<<"/"<<getAnio()<<endl;
    }
    else if(_mes>=10&&_anio<10){
        cout<<getDia()<<"/"<<getMes()<<"/"<<"0"<<getAnio()<<endl;
    }
    else{
        cout<<getDia()<<"/"<<"0"<<getMes()<<"/"<<"0"<<getAnio()<<endl;
    }
}

 /*string Fecha::toString(){
    string fecha;
    fecha = to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
    return fecha;
}
*/

 Fecha Fecha::operator++(){
    int dia=_dia;
    int mes=_mes;
    int anio=_anio;

    if (_mes==2&&_dia<=27)
    {
        dia+=1;
    }
    if (_mes==2&&_dia>27)
    {
        dia-=27;
        mes+=1;
    }

    if((_mes==4||_mes==6||_mes==9||_mes==11)&&_dia<=29)
    {
        dia+=1;
    }
    if((_mes==4||_mes==6||_mes==9||_mes==11)&&_dia>29)
    {
        dia-=29;
        mes+=1;
    }

    if((_mes==1||_mes==3||_mes==5||_mes==7||_mes==8||_mes==10||_mes==12)&&_dia<=30)
    {
        dia+=1;
    }
    if((_mes==1||_mes==3||_mes==5||_mes==7||_mes==8||_mes==10)&&_dia>30)
    {
        dia-=30;
        mes+=1;
    }

    if(_mes==12&&_dia>30)
    {
        dia-=30;
        mes=1;
        anio+=1;
    }

    _dia=dia;
    _mes=mes;
    _anio=anio;
 }

