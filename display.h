#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "Arduino.h"

class Display {
  public:
  Display (int min, int max);
  void print(int number);

  private:
  int *mask;
  int *leds;
};

#endif