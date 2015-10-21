#include <rflpc17xx/rflpc17xx.h>
#include "wait.h"

int isShining;

RFLPC_IRQ_HANDLER switchLed(){



	if(isShining==1){
		rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P2_0,1);
		rflpc_gpio_clr_pin (RFLPC_PIN_P2_1);
		isShining=0;
	}
	else{
		rflpc_gpio_set_pin (RFLPC_PIN_P2_1);
		isShining=1;
	}


	rflpc_gpio_clr_pin (RFLPC_PIN_P2_0);


	rflpc_timer_reset(RFLPC_TIMER0);
}


int main() {




rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P2_1,1);
isShining=1;

	//timer
	rflpc_timer_enable(RFLPC_TIMER0);
	rflpc_timer_set_clock (RFLPC_TIMER0, RFLPC_CCLK);

	rflpc_timer_set_pre_scale_register(RFLPC_TIMER0, rflpc_clock_get_system_clock());
	rflpc_timer_set_callback(RFLPC_TIMER0,switchLed);

	rflpc_timer_set_match_value(RFLPC_TIMER0,RFLPC_TIMER_MATCH0,4);

	rflpc_timer_set_irq_on_match(RFLPC_TIMER0, RFLPC_TIMER_MATCH0, RFLPC_TIMER_IRQ_ON_MATCH | RFLPC_TIMER_RESET_ON_MATCH);

	rflpc_timer_start(RFLPC_TIMER0);


    while (1)
    {

    }


return 0;
}
