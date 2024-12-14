#include "Keyboard.h"
//define the variable that holds the amount of bound pins so we dont have to do a division operation every loop
uint8_t assignedPinAmount;
//define the struct that acts as a "map" between the arduino's pins and the assignment of the keyboard key to send
struct pinMap {
  uint8_t pin; 
  char key;
};

struct pinMap pm[] = {
  //edit these to whichever pin and key you want bound together
  //you can add/remove pin assignments here!
  {2, 'z'}, //button one is wired to 2 which should press the z key
  {3, 'x'}, //button two, pin 3, press x, etc
  {4, 'd'},
  {10, KEY_LEFT_ARROW},
  {14, KEY_UP_ARROW},
  {15, KEY_DOWN_ARROW},
  {16, KEY_RIGHT_ARROW}
};

void setup() {
  assignedPinAmount = sizeof(pm) / sizeof(pm[0]);
  Keyboard.begin();
  for (uint8_t i = 0; i < assignedPinAmount; i++) {
    pinMode(pm[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  for (uint8_t i = 0; i < assignedPinAmount; i++) {
    if (digitalRead(pm[i].pin) == LOW) {
      Keyboard.press(pm[i].key);
    } else {
      Keyboard.release(pm[i].key);
    }
  }
}