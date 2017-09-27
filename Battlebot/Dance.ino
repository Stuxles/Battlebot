void dance(){
  forwardEngineRight(100);
  forwardEngineLeft(100);
  delay(200);
  stopEngine();
  turnLeft(200);
  delay(200);
  stopEngine();
  turnRight(200);
  delay(200);
  stopEngine();
  for (int i=200; i >= 50; i--)
  {
    turnLeft(i);
    delay(50);
  }
  delay(100);
  turnRight(200);
  delay(1000);
  stopEngine();
  backwardEngineRight(200);
  backwardEngineLeft(200);
  delay(1000);
  stopEngine();
}

