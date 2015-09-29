/* 
 * Bike Arduino Speedometer Variation by Edward Delaporte
 */

/*
 * LICENSE
 * -----------
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/

#include <Wire.h>

//pin connected to read switch
#define read_pin A1
#define hot_pin D1

//storage variable
int sensor_value;

int SENSOR_TRIGGER = 1019;
int SENSOR_DELAY = 50; 

void setup()
{
  // Make hot pin hot.
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
}

void do_sensor()
{
  // Always update the sensor
  sensor1 = analogRead(A1);
  sensor2 = analogRead(A2);
  sensor3 = analogRead(A3);
  serial.write
  Serial.print("Sensor value 1", sensor1);
  Serial.print("Sensor value 2", sensor1);
  Serial.print("Sensor value 3", sensor1);
}

void loop()
{
  // Strongly favor gathering data over displaying it.
  for(int i; i<100;i++)
  {
	  do_sensor();
	  delay(SENSOR_DELAY);
  }
  // do_display();
}
