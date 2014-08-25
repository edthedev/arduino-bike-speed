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
#include <LiquidCrystal.h>

//pin connected to read switch
#define read_pin A1
#define hot_pin A2

//storage variable
int read_pin_value;


LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

void setup()
{
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  // Make hot pin hot.
  digitalWrite(hot_pin, HIGH);
}

void loop()
{
  read_pin_value = analogRead(read_pin);
  // Serial.println(read_pin_value);
  lcd.print("Sensor value: ");
  lcd.print(read_pin_value, DEC);
  delay(10);
}
