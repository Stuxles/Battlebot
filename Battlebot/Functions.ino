void changeGame()
{
  if (BT.available() > 0)
  {
    switch (BT.read()) {
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
}

