#define LS 11  //left sensor
#define RS 10  //right sensor

int in1 = 9;
int in2 = 4;
int in3 = 3;
int in4 = 2;

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
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

void backwardEngineLeft(int speed)
{
  analogWrite(in3, -speed);
  digitalWrite(in4, HIGH);
}

void backwardEngineRight(int speed)
{
  analogWrite(in1, -speed);
  digitalWrite(in2, HIGH);
}

void turnRight(int speed)
{
  analogWrite(in1, -speed);
  digitalWrite(in2, HIGH);
  analogWrite(in3, speed);
  digitalWrite(in4, LOW);
}

void turnLeft(int speed)
{
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
  analogWrite(in3, -speed);
  digitalWrite(in4, HIGH);
}


void loop() {
  if (digitalRead(LS) && digitalRead(RS)){ // Turn left 90 degrees
    stopEngine();
    delay(500);
    backwardEngineLeft(50);
    backwardEngineRight(50);
    delay(500);
    turnLeft(100);
    delay(500);
  }
  if(!(digitalRead(LS)) && digitalRead(RS)) //Turn Left
  {
    turnLeft(100);
  }
  if(digitalRead(LS) && !(digitalRead(RS))) //Turn Right
  {
    turnRight(100);
  }
  if(!(digitalRead(LS)) && !(digitalRead(RS))){ // Move forward
      forwardEngineLeft(50);
      forwardEngineRight(50);
  }
}
