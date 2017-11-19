#include<stdlib.h>
#include<stdio.h>
#include<Servo.h>
void imprimePinLog(int s, int d);
void imprimeUsLog(String U);

class Usuario {
  private:
    String Nombre, AP, AM;
    int clave;
    long int tarjeta;
  public:
    Usuario() {
      Nombre = "DEFAULT";
      AP = "DEFAULT";
      AM = "DEFAULT";
      clave = 0000;
      tarjeta = 0000000000000000;
    }
    void setNombre(String nombre) {
      Nombre = nombre;
    }
    void setAp(String ApPat) {
      AP = ApPat;
    }
    void setAm(String ApMat) {
      AM = ApMat;
    }
    void setClave(int claven) {
      clave = claven;
    }
    void setTarjeta(long int Tarjeta) {
      tarjeta = Tarjeta;
    }
    String getNombre() {
      return Nombre;
    }
    String getAp() {
      return AP;
    }
    String getAm() {
      return AM;
    }
    int getClave() {
      return clave;
    }
    long int getTarjeta() {
      return tarjeta;
    }
};
/*
FILE *registro,*Lista;
*registro = fopen("Registro.txt", "rw");
*Lista = fopen("Usuarios.txt", "rw");
*/

Usuario U1;
void setup() {
  Serial.begin(9600);
  
  /*String CadAux;
  int i, temp;
  int x=0;
  for (i = 0; i < sizeof(Lista); i++) {
    if (Lista[i] == "," || Lista[i] == "\n") {
      cadAux.concat((Lista[x:i]));
      x = i + 1;
      if (i == sizeof(Lista) - 1) {
        cadAux.concat((Lista[x:sizeof(Lista)]));
      }
      Serial.print(cadAux);
      return CadAux;
    }
  }
  //Usuario*/
}

void loop() {
  U1.setNombre("Juan Carlos");
  U1.setAp("Bodoque");
  U1.setAm("y Vodoque");
  U1.setClave(1234);
  String UsEnt;
  UsEnt.append(U1.getNombre());
  UsEnt.append(U1.getAp());
  UsEnt.append(U1.getAm());
  imprimeUsLog(UsEnt);
  Serial.print(U1.getNombre());

}

void imprimePinLog(String s, int d) {
  Serial.print("#S|LOG|[Ping no.:");
  Serial.print(String(s));
  Serial.print("  ,");
  Serial.print(String(d));
  Serial.println(" cm]#");

}

void imprimeUsLog(String U) {
  Serial.print("#S|LOG|[El usuario:");
  Serial.print(U);
  Serial.println(" ha ingresado]#");

}
