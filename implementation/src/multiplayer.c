/**
 * @file multiplayer.c
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief  This function contains all the functionality for a multi-player gaming.
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
 * @brief his function contains all the functionality for a multi-player gaming.
 * 
 */
void multiplayer(){
char done;
printf("\n\n***************************************************\n");
printf("***************************************************\n");
printf("\tThis is the game of Tic Tac Toe.\n");
printf("***************************************************\n");
printf("***************************************************\n");
printf("\tTwo plater can play this game against each other.\n\n\n");
printf("Enetr  the name of first player:  ");  /// Taking input for First player name.
char player1[100];
scanf("%s", &player1);
printf("\n\n");
printf("Enetr  the name of second player:  ");   /// Taking input for Second player name.
char player2[100];
scanf("%s", &player2);
printf("\n\n");
init_matrix();   /// Initillizing the matrix.
disp_matrix();   /// Display the empty game board fro thr fist time.
int count=0;
while(1)
{   
    int x, y;
    repeat_player1:
    printf("%s Enter X,Y coordinates for your move: ", player1);   /// Taking Player 1 Move.
    scanf("%d%*c%d", &x, &y);
    x--; y--;
    /// Checking for a valid move.
    if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    goto repeat_player1;
    }
    else{
         matrix[x][y] = 'X';
         count++;
    }
    disp_matrix();         /// Displaying matrix(Game Board) after every move.

    if(check()!=' '){
        break;
    }

    /// Checking weather number of moves are over or not.
    if(count==9)
    {
        break;
    }

    repeat_player2:
    printf("%s Enter X,Y coordinates for your move: ", player2);     ///Taking Player 2 Move.
    scanf("%d%*c%d", &x, &y);
    x--; y--;

        /// Checking for a valid move.
    if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    goto repeat_player2;
    }
    else{
         matrix[x][y] = 'O';
         count++;
    }
    disp_matrix();       /// Displaying matrix(Game Board) after every move.

    if(check()!=' '){
        break;
    }

    /// Checking weather number of moves are over or not.
    if(count==9)
    {
        break;
    }

}

/**
 * @brief Displaying a winner name.
 * 
 */

if(check()=='X')
{
    printf("%s wins\n", player1);
}else if(check()=='O')
{
    printf("%s Wins\n", player2);
}else{
    printf("It's a Draw\n");
}


}