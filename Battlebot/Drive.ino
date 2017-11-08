void stopEngine()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void straightForward(int speed)
{
  if (yaw < -2) {
    turnLeft(speed);
  } else if (yaw > 2) {
    turnRight(speed);
  } else {
    forwardEngineLeft(speed);
    forwardEngineRight(speed);
  }
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

void turnRightDegree(int degree, int speed)
{
  yaw = 0;
  turnRight(speed);
  while (yaw > degree) {
    changeGame();
    yawGet();
  }
}

void turnLeftDegree(int degree, int speed)
{
  yaw = 0;
  turnLeft(speed);
  while (yaw < degree) {
    changeGame();
    yawGet();
  }
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

