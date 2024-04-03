/*
  LiquidCrystal Library - Autoscroll

 Demonstrates the use of a 16x2 LCD display. The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch demonstrates the use of the autoscroll()
 and noAutoscroll() functions to make new text scroll or not.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K or 100K potentiometer:
   * ends to +5V and ground
   * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 https://docs.arduino.cc/learn/electronics/lcd-displays#autoscroll-example
 https://github.com/arduino-libraries/LiquidCrystal
*/
// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <DHT.h>
#define DHTPIN8
#define DHTTYPEDHT11
const int pot=A0;
const int button = 10;
int buttonState;
float value;

Servo servoAccelerator;

Ultrasonic ultrasonic(7, 6);

DHT dht(8, DHT11);



// initialize the library by associating any needed LCD interface pin
// with the Arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);

  lcd.print("   FIAT SEICENTO!");
  lcd.setCursor(0, 1);
  lcd.print("   BODY COMPUTER");
  lcd.setCursor(0, 3);
  lcd.print("   VERSIONE: 1.0B"); 
  delay(2000);
  lcd.clear();

servoAccelerator.attach(9);   
  pinMode(pot,INPUT);
  pinMode(button, INPUT);
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("FIAT 600 1.1 8v i.e. ");
  lcd.setCursor(0, 1);
  lcd.print("  M.P.I. 54CV 88Nm");
  lcd.setCursor(7, 2);
  lcd.print("EURO 4");
  delay(5000);
  lcd.clear();
  
delay(500);



}

void loop() {
  // set the cursor to (0,0):
    lcd.setCursor(0, 0);

     buttonState = digitalRead(button);
  if (buttonState==1){
    int distanza = ultrasonic.read();
    lcd.setCursor(0, 0);
    lcd.print("DISTANZA :");
    lcd.print(distanza);
    lcd.print("cm.      ");
    delay(1000);
    lcd.setCursor(0, 3);
    lcd.print("TEMP=");
    lcd.print((float)dht.readTemperature());
    lcd.print("C ");
    lcd.print("H=");
    lcd.print((float)dht.readHumidity());
    lcd.print("%");

    
   
     }
    

else{ 
     value=analogRead(pot);
   float secondsFraction = millis() / 1000.0F;
    lcd.print("FIAT SEICENTO1.1 i.e.");
    lcd.setCursor(0, 3);
    lcd.print("TEMP=");
    lcd.print((float)dht.readTemperature());
    lcd.print("C ");
    lcd.print("H=");
    lcd.print((float)dht.readHumidity());
    lcd.print("%");
  
    }


  // print from 0 to 9:
 

 





}

