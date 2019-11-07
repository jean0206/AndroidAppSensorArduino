/*************************************************** 
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1748
  ----> https://www.adafruit.com/products/1749

  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <SoftwareSerial.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
SoftwareSerial miBT(2,3);

int redPin=11;
int greenPin=12;
int bluePin=13;

void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  
   //Bluethooth

    // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Listo");
  miBT.begin(38400);

  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  int x=mlx.readObjectTempC();
  if(x<10){
    setColor(0,0,250);
  }else if(x>10&&x<25){
    setColor(0,250,0);
  }else{
    setColor(250,0,0);
   }
  miBT.print("Ambient = "); miBT.print(mlx.readAmbientTempC()); 
  miBT.print("*C\tObject = "); miBT.print(mlx.readObjectTempC()); miBT.println("*C");
  miBT.print("Ambient = "); miBT.print(mlx.readAmbientTempF()); 
  miBT.print("*F\tObject = "); miBT.print(mlx.readObjectTempF()); miBT.println("*F");

  miBT.println();
  delay(2000);

  //Bluetooth

   // put your main code here, to run repeatedly:
  if(miBT.available())    //lee BT y envia a Arduino
  Serial.write(miBT.read());

  if(Serial.available())
  miBT.write(Serial.read());  //Lee arduino y envia a BT

}


void setColor(int red, int green,int blue){
  analogWrite(redPin,red);
  analogWrite(greenPin,green);
  analogWrite(bluePin,blue);
  }
