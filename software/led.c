#include "led.h"
#include <avr/io.h>

/* The LEDs are organized in the following coordinate System:

+---------+---------+---------+
|         |         |         |
|   LED1  | no LED  |   LED2  |
|    PC1  |         |    PC4  |
+---------+---------+---------+
|         |         |         |
|   LED3  |   LED4  |   LED5  |
|     PD0 |    PC2  |    PC5  |
+---------+---------+---------+
|         |         |         |
|   LED6  | no LED  |   LED7  |
|    PC0  |         |    PC3  |
+---------+---------+---------+

*/

void set_led(uint8_t led) {
  PORTD &=~ (1<<0);
  PORTC=0;
  switch (led) {
    case 1:
      PORTC = 2;
      break;
    case 2:
      PORTC = 16;
      break;
    case 3:
      PORTD |= (1<<0);
      break;
    case 4:
      PORTC = 4;
      break;
    case 5:
      PORTC = 32;
      break;
    case 6:
      PORTC = 1;
      break;
    case 7:
      PORTC = 8;
      break;
  }
}

set_number(uint8_t number) {
  PORTD &=~ (1<<0);
  if (number==0) {
    PORTC=0;
  } else if (number==1)
    PORTC = 4;
  else if (number==2)
    PORTC = 10;
  else if (number==3)
    PORTC = 14;
  else if (number==4)
    PORTC = 27;
  else if (number==5)
    PORTC = 31;
  else if (number==6) {
    PORTC = 59;
    PORTD |= (1<<0);
  } else if (number==7) {
    PORTC = 63;
    PORTD |= (1<<0);
  }
}
