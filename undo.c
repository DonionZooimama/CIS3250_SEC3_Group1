#include "header.h"

//Wil
void Undo(int *savePlace, int *restorePlace, int *Height, int *Width, int *numberOfPlay, int *scoreOne, int *scoreTwo,
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
                updateScore(counter , noOfCol, Width, Height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr);
                arr[counter][noOfCol] = '-';

                flag = 1;
            }
        }
    }

    system("cls");
    PrintArrayValue(Height, Width, scoreOne, scoreTwo, arr);

    if (*numberOfPlay % 2 == 0)
    {
        if (whichPlayer == 'H')
        {
            printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`",INTENSITY);
            printf("\tplayer2<<Enter your play>> = ",BLUE);
            scanf("%s",playerInput);
            player(playerInput , *numberOfPlay, Height, arr, arrSaveAction, savePlace, Width, restorePlace, whichPlayer, scoreOne, scoreTwo, arrRestorePlace);
        }
        else
        {
            computerPlayer(arr, Height, Width, restorePlace, arrSaveAction, savePlace, scoreOne, scoreTwo);
        }
    }
    else
    {
        printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8",INTENSITY);
        printf("\t player1<<Enter your play>> = ",GREEN);
        scanf("%s",playerInput);
        player(playerInput , *numberOfPlay, Height, arr, arrSaveAction, savePlace, Width, restorePlace, whichPlayer, scoreOne, scoreTwo, arrRestorePlace);
    }
} 
