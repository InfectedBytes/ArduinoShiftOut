#include <ShiftOut.h>

// Init ShiftOut instance with a single chip
// If you want to use more shift registers, just modify this number
ShiftOut<1> shift;

int led = 0;

void setup() {
	Serial.begin(9600);
	// declare pins: data, clock, latch
	shift.begin(4, 6, 5);
}

void loop() {
	shift.setAllLow(); // set all to zero
	shift.setHigh(led); // set led to high
	shift.write(); // write out to 74HC595
	led = (led + 1) % shift.getDataWidth(); // increment led
	delay(250); // wait a bit
}