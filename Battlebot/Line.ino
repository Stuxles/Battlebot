void linefollow() {


  if (digitalRead(LS) && digitalRead(RS)) //Move Forward
  {
    stopEngine();
    delay(500);
    backwardEngineLeft(30);
    backwardEngineRight(30);
    //delay(500);
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
    changeGame();
}
