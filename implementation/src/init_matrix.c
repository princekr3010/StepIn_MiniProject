/**
 * @file init_matrix.c
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief  This function intillize the game matrix. 
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include <stdlib.h>
#include "../inc/tic-tac-toe.h"

/**
 * @brief This function intillize the game matrix.
 * 
 * @return Return 1 after sucessfully initillizing the matrix.
 */

int init_matrix(void)
{
int i, j;
for(i=0; i<3; i++)
for(j=0; j<3; j++) matrix[i][j] = ' ';

if(matrix[0][0]==' ' && matrix[2][2]==' ')
{
    return 1;
}else{
    return 0;
}
}