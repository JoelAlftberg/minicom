/*
 * gpio.c
 *
 * Created: 2025-10-17 20:14:13
 *  Author: Joel Alftberg
 */ 

#include <avr/io.h>
#include "../include/gpio.h"
#define NOP() __asm__ __volatile__("nop") // Define NOP instruction

// Mapping for the arduino digital pins
const pin_mapping_t arduino_mapping_digital[] = {
	{ &PORTD, &DDRD, &PIND, 0},
	{ &PORTD, &DDRD, &PIND, 1},
	{ &PORTD, &DDRD, &PIND, 2},
	{ &PORTD, &DDRD, &PIND, 3},
	{ &PORTD, &DDRD, &PIND, 4},
	{ &PORTD, &DDRD, &PIND, 5},
	{ &PORTD, &DDRD, &PIND, 6},
	{ &PORTD, &DDRD, &PIND, 7},
	{ &PORTB, &DDRB, &PINB, 0},
	{ &PORTB, &DDRB, &PINB, 1},
	{ &PORTB, &DDRB, &PINB, 2},
	{ &PORTB, &DDRB, &PINB, 3},
	{ &PORTB, &DDRB, &PINB, 4},
	{ &PORTB, &DDRB, &PINB, 5},
    { &PORTC, &DDRC, &PINC, 0},
	{ &PORTC, &DDRC, &PINC, 1},
	{ &PORTC, &DDRC, &PINC, 2},
	{ &PORTC, &DDRC, &PINC, 3},
	{ &PORTC, &DDRC, &PINC, 4},
	{ &PORTC, &DDRC, &PINC, 5}
};

void gpio_set_direction(uint8_t pin_number, mode_t pin_mode){
	 if (pin_mode == OUTPUT){
		 *arduino_mapping_digital[pin_number].ddr |= (1 << arduino_mapping_digital[pin_number].bit);
	 }
	 else if (pin_mode == INPUT){
		 *arduino_mapping_digital[pin_number].ddr &= ~(1 << arduino_mapping_digital[pin_number].bit);
	 }
}

// TODO: Add functionality for pull-up/pull-down
void gpio_set_pullup(uint8_t pin_number, pullup_mode_t){
    return;
}

// Reads the Input from the pin and checks if it's high or low
uint8_t gpio_digital_read(uint8_t pin_number){
	return (*arduino_mapping_digital[pin_number].pin & (1 << arduino_mapping_digital[pin_number].bit)) ? 1: 0;
}

// Sets the bit corresponding to the pin in the PORT register
void gpio_digital_write(uint8_t pin_number, digital_state_t state){
	
	if (state == HIGH)
	{
		*arduino_mapping_digital[pin_number].port |= (1 << arduino_mapping_digital[pin_number].bit);
	}
	else{
		*arduino_mapping_digital[pin_number].port &= ~(1 << arduino_mapping_digital[pin_number].bit);
	}
	
}

uint16_t gpio_analog_read(analog_pin_t pin_number){

	uint8_t adc_channel = pin_number - 14;
	ADMUX = (ADMUX & 0xF0) | (adc_channel & 0x0F);
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));
	return ADC;

}

void gpio_pulse(uint8_t pin){
	gpio_digital_write(pin, HIGH);
	NOP();
	gpio_digital_write(pin, LOW);
	NOP();
}
