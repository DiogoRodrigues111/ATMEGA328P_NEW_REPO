/*
 * Breadboard_LED_blink.c
 *
 * Created: 3/6/2021 2:10:48 AM
 * Author : Diogo Rodrigues Roessler (2021)
 */ 

#define ENTRY_FLAGS(P)			(*(volatile unsigned char *)(P))

/************************************************************************/
/* When using the I/O specific commands IN and OUT, the I/O addresses 0x00 - 0x3F must be used.
   When addressing I/O Registers as data space using LD and ST instructions, 0x20 must be added to these addresses.
   The ATmega48A/48PA/88A/88PA/168A/168PA/328/328P is a complex microcontroller with more peripheral units than can be supported within the 64 location reserved in Opcode for the IN and OUT instructions. 
   For the Extended I/O space from 0x60 - 0xFF in SRAM, only the ST/STS/STD and LD/LDS/LDD instructions can be used. */
/************************************************************************/
#define SFR_DDRB0				0x20

/************************************************************************/
/* PORTB_0                                                              */
/************************************************************************/
#define PORTB0_ADDR				0x05
#define ENTRY_PORTB0_FLAGS(P)	ENTRY_FLAGS((P) +SFR_DDRB0)
#define PUT_SFR_PORTB0			ENTRY_PORTB0_FLAGS(PORTB0_ADDR)
#define PORTB0_SUCCESS			PUT_SFR_PORTB0

/************************************************************************/
/* DDRB_0                                                               */
/************************************************************************/
#define DDRB0_ADDR				0x04
#define ENTRY_DDRB0_FLAGS(P)	ENTRY_FLAGS((P) +SFR_DDRB0)
#define PUT_SFR_DDRB0			ENTRY_DDRB0_FLAGS(DDRB0_ADDR)
#define DDRB0_SUCCESS			PUT_SFR_DDRB0

void make_delay_ms(unsigned long ms) {
	unsigned int a=0,b=0;
	for(a=0;  a<65000; a++)
		for(b=0; b<ms; b++)
			;
}

int main(void)
{
	DDRB0_SUCCESS = 0;
	
	if(DDRB0_SUCCESS >= 0)
		DDRB0_SUCCESS = 1;
	
    while(1) 
    {
		if(PORTB0_SUCCESS >= 0) {
			PORTB0_SUCCESS = 1;
			make_delay_ms(500);
		} else if(PORTB0_SUCCESS >= 1) {
			PORTB0_SUCCESS = 0;
			make_delay_ms(500);
		}
    }
}

