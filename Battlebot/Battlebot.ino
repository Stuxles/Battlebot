//https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
//http://playground.arduino.cc/Code/NewPing

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Motor links
int in1 = 2;
int in2 = 3;
// Motor Rechts
int in3 = 4;
int in4 = 9;

int minDistance = 10;
int sonarOld = 10;

void setup()
{
  lcd.begin(16,2);
  Serial.begin(115200);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void schermUltra(){

  if (sonar.ping_cm() >= minDistance){
    if(sonarOld != sonar.ping_cm()){
      sonarOld = sonar.ping_cm();
      lcd.clear();
      lcd.print("No danger! ");
      lcd.setCursor(0,1);
      lcd.print(sonar.ping_cm());
      lcd.print(" cm!");
      delay(500);
    }
  }else{
    if(sonarOld != sonar.ping_cm()){
      sonarOld = sonar.ping_cm();
      lcd.clear();
      lcd.print("Danger! ");
      lcd.setCursor(0,1);
      lcd.print(sonar.ping_cm());
      lcd.print(" cm!");
      delay(500);
    }
  }
}

void loop()
{
  if (sonar.ping_cm() > 30)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(500);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(500);
  }
}
