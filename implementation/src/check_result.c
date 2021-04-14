/**
 * @file check_result.c
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief Check for the winner.
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
 * @brief Check for the winner.
 * 
 * @return return X and O according to the winner of the game and returns ' ' if there is a draw. 
 */
char check(void)
{
int i;
for(i=0; i<3; i++)                                                    /* check rows */
if(matrix[i][0]==matrix[i][1] &&
matrix[i][0]==matrix[i][2]) return matrix[i][0];
for(i=0; i<3; i++)                                                   /* check columns */
if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
    return matrix[0][i];
/* test diagonals */
if(matrix[0][0]==matrix[1][1] &&
matrix[1][1]==matrix[2][2])
return matrix[0][0];
if(matrix[0][2]==matrix[1][1] &&
matrix[1][1]==matrix[2][0])
return matrix[0][2];
return ' ';
}