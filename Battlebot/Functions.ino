void sendDataToServer(long botSpeed, long distance, long drivingTime) {
  if (millis() - old_time > 250) {
    char buf [4];
    sprintf (buf, "%lu&%lu&%lu\n", botSpeed, distance, drivingTime);
    BT.write(buf);
    old_time = millis();
  }
}

void changeGame()
{
  long dummySpeed = 300;
  long dummyDistance = 400;
  long dummyTime = random(800, 2000);

  if (BT.available() > 0)
    btvalue = BT.read();
  {
    switch (btvalue) {
      case 49:
        forwardEngineLeft(80);
        forwardEngineRight(80);
        break;
      case 50:
        turnRight(80);
        break;
      case 51:
        backwardEngineRight(80);
        backwardEngineLeft(80);
        break;
      case 52:
        turnLeft(80);
        break;
      case 53:
        stopEngine();
        break;
      case 54:
        linefollow();
        break;
      case 55:
        maze();
        break;
      case 56:
        sonarDrive();
        break;
      case 57:
        straightForward(80);
        break;
    }
    BT.flush();
  }
  sendDataToServer(dummySpeed, dummyDistance, dummyTime);
}

