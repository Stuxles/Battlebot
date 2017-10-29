void btUpdate()
{
  if (BT.available() > 0) {
    btCommand = BT.readString().toInt();
  }
}

void changeGame()
{
  btUpdate();
  if (btCommand != oldCommand)
  {
    switch (btCommand) {
      case 0:
        Serial.println("0");
        break;
      case 1:
        straightForward(80);
        break;
      case 2:
        turnRightDegree(90, 80);
        break;
      case 3:
        turnLeftDegree(90, 80);
        break;
      case 4:
        backwardEngineRight(80);
        backwardEngineLeft(80);
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
        Serial.println("move to new game hier");
        break;
    }
    oldCommand = btCommand;
  }
}

