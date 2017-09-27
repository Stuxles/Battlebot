//https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
//http://playground.arduino.cc/Code/NewPing
//http://diyhacking.com/projects/MPU6050.zip

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200

#include <SoftwareSerial.h>
SoftwareSerial EEBlue(A0, A1); // RX | TX

#define IR 10
int detection = HIGH;    // no obstacle

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);



int in1 = 9;
int in2 = 4;
int in3 = 3;
int in4 = 2;

void setup() {    
  Serial.begin(9600);
  EEBlue.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
   
  pinMode(IR, INPUT); 
    
  // engine pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
//  detection = digitalRead(IR);
//  if(detection != LOW){
//    Serial.print("There is an obstacle!\n");
//  }
//  else{ 
//    Serial.print("No obstacle!\n");
//  }
//  delay(500);    // in ms
  
  if(sonar.ping_cm() < 30 && sonar.ping_cm() != 0)
  {
    stopEngine();
    delay(500);
    turnLeft(100);
    delay(450);
    stopEngine();
    delay(500);
    if (sonar.ping_cm() < 30 && sonar.ping_cm() != 0){
      turnRight(100);
      delay(900);
      stopEngine();
      delay(500);
    }
  }else{
    forwardEngineRight(100);
    forwardEngineLeft(100);
  }
}
