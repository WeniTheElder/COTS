/*
 * Timer0_config.h
 *
 * Created: 2/17/2025 1:34:26 PM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_
/*
prescaler value      = 1024
overflow_time        = (prescaler_value/F_CPU) * 256
number_of_over_flows = desierd_time/overflow_time
preload_value        = (1-fraction)*256
*/
#define TIMER0_NUMBER_OF_OVERFLOWS 122    //2sec  
#define TIMER0_PRELOAD_VALUE       0      




#endif /* TIMER0_CONFIG_H_ */
