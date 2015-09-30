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
// #define read_pin A1
// #define hot1 D1

//storage variable
int sensor_value;
long sensor1;
long sensor2;
long sensor3;

int SENSOR_TRIGGER = 1019;
int SENSOR_DELAY = 500; 

void setup()
{
  Serial.begin(9600);
  // Make hot pin hot.
  digitalWrite(0, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
}

void do_sensor()
{
  // Always update the sensor
  digitalWrite(13, HIGH);
  sensor1 = analogRead(0);
  sensor2 = analogRead(4);
  sensor3 = analogRead(5);
  Serial.print("\n");
  Serial.print("Sensor value 1 ");
  Serial.print(sensor1);
  Serial.print("\n");
  Serial.print("Sensor value 2 ");
  Serial.print(sensor2);
  Serial.print("\n");
  Serial.print("Sensor value 3 ");
  Serial.print(sensor3);
  Serial.print("\n");
  digitalWrite(13, LOW);
  delay(SENSOR_DELAY);
}

void loop()
{
  // Strongly favor gathering data over displaying it.
  //for(int i; i<100;i++)
  //{
  //}
  do_sensor();
  // do_display();
}
