/**
 * @file filter.h
 * @author Pramodh Mahadesh K M (pramodhmahadesh@gmail.com)
 * @brief A project to design Active filters using opamps
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __FILTER_H__
#define __FILTER_H__

/**
 * @brief structure to take the input values
 * Band pass gain = Af
 * Cutoff frequency = freq
 * For band pass filter lower and upper cutoff frequency are denoted as l_freq & u_freq respectively
 * 
 */
typedef struct input_val{
    float freq;
    float Av;
    float l_freq;
    float u_freq;
}input_val;

/**
 * @brief structure to store output values
 * Different resistors are denoted by R,R1,R2,R3,R4
 * Different capacitors are denoted by C,C1,C2
 * 
 */
typedef struct output_val{
    float R;
    float C;
    float R1;
    float R2;
    float R3;
    float R4;
    float C1;
    float C2;
}output_val;

/**
 * @brief enum to denote different return conditions
 * Failure is used to test null pointer error
 * code_error is used to test the character entered by user
 * Limit_error is used to test the input values stay within operating range
 */
typedef enum condition{
    Limit_error=-2,
    code_error=-1,
    Failure = 0,
    Success = 1
}condition;

/**
 * @brief This function displays the instructions message
 * 
 */
void display(void);

/**
 * @brief Checks if the char entered is matching the code displayed
 * 
 * @param c input character from user
 * @return condition returns Success if it matches else returns code_error
 */
condition check_code(char c);

/**
 * @brief depending on the input, this function chooses the type of filter and passes the input parameters to them
 * 
 * @param c input character from user
 * @return condition returns Success if it matches else returns code_error
 */
condition choose_filter(char c);

/**
 * @brief to design a First order active low pass filter, prints the output parameters.
 * 
 * @param params the design parameters taken from the user
 * @return condition returns Failure if null pointer error is present, returns Limit_error if entered values are out of limits
 * else returns Success
 */
condition FLP(input_val* params);

/**
 * @brief to design a First order active low pass filter, prints the output parameters.
 * 
 * @param params the design parameters taken from the user
 * @return condition returns Failure if null pointer error is present, returns Limit_error if entered values are out of limits
 * else returns Success
 */
condition FHP(input_val* params);

/**
 * @brief to design a First order active low pass filter, prints the output parameters.
 * 
 * @param params the design parameters taken from the user
 * @return condition returns Failure if null pointer error is present, returns Limit_error if entered values are out of limits
 * else returns Success
 */
condition SLP(input_val* params);

/**
 * @brief to design a First order active low pass filter, prints the output parameters.
 * 
 * @param params the design parameters taken from the user
 * @return condition returns Failure if null pointer error is present, returns Limit_error if entered values are out of limits
 * else returns Success
 */
condition SHP(input_val* params);

/**
 * @brief to design a First order active low pass filter, prints the output parameters.
 * 
 * @param params the design parameters taken from the user
 * @return condition returns Failure if null pointer error is present, returns Limit_error if entered values are out of limits
 * else returns Success
 */
condition BPF(input_val* params);



#endif /*__FILTER_H__*/





