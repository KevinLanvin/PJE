#include <rflpc17xx/rflpc17xx.h>
 
int main() {

rflpc_gpio_set_pin_mode_output (RFLPC_PIN_P2_1,1);

    while(1) {

int j;

rflpc_gpio_set_pin(RFLPC_PIN_P2_1);
for(j=0;j<1000000;j=j+1);
rflpc_gpio_clr_pin(RFLPC_PIN_P2_1);
for(j=0;j<1000000;j=j+1);
    }
}
