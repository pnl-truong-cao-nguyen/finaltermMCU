/**
  ******************************************************************************
  * Ten Tep      :        DEF_16F877A.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-08-2012
  * Tom Tat      :        Khai bao, dinh nghia mot so thah ghi cho PIC16F877A
  *           
  *
  ******************************************************************************
  * Chu Y      :          
  *                          
  *                      
  ******************************************************************************
  */
#ifndef __DEF_16F877A_H
#define __DEF_16F877A_H
#byte PORTA           = 0x05
#byte PORTB           = 0x06
#byte PORTC           = 0x07
#byte PORTD           = 0x08
#byte PORTE           = 0x09
#byte PINA            = 0x05
#byte PINB            = 0x06
#byte PINC            = 0x07
#byte PIND            = 0x08
#byte PINE            = 0x09
//Thanh Ghi Huong
#byte DDRA            = 0x85
#byte DDRB            = 0x86
#byte DDRC            = 0x87
#byte DDRD            = 0x88
#byte DDRE            = 0x89
/*********************PORTA**********************/
#bit PORTA_5          = PORTA.5
#bit PORTA_4          = PORTA.4
#bit PORTA_3          = PORTA.3
#bit PORTA_2          = PORTA.2
#bit PORTA_1          = PORTA.1
#bit PORTA_0          = PORTA.0
#bit PINA_0           = PINA.0
#bit PINA_1           = PINA.1
#bit PINA_2           = PINA.2
#bit PINA_3           = PINA.3
#bit PINA_4           = PINA.4
#bit PINA_5           = PINA.5
#bit DDRA_0           = DDRA.0
#bit DDRA_1           = DDRA.1
#bit DDRA_2           = DDRA.2
#bit DDRA_3           = DDRA.3
#bit DDRA_4           = DDRA.4
/*********************PORTB**********************/
#bit PORTB_7          = PORTB.7
#bit PORTB_6          = PORTB.6
#bit PORTB_5          = PORTB.5
#bit PORTB_4          = PORTB.4
#bit PORTB_3          = PORTB.3
#bit PORTB_2          = PORTB.2
#bit PORTB_1          = PORTB.1
#bit PORTB_0          = PORTB.0
#bit PINB_7           = PINB.7
#bit PINB_6           = PINB.6
#bit PINB_5           = PINB.5
#bit PINB_4           = PINB.4
#bit PINB_3           = PINB.3
#bit PINB_2           = PINB.2
#bit PINB_1           = PINB.1
#bit PINB_0           = PINB.0
#bit DDRB_0           = DDRB.0
#bit DDRB_1           = DDRB.1
#bit DDRB_2           = DDRB.2
#bit DDRB_3           = DDRB.3
#bit DDRB_4           = DDRB.4
#bit DDRB_5           = DDRB.5
#bit DDRB_6           = DDRB.6
#bit DDRB_7           = DDRB.7
/*********************PORTC**********************/
#bit PORTC_7          = PORTC.7
#bit PORTC_6          = PORTC.6
#bit PORTC_5          = PORTC.5
#bit PORTC_4          = PORTC.4
#bit PORTC_3          = PORTC.3
#bit PORTC_2          = PORTC.2
#bit PORTC_1          = PORTC.1
#bit PORTC_0          = PORTC.0
#bit PINC_7           = PINC.7
#bit PINC_6           = PINC.6
#bit PINC_5           = PINC.5
#bit PINC_4           = PINC.4
#bit PINC_3           = PINC.3
#bit PINC_2           = PINC.2
#bit PINC_1           = PINC.1
#bit PINC_0           = PINC.0
#bit DDRC_0           = DDRC.0
#bit DDRC_1           = DDRC.1
#bit DDRC_2           = DDRC.2
#bit DDRC_3           = DDRC.3
#bit DDRC_4           = DDRC.4
#bit DDRC_5           = DDRC.5
#bit DDRC_6           = DDRC.6
#bit DDRC_7           = DDRC.7
/*********************PORTD**********************/
#bit PORTD_7          = PORTD.7
#bit PORTD_6          = PORTD.6
#bit PORTD_5          = PORTD.5
#bit PORTD_4          = PORTD.4
#bit PORTD_3          = PORTD.3
#bit PORTD_2          = PORTD.2
#bit PORTD_1          = PORTD.1
#bit PORTD_0          = PORTD.0
#bit PIND_7           = PIND.7
#bit PIND_6           = PIND.6
#bit PIND_5           = PIND.5
#bit PIND_4           = PIND.4
#bit PIND_3           = PIND.3
#bit PIND_2           = PIND.2
#bit PIND_1           = PIND.1
#bit PIND_0           = PIND.0
#bit DDRD_0           = DDRD.0
#bit DDRD_1           = DDRD.1
#bit DDRD_2           = DDRD.2
#bit DDRD_3           = DDRD.3
#bit DDRD_4           = DDRD.4
#bit DDRD_5           = DDRD.5
#bit DDRD_6           = DDRD.6
#bit DDRD_7           = DDRD.7
/*********************PORTE**********************/
#bit PORTE_2          = PORTE.2
#bit PORTE_1          = PORTE.1
#bit PORTE_0          = PORTE.0
#bit PINE_2           = PINE.2
#bit PINE_1           = PINE.1
#bit PINE_0           = PINE.0
#bit DDRE_0           = DDRE.0
#bit DDRE_1           = DDRE.1
#bit DDRE_2           = DDRE.2
#ifndef DDR_OUT
    #define DDR_OUT     0
#endif
#ifndef DDR_IN
    #define DDR_IN      1
#endif
#endif
/******************************KET THUC FILE******************************
______________________________NGUYEN QUY NHAT______________________________*/

