//tictactoe.cc – DO alter this file.  
//Add your functions above runGame().
//NOTE that I have commented out the functions so it will compile.  You
//MUST uncomment these as you complete them for the game to work and for
//testing.

#include <stdio.h>
#include "tictactoe.h"

void clearBoard(gameData_t *gameData)
{
  int i = 0;
  int j = 0;
  //loops through clearing each space on the board
  while(i < ROWS)
  {
    while(j < COLS)
    {
      gameData -> board[i][j] = ' ';
      j++;
    }
    i++;
    j = 0;
  }
}

void getPlayerInfo(gameData_t *gameData)
{
 printf("Player 1 enter your name: ");// prompts player 1 for their name
 scanf("%s", gameData->name1);//keyboard scanf to set name1

 printf("Player 1 enter your age: ");// prompts player 1 for their age
 scanf("%d",&gameData->age1);//keyboard scanf to set age1

 printf("\n");

 printf("Player 2 enter your name: ");// prompts player 2 for their name
 scanf("%s", gameData->name2);//keyboard scanf to set name2

 printf("Player 2 enter your age: ");// prompts player 2 for their age
 scanf("%d", &gameData->age2);//keyboard scanf to set age2

 return;
}

void printPlayerInfo(gameData_t gameData)
{
  //player 1 data
  printf("Player 1 is %s age %d and will be Xs\n", gameData.name1, gameData.age1);
  //player 2 data
  printf("Player 2 is %s age %d and will be Os\n", gameData.name2, gameData.age2);

  return;

}

void printBoard(gameData_t gameData)
{
  printf("    C1  C2  C3\n");//column numbers
  printf("R1  %c | %c | %c \n", gameData.board[0][0], gameData.board[0][1], gameData.board[0][2]); // row 1
  printf("   -----------\n");
  printf("R2  %c | %c | %c \n", gameData.board[1][0], gameData.board[1][1], gameData.board[1][2]);// row 2
  printf("   -----------\n");
  printf("R3  %c | %c | %c \n", gameData.board[2][0], gameData.board[2][1], gameData.board[2][2]); // row 3

  return;
}

void printTurnHeader(gameData_t gameData, char turn)
{
  
  
  switch (turn)
  {
  case 'X':
    printf("--------------------------------------------------\n");
    printf("---------- %s's Turn --------------------\n", gameData.name1);
    printf("---------- You are Xs --------------------\n");
    printf("--------------------------------------------------\n");
    break;
  
  default:
    printf("--------------------------------------------------\n");
    printf("---------- %s's Turn --------------------\n", gameData.name2);
    printf("---------- You are Os --------------------\n");
    printf("--------------------------------------------------\n");
    break;
  }
  

  return;
}

void getMove(gameData_t *gameData, char turn)
{

  if(turn == 'X')
  {
    printf("%s, please enter your move in the form RXCY: ", gameData->name1);
  }
  else
  {
    printf("%s, please enter your move in the form RXCY: ", gameData->name2);
  }

  int validMove = 0;
  char move[5];
  scanf("%4s", move);

  while (validMove != 1)
  {
    // checks for input in the right form
   if ((move[0] != 'r' && move[0] != 'R') || (move[2] != 'C' && move[2] != 'c'))
   {
    printf("Results must be in the form RxCy. Try again: ");
    scanf("%4s", move);
   }
   // checks if row and column are in the correct range.
   else if ((move[1] < 49 || move[1] > 51) || (move[3] < 49 || move[3] > 51))
   {
    printf("Row and column must be in the range 1 to 3. Try again: ");
    scanf("%4s", move);
   }
   //checks if space is taken
   else if ((gameData->board[move[1]-49][move[3]-49] == 'X') || (gameData->board[move[1]-49][move[3]-49] == 'O'))
   {
    printf("That space is taken.  Try again: ");
    scanf("%4s", move);
   }
   //places move
   else
   {
    gameData->board[move[1] - 49][move[3] - 49] = turn;
    validMove = 1;
   }
   
  }

    
}

int checkWin(gameData_t gameData, char turn)
{
  int win = 0;
  if(gameData.board[0][0] == turn && gameData.board[0][1] == turn && gameData.board[0][2] == turn) // first row across
  {
    win = 1;
  }
  else if (gameData.board[1][0] == turn && gameData.board[1][1] == turn && gameData.board[1][2] == turn)// second row across
  {
    win = 1;
  }
  else if (gameData.board[2][0] == turn && gameData.board[2][1] == turn && gameData.board[2][2] == turn)// third row across
  {
    win = 1;
  }
  else if (gameData.board[0][0] == turn && gameData.board[1][0] == turn && gameData.board[2][0] == turn) // first column
  {
    win = 1;
  }
  else if (gameData.board[0][1] == turn && gameData.board[1][1] == turn && gameData.board[2][1] == turn) // second column
  {
    win = 1;
  }
  else if (gameData.board[0][2] == turn && gameData.board[1][2] == turn && gameData.board[2][2] == turn)//third column
  {
    win = 1;
  }
  else if (gameData.board[0][0] == turn && gameData.board[1][1] == turn && gameData.board[2][2] == turn)// diagonal 
  {
    win = 1;
  }
  else if (gameData.board[2][0] == turn && gameData.board[1][1] == turn && gameData.board[0][2] == turn)// diagonal
  {
    win = 1;
  }
  
  return win;
}

int checkTie(gameData_t gameData)
{
  int tie = 0;
  int i = 0;
  int j = 0;
  int fullSpace = 0;
  //full space counts up to make sure the board doesn't have any free spaces
  while (i < 3)
  {
    while (j < 3)
    {
      if(gameData.board[i][j] == 'X' || gameData.board[i][j] == 'O')
      {
        fullSpace++;
      }
      j++;
    }
    i++;
    j = 0;
  }
  //printf("%d\n", fullSpace);
  if (fullSpace == 9)
  {
    tie = 1;
  }
  return tie;
}

void runGame() {
  
  gameData_t gameData;
  
  int win = 0;
  int tie = 0;  
  char turn = 'X';
  
  //Set board to all spaces.
  clearBoard(&gameData);
  
  //Get both players name and age
  getPlayerInfo(&gameData);
  
  //Show the player info1
  printf("\n");
  printPlayerInfo(gameData);
  printf("\n");
  
  //printTurnHeader(gameData, turn); 
  //printBoard(gameData);
  while (!win && !tie) {
    
    
    printTurnHeader(gameData, turn); 
    printBoard(gameData);
    getMove(&gameData, turn);    
    
    //Check for win
    win = checkWin(gameData, turn);        
    if (win == 1) {
      printf("--------------------------------------------------\n");      
      if (turn == 'X') {        
        printf("---------- %s WINS! --------------------\n", gameData.name1);
      } else {        
        printf("---------- %s WINS! --------------------\n", gameData.name2);
      }
      printf("--------------------------------------------------\n");      
      printBoard(gameData);
      printf("\n");
    } else {
      tie = checkTie(gameData);        
      if (tie == 1) {
        printf("--------------------------------------------------\n");      
        printf("---------- TIE GAME! --------------------\n");
        printf("--------------------------------------------------\n");      
        printBoard(gameData);
      }
    }
    
    //Toggle turn so other player goes next.
    if (turn == 'X') turn = 'O';
    else turn = 'X';
  }
}









