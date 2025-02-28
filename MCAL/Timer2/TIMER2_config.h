/*
 * TIMER2_config.h
 *
 * Created: 2/18/2025 12:31:22 PM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

/*
prescaler value      = 1024
overflow_time        = (prescaler_value/F_CPU) * 256
number_of_over_flows = desierd_time/overflow_time
preload_value        = (1-fraction)*256
*/
#define TIMER2_NUMBER_OF_OVERFLOWS 153    //2.5sec
#define TIMER2_PRELOAD_VALUE       105




#endif /* TIMER2_CONFIG_H_ */
