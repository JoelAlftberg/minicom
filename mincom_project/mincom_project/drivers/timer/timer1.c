/*
 * timer1.c
 *
 * Created: 2025-10-17 20:42:14
 *  Author: joela
 */

ISR(TIMER1_COMPA_vect){
	system_ticks++;
}

void timer1_init(){
	
	/* Setup CTC mode, no pre-scaler and use internal clock*/
	TCCR1A = 0x00;
	TCCR1B = (1 << WGM12) | (1 << CS10);
	TCCR1C = 0x00;
	
	/* Load compare register with 3E7F (15 999) */
	OCR1AH = 0x3E;
	OCR1AL = 0x7F;
	
	/* Make sure we start from counting 0 */
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	
	/* Enable Output Compare Interrupt A bit for Timer1 in Timer Interrupt Mask*/
	TIMSK1 |= (1 << OCIE1A);

	
}