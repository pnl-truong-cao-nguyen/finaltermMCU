#include <main.h>

unsigned int8 seg7ledca[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};//7 segment led code common anode

unsigned int8 n = 0;
unsigned int16 i = 0;

//=========================declare function====================================
void init_pin(void)
{
// set up port
   DDRA_0 = 1;//button on/off sensor
   DDRA_1 = 1;//button on/off light
   DDRA_2 = 1;//button reset count
   DDRB_0 = 1;//input sensor
   DDRB_1 = 0;//signal led green
   DDRB_2 = 0;//signal led yellow
   DDRB_3 = 0;//signal led red
   DDRB_4 = 0;//light
   DDRB_5 = 0;//signal sensor led
   DDRC = 0x00;//7 segment led dozens
   DDRD = 0x00;//7 segment led units
}

void init_int_ext(void);//init interrupt external

void status_on_off(unsigned int8 n);//notification status

void display_on_seg7led(unsigned int8 n);//export 7 segment led

void init_int_timer0(void);//init interrupt timer 0

//=====================declare interrupt program===============================
#INT_EXT
void _int_ext(void)
{
   PORTB_4 = 1;
   i = 0;
   do
   {
      set_timer1(0);
      while(get_timer1() < 50000)
      {
         if(PORTB_0)
         {
            i = 0;
            while(PORTB_0);
         }
      }
      i++;
   }
   while(i < 100);
   
   PORTB_4 = 0;
   n++;
}

#INT_TIMER0
void _int_timer0(void)
{
   if(PORTA_0)
   {
      //on/off sensor
      delay_ms(20);
      if(PORTA_0)
      {
         DDRB_0 = !DDRB_0;
         while(PORTA_0);
         if(PORTB_4)
         {
            PORTB_4 = 0;
            n++;
         }
      }     
   }
   if(DDRB_0 == 0)
   {
      if(PORTA_1)
      {
         //on/off light when sensor off
         delay_ms(20);
         if(PORTA_1)
         {
            PORTB_4 = !PORTB_4;
            if(!PORTB_4)
            {
               n++;
            }
            while(PORTA_1);
         }   
      }
   }
   if(PORTA_2)
   {
      //reset counter on/off light
      delay_ms(20);
      if(PORTA_2)
      {
         n = 0;
         PORTB_4 = 0;
         while(PORTA_2);
      }
      
   }
   set_timer0(231);
}


//===========================main program======================================
void main()
{
   init_pin();
   init_int_ext();
   init_int_timer0();
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);//set timer1
   
   while(TRUE)
   {
      status_on_off(n);
      display_on_seg7led(n);
      if(DDRB_0)
      {
         PORTB_5 = 1;//sensor on
      }
      else
      {
         PORTB_5 = 0;//sensor off
      }
   }
}

//==================================function===================================
void init_int_ext(void)
{
   //interrupt at RB0
   ext_int_edge(L_TO_H);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
}

void init_int_timer0(void)
{
   //interrupt timer 0
   setup_timer_0(T0_INTERNAL|T0_DIV_1);
   set_timer0(231);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
}

void status_on_off(unsigned int8 n)
{
   if(n < 10)
   {
      //green led
      PORTB_1 = 1;
      PORTB_2 = 0;
      PORTB_3 = 0;
   }
   else if(n < 20)
   {
      //yellow led
      PORTB_1 = 0;
      PORTB_2 = 1;
      PORTB_3 = 0;
   }
   else
   {
      //red led
      PORTB_1 = 0;
      PORTB_2 = 0;
      PORTB_3 = 1;
   }
}

void display_on_seg7led(unsigned int8 n)
{
   PORTC = seg7ledca[n/10];//7 segment led dozens
   PORTD = seg7ledca[n%10];//7 segment led units
}
