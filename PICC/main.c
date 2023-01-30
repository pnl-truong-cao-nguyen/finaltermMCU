#include <main.h>

unsigned int8 seg7ledca[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};//7 segment led code common anode

unsigned int8 n = 0;
unsigned int8 on_lamp = 0;
unsigned int8 i;
unsigned int16 t;
//=========================declare function====================================
void init_pin(void)
{
// set up port
   DDRB_1 = 0;
   DDRB_2 = 0;
   DDRB_3 = 0;
   DDRB_4 = 0;
   DDRC = 0x00;
   DDRD = 0x00;
}

void init_int_ext(void);//init interrupt external

void status_on_off(unsigned int8 n);

void display_on_seg7led(unsigned int8 n);//export 7 segment led

void delay_timer0(unsigned int16 t);// delay timer 0

void on_off_lamp(void);


//=====================declare interrupt program===============================
#INT_EXT
void _int_ext(void)
{
   clear_interrupt(INT_EXT);
   disable_interrupts(GLOBAL);
   //begin interrupt external program
   n++;
   on_lamp = 1;
   //end interrupt external program
   enable_interrupts(GLOBAL);
}

//===========================main program======================================
void main()
{
   init_pin();
   init_int_ext();
   
   setup_timer_0(T0_INTERNAL|T0_DIV_4);//set timer 0
   
   while(TRUE)
   {
      status_on_off(n);
      display_on_seg7led(n);
      on_off_lamp();
   }

}

//==================================function===================================
void init_int_ext(void)
{
   DDRB_0 = 1;
   ext_int_edge(L_TO_H);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
}

void status_on_off(unsigned int8 n)
{
   if(n < 10)
   {
      PORTB_1 = 1;
      PORTB_2 = 0;
      PORTB_3 = 0;
   }
   else if(n < 20)
   {
      PORTB_1 = 0;
      PORTB_2 = 1;
      PORTB_3 = 0;
   }
   else
   {
      PORTB_1 = 0;
      PORTB_2 = 0;
      PORTB_3 = 1;
   }
}

void display_on_seg7led(unsigned int8 n)
{
   PORTC = seg7ledca[n/10];
   PORTD = seg7ledca[n%10];
}

void delay_timer0(unsigned int16 t)
{
   do
   {
      for(i = 0; i < 5; i++)
      {
         set_timer0(5);//initial count value
         // T = 4 * (1 / Fosc) * Prescaler
         while(get_timer0() < 255);
      }
      t--;
   }
   while(t != 0);
}

void on_off_lamp(void)
{
   if(on_lamp)
   {
      on_lamp = 0;
      PORTB_4 = 1;
      display_on_seg7led(n);
      delay_timer0(1000);
      PORTB_4 = 0;
   }
   else
   {
      PORTB_4 = 0;
   }
}

