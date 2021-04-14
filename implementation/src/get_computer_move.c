/**
 * @file get_computer_move.c
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief  This function randomely generate a valid move for computer.
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
 * @brief this function generate a vaid move for computer on random basis.
 * 
 * @return returns 1 if computer generate a valid move.
 */
int get_computer_move(void)
{
int i, j;
/// Searching for a valid position in matrix(game board).
for(i=0; i<3; i++){
for(j=0; j<3; j++)
if(matrix[i][j]==' ') break;
if(matrix[i][j]==' ') break;
}
if(i*j==9) {
printf("draw\n");
exit(0);
}
else
matrix[i][j] = 'O';   /// Making the computer Move visible on the board.

return 1;
}