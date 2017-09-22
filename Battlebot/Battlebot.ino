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

int in1 = 9;
int in2 = 4;
int in3 = 3;
int in4 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void stopEngine()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forwardEngineLeft(int speed)
{
  analogWrite(in3, speed);
  digitalWrite(in4, LOW);
}

void forwardEngineRight(int speed)
{
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
}

void turnRight(int speed)
{
  analogWrite(in1, speed);
  digitalWrite(in2, HIGH);
  analogWrite(in3, speed);
  digitalWrite(in4, LOW);
}

void turnLeft(int speed)
{
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
  analogWrite(in3, speed);
  digitalWrite(in4, HIGH);
}

void loop() {
  
}
