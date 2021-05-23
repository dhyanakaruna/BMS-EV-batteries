#include <LiquidCrystal.h>
#include<Servo.h>
const int flexPin = A0;
const int TempPin = A1;
const int trigger = 9;
Servo servo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2, 1);
int servoPin = 6;

void setup() 
{
Serial.begin(9600);
lcd.begin(16, 2);
servo.attach(6);
pinMode(flexPin, INPUT);
pinMode(TempPin, INPUT);
pinMode(trigger, OUTPUT);
digitalWrite(trigger,LOW);
}

void loop() 
{
int flexVal = digitalRead(flexPin);
int TempVal = analogRead(TempPin);
float TempCel = ( TempVal / 1024.0) * 500;

   lcd.print("Arduino");
    delay(3000);
    lcd.setCursor(7,1);
lcd.setCursor(0, 1);
lcd.print("Temperature is Normal");
digitalWrite(trigger,LOW);
lcd.setCursor(0, 1);
lcd.print("Thermal runaway detected");
digitalWrite(trigger,HIGH);
servo.write(170);
delay(5);
    }
  
