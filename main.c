#include "drivers.h"

int main(void) {

    Drivers_Init();
    
    unsigned long last_time = 0;

    while (1) {
        
        if (Get_Tick() - last_time >= 100) {
            last_time = Get_Tick();
            Maquina_Estados();
        }
    }
    return 0;
}