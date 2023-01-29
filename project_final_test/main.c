#include <main.h>

unsigned int8 seg7ledca[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

unsigned int8 n = 0;
void init_pin(void)
{
   DDRB_1 = 0;
   DDRB_2 = 0;
   DDRB_3 = 0;
   DDRC = 0x00;
   DDRD = 0x00;
}

void init_int_ext(void);

#INT_EXT
void _int_ext(void)
{
   clear_interrupt(INT_EXT);
   disable_interrupts(GLOBAL);
   //begin interrupt external program
   PORTB_1 = !PORTB_1;
   PORTB_2 = !PORTB_2;
   PORTB_3 = !PORTB_3;
   //end interrupt external program
   enable_interrupts(GLOBAL);
}

void main()
{
   init_pin();
   init_int_ext();
   
   while(TRUE)
   {
      PORTB_1 = 1;
      PORTB_2 = 1;
      PORTB_3 = 1;
      for(n = 0; n < 100; n++)
      {
         PORTC = seg7ledca[n/10];
         PORTD = seg7ledca[n%10];
         delay_ms(1000);
      }

   }

}

void init_int_ext(void)
{
   DDRB_0 = 1;
   ext_int_edge(L_TO_H);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
}

