#include "drivers.h"

int main(void) {

    Drivers_Init();
    
    unsigned long last_time = 0;

    while (1) {
        
        if (ms_ticks - last_time >= 100) {
            last_time = ms_ticks;
            Maquina_Estados();
        }
    }
    return 0;
}