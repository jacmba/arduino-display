#include "Arduino.h"
#include "display.h"

Display::Display (int min, int max) {
  leds = new int[7];
  for(int i = min, j = 0; i <= max; i++, j++) {
    pinMode(i, OUTPUT);
    leds[j] = i;
  }

  mask = new int[10];
  mask[0] = B01110111;
  mask[1] = B01000001;
  mask[2] = B00111011;
  mask[3] = B01101011;
  mask[4] = B01001101;
  mask[5] = B01101110;
  mask[6] = B01111110;
  mask[7] = B01000011;
  mask[8] = B01111111;
  mask[9] = B01101111;
}

void Display::print (int number) {
  int m = B01000000;

  for (int i = 0; i < 7; i++) {
    int volt;
    int result = mask[number] & m;

    volt = result > 0 ? HIGH : LOW;
    m = m >> 1;

    digitalWrite(leds[i], volt);
  }
}