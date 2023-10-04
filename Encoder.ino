#include <Arduino.h>

#define CW 2
#define CCW A0
#define buttonPin A2

volatile bool dir = false;
volatile bool action = false;
bool button[] = {true, true};
bool button_pressed = false;
bool aState = false;

void setup() {
  pinMode(CW, INPUT_PULLUP);
  pinMode(CCW, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(CW), encoder, FALLING);
}

void loop() {

button[0] = digitalRead(buttonPin);

  
  if (action)
    action = false;

  if (!button_pressed & (button[0] != button[1])){
    if (!button[0])
      button_pressed = true;
    button[1] = button[0];
    }

}

void encoder(){
  aState = digitalRead(CW);
  action = true;
    
  if (digitalRead(CCW) != aState) { 
      dir = true;
  }
  else{
    dir = false;
  }
}
