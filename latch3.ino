#include <Bounce2.h>

const int ExitButton = 6;    // pin number for exit button
const int BookButton = 8;    // pin number for magnetic button
const int DoorLatch = 12;    // pin number for door solenoid

Bounce buttonBounce = Bounce();
Bounce bookBounce = Bounce();

void setup() {
  // put your setup code here, to run once:
  pinMode(ExitButton, INPUT);
  pinMode(BookButton, INPUT);
  pinMode(DoorLatch, OUTPUT);

  // debouncers
  buttonBounce.attach(ExitButton);
  buttonBounce.interval(5);
  bookBounce.attach(BookButton);
  bookBounce.interval(5);

  // door latched...
  digitalWrite(DoorLatch, LOW);
  // Serial.begin(9600);
  // Serial.println("Setup Complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonBounce.update();
  bookBounce.update();
  int ExitValue = buttonBounce.read();
  int BookValue = bookBounce.read();
  if ( ExitValue == 1 || BookValue == 0 ) {
    digitalWrite(DoorLatch, HIGH);
    delay(1000);
    digitalWrite(DoorLatch, LOW);
  }
}
