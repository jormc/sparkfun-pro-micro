/*
 * Try to test if HID & Serial read is available altogether
 *  
 * It seems to be true... :-)
 * 
 */

#include <Keyboard.h>


int incomingByte = 0; // for incoming serial data
int buttonPin = 9; // Set a button to any pin

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  pinMode(buttonPin, INPUT);     // Set the button as an input
  digitalWrite(buttonPin, HIGH); // Pull the button high
  Keyboard.begin(); //Init keyboard emulation
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

    Keyboard.write(incomingByte); // send a 'z' to the computer via Keyboard HID
  }

}
