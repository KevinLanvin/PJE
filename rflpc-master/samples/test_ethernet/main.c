
#include <rflpc17xx/rflpc17xx.h>
#include "wait.h"

void pinpon (void)
{
	int status = rflpc_eth_link_state () ;

	if (status)
	{	

		while(rflpc_eth_link_state ()){
		rflpc_led_set(RFLPC_LED_1);
		rflpc_led_set(RFLPC_LED_2);
		wait(1);
		rflpc_led_set(RFLPC_LED_3);
		rflpc_led_set(RFLPC_LED_4);
		rflpc_led_clr(RFLPC_LED_1);
		rflpc_led_clr(RFLPC_LED_2);
		wait(1);
		rflpc_led_clr(RFLPC_LED_3);
		rflpc_led_clr(RFLPC_LED_4);
		}

	}
	else
	{
		rflpc_led_clr(RFLPC_LED_1);
		rflpc_led_clr(RFLPC_LED_2);
		rflpc_led_clr(RFLPC_LED_3);
		rflpc_led_clr(RFLPC_LED_4);

	}

}

int main(void) 
{
	rflpc_eth_init () ;
	rflpc_led_init () ;

	rflpc_eth_irq_enable_set (~0) ;
	rflpc_eth_irq_enable (~0) ;
	rflpc_eth_irq_trigger(~0);
	rflpc_irq_handler_t led = pinpon ;
	rflpc_eth_set_irq_handler (led) ;





	/*
	rflpc_rit_enable() ;
	rflpc_irq_handler_t check_led = pinpon ;
	rflpc_rit_set_callback(period, ~period, 1, check_led) ;
*/
	while (1)
	{
	}

	return 0 ;
}

