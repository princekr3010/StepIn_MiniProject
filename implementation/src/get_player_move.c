/**
 * @file get_player_move.c
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief  This function accepts the User Move in terms of co-ordinates of the matrix. 
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
 * @brief Get the player move object
 * 
 */
void get_player_move(void)
{
int x, y;
printf("Enter X,Y coordinates for your move: ");     
scanf("%d%*c%d", &x, &y);       /// Taking Co-ordinates for the Move.
x--; y--;

/// CHecking for valid Move.
if(matrix[x][y]!= ' '){
printf("Invalid move, try again.\n");
get_player_move();
}
else matrix[x][y] = 'X';
}