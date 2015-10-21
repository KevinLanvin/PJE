#include <rflpc17xx/rflpc17xx.h>
#include "wait.h"

int main() {
//PIN 2
rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P2_1,0);
/*
//PIN 25
rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P2_1,0);
//PIN 24
rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P2_2,0);
*/

/*
100 0000 000 == 31 sec;

rapport == 32258000;
*/

    while(1) {
		rflpc_gpio_set_pin (RFLPC_PIN_P2_1);
wait(30);
		rflpc_gpio_clr_pin (RFLPC_PIN_P2_1);
wait(1);
/*
		rflpc_gpio_set_pin (RFLPC_PIN_P2_0);
for(j=0;j<1000000;j=j+1);
		rflpc_gpio_clr_pin (RFLPC_PIN_P2_0);
for(j=0;j<1000000;j=j+1);

		rflpc_gpio_set_pin (RFLPC_PIN_P2_0);
for(j=0;j<1000000;j=j+1);
		rflpc_gpio_clr_pin (RFLPC_PIN_P2_0);
for(j=0;j<1000000;j=j+1);
*/
    }
}
