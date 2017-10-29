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
    forwardEngineRight(100);
    forwardEngineLeft(100);
  }
}
