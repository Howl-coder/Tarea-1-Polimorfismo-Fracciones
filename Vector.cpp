#include "Vector.h"
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

Vector::Vector(){
  Vec = new Fraccion();
  size = 1;
  sizeMem = 1;
}

Vector::Vector(int s){
  size = s;
  Vec = new Fraccion[s];
  sizeMem = s;
}

Vector::Vector(int s, Fraccion* Vector){
  Vec = Vector;
  size = s;
  sizeMem = s;
}

int Vector::getSize(){
  return size;
}

Fraccion Vector::getFraccion(int i){
  return Vec[i];
}

void Vector::setFraccion(int i, Fraccion f){
    Vec[i] = f;
}

Vector Vector::operator + (Vector v2){
  if(size == v2.getSize()){
    Vector newVector(size);
    for (int i=0; i<size; i++){
    
      Vec[i].Suma(v2.getFraccion(i));
      newVector.setFraccion(i, Vec[i].Suma(v2.getFraccion(i)));
    }
    return newVector;
  }
  cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vector();
}

Vector Vector::operator - (Vector v2){
  if(size == v2.getSize()){
    Vector newVector(size);
    for (int i=0; i<size; i++){
    
      Vec[i].Resta(v2.getFraccion(i));
      newVector.setFraccion(i, Vec[i].Resta(v2.getFraccion(i)));
    }
    return newVector;
  }
  cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vector();
}

Vector Vector::multiplicacion(Vector v2){
  if(size == v2.getSize()){
    Vector newVector(size);
    for (int i=0; i<size; i++){
      newVector.setFraccion(i, Vec[i].Multiplicacion(v2.getFraccion((i))));
    }
    return newVector;
  }
  cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vector();
}

float Vector::productoPunto(Vector Vec2){
  if(size == Vec2.getSize()){
    Fraccion fResultado;
    float valorFinal;
    for (int i=0; i < size; i++){
      fResultado = fResultado.Suma(Vec[i].Multiplicacion(Vec2.getFraccion(i)));
      valorFinal = float(fResultado.getNum())/float(fResultado.getDen());
    } 
    return valorFinal;
  }
  else {
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return 0;
    }
}

float Vector::operator * (Vector Vec2){
  if(size == Vec2.getSize()){
    Fraccion fResultado;
    float valorFinal;
    for (int i=0; i < size; i++){
      fResultado = fResultado.Suma(Vec[i].Multiplicacion(Vec2.getFraccion(i)));
      valorFinal = float(fResultado.getNum())/float(fResultado.getDen());
    } 
    return valorFinal;
  }
  else {
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return 0;
    }
}

Vector Vector::producto(Vector v2){
  if ((size == 3)  && (v2.getSize() == 3)){
    Vector newVector(size);
    Fraccion fTemporal;
    // Primer valor
    fTemporal = (Vec[1].Multiplicacion(v2.getFraccion(2)));
    newVector.setFraccion(0, fTemporal.Resta((Vec[2].Multiplicacion(v2.getFraccion(1)))));
    // Segundo Valor
    fTemporal = (Vec[2].Multiplicacion(v2.getFraccion(0)));
    newVector.setFraccion(1, fTemporal.Resta((Vec[0].Multiplicacion(v2.getFraccion(2)))));
    // Tercer Valor
    fTemporal = (Vec[0].Multiplicacion(v2.getFraccion(1)));
    newVector.setFraccion(2, fTemporal.Resta((Vec[1].Multiplicacion(v2.getFraccion(0)))));

    return newVector;
  }
  else{
      cout << "Ambos vectores deben tener 3 fracciones dentro de si mismos" << endl;
      return 0;
  }
}

float Vector::angulo(Vector Vec2){ 
  float angulo;
  if(size == Vec2.getSize()){
    float numerador = productoPunto(Vec2);
    float denominador = magnitud() * Vec2.magnitud();
    angulo = acos(numerador/denominador);
    angulo = angulo * 57.29;
    return angulo;
    } 
  else {
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return 0;
    }
}

float Vector::magnitud(){
  int i = 0;
  float sum = 0,
        dec;

  while(i<size){
    dec = float(Vec[i].getNum())/float(Vec[i].getDen());
    sum += pow(dec,2);
    i++;
  }

  return sqrt(sum);
}

Vector Vector::producto(int a){

  Vector newVector(size);
  for (int i=0; i<size; i++){
    int numerador,
        denominador;
      
    numerador = Vec[i].getNum()*a;
    denominador = Vec[i].getDen();

    Fraccion f1(numerador,denominador);

    newVector.setFraccion(i, f1);
  }
  
  return newVector;
}

void Vector::agregarFraccion(Fraccion f){
  if(size+1 > sizeMem){
    Fraccion* newVec = new Fraccion[size*2];
    for (int i=0; i<size; i++){
      newVec[i] = Vec[i];
    }
    newVec[size] = f;
    Vec = newVec;
    sizeMem =size*2;
    size = size+1;
  }else{
   Vec[size+1] = f;
   size++; 
  }
}

void Vector::eliminarFraccion(){
  Vec[size].setNumerador(0);
  Vec[size].setDenominador(1);
  size--;
}

void Vector::Imprimir(bool showSize){
  if(showSize)
    cout << "size: " << size << ", sizeMem: " << sizeMem << "---";
  cout << "[";
  int i;
  for (i=0; i<size; i++){
    cout << Vec[i].getNum() << "/" << Vec[i].getDen();
    if(i < size-1)
      cout << ",";
  }
  cout << "]" << endl;
}