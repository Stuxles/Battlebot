//https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
//http://playground.arduino.cc/Code/NewPing
//http://diyhacking.com/projects/MPU6050.zip

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <MPU6050.h>

MPU6050 mpu;

#define LS 11  //left IR sensor
#define RS 10  //right IR sensor
#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200

#include <SoftwareSerial.h>
SoftwareSerial BT(A0, A1); // RX | TX
unsigned long start_time = millis();
unsigned long old_time; // VOOR DE TIMING VAN HET VERSTUREN

int detection = HIGH;    // no obstacle

  long dummySpeed = 0;
  long dummyDistance = 10;

//0 = custom > kruisje
//1 = forward > Omhoog
//2 = right > Rechts
//3 = reverse > Onder
//4 = left > Links
//5 = stop > Select
//6 = game 1 > vierkant
//7 = game 2 > Driehoek
//8 = game 3 > Rondje
//9 = move to new game > start

// Timers
unsigned long timer = 0;
float timeStep = 0.01;
// Yaw values
float yaw = 0;

int btvalue = 5;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int in1 = 9;
int in2 = 4;
int in3 = 3;
int in4 = 2;

void setup() {
  Serial.begin(9600);
  BT.begin(38400);  //Default Baud for comm, it may be different for your Module.

  // engine pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  old_time = millis();

    lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.backlight(); // finish with backlight on  

//-------- Write characters on the display ------------------
// NOTE: Cursor Position: (CHAR, LINE) start at 0  
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("-->BetterBott<--");
  lcd.setCursor(0,1);
  lcd.print("--->INF1F2B!<---");


  // Initialize MPU6050
  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(1);

  yawGet();
  delay(1000);

}

void loop() {
  changeGame();
}
