#include "header.h"

//Wil
void Undo(int *savePlace, int *restorePlace, int *Height, int *Width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *Highscores, int *gameOut,
		  char whichPlayer, char *arrSaveAction, char *arrRestorePlace, char *playerInput, char arr[100][100])
{
    int counter = 0 , flag = 0 , noOfCol;

    if (*savePlace == 0)
    {
       
    }
    else
    {
        *savePlace -= 1;
        noOfCol = arrSaveAction[*savePlace] ;
        arrRestorePlace[*restorePlace] = noOfCol ;
        *restorePlace += 1;

        for (counter = 0 ; counter < *Height && flag == 0 ; counter++)
        {
            if (arr[counter][noOfCol] == 'X' ||  arr[counter][noOfCol] == 'O')
            {
                *numberOfPlay -= 1;
                UpdateScore(counter , noOfCol, Width, Height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr);
                arr[counter][noOfCol] = '-';

                flag = 1;
            }
        }
    }

    PrintArrayValue(Height, Width, scoreOne, scoreTwo, arr);

    if (*numberOfPlay % 2 == 0)
    {
        if (whichPlayer == 'H')
        {
            printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`");
            printf("\tplayer2<<Enter your play>> = ");
            scanf("%s",playerInput);
            Player(playerInput , numberOfPlay, Height, arr, arrSaveAction, savePlace, Width, Highscores, restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace);
        }
        else
        {
            ComputerPlayer(arr, Height, Width, restorePlace, arrSaveAction, savePlace, scoreOne, scoreTwo, numberOfPlay, playerInput);
        }
    }
    else
    {
        printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8");
        printf("\t player1<<Enter your play>> = ");
        scanf("%s",playerInput);
        Player(playerInput , numberOfPlay, Height, arr, arrSaveAction, savePlace, Width, Highscores, restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace);
    }
} 
