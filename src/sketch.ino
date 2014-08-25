//arduino bike speedometer w serial.print()
//by Amanda Ghassaei 2012
//http://www.instructables.com/id/Arduino-Bike-Speedometer/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/

//pin connected to read switch
#define read_pin A1
#define hot_pin A2

//storage variable
int read_pin_value;

void setup(){
  Serial.begin(9600);
  // Make hot pin hot.
  digitalWrite(hot_pin, HIGH);
}

void loop(){
  read_pin_value = analogRead(read_pin);
  Serial.println(read_pin_value);
  delay(10);
}
