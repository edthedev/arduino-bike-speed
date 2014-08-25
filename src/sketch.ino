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

// Distance constants for United States
int INCHES_PER_MILE = 63360;
int MILISECONDS_PER_HOUR = 3600000;
int TIRE_INCHES_DIAMETER = 27;

int SENSOR_TRIGGER = 1019;
int SENSOR_DELAY = 125; // Measure every 1/8 second

int inches_traveled = 0;
int miles_traveled = 0;

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

void setup()
{
  lcd.begin(16, 2);
  // Make hot pin hot.
  digitalWrite(hot_pin, HIGH);
}

void increment()
{
}

void loop()
{
  read_pin_value = analogRead(read_pin);

  // Show raw sensor data on line 0
  /*
  lcd.setCursor(0,0);
  lcd.print("Sensor: ");
  lcd.setCursor(9,0);
  lcd.print("    ");
  lcd.setCursor(9,0);
  lcd.print(read_pin_value, DEC);
  delay(SENSOR_DELAY);
  */
 
  // If we've triggered the sensor... 
  if(read_pin_value > SENSOR_TRIGGER)
  {
	// We've traveled another 27 inches.
	inches_traveled += TIRE_INCHES_DIAMETER;
  }

  // Show inches traveled on both lines
  lcd.setCursor(0,0);
  lcd.print("Inches this trip: ");
  lcd.setCursor(0,1);
  lcd.print("         ");
  lcd.setCursor(0,1);
  lcd.print(inches_traveled, DEC);
  delay(SENSOR_DELAY);
 

}
