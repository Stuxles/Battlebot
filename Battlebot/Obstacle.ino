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
    if (!(digitalRead(LS)) && digitalRead(RS)) //Turn Right
    {
      turnRight(100);
      //delay(200);
    }

    if (digitalRead(LS) && !(digitalRead(RS))) //Turn Left
    {
      turnLeft(100);
      //delay(200);
    }
    forwardEngineRight(100);
    forwardEngineLeft(100);
  }
  changeGame();
}
