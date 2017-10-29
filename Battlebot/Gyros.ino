void yawGet()
{
  timer = millis();

  // Read normalized values
  Vector norm = mpu.readNormalizeGyro();

  // Calculate Pitch, Roll and Yaw
  yaw = yaw + norm.ZAxis * timeStep;

  // Wait to full timeStep period
  delay((timeStep * 1000) - (millis() - timer));
}

