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


  if (BT.available() > 0)
    btvalue = BT.read();
  {
    switch (btvalue) {
      case 1:
        forwardEngineLeft(80);
        forwardEngineRight(80);
        break;
      case 2:
        turnRight(80);
        break;
      case 3:
        backwardEngineRight(80);
        backwardEngineLeft(80);
        break;
      case 4:
        turnLeft(80);
        break;
      case 5:
        stopEngine();
        break;
      case 6:
        linefollow();
        break;
      case 7:
        maze();
        break;
      case 8:
        sonarDrive();
        break;
      case 9:
        straightForward(80);
        break;
    }
    BT.flush();
  }
  sendDataToServer(dummySpeed, dummyDistance, dummyTime);
}

