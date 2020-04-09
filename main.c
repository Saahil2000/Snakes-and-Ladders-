//
//  main.c
//  Design Assessment
//
//  Created by Kuren Dhand on 05/02/2020.
//  Copyright © 2020 Kuren Dhand. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameBoard();
int i,j,k; //Define global variables so they do not habe to be defined in each conditional
int position = 0;
int position2=0;
int diceRoll;

int main(){
    srand(time(0));  // to randomise the dice rolla each game to not have the same sequence repeated
    printf("Welcome to snakes and ladders...First to reach the end of the board wins \n");
    //int pos1 = 0;
    //int pos2 = 0;
    int gameRunning = 1;
    int playerTurn;
    int numRolls1 = 0; //Initialising a counter for player 1
    int numRolls2 = 0; //Counter for player 2 number of rolls
    while (gameRunning == 1){ //Cna set gameRunning to 0 when game ends and break code
        printf("Enter a player number to roll\n");
        scanf("%d",&playerTurn);
        diceRoll = (rand() % 6 + 1); //Will give a random number from 1 to 6
        if (playerTurn == 1){
            numRolls1++; //Counter for number of player 1 rolls that incrememnts each roll 
            printf("Player1 rolled a %d\nPlayer1 Rolls : %d   Player2 Rolls : %d \n",diceRoll,numRolls1,numRolls2);
            position = position + diceRoll;
            if (position == 85){
                position = 49;
                printf("You landed on a snake down you go to position 49");
            }
            else if(position == 33){
                position = 73;
                printf("You landed on a ladder up you go to position 73");
            }
            else if(position >= 100){
                printf("Congratulations Player 1 you have won the game\n");
                gameRunning =0;
            }
            else{
                printf("Player one is on position %d\n",position);
            }
            printf("Player Two is on position %d\n",position2);
            char grid[10][10];
            for (i = 0; i < 10; i++) {
                 for (j = 0; j < 10; j++) {
                     grid[i][j] = '.'; //Could not get ASCII values correct for mac
                         for (k=3;k<8;k++){
                             grid[k][3] = '|'; //Could not get ASCII values correct for mac
                         }
                     grid[8][5] = 's'; //Could not display ASCII characters for snake and ladders on mac
                     grid[7][6] = 's';
                     grid[6][7] = 's';
                     grid[5][8] = 's';
                     grid[4][9] = 's';
                                    
                     grid[position/10][position%10] = '1'; //Value of i will be position/10 and value of j will be the remainder when position/10
                     grid[position2/10][position2%10] = '2';
                                    
                     printf("%c ", grid[i][j]);
                 }
                 printf("\n");
             }
            
        }
        else if (playerTurn == 2){
            numRolls2++;
            printf("Player2 rolled a %d\nPlayer1 Rolls : %d   Player2 Rolls : %d \n",diceRoll,numRolls1,numRolls2);
            position2 = position2 + diceRoll;
            if (position2 == 85){
                position2 = 49;
                printf("You landed on a snake down you go to position 49\n");
            }
            else if(position2 == 33){
                position2 = 73;
                printf("You landed on a ladder up you go to position 73");
            }
            else if(position2 >= 100){
                printf("Congratulations Player 2 you have won the game\n");
                gameRunning = 0;
            }
            else{
            printf("Player one is on position %d\n",position);
            }
            char grid[10][10];
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 10; j++) {
                    grid[i][j] = 46;
                        for (k=3;k<8;k++){
                            grid[k][3] = 124;
                        }
                    grid[8][5] = 's'; //Could not display ASCII characters for snake and ladders on mac
                    grid[7][6] = 's';
                    grid[6][7] = 's';
                    grid[5][8] = 's';
                    grid[4][9] = 's';
                                   
                    grid[position/10][position%10] = '1';
                    grid[position2/10][position2%10] = '2';
                                   
                    printf("%c ", grid[i][j]);
                }
                printf("\n");
            }
        
        }
        else{
            printf("PLease enter a valid player number \n");
            }
    }
    
    return 0;
}
                       
