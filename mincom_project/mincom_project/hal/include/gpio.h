/*
 * gpio.h
 *
 * Created: 2025-10-17 20:17:48
 *  Author: Joel Alftberg
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>


typedef struct {
	volatile uint8_t *port;
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	uint8_t bit;
	
} pin_mapping_t;

typedef enum {
	LOW, HIGH
} digital_state_t;

typedef enum {
	INPUT, OUTPUT
} mode_t;

typedef enum {
	DISABLE, ENABLE
} pullup_mode_t;

typedef enum {
	A0 = 14,
	A1 = 15,
	A2 = 16,
	A3 = 17,
	A4 = 18,
	A5 = 19
} analog_pin_t;

void gpio_set_direction(uint8_t pin_number, mode_t pin_mode);
void gpio_digital_write(uint8_t pin_number, digital_state_t state);
uint8_t gpio_digital_read(uint8_t pin_number);
uint8_t gpio_analog_read(analog_pin_t pin_number);
void gpio_pulse(uint8_t pin);

#endif /* GPIO_H_ */