/*
 * TIMER1_config.h
 *
 * Created: 2/18/2025 11:44:26 AM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/*
prescaler_value      = 64
tick_time            = prescaller_value/F_CPU
Normal mode:
overflow_time        = (prescaler_value/F_CPU) * 65536
number_of_over_flows = desierd_time/overflow_time
preload_value        = (1-fraction)*256

CTC mode:
--you try to set OCR to a value that makes the number of overflows(interrupts) integer value--

number_of_overflows  = desired_time/((OCR2+1)*tick_time)
*/
#define TIMER1_NUMBER_OF_INTERRUPTS 5 
#define TIMER1_PRELOAD_VALUE        0
#define TIMER1_OCRA_VALUE           50000




#endif /* TIMER1_CONFIG_H_ */
