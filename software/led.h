#ifndef LED_H

#define LED_BRIGHT DDRD |= (1<<0); DDRC |= 127; //Set pins as output
#define LED_DIMMED DDRD &=~ (1<<0); DDRC &=~ 127; //Set pins as input and abuse internal pull up resistor to dim
#define LED_H
#endif
