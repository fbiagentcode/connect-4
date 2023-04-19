//c4
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

char c4[6][7];
char winner;

void resetBoard()
{
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
            c4[i][j] = ' ';
        }
    }
    printf("\n\n\n---------------------");
    //displaying the board
    for(int i = 0; i<6; i++)
    {
        printf("\n");
        for(int j = 0; j<7; j++)
        {
            printf("%c |", c4[i][j]);
        }
        printf("\n---------------------");
    }
}

bool spaceEmpty(int row, int col)
{
    if (c4[row][col] == ' ') return true;
    else return false;
}

int spacesLeft()
{
    int spaces_left = 42;
    for (int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
            if (c4[i][j] != ' ')
            spaces_left--;
        }
    }
    return spaces_left;
}

void fillBoard(int row, int col, char symbol)
{
    c4[row][col] = symbol;
    printf("\n\n\n---------------------");
    for(int i  = 0; i<6; i++)
    {
        printf("\n");
        for(int j = 0; j<7; j++)
        {
            printf("%c |", c4[i][j]);
        }
        printf("\n---------------------");
    }
}

bool validMove(int row, int col)
{
    bool proceed = true;
    int j = col;
    //int i = 6 - row;
    for(int x = row + 1; x<=5; x++)
    {
        if (c4[x][j] == ' ')
        {
            proceed = false;
            break;
        }
    }
    return proceed;
}



void playerMove(char player, bool (*space_empty)(int row, int col), void (*fillBoard)(int, int, char), bool(*valid_or_not)(int r, int c))
{
    
    int row, col;
    do
    {
    
    printf("\n\nEnter row to fill!\n");
    scanf("%d", &row);
    row = 6 - row;
    printf("Enter column to fill!\n");
    scanf("%d", &col);
    col--;
        if (spaceEmpty(row, col) && validMove(row, col) && !(row>6) && !(row<1) && !(col<0) && !(col>6))
        {
            fillBoard(row, col, player);
            break;
        }
        else
        printf("Please enter valid inputs.\n");
    }while(!spaceEmpty(row, col) || !validMove(row, col));
}

void compMove(char comp, bool (*is_empty)(int r, int c), bool (*validMove)(int r, int c), void (*makeMove)(int r, int c, char s))
{
    int row, col;
    do
    {
    row = rand() % 6;
    row = 6 - row;
    col = rand() % 7;
        if (spaceEmpty(row, col) && validMove(row, col))
        {
            fillBoard(row, col, comp);
            break;
        }
        
    }while(!spaceEmpty(row, col) || !validMove(row, col));
}

char gameWinner()
{
    //for each row
    for(int i = 0; i<6; i++)
    {
       
            if (c4[i][0] != ' ' && c4[i][0] == c4[i][1] && c4[i][0] == c4[i][2] && c4[i][0] == c4[i][3])
            return c4[i][0];
            else if (c4[i][1] != ' ' && c4[i][1] == c4[i][2] && c4[i][1] == c4[i][3] && c4[i][1] == c4[i][4])
            return c4[i][1];
            else if(c4[i][2] != ' ' && c4[i][2] == c4[i][3] && c4[i][2] == c4[i][4] && c4[i][2] == c4[i][5])
            return c4[i][2];
            else if(c4[i][3] != ' ' && c4[i][3] == c4[i][4] && c4[i][3] == c4[i][5] && c4[i][3] == c4[i][6])
            return c4[i][3];
    }

    //for each column
    for(int i = 0; i<7; i++)
    {
        if (c4[0][i] != ' ' && c4[0][i] == c4[1][i] && c4[0][i] == c4[2][i] && c4[0][i] == c4[3][i])
        return c4[0][i];
        else if (c4[1][i] != ' ' && c4[1][i] == c4[2][i] && c4[1][i] == c4[3][i] && c4[1][i] == c4[4][i])
        return c4[1][i];
        else if (c4[2][i] != ' ' && c4[2][i] == c4[3][i] && c4[2][i] == c4[4][i] && c4[2][i] == c4[5][i])
        return c4[2][i];
    }

    //for each diagonal (from top left)
    
    if (c4[0][3] != ' ' && c4[0][3] == c4[1][2] && c4[0][3] == c4[2][1] && c4[0][3] == c4[3][0])
    return c4[0][3];
    
    else if(c4[0][4] != ' ' && c4[0][4] == c4[1][3] && c4[0][4] == c4[2][2] && c4[0][4] == c4[3][1])
    return c4[0][4];
    else if(c4[1][3] != ' ' && c4[1][3] == c4[2][2] && c4[1][3] == c4[3][1] && c4[1][3] == c4[4][0])
    return c4[1][3];
   
    else if(c4[0][5] != ' ' && c4[0][5] == c4[1][4] && c4[0][5] == c4[2][3] && c4[0][5] == c4[3][2])
    return c4[0][5];
    else if(c4[1][4] != ' ' && c4[1][4] == c4[2][3] && c4[1][4] == c4[3][2] && c4[1][4] == c4[4][1])
    return c4[1][4];
    else if(c4[2][3] != ' ' && c4[2][3] == c4[3][2] && c4[2][3] == c4[4][1] && c4[2][3] == c4[5][0])
    return c4[2][3];

    else if(c4[0][6] != ' ' && c4[0][6] == c4[1][5] && c4[0][6] == c4[2][4] && c4[0][6] == c4[3][3])
    return c4[0][6];
    else if(c4[1][5] != ' ' && c4[1][5] == c4[2][4] && c4[1][5] == c4[3][3] && c4[1][5] == c4[4][2])
    return c4[1][5];
    else if(c4[2][4] != ' ' && c4[2][4] == c4[3][3] && c4[2][4] == c4[4][2] && c4[2][4] == c4[5][1])
    return c4[2][4];
    
    else if(c4[1][6] != ' ' && c4[1][6] == c4[2][5] && c4[1][6] == c4[3][4] && c4[1][6] == c4[4][3])
    return c4[1][6];
    else if(c4[2][5] != ' ' && c4[2][5] == c4[3][4] && c4[2][5] == c4[4][3] && c4[2][5] == c4[5][2])
    return c4[2][5];

    else if(c4[2][6] != ' ' && c4[2][6] == c4[3][5] && c4[2][6] == c4[4][4] && c4[2][6] == c4[5][3])
    return c4[2][6];

    
    //top right
    else if(c4[0][3] != ' ' && c4[0][3] == c4[1][4] && c4[0][3] == c4[2][5] && c4[0][3] == c4[3][6])
    return c4[0][3];

    else if(c4[0][2] != ' ' && c4[0][2] == c4[1][3] && c4[0][2] == c4[2][4] && c4[0][2] == c4[3][5])
    return c4[0][2];
    else if(c4[1][3] != ' ' && c4[1][3] == c4[2][4] && c4[1][3] == c4[3][5] && c4[1][3] == c4[4][6])
    return c4[1][3];
    
    else if(c4[0][1] != ' ' && c4[0][1] == c4[1][2] && c4[0][1] == c4[2][3] && c4[0][1] == c4[3][4])
    return c4[0][1];
    else if(c4[1][2] != ' ' && c4[1][2] == c4[2][3] && c4[1][2] == c4[3][4] && c4[1][2] == c4[4][5])
    return c4[1][2];
    else if(c4[2][3] != ' ' && c4[2][3] == c4[3][4] && c4[2][3] == c4[4][5] && c4[2][3] == c4[5][6])
    return c4[2][3];

    else if (c4[0][0] != ' ' && c4[0][0] == c4[1][1] && c4[0][0] == c4[2][2] && c4[0][0] == c4[3][3])
    return c4[0][0];
    else if(c4[1][1] != ' ' && c4[1][1] == c4[2][2] && c4[1][1] == c4[3][3] && c4[1][1] == c4[4][4])
    return c4[1][1];
    else if(c4[2][2] != ' ' && c4[2][2] == c4[3][3] && c4[2][2] == c4[4][4] && c4[2][2] == c4[5][5])
    return c4[2][2];

    else if(c4[1][0] != ' ' && c4[1][0] == c4[2][1] && c4[1][0] == c4[3][2] && c4[1][0] == c4[4][3])
    return c4[1][0];
    else if(c4[2][1] != ' ' && c4[2][1] == c4[3][2] && c4[2][1] == c4[4][3] && c4[2][1] == c4[5][4])
    return c4[2][1];

    else if(c4[2][0] != ' ' && c4[2][0] == c4[3][1] && c4[2][0] == c4[4][2] && c4[2][0] == c4[5][3])
    return c4[2][0];

    else
    
    return ' ';
    


}

int main()
{
    char playerSymbol, compSymbol, playAgain;

    int pWinCounter = 0, cWinCounter = 0;
    
    do
    {
        printf("\nPICK A SYMBOL TO PLAY AS -> O OR X: ");
        scanf(" %c", &playerSymbol);
        playerSymbol = toupper(playerSymbol);

        if(playerSymbol == 'X') compSymbol = 'O';
        else if(playerSymbol == 'O') compSymbol = 'X';

        if (playerSymbol != 'O' && playerSymbol != 'X')
        printf("\nPLEASE DO NOT BE AN IDIOT.");

    }while(playerSymbol != 'O' && playerSymbol != 'X');

    srand(time(0));
    
    do
    {
            int roundWinner = ' ';
            resetBoard();
            while(roundWinner == ' ' && spacesLeft() != 0)
            {   
                playerMove(playerSymbol, spaceEmpty, fillBoard, validMove);

                roundWinner = gameWinner();
                compMove(compSymbol, spaceEmpty, validMove, fillBoard);
                
                roundWinner = gameWinner();
                
                
            }

        if (roundWinner == playerSymbol)
        {
        printf("\nYOU WIN!");
        pWinCounter++;
        }
        else if(roundWinner == compSymbol)
        {
            cWinCounter++;
            printf("\nYOU LOSE!");
        }
        else printf("\n IT\'S A TIE!");
        printf("\nDO YOU WANT TO PLAY AGAIN? (Y) YES (N) NO: ");
        scanf(" %1c", &playAgain);
    }
    while(toupper(playAgain) == 'Y');


    printf("\nYOU WON %d TIMES.", pWinCounter);
    printf("\nYOU LOST %d TIMES.", cWinCounter);
    printf("\nTHANKS FOR PLAYING.");

}