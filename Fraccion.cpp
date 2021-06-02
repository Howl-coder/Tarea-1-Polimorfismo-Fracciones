#include "Fraccion.h"
#include <iostream>
#include<string>
#include<cmath>

using namespace std;

Fraccion::Fraccion(){
  this->num=0;
  this->den=1;
}

Fraccion::Fraccion(int num, int den ){
  
  //Simplifiación
  int a,
      b,
      res = 1;

  a = max(abs(num),abs(den));
  b = min(abs(num),abs(den));

  while (b!=0){
    res = b;
      b = a%b;
      a = res;
  }

  this->num=abs(num)/res;
  this->den=abs(den)/res;

  //Formato de signo
  if((num>0 && den<0)  || (num<0 && den>0)){
    this->num=-this->num;
  }
  else if (num == 0){
    this->den = 1;
  }
}

int Fraccion::getNum(){
  return this->num;
}

int Fraccion::getDen(){
  return this->den;
}

Fraccion Fraccion::Suma(Fraccion f1){
  //Operación aritmética
  int denS,
      numS;

  denS = this->den*f1.getDen();
  numS = ((denS/this->den)*this->num)+((denS/f1.getDen())*f1.getNum());

  Fraccion s(numS,denS);

  return s;
}

Fraccion Fraccion::Resta(Fraccion f1){
  int denS = this->den*f1.getDen(),
      numS = ((denS/this->den)*this->num)-((denS/f1.getDen())*f1.getNum());

  Fraccion s(numS,denS);

  return s;
}