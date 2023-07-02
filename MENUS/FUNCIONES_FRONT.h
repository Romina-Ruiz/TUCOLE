#ifndef FUNCIONES_FRONT_H_INCLUDED
#define FUNCIONES_FRONT_H_INCLUDED
#include"cstring"

void mostrar_mensaje(std::string texto, int x, int y);
void rectangulo(int posx, int posy, int ancho, int alto);
void showItem (const char* text, int posx, int posy, bool selected);
void cargarCadena(char *pal, int tam);
void mostrarVector(const char *v, int tam);

#endif // FUNCIONES_H_INCLUDED
