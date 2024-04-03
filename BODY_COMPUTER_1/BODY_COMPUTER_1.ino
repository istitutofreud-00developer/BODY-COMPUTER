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

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  lcd.begin(20, 4);

  lcd.print("   FIAT SEICENTO!");
  lcd.setCursor(0, 1);
  lcd.print("   BODY COMPUTER");
  lcd.setCursor(0, 3);
  lcd.print("   VERSIONE: 1.0"); 
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

    lcd.setCursor(0, 0);

     buttonState = digitalRead(button);
  if (buttonState==1){
    int distanza = ultrasonic.read();
    
    lcd.setCursor(0, 0);
    lcd.print("DISTANZA :");
    lcd.print(distanza);
    lcd.print("cm");
    delay(1000);
    lcd.setCursor(0, 3);
    lcd.print("TEMP=");
    lcd.print((float)dht.readTemperature());
    lcd.print("C ");
    lcd.print("H=");
    lcd.print((float)dht.readHumidity());
    lcd.print("%"):
     }
    
else{ 
     value=analogRead(pot);
   int accelerazione= map(value, 0, 1023, 0, 180);
   float secondsFraction = millis() / 1000.0F;
   float farfalla= value /10.20;

    lcd.print("FARFALLA:");
    lcd.print(farfalla);
    lcd.print("% ");
    servoAccelerator.write(accelerazione);
    lcd.setCursor(0, 3);
    lcd.print("TEMP=");
    lcd.print((float)dht.readTemperature());
    lcd.print("C ");
    lcd.print("H=");
    lcd.print((float)dht.readHumidity());
    lcd.print("%");
  
    }



 

 





}

