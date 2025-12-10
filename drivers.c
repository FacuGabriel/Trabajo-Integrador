
#include "drivers.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <inttypes.h>
#include "avr_Gpio.h"    
#include "avr_Adc.h"     
#include "avr_Timers.h"


   volatile unsigned long ms_ticks=0;

   void mSystick(void) {
       ms_ticks++;
   }

   void Drivers_Init(void) {
       // RIEGO (PB0)
       GpioInitStructure_AVR riego;
       riego.port = avr_GPIO_B;
       riego.modo = avr_GPIO_mode_Output;
       riego.pines = avr_GPIO_PIN_0;
       init_gpio(riego);

       // ALARMA (PB1)
       GpioInitStructure_AVR alarma;
       alarma.port = avr_GPIO_B;
       alarma.modo = avr_GPIO_mode_Output;
       alarma.pines = avr_GPIO_PIN_1;
       init_gpio(alarma);

       // SENSOR (ADC)
       AdcInitStructure_AVR sensor;
       sensor.mode = avr_ADC_MODE_Single_Conversion;
       sensor.prescaler = avr_ADC_Prescaler_32;
       sensor.resolution = avr_ADC_RES_10Bit;
       sensor.reference = avr_ADC_REF_AVcc;
       sensor.channel = avr_ADC_canal0;
       sensor.avr_adc_handler = 0;
       init_adc(sensor);

       // SYSTICK
       SystickInitStructure_AVR systick;
       systick.timernumber = avr_TIM0;
       systick.time_ms = 1;
       systick.avr_systick_handler = mSystick;
       init_Systick_timer(systick);

       sei();
   }



   void Riego_Set(unsigned char estado) {
       if(estado) PORTB |= (1 << PB0);
       else       PORTB &= ~(1 << PB0);
   }

   void Alarma_Set(unsigned char estado) {
       if(estado) PORTB |= (1 << PB1);
       else       PORTB &= ~(1 << PB1);
   }


   unsigned int Sensor_Read_Raw(void) {
       return leer_ADC(avr_ADC_canal0);
   }


   unsigned char Sensor_Get_Percentage(void) {
       unsigned int valor_raw = Sensor_Read_Raw();
       
       unsigned long cuenta = ((unsigned long)valor_raw * 100) / 1023;
       
       return (unsigned char)cuenta;
   }
