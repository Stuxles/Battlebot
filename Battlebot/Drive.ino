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

void checkFront()
{
  
}

