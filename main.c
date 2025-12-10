#include "drivers.h"

int main(void) {

    Drivers_Init();
    
    unsigned long last_time = 0;

    while (1) {
        
	 Maquina_Estados();   
    }
    return 0;
}