#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/***********************************************************************
create the game board using a 1-dimensional array
variable choice(for where they enter x or 0) and player
write a function to check winner
write function to draw board
write a function to mark board
***********************************************************************/

char  square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;
char newName[];
char newName2[];

int checkWin();
void displayBoard();
void markBoard(char mark);
int changeName();



int main()
{
    player = 1;

    int gameStatus; //gamestatus will be the returnValue to check the game

    char mark;


    printf("Player 1, Enter your Name: ");
        scanf("%s", newName);


    printf("Player 2, Enter your Name: ");
        scanf("%s", newName2);
    do
    {
        displayBoard();

        // change player turns
        player = (player % 2) ? 1 : 2;


        //get input
        printf(" Player %d, Enter a number: ", player);
        scanf("%d", &choice);

        //give players respective characters
        mark = (player == 1) ? 'X' : 'O';

        markBoard(mark);

        gameStatus = checkWin();

        player++;

    }while(gameStatus == -1);

    if(gameStatus == 1)
        printf ("==>\aPlayer %d WINS!!  <==", --player);
    else
        printf("==>\a DRAWWWWWW!!<==");
    return 0;
}

/************************************************
Return:
1 If game is over with a winner
-1 If game  is still in progress
0 If game is over with a draw
************************************************/

int checkWin()
{
    int returnValue = 0;
    if (square[1] ==  square [2] && square [2] == square [3])
    {
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square [4] != '4' &&
            square [5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

            returnValue = 0;
    else
        returnValue = -1;

    return returnValue;

}


void displayBoard()
{
    system("cls");

    printf("\n\n Tic - Tac - Toe\n\n");


    printf ("%s (X) - %s (O)\n\n\n", newName, newName2);

    printf("        |        |        \n");
    printf("    %c   |    %c   |  %c    \n", square[1], square[2], square[3]);

    printf("________|________|________\n");
    printf("        |        |        \n");

    printf("    %c   |    %c   |  %c    \n",square[4], square[5], square[6]);

    printf("________|________|________\n");
    printf("        |        |        \n");

    printf("    %c   |    %c   |  %c    \n",square[7], square[8], square[9]);

    printf("        |        |        \n");

}


/********************************
Input character X or O in the
correct spot in the array
********************************/

void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square [1] = mark;

    else if (choice == 2 && square[2] == '2')
        square [2] = mark;
    else if (choice == 3 && square[3] == '3')
        square [3] = mark;
    else if (choice == 4 && square[4] == '4')
        square [4] = mark;
    else if (choice == 5 && square[5] == '5')
        square [5] = mark;
    else if (choice == 6 && square[6] == '6')
        square [6] = mark;
    else if (choice == 7 && square[7] == '7')
        square [7] = mark;
    else if (choice == 8 && square[8] == '8')
        square [8] = mark;
    else if (choice == 9 && square[9] == '9')
        square [9] = mark;

    else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
}

int changeName()
{

        printf("Player 1, Enter your Name: ", player);
        scanf("%s", newName);


        printf("Player 2, Enter your Name: ", player);
        scanf("%s", newName2);
}
