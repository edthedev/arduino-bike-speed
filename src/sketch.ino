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
int sensor_value;

// Distance constants for United States
int INCHES_PER_MILE = 63360;
// int MILISECONDS_PER_HOUR = 3600000;
//
double INCH_PER_100_MILISECOND_TO_MPH = .568181818;
double mph;


int SENSOR_TRIGGER = 1019;
int SENSOR_DELAY = 50; 

int inches_traveled = 0;
int total_inches_traveled = 0;
// double miles_traveled = 0;
//
//
// New method for counting revolutions
int revolutions = 0;
int found_magnet = 0;

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

void setup()
{
  lcd.begin(16, 2);
  // Make hot pin hot.
  digitalWrite(hot_pin, HIGH);
}

void do_sensor()
{
  // Always update the sensor
  sensor_value = analogRead(read_pin);

  if(found_magnet == 1)
  {
	  // Did we just leave the magnet?
	  if(sensor_value < SENSOR_TRIGGER)
	  {
		  // Add a revolution
		  revolutions += 1;
		  // We're no longer seeing magnet.
		  found_magnet = 0;
	  }
  }

  // See if we've just found the magnet.
  if(sensor_value > SENSOR_TRIGGER)
  {
	found_magnet = 1;
  }
}

void do_display()
{
  // found_magnet at 0,0
  lcd.setCursor(0,0);
  lcd.print(found_magnet);

  // sensor raw value at 2,0 through 5,0
  lcd.setCursor(2,0);
  lcd.print("    ");
  lcd.setCursor(2,0);
  lcd.print(sensor_value);

  // revolutions at 0,1
  lcd.setCursor(0,1);
  lcd.print(revolutions);
}

void loop()
{
  // Strongly favor gathering data over displaying it.
  for(int i; i<100;i++)
  {
	  do_sensor();
	  delay(SENSOR_DELAY);
  }
  do_display();

  // Show raw sensor data on line 0 
  /*
  lcd.setCursor(0,0);
  lcd.print("Sensor: ");
  lcd.setCursor(9,0);
  lcd.print("    ");
  lcd.setCursor(9,0);
  lcd.print(sensor_value, DEC);
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

  /* 
  inches_traveled = 0;
  // Loop is tuned to be about 1 second long.
  for(int i=0; i<10; i++)
  {
	  // Track distance traveled.
	  delay(SENSOR_DELAY);

	  sensor_value = analogRead(read_pin);
	  // If we've triggered the sensor... 
	  if(sensor_value > SENSOR_TRIGGER)
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
  */
 
}
