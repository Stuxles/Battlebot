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
        dummySpeed = 120;
        forwardEngineLeft(120);
        forwardEngineRight(120);
        break;
      case 2:
        dummySpeed = 60;
        turnRight(120);
        break;
      case 3:
        dummySpeed = 120;
        backwardEngineRight(120);
        backwardEngineLeft(120);
        break;
      case 4:
        dummySpeed = 60;
        turnLeft(120);
        break;
      case 5:
        dummySpeed = 0;
        stopEngine();
        break;
      case 6: dummySpeed = 80;
        linefollow();
        break;
      case 7:
        dummySpeed = 80;
        maze();
        break;
      case 8:
        dummySpeed = 80;
        sonarDrive();
        break;
      case 9:
        dummySpeed = 80;
        newGame();
        break;
    }
    BT.flush();
  }
  if (dummySpeed >10){
    dummyDistance = (dummySpeed /10) * ((millis() - start_time) / 1000);
  }
  sendDataToServer(dummySpeed, dummyDistance, (millis() - start_time) / 1000);
}

