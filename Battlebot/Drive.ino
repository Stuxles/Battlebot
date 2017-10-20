
void stopEngine()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  driving = false;
}

void straightForward(int speed)
{
  if(yaw < -2){
    turnLeft(speed);    
  }else if(yaw > 2){
    turnRight(speed);
  }else{
    forwardEngineLeft(speed);
    forwardEngineRight(speed);
  }
  driving = true;
}

void forwardEngineLeft(int speed)
{
  analogWrite(in3, speed);
  digitalWrite(in4, LOW);
  driving = true;
}

void forwardEngineRight(int speed)
{
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
  driving = true;
}

void backwardEngineLeft(int speed)
{
  analogWrite(in3, -speed);
  digitalWrite(in4, HIGH);
  driving = true;
}

void backwardEngineRight(int speed)
{
  analogWrite(in1, -speed);
  digitalWrite(in2, HIGH);
  driving = true;
}

void turnRight(int speed)
{
  analogWrite(in1, -speed);
  digitalWrite(in2, HIGH);
  analogWrite(in3, speed);
  digitalWrite(in4, LOW);
  driving = true;
}

void turnLeft(int speed)
{
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
  analogWrite(in3, -speed);
  digitalWrite(in4, HIGH);
  driving = true;
}

