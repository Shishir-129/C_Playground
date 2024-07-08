#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // 3x3 Tic Tac Toe board

// Function to initialize the board with empty spaces
void initializeBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the game is over
int isGameOver()
{
    // Check rows, columns, and diagonals for a win
    for(int i = 0; i < 3; i++)
      {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
          {
            return 1; // Win in row
          }
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
          {
            return 1; // Win in column
          }
      }
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
          {
        return 1; // Win in top-left to bottom-right diagonal (\)
          }
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
          {
        return 1; // Win in top-right to bottom-left diagonal (/)
          }

    // Check if board is full (tie)
    for(int i = 0; i < 3; i++)       //If gameOver is 0, it means the game is not over yet.
      {                              //If gameOver is 1, it means someone has won the game.
        for(int j = 0; j < 3; j++)   //If gameOver is -1, it means the game is a tie.
          {
            if(board[i][j] == ' ')
            {
                return 0; // Game is not over yet
            }
          }
       }
    return -1; // Game is a tie
}

// Function to get player's move
void getPlayerMove(int *row, int *col)
{
    printf("Enter row and column (1-3) to place your mark (e.g: 1 2) :: ");
    scanf("%d %d",row,col);
    (*row)--;  //Here if 3,1 is entered by user it makes 2,0 while processing
    (*col)--;  //because we have initialized from 0 till 2 (value of board[i][j])
}

// Function to make a move
void makeMove(int row, int col, char mark)
{
    if(board[row][col] == ' ')
        {
        board[row][col] = mark;  //this checks whether that place is empty or already occupied, if empty then put the value
        }
    else
        {
        printf("Invalid move! Try again.\n"); //if that place is occupied previously then display invalid, overlapping is not allowed
        getPlayerMove(&row, &col);
        makeMove(row, col, mark);
        }
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    int gameOver = 0;

    initializeBoard();

    printf("Welcome to Tic Tac Toe!\n");

    while(!gameOver) //if gameover's value is not equal to 0 i.e 1 or -1 , the loop will continue
    {                 // but if it is equal to 0 , then loop will not continue. In general gameover's value should be different than initial value
        displayBoard();
        printf("Player %c's turn.\n", currentPlayer);
        getPlayerMove(&row, &col);
        makeMove(row, col, currentPlayer);

        gameOver = isGameOver();

        if(gameOver == 1)
            {
            displayBoard();
            printf("Player %c wins!\n", currentPlayer);
            }
        else if(gameOver == -1)
            {
            displayBoard();
            printf("It's a tie!\n");
            }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; //if condition true then switch to 'O' else switch to 'X'
     }

    return 0;
}
