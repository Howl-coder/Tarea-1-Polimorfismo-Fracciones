#include "Fraccion.h"

class Vector{
private: 
    Fraccion * Vec;
    int size;
    int sizeMem;
    void setSize();
     
public:
    Vector();
    Vector(int);
    Vector(int, Fraccion *);
    int getSize();
    Fraccion getFraccion(int);
    void setFraccion(int, Fraccion);
    Vector operator + (Vector Vec2);
    Vector operator - (Vector Vec2);
    Vector multiplicacion(Vector Vec2);
    float productoPunto(Vector Vec2);
    float operator * (Vector Vec2);
    Vector producto(Vector Vec2);
    float angulo(Vector Vec2);
    float magnitud();
    Vector producto(int);
    void agregarFraccion(Fraccion);
    void eliminarFraccion(); // ultimo elemento 
    Fraccion productPuntoVector(Vector Vec2);
    void Imprimir(bool);
};