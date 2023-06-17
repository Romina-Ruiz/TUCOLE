#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "rlutil.h"
#include "FUNCIONES_FRONT.h"
#include "Fecha.h"
#include <cstring>

void mostrar_mensaje (string texto, int x, int y)
{
    rlutil::  locate (x,y);
    cout <<texto;
}

void rectangulo (int posx, int posy, int ancho, int alto){

/// ABAJO
    for (int x= 1; x <=ancho; x++)
    {
        rlutil::locate( x+ posx, posy);
        cout << (char)205;

        rlutil::locate( x+ posx, posy+alto+1);
        cout << (char)205;
    }

///ANCHO
    for (int y= 1; y <=alto; y++)
    {
        rlutil::locate( posx,  posy+y);
        cout << (char)186;

        rlutil::locate( posx+ancho+1, posy+y);
        cout << (char)186;

    }

///ESQUINAS
    rlutil::locate( posx, posy);
    cout << (char)201;

    rlutil::locate( posx, posy+alto +1);
    cout << (char)200;

    rlutil::locate( posx +ancho +1, posy);
    cout << (char)187;

    rlutil::locate( posx +ancho +1, posy+ alto +1);
    cout << (char)188;
}

///MENU MOVIL
void showItem (const char* text, int posx, int posy, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::CYAN);
        rlutil::  locate (posx -3,posy);
        cout <<"==>";
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        rlutil::  locate (posx -3,posy);
        cout <<"==>";
    }
    rlutil::locate(posx, posy);
    cout << text <<endl;
    rlutil::setBackgroundColor(rlutil::MAGENTA);
}


