/*
 * SparkNunchuk.h - Spark customized library for nunchuk
 *
 * Copyright 2015 - Tim Caswell <tim@creationix.com>
 *
 * Based on: https://github.com/GabrielBianconi/ArduinoNunchuk
 * but packaged and patched for spark.io
 *
 */

#include "nunchuk.h"

#define ADDRESS 0x52

void SparkNunchuk::init()
{
  Wire.begin();

  SparkNunchuk::_sendByte(0x55, 0xF0);
  SparkNunchuk::_sendByte(0x00, 0xFB);

  SparkNunchuk::update();
}

void SparkNunchuk::update()
{
  int count = 0;
  int values[6];

  Wire.requestFrom(ADDRESS, 6);

  while(Wire.available())
  {
    values[count] = Wire.read();
    count++;
  }

  SparkNunchuk::analogX = values[0];
  SparkNunchuk::analogY = values[1];
  SparkNunchuk::accelX = (values[2] << 2) | ((values[5] >> 2) & 3);
  SparkNunchuk::accelY = (values[3] << 2) | ((values[5] >> 4) & 3);
  SparkNunchuk::accelZ = (values[4] << 2) | ((values[5] >> 6) & 3);
  SparkNunchuk::zButton = !((values[5] >> 0) & 1);
  SparkNunchuk::cButton = !((values[5] >> 1) & 1);

  SparkNunchuk::_sendByte(0x00, 0x00);
}

void SparkNunchuk::_sendByte(char data, char location)
{
  Wire.beginTransmission(ADDRESS);

  Wire.write(location);
  Wire.write(data);

  Wire.endTransmission();

  delay(10);
}
