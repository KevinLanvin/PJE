#include <rflpc17xx/rflpc17xx.h>
 
int main() {

rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P2_1,0);
rflpc_gpio_set_pin_mode_input(RFLPC_PIN_P2_0,RFLPC_PIN_MODE_RESISTOR_PULL_DOWN);

    while(1) {
	if(rflpc_gpio_get_pin (RFLPC_PIN_P2_0)==1)
		rflpc_gpio_set_pin (RFLPC_PIN_P2_1);
	else
		rflpc_gpio_clr_pin (RFLPC_PIN_P2_1);

    }
}
