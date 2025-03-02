/*
 * TIMER1_config.h
 *
 * Created: 2/18/2025 11:44:26 AM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/*
prescaler value      = 1024
Tick_time            = prescaler_value/F_CPU
overflow_time        = Tick_time * 65536
number_of_interrupts = desierd_time/overflow_time
preload_value        = (1-fraction)*65536
for CTC mode:
number_of_interrupts = desierd_time/((OCR_value + 1)*Tick_time)
*/
#define TIMER1_NUMBER_OF_INTERRUPTS 2 
#define TIMER1_PRELOAD_VALUE        0
#define TIMER1_OCRA_VALUE           39062UL




#endif /* TIMER1_CONFIG_H_ */
