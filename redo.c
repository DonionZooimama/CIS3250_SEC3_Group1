#include "header.h"

//Ajai
void Redo()
{
    int counter = 0 , flag = 0 , noOfCol;

    if (restorePlace == 0)
    {
        
    }
    else
    {
        restorePlace--;
        noOfCol = arrRestorePlace[restorePlace];
        savePlace++;
        for (counter = 0 ; counter < Height && flag == 0 ; counter++)
        {
            if (arr[Height-counter-1][noOfCol] == '-')
            {
                if (numberOfPlay % 2 != 0)
                {
                    arr[Height-counter-1][noOfCol] = 'X';
                }
                else
                {
                    arr[Height-counter-1][noOfCol] = 'O';
                }
                flag = 1;
            }
        }
        updateScore(Height-counter , noOfCol);
        numberOfPlay++;
    }
    system("cls");
    PrintArrayValue(Height,Width);
    if (numberOfPlay % 2 == 0)
    {
        printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`",INTENSITY);
        printf("\tplayer2<<Enter your play>> = ",BLUE);
        scanf("%s",playerInput);
        player( playerInput , numberOfPlay);
    }
    else
    {
        printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8",INTENSITY);
        printf("\t player1<<Enter your play>> = ",GREEN);
        scanf("%s",playerInput);
        player(playerInput , numberOfPlay);
    }
} 