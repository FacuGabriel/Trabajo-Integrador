#include "drivers.h"

   static Estado_t estado_actual = ESTADO_ESPERA;

   static unsigned long tiempo_inicio_estado = 0;

   static int intento_riego_previo = 0; 

   typedef void (*AccionEstado_t)(unsigned long);
   
   void Func_Estado_Espera(unsigned long tiempo_transcurrido) {
       
       if (tiempo_transcurrido >= TIEMPO_ESPERA_MS) {
	   estado_actual = ESTADO_MIDIENDO;
	   tiempo_inicio_estado = ms_ticks;
       }
     }


   void Func_Estado_Midiendo(unsigned long tiempo_transcurrido) {
       if (tiempo_transcurrido >= TIEMPO_LECTURA_MS) {
	   unsigned char humedad = Sensor_Get_Percentage();
	   unsigned char cambio = 0;

	   if (humedad < UMBRAL_SECO) {
	     
	       if (intento_riego_previo == 1) {

		   estado_actual = ESTADO_ALARMA;
		   cambio = 1;
	       } else {
		  
		   Riego_Set(1);
		   estado_actual = ESTADO_REGANDO;
		   cambio = 1;
	       }
	   } 
	   else {
	       Alarma_Set(0); 
	       intento_riego_previo = 0;
	       estado_actual = ESTADO_ESPERA;
	       cambio = 1;
	   }

	   if (cambio) tiempo_inicio_estado = ms_ticks;
       }
   }

   void Func_Estado_Regando(unsigned long tiempo_transcurrido) {
       unsigned char humedad = Sensor_Get_Percentage();
       
       if (humedad >= UMBRAL_OK || tiempo_transcurrido >= TIEMPO_RIEGO_MAX) {
	   Riego_Set(0); 
	   intento_riego_previo = 1; 
	   estado_actual = ESTADO_ESPERA;
	   tiempo_inicio_estado = ms_ticks;
       }
   }

   void Func_Estado_Alarma(unsigned long tiempo_transcurrido) {

       Alarma_Set(1);     
    
       intento_riego_previo = 0; 

       estado_actual = ESTADO_ESPERA;
       tiempo_inicio_estado = ms_ticks;
   }
   
   static const AccionEstado_t Vector_Estados[] = {
    Func_Estado_Espera,
    Func_Estado_Midiendo,
    Func_Estado_Regando,
    Func_Estado_Alarma
   };

   void Maquina_Estados(void) {
	unsigned long tiempo_transcurrido = ms_ticks - tiempo_inicio_estado;
	Vector_Estados[estado_actual](tiempo_transcurrido);
   }