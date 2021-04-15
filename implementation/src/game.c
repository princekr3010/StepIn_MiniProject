/**
 * @file game.c
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief  This Function controlls all the menu and navigation for the game.
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
 * @brief This function controlls the compelte menu and flow of game. 
 * 
 * @return it returns integer if program executes sucessfully without an error. 
 */
int main(){


    printf("***************************************************\n");
    printf("***************************************************\n\n");
    printf("******************TIC-TAC-TOE**********************\n\n");
    printf("***************************************************\n");
    printf("***************************************************\n\n");
    printf("****************Welcome To Game********************\n\n");
    printf("***************************************************\n");
    printf("***************************************************\n");

/// Print Game Menu.
    printf("\n\n\n");
    printf("1. Play with Computer.\n");
    printf("2. Play Multiplayer.\n");
    printf("Your Choise:  ");
    int mode;
    /// Taking input for Game MOde.
    scanf("%d",&mode);
    switch (mode)
    {
    case 1:
        vscomputer();   /// calling the vscomputer function.
        break;
    case 2:
        multiplayer();  /// calling the multiplayer function.
        break;
    
    default:
        printf("Invalid Option \n select form above option"); /// Asking user to select correct option.
        break;

    }
  return 0;
}


