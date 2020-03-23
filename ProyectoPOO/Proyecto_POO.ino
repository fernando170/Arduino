#include<stdlib.h>
#include<stdio.h>
#include<Servo.h>
void imprimePinLog(int s, int d);
void imprimeUsLog(String U);
void BeepA();
void BeepN();

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
  registro = fopen("Registro.txt", "rw");
  Lista = fopen("Usuarios.txt", "rw");
*/

Usuario U[3];
int dis,claveIng;
void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
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
  U[0].setNombre("Ricardo");
  U[0].setAp("Martínez");
  U[0].setAm("Moreno");
  U[0].setClave(1234);

  U[1].setNombre("Juan Carlos");
  U[1].setAp("Bodoque");
  U[1].setAm("y Vodoque");
  U[1].setClave(5678);

  U[2].setNombre("Ivonne");
  U[2].setAp("Fleurette");
  U[2].setAm("Ewart");
  U[2].setClave(2653);

  //EL SERVO TIENE QUE ESTAR CERRADO CUANDO SE INICIE EL PROGRAMA

  if (dis <= 30) {
    for (int i = 0; i < 3; i++) {
      if (claveIng == U[i].getClave()) {
        EntraUs(U[i]);
        BeepA();
        //APERTURA DEL SERVO
      } else {
        BeepN();
      }
    }
  }


}

void imprimePinLog(String s, int d) {
  Serial.print("#S|LOG|[Ping no.:");
  Serial.print(String(s));
  Serial.print("  ,");
  Serial.print(String(d));
  Serial.println(" cm]#");

}

void BeepA() { //Emite dos pitidos cortos en el buzzer en caso de que se otorgue la entrada

  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  //delay(500);

}

void BeepN() { //Emite un pitido largo en el buzzer en caso de no otorrrrgar la entrada
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
}

void EntraUs(Usuario U) {
  String UsEnt;
  UsEnt += String(U.getNombre());
  UsEnt += String(U.getAp());
  UsEnt += String(U.getAm());
  imprimeUsLog(String(UsEnt));
  Serial.print(U.getNombre());
}

void imprimeUsLog(String U) {
  Serial.print("#S|LOG|[El usuario:");
  Serial.print(U);
  Serial.println(" ha ingresado]#");

}

