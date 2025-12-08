
#ifndef DRIVERS_H
#define DRIVERS_H


void Drivers_Init(void);


void Riego_Set(unsigned char estado);  // 1 = Prender, 0 = Apagar
void Alarma_Set(unsigned char estado); // 1 = Prender, 0 = Apagar

// Devuelve un entero sin signo (0 a 1023)
unsigned int Sensor_Read_Raw(void);

// Devuelve porcentaje (0 a 100)
unsigned char Sensor_Get_Percentage(void);

// Devuelve el tiempo 
unsigned long Get_Tick(void);

void Maquina_Estados(void); //lo coloco aca ya que sino es una libreria extra sin sentido

#endif








