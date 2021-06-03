#include <iostream>
#include "Fraccion.h"
#include "Vector.h"

int main() {
  //Validación del funcionamiento de la clase

  //Fracciones para formar el Vector 1
  Fraccion F4_1[4];

  Fraccion f1_1(1,2);
  Fraccion f1_2(1,4);
  Fraccion f1_3(1,5);
  Fraccion f1_4(1,3);

  F4_1[0] = f1_1;
  F4_1[1] = f1_2;
  F4_1[2] = f1_3;
  F4_1[3] = f1_4;

  //Fracciones para formar el Vector 2
  Fraccion F4_2[4];
  Fraccion f2_1(5,2);
  Fraccion f2_2(4,5);
  Fraccion f2_3(7,4);
  Fraccion f2_4(6,9);

  F4_2[0] = f2_1;
  F4_2[1] = f2_2;
  F4_2[2] = f2_3;
  F4_2[3] = f2_4;

  //Instanciación de los vectores de 4 dimensiones
  cout<<"Validación para vectores de 4 dimensiones"<<endl<<endl;

  Vector v1(4,F4_1);
  cout<<"El vector uno es: ";
  v1.Imprimir(0);
  
  Vector v2(4,F4_2);
  cout<<"El vector dos es: ";
  v2.Imprimir(0);

  //Operaciones
  //Suma
  Vector suma4 = v1+v2;
  cout<<"Suma del vector 1 y 2: ";
  suma4.Imprimir(0);

  //Resta
  Vector resta4 = v1-v2;
  cout<<"Resta del vector 1 menos el 2: ";
  resta4.Imprimir(0);

  //Producto Punto
  float pp4 = v1*v2;
  cout<<"Producto punto del vector 1 y 2: "<<pp4<<endl;

  //Producto Cruz
  cout<<"Producto cruz entre vector 1 y 2: ";
  Vector pc4 = v1.producto(v2);

  //Ángulo
  float a4 = v1.angulo(v2);
  cout<<"El ángulo entre el vector 1 y 2 es: "<<a4<<"º"<<endl;


  //Instanciación de los vectores de 3 dimensiones
  cout<<endl<<"Validación para vectores de 3 dimensiones"<<endl<<endl;
  
  v1.eliminarFraccion();
  cout<<"El vector uno es: ";
  v1.Imprimir(0);
  
  v2.eliminarFraccion();
  cout<<"El vector dos es: ";
  v2.Imprimir(0);

  //Operaciones
  //Suma
  Vector suma3 = v1+v2;
  cout<<"Suma del vector 1 y 2: ";
  suma3.Imprimir(0);

  //Resta
  Vector resta3 = v1-v2;
  cout<<"Resta del vector 1 menos el 2: ";
  resta3.Imprimir(0);

  //Producto Punto
  float pp3 = v1*v2;
  cout<<"Producto punto del vector 1 y 2: "<<pp3<<endl;

  //Producto Cruz
  Vector pc3 = v1.producto(v2);
  cout<<"Producto cruz entre vector 1 y 2: ";
  pc3.Imprimir(0);

  //Ángulo
  float a3 = v1.angulo(v2);
  cout<<"El ángulo entre el vector 1 y 2 es: "<<a3<<"º"<<endl;

  //Magnitud
  float m1 = v1.magnitud(),
        m2 = v2.magnitud();
  
  cout<<"La magnitud del vector 1 es: "<<m1<<" y la del vector 2 es: "<<m2<<endl;

  //Escalamiento
  Vector e1 = v1.producto(2),
         e2 = v2.producto(2);
  
  cout<<"El vector 1 escalado a 2 es: ";
  e1.Imprimir(0);

  cout<<"El vector 2 escalado a 2 es: ";
  e2.Imprimir(0);

  //Vectores con diferentes dimensiones
  cout<<endl<<"Validación para vectores con diferentes dimensiones"<<endl<<endl;

  cout<<"El vector uno es: ";
  v1.Imprimir(0);

  v2.agregarFraccion(f2_4);
  cout<<"El vector dos es: ";
  v2.Imprimir(0);

  //Operaciones
  //Suma
  cout<<"Suma del vector 1 y 2: ";
  Vector sumad = v1+v2;

  //Resta
  cout<<"Resta del vector 1 menos el 2: ";
  Vector restad = v1-v2;

  //Producto Punto
  cout<<"Producto punto del vector 1 y 2: ";
  float ppd = v1*v2;

  //Producto Cruz
  cout<<"Producto cruz entre vector 1 y 2: ";
  Vector pcd = v1.producto(v2);

  //Ángulo
  cout<<"El ángulo entre el vector 1 y 2 es: ";
  float ad = v1.angulo(v2);
}