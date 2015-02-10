/*
 * SparkNunchuk.h - Spark customized library for nunchuk
 *
 * Copyright 2015 - Tim Caswell <tim@creationix.com>
 *
 * Based on: https://github.com/GabrielBianconi/ArduinoNunchuk
 * but packaged and patched for spark.io
 *
 */

#ifndef SparkNunchuk_H
#define SparkNunchuk_H

class SparkNunchuk
{
  public:
    int analogX;
    int analogY;
    int accelX;
    int accelY;
    int accelZ;
    int zButton;
    int cButton;

    void init();
    void update();

  private:
    void _sendByte(char data, char location);
};

#endif
