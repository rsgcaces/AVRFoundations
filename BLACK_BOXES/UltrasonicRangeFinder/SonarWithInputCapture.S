// Purpose:   Assembly version of Nedelkovski's Sonar Project
// Trial 1:   Worked: placed a 65ms/10us pulse on Pin 7
// Trial 2:   place an input capture event interrupt on ICP1  
// Reference: http://howtomechatronics.com/projects/arduino-radar-project/
// Reference: http://www.atmel.com/Images/Atmel-2505-Setup-and-Use-of-AVR-Timers_ApplicationNote_AVR130.pdf
// Reference: https://www.easycalculation.com/engineering/electrical/avr-timer-calculator.php
// Author:    C. D'Arcy
// Date:      2017 01 08
// Status:    In development
/*// Algorithm: Place a 60ms/10us PWM signal on the Trig pin (9:OC1A) and an Input Capture on the Echo Pin (8:ICP1)
#include "avr/io.h"
#define hi  0x00
#define lo  0xFF                ; 10us
#define gnd PD6                 ; digital pin 6 (ground)
#define trig PD7                ; digital pin 7 (+/-/+/-...)
#define echo PB0                ; digital pin 8 (ICP1)
#define state PB5               ; digital pin 13
.global setup
setup:
;  sbi _SFR_IO_ADDR(DDRB), trig  ; pinMode(9,OUTPUT)
;  sbi _SFR_IO_ADDR(DDRB), gnd   ; pinMode(10,OUTPUT)
;  sbi _SFR_IO_ADDR(DDRB), state ; pinMode(13,OUTPUT)
;  cbi _SFR_IO_ADDR(DDRB), echo  ; default: pinMode(8,INPUT) (ICP1:PB0)
  ldi r16, (1<<PB5)              ; declare state pin for OUTPUT
  out _SFR_IO_ADDR(DDRB),r16     ;
;------Trial 1: (Worked) placed a 65ms/10us pulse on Pin 7 -----------  
  ldi r16, (1<<PD6) | (1<<PD7)   ; declare trig and gnd pins to OUTPUT
  out _SFR_IO_ADDR(DDRD),r16     ;
  cbi _SFR_IO_ADDR(PORTD), gnd   ; clear ground pin for trig
;------Trial 1:End ---------------------------------------------------  
  ldi r16,0///*(1<<COM1A1)|(1<<COM1A0) ; | (1<<WGM10); prepare for Normal Mode
  clr r16                       ; Normal Mode 0, OC1A/B disconnected
  sts TCCR1A, r16               ; set Normal Mode, now configure the prescaler...
;  ldi r16, 0b00000001          ; T1:2^24/2^16   (no prescale) > 2^8 ovf/s  > 128Hz
;  ldi r16, 0b00000010          ; T1:2^24/2^3/2^16  (prescale) > 2^5 ovf/s  > 16Hz
;  ldi r16, 0b00000011          ; T1:2^24/2^6/2^16  (prescale) > 2^2 ovf/s  > 2Hz
   ldi r16, 0b00000100          ; T1:2^24/2^8/2^16  (prescale) > 1 ovf/s    > 0.5Hz
;  ldi r16, 0b00000101          ; T1:2^24/2^10/2^16 (prescale) > 0.25 ovf/s > 0.125Hz
  sts TCCR1B, r16               ; Timer1 clock = system clock / prescale
  ldi r16,hi                    ; load TCNT1 (Timer1's 2-byte counter)
  ldi r17,lo                    ; load TCNT1 (Timer1's 2-byte counter)
  sts OCR1AH,r16                ; 
  sts OCR1AL,r17                ; 
;  sts TCNT1H,r16                ; 
;  sts TCNT1L,r17                ; 
  ldi r16,(1<<TOIE1)|(1<<OCIE1A); prepare to enable TC Overflow and Output Comapare Interrupt
  sts TIMSK1,r16                ; enable configured interrupts
  sei                           ; enable global interrupts
  ret

.global loop
loop:
  rjmp loop                     ; this avoids returning to the C driver

.global TIMER1_COMPA_vect
TIMER1_COMPA_vect:
  cbi _SFR_IO_ADDR(PORTD), trig ;clear trigger pin
reti

.global TIMER1_CAPT_vect
TIMER1_CAPT_vect:
;  cbi _SFR_IO_ADDR(PORTB), trig ;
reti


.global TIMER1_OVF_vect
TIMER1_OVF_vect:                ; destination for TCNT1 overflow interrupt 
;  push r16                     ; preserve r16 if used externally to this ISR
; push r17                     ; preserve r17 if used externally to this ISR
;  in  r16, _SFR_IO_ADDR(SREG)  ; preserve the Status Register if necessary
; push  r16                    ;
; ldi r16,hi                    ; reload TCNT1 (Timer1's 2-byte counter)
;  ldi r17,lo                    ; LED flashing at 24Hz does not seem to produce PoV
;  sts TCNT1H,r16                ; 
;  sts TCNT1L,r17                ; 
  in r16,_SFR_IO_ADDR(PORTB)    ; read the port
  ldi r17,1<<PB5                ; prepare the bit(s) to toggle
  eor r16,r17                   ; toggle the bit(s), leaving the others unaffected
  out _SFR_IO_ADDR(PORTB),r16   ; update the port
  sbi _SFR_IO_ADDR(PORTD), trig ; set trigger pin
;  pop r16                      ; if necessary, restore the data stacked on input to this ISR
;  out _SFR_IO_ADDR(SREG),r16   ; restore Status Register
;  pop r17                      ; restore r17 if used externally to this ISR
;  pop r16                      ; restore r16 if used externally to this ISR
  reti                          ; return from interrupt
*/
