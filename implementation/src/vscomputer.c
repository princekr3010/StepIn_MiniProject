/**
 * @file vscomputer.c
 * @author Prince Kumar (you@domain.com)
 * @brief  This Function contains all the functionalty for VS computer mode.
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
 * @brief This Function contains all the functionalty for VS computer mode.
 * 
 */
void vscomputer()
{
char done;
printf("\n\n***************************************************\n");
printf("***************************************************\n");
printf("\tThis is the game of Tic Tac Toe.\n");
printf("***************************************************\n");
printf("***************************************************\n");
printf("\tYou will be playing against the computer.\n\n\n");
done = ' ';
init_matrix();
do{
disp_matrix();  /// Display the empty game board
get_player_move();
done = check();                                                               /// see if winner 
if(done!= ' ') break;                                                       /// winner!
get_computer_move();
done = check();                                      /// see if winner 
} while(done== ' ');
if(done=='X') printf("You won!\n");
else printf("I won!!!!\n");
disp_matrix();                                          /// show final positions 
}