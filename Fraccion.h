#ifndef FRACCION_H
#define FRACCION_H
#include<string>
#include <iostream>


using namespace std;

class Fraccion{
  private:
    int num,
        den;
    
  public:
    Fraccion();
    Fraccion(int num,int den);
    int getNum();
    int getDen();
    Fraccion Suma(Fraccion);
    Fraccion Resta(Fraccion);
    Fraccion Multiplicacion(Fraccion);
    void Imprimir();
    void setNumerador(int);
    void setDenominador(int);
};
#endif