#ifndef DRIVERS_H
#define DRIVERS_H

#define UMBRAL_SECO     20
#define UMBRAL_OK       60

#define TIEMPO_ESPERA_MS   10000  
#define TIEMPO_LECTURA_MS  100    
#define TIEMPO_RIEGO_MAX   5000  

typedef enum {
    ESTADO_ESPERA,
    ESTADO_MIDIENDO,
    ESTADO_REGANDO,
    ESTADO_ALARMA
} Estado_t;

extern volatile unsigned long ms_ticks; 

void Drivers_Init(void);
void Riego_Set(unsigned char estado);
void Alarma_Set(unsigned char estado);
unsigned int Sensor_Read_Raw(void);
unsigned char Sensor_Get_Percentage(void);
void Maquina_Estados(void);

#endif



