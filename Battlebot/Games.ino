void newGame() {


  if (digitalRead(LS) && digitalRead(RS)) //Move Forward
  {
    stopEngine();
    delay(500);
    forwardEngineLeft(50);
    forwardEngineRight(50);
    delay(500);
    stopEngine();
    delay(100);
    //turnLeft(50);
    //delay(1000);
  }

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

  if (!(digitalRead(LS)) && !(digitalRead(RS))) // stop
  {
    forwardEngineLeft(50);
    forwardEngineRight(50);
  }
}
