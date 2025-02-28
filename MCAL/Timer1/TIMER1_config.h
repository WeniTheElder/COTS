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
overflow_time        = (prescaler_value/F_CPU) * 65536
number_of_over_flows = desierd_time/overflow_time
preload_value        = (1-fraction) * 65536
*/
#define TIMER1_NUMBER_OF_OVERFLOWS 2    //5sec
#define TIMER1_PRELOAD_VALUE       52947



#endif /* TIMER1_CONFIG_H_ */
