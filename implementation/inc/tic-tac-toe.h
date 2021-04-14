/**
 * @file tic-tac-toe
 * @author Prince Kumar (princekr3010@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * @brief  character type game board .
 * 
 */
char matrix[3][3];


/**
 * @brief This method initilize the tic tac toe game board. 
 * 
 * @return returns 1 if game board initilized sucessfully. 
 */
int init_matrix(void);



/**
 * @brief Get the player move(User Move).
 * 
 */
void get_player_move(void);



/**
 * @brief this function generate a vaid move for computer on random basis.
 * 
 * @return returns 1 if computer generate a valid move.
 */
int get_computer_move(void);



/**
 * @brief  This function displays the game board after every move by the user.
 * 
 * @return it return 1 after every sucessful run. 
 */
int disp_matrix(void);



/**
 * @brief Check for the winner.
 * 
 * @return return X and O according to the winner of the game and returns ' ' if there is a draw. 
 */
char check(void);


/**
 * @brief it consist all the functionality required by a computer to play the game.
 * 
 */
void vscomputer();


/**
 * @brief it consist all the functionality required for a multiplayer game.
 * 
 */
void multiplayer();


/**
 * @brief This function controlls the compelte menu and flow of game. 
 * 
 * @return it returns integer if program executes sucessfully without an error. 
 */
int game();


