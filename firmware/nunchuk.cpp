/*
 * wiichunk-demo.ino
 *
 * Copyright 2015 - Tim Caswell <tim@creationix.com>
 *
 * Based on: https://github.com/GabrielBianconi/ArduinoNunchuk
 * but packaged and patched for spark.io
 *
 *  To setup I2C for sparkcore:
 *
 *    Clk  -> D1 (with 10k pullup resustor)
 *    Data -> D0 (with 10k pullup resustor)
 *    3.3v -> 3V3
 *    Gnd  -> GND
 *
 */


#include "nunchuk/nunchuk.h"

#define BAUDRATE 19200

static SparkNunchuk nunchuk = SparkNunchuk();

void setup()
{
  Serial.begin(BAUDRATE);
  nunchuk.init();
}

void loop()
{
  nunchuk.update();

  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);
}