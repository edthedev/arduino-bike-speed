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

// About the bike
int TIRE_INCHES_DIAMETER = 27;

//storage variable
int read_pin_value;

// Distance constants for United States
int INCHES_PER_MILE = 63360;
// int MILISECONDS_PER_HOUR = 3600000;
//
double INCH_PER_100_MILISECOND_TO_MPH = .568181818;
double mph;


int SENSOR_TRIGGER = 1019;
int SENSOR_DELAY = 100; // Measure every 1/8 second

int inches_traveled = 0;
int total_inches_traveled = 0;
// double miles_traveled = 0;

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

void setup()
{
  lcd.begin(16, 2);
  // Make hot pin hot.
  digitalWrite(hot_pin, HIGH);
}

void loop()
{

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
 

  // Show inches traveled on both lines
  /*
  lcd.setCursor(0,0);
  lcd.print("Inches this trip: ");
  lcd.setCursor(0,1);
  lcd.print("         ");
  lcd.setCursor(0,1);
  lcd.print(inches_traveled, DEC);
  delay(SENSOR_DELAY);
  */

  // Compute miles traveled.
  // miles_traveled += (inches_traveled / INCHES_PER_MILE);

  inches_traveled = 0;
  // Loop is tuned to be about 1 second long.
  for(int i=0; i<10; i++)
  {
	  // Track distance traveled.
	  delay(SENSOR_DELAY);

	  read_pin_value = analogRead(read_pin);
	  // If we've triggered the sensor... 
	  if(read_pin_value > SENSOR_TRIGGER)
	  {
		// We've traveled another 27 inches.
		inches_traveled += TIRE_INCHES_DIAMETER;
	  }

  } 
  total_inches_traveled += inches_traveled;
 
  // Display MPH on top line
  mph = inches_traveled * INCH_PER_100_MILISECOND_TO_MPH;
  lcd.setCursor(0,0);
  lcd.print("MPH: ");
  lcd.setCursor(5,0);
  lcd.print("             ");
  lcd.setCursor(5,0);
  lcd.print(mph, DEC);

  // Display total inches on second line
  lcd.setCursor(0,1);
  lcd.print("Traveled: ");
  lcd.setCursor(10,1);
  lcd.print("             ");
  lcd.setCursor(10,1);
  lcd.print(total_inches_traveled, DEC);
 
}
