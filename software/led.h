#ifndef LED_H

#define LED_BRIGHT DDRC |= 127; DDRD |= 1; //Set pins as output
#define LED_DIMMED DDRC &=~ 127; DDRD &=~ 1; //Set pins as input and abuse internal pull up resistor to dim
#define LED_H
#endif
