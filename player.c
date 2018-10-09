#include "header.h"

//Jordan
void player(char *playerInput , int *numberOfPlay, int *Height, char arr[100][100],
			char *arrSaveAction, int *savePlace, int *Width, int *Highscores, int *restorePlace, int *gameOut,
			char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace) //this got really long use our coding convention --- AJAI
{
    int row; 
    int flag = 0; 
    int convert;
	char numberOfCol;

    convert = atoi(playerInput);

    if (convert == 0)
    {
        numberOfCol = 0;
    }
    else
    {
        numberOfCol = convert;//this is bad because it screws with the values of th Undo call below
    }

    if(numberOfCol > 0 && numberOfCol <= *Width)
    {
        
    }
    else if (playerInput[0] == 'U')
    {
        Undo(savePlace, restorePlace, Height, Width, numberOfPlay, scoreOne, scoreTwo, Highscores, gameOut, whichPlayer, arrSaveAction, arrRestorePlace, playerInput, arr);
        flag = 1;
    }
    else if (playerInput[0] == 'R')
    {
        Redo(restorePlace, Height, Width, numberOfPlay, scoreOne, scoreTwo, gameOut, Highscores, savePlace, whichPlayer, playerInput, arrRestorePlace, arr, arrSaveAction);
        flag = 1;
    }
    else if(playerInput[0] == 'S')
    {
        saveGame(Width, Height, Highscores, numberOfPlay, scoreOne, scoreTwo, gameOut, whichPlayer, savePlace, restorePlace, arr, arrSaveAction, arrRestorePlace, playerInput);
        flag = 1;
    }
    else
    {
        flag = 2;
    }

    for(row = 0 ; row < *Height && flag == 0; row++)
    {
if(arr[*Height-row-1][numberOfCol-1]== 'X' || arr[*Height-row-1][numberOfCol-1] == 'O')
        {
           
        }
        else
        {
            if (row < *Height)
            {
                *restorePlace = 0;
                if (*numberOfPlay % 2 != 0)
                {
                    arr[*Height-row-1][numberOfCol -1] = 'X';
                    arrSaveAction[*savePlace] = (numberOfCol- 1);
                    *savePlace += 1;
                    updateScore(*Height-row-1 , numberOfCol - 1, Width, Height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr);
                }
                else
                {
                    if (whichPlayer == 'H')
                    {
                        arr[*Height-row-1][numberOfCol - 1] = 'O';
                        arrSaveAction[*savePlace] = (numberOfCol- 1);
                        *savePlace += 1;
                        updateScore(*Height-row-1 , numberOfCol - 1, Width, Height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr);
                    }
                    else
                    {
                        computerPlayer(arr, Height, Width, restorePlace, arrSaveAction, savePlace, scoreOne, scoreTwo, numberOfPlay, playerInput);
                    }
                }

				
                PrintArrayValue(Height, Width, scoreOne, scoreTwo, arr);
                flag = 1;
            }
        }
    }
    if (flag == 0 || flag == 2) //if flag = this mean row "counter" is bigger than *Height <<all the row is fulled
    {
        playAgain(playerInput , numberOfPlay, Height, arr, arrSaveAction, savePlace, Width, Highscores, restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace); 
    }
}