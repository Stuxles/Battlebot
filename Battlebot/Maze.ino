
void maze() {
  if (digitalRead(LS) && digitalRead(RS)) { // Turn left 90 degrees
    stopEngine();
    delay(500);
    backwardEngineLeft(50);
    backwardEngineRight(50);
    delay(500);
    turnLeft(100);
    delay(500);
  }
  if (!(digitalRead(LS)) && digitalRead(RS)) //Turn Left
  {
    turnLeft(100);
  }
  if (digitalRead(LS) && !(digitalRead(RS))) //Turn Right
  {
    turnRight(100);
  }
  if (!(digitalRead(LS)) && !(digitalRead(RS))) { // Move forward
    forwardEngineLeft(50);
    forwardEngineRight(50);
  }
}
