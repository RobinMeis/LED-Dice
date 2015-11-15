#define F_CPU 1000000UL

#include "main.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include "led.h"

volatile uint8_t sleeps=0, upside_down_count=0, dice_number=0, inoffical_dice_number=1;
volatile uint8_t toggle_count_changed=0, toggle_count_unchanged=0;
volatile uint32_t old_toggle_count=0, toggle_count=0;

void configure_interrupt(void) {
  toggle_count=0;
  sleeps=0;
  MCUCR |= (1 << ISC00); //Configures interrupt0 to detect shaking
  GICR |= (1 << INT0);

  OCR1A = 244;
  TCCR1B |= (1 << WGM12);
  TIMSK |= (1 << OCIE1A);
  TCCR1B |= (1 << CS10) | (1 << CS12); //Timer 1, prescaler 1024

  sei();
}

void sleep(void) {
  sleeps=1;
  set_number(0);
  MCUCR &=~ (1 << ISC00)|(1 << ISC01); //Interrupt on INT0 to wake up
  GICR |= (1 << INT0);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  sleep_enable();
  sei(); //Enable interrupts
  sleep_cpu();
  sleep_disable();

  GICR &= ~(1 << INT0); //Disable interrupts
  cli();
  set_number(7);
  _delay_ms(500);
  configure_interrupt();
}


ISR (TIMER1_COMPA_vect) {
  if(PIND&(1<<2)) { //When dice is upside down for 5 seconds go to sleep mode
    if (upside_down_count==10) sleep();
    else if (upside_down_count==9) { //Goodbye..
      LED_BRIGHT;
      set_number(7);
    }
    ++upside_down_count;
  } else upside_down_count=0;

  if (toggle_count_changed<1) {
    if (toggle_count>20 && old_toggle_count<toggle_count-20) ++toggle_count_changed;
    else toggle_count_changed=0;
    old_toggle_count=toggle_count;
  } else if (toggle_count_unchanged<4) {
    set_number(inoffical_dice_number);
    if (old_toggle_count==toggle_count) ++toggle_count_unchanged;
    else toggle_count_unchanged=0;
    old_toggle_count=toggle_count;
    if (toggle_count_unchanged==4) {
      LED_BRIGHT
      set_number(7);
    }
  } else {
    LED_DIMMED
    set_number(dice_number);
    toggle_count_changed=0;
    toggle_count_unchanged=0;
  }

  if (inoffical_dice_number<6) ++inoffical_dice_number;
  else inoffical_dice_number=1;
}

ISR(INT0_vect) {
  if (!sleeps) {
    if (toggle_count<4294967294U) ++toggle_count; //filter if dice was hit or rolled
    else {
      toggle_count=0;
    }
  }
}

int main(void) {
  DDRD &=~ (1<<2); //Input vibration and rotation sensor
  PORTD |= (1<<2);
  LED_BRIGHT;
  set_number(7);
  _delay_ms(1000);
  configure_interrupt();
  LED_DIMMED;
  for (;;) {
    if (dice_number < 6) ++dice_number; //Increment the official number
    else dice_number=1;
  }
  return 0;
}
