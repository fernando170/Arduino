/*
 * @Author: Fernando Arturo Medina Molina
 * @Version: 1.0
 * @Copyleft:
 * 1.-Usarla sin ninguna limitación.
 * 2.-Libertad de estudio (ver cómo está hecho el trabajo).
 * 3.-(re)distribuir cuantas copias desee.
 * 4.-Modificarla de la manera que crea conveniente.
 * 
 * @Componentes:
 * > 1 Sensor de temperatura y humedad DHT11 en una placa
 * > 1 LCD Display
 * 
 * @Description:Por medio de las lecturas del sensor DHT11 Podremos medir temperatura 
 * y humedad relativa dentro de un cuarto o estancia, con la finalidad de que en un 
 * siguiente código se pueda emplear un ventilador o controlar un aire acondicionado 
 * para regular la temperatura del mismo
 * 
 * @Referencias:  
 * Ejemplos de las librerias DHT, LCD.
 * https://create.arduino.cc/projecthub
 * http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay
 * https://hetpro-store.com/TUTORIALES/sensor-dht11/}
 *
 * 
  CONEXIÓN LCD
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
//LIBRARIES
/*
 * Utilizaremos las librerías de DHT, así como las de Liquid Crystal, para simplificar el 
 * uso de estos dos componentes.
*/
#include <LiquidCrystal.h>
#include "DHT.h"
/*Definitmos el objeto o sensor, así como su pin asociado*/
#define DHTPIN 6
#define DHTTYPE DHT11
/*Inicialización del LCD con los pines mencionados en la documentación
al igual que el pin de temperatura*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);
//SETUP
/*
 * Indicamos el tamaño de nuestro LCD con la finalidad de poder indicar 
 * el número de columnas y renglones que contiene, así como en dónde comenzará
 * a escribir nuestro menaje, en el caso personal utilizaré la columna 4 y la fila0.
 * Para el caso del sensor de humedad y temperatura, tendremos que inicializarlo 
 * solamente.
*/
void setup() {
  dht.begin();
  lcd.begin(16,  2);
  lcd.setCursor(4, 0);
  lcd.print("Sistema de Temp");
  delay(1000);
}
//LOOP
/*
 * En cuanto al loop o al bucle iterativo, revisaremos cada minuto la temperatura de la 
 * habitación en la que nos encontramos, así como su humedad relativa a través de las 
 * vatiables h (humedad)y t (temperatura), las cuales desplegaremosen el LCD cada 
 * una de las lecturas en cada una de las filas con las que contamos.
*/
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.clear();//Borraremos todo lo que tengamos anteriormente
  lcd.setCursor(4,0);
  lcd.print("Temperatura: ");
  lcd.println(t);
  lcd.setCursor(4,1);
  lcd.print("Humedad: ");
  lcd.print(int(h));
  lcd.println(" %");
  delay(60000);//Esperaremos para hacer la medición siguiente 1 min.
}
