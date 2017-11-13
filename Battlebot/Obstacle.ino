void sonarDrive()
{

  if (sonar.ping_cm() < 30 && sonar.ping_cm() != 0)
  {
    stopEngine();
    delay(500);
    turnLeft(100);
    delay(450);
    stopEngine();
    delay(500);
    if (sonar.ping_cm() < 30 && sonar.ping_cm() != 0) {
      turnRight(100);
      delay(900);
      stopEngine();
      delay(500);
    }
  } else {
    if (digitalRead(LS) == true && digitalRead(RS) == true) { // Turn left 90 degrees
    stopEngine();
    delay(500);
    backwardEngineLeft(50);
    backwardEngineRight(50);
    delay(500);
    turnLeft(100);
    delay(500);
  }
    if (digitalRead(RS) == true) //Turn Left
    {
      turnLeft(100);
      delay(100);
    }
    if (digitalRead(LS) == true) //Turn Right
    {
      turnRight(100);
      delay(100);
    }
    forwardEngineRight(80);
    forwardEngineLeft(80);
  }
}
