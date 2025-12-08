
#include "drivers.h"

#define TIEMPO_ESPERA_MS   300000
#define TIEMPO_LECTURA_MS  10000  
#define TIEMPO_RIEGO_MAX   30000

// Umbrales en porcentaje
#define UMBRAL_SECO      30
#define UMBRAL_OK        60
#define UMBRAL_CRITICO   10

typedef enum {
    ESTADO_ESPERA,  
    ESTADO_MIDIENDO,
    ESTADO_REGANDO,
    ESTADO_ALARMA
} Estado_t;

// Variable estatica
static Estado_t estado_actual = ESTADO_ESPERA;

static unsigned long tiempo_inicio_estado = 0;

void Maquina_Estados(void) {
    
    // Leemos la humedad actual
    int humedad = Sensor_Get_Percentage();
    
    // Calculamos cuanto tiempo pasó desde que entramos al estado actual
    unsigned long tiempo_transcurrido = Get_Tick() - tiempo_inicio_estado;

    switch (estado_actual) {

        // ESPERA DE 5 MINUTOS
        case ESTADO_ESPERA:
            
            if (tiempo_transcurrido >= TIEMPO_ESPERA_MS) {
                // Pasaron los 5 mins, vamos a medir
                estado_actual = ESTADO_MIDIENDO;
                tiempo_inicio_estado = Get_Tick();
            }
            break;

        // LECTURA DE 10 SEGUNDOS 
        case ESTADO_MIDIENDO:
            // Esperamos 10 segundos para que el sensor se estabilice o tomamos lectura
            if (tiempo_transcurrido >= TIEMPO_LECTURA_MS) {
                // Pasaron los 10 seg, ahora si tomamos la decisión
                
                if (humedad < UMBRAL_CRITICO) {
                   Alarma_Set(1);
                   estado_actual = ESTADO_ALARMA;
                }
                if (humedad < UMBRAL_SECO) {
                   Riego_Set(1); // Prender bomba
                   estado_actual = ESTADO_REGANDO;
                }
                else {
                   // Si la humedad esta bien, volvemos al tiempo de espera 5
                   estado_actual = ESTADO_ESPERA;
                }
                //Reiniciar cronometro
                tiempo_inicio_estado = Get_Tick();
            }
            break;

        //  RIEGO 30 SEGUNDOS
        case ESTADO_REGANDO:
            
            if (humedad >= UMBRAL_OK) {
                Riego_Set(0); // Apagar
                estado_actual = ESTADO_ESPERA;
                tiempo_inicio_estado = Get_Tick();
            }
  
            else if (tiempo_transcurrido >= TIEMPO_RIEGO_MAX) {
                Riego_Set(0);
                
                estado_actual = ESTADO_ESPERA; 
		
                tiempo_inicio_estado = Get_Tick();
            }
            break;

        case ESTADO_ALARMA:
           
            if (humedad > UMBRAL_SECO) {
                Alarma_Set(0);
                estado_actual = ESTADO_ESPERA;
                tiempo_inicio_estado = Get_Tick();
            }
            break;
    }
}