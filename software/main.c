#define F_CPU 1000000UL

#include <avr/io.h>

#include <util/delay.h>
#include "led.h"

int main(void) {


  LED_DIMMED;

  uint8_t dice;
  for (;;) {
    for (dice=1; dice<=7; ++dice) {
      set_number(dice);
      _delay_ms(1000);
    }
  }
  return 0;
}
