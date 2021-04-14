/**
 * @file disp_matrix.c
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief   This Function display the matrix(game Board). it returns 1 after sucessfully display the matrix.
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
 * @brief  This function displays the game board after every move by the user.
 * 
 * @return it return 1 after every sucessful run. 
 */
int disp_matrix(void)
{
int t;
for(t=0; t<3; t++) {
printf(" %c | %c | %c ",matrix[t][0],
matrix[t][1], matrix [t][2]);
if(t!=2) printf("\n---|---|---\n");
}
printf("\n");
return 1;
}