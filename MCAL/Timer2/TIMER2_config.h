/*
 * TIMER2_config.h
 *
 * Created: 2/18/2025 12:31:22 PM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

/*
prescaler_value      = 64
tick_time            = prescaller_value/F_CPU
Normal mode:
overflow_time        = (prescaler_value/F_CPU) * 256
number_of_over_flows = desierd_time/overflow_time
preload_value        = (1-fraction)*256

CTC mode:
--you try to set OCR to a value that makes the number of overflows(interrupts) integer value--

number_of_overflows  = desired_time/((OCR2+1)*tick_time)
*/
#define TIMER2_NUMBER_OF_OVERFLOWS 1000    //1 second for OC value of 250 in CTC mode
#define TIMER2_PRELOAD_VALUE       105
#define TIMER2_OCR2_VALUE          250




#endif /* TIMER2_CONFIG_H_ */
