/*
 * systick.c
 *
 * Created: 2025-10-17 20:22:48
 *  Author: joela
 */ 

volatile uint32_t system_ticks = 0;

void systick_init() {
	timer1_init();
}

uint32_t systick_get_ticks(void) {
	return system_ticks;
}

void systick_delay(uint32_t ticks) {
	uint32_t start = system_ticks;
	while
}
