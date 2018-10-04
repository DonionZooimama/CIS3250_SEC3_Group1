#include "header.h"

//Just a note for you. This code makes no sense because he's using chars and comparing it with ints so im not gonna fix that.
//still creates errors in compilation but you will figure it out. --- AJAI

//Jordan
void player(char *numberOfCol , int *numberOfPlay, int *Height, char arr[100][100],
			char *arrSaveAction, int *savePlace, int *Width, int *restorePlace,
			char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace) //this got really long use our coding convention --- AJAI
{
    int row; 
    int flag = 0; 
    int convert;

    convert = atoi(numberOfCol);

    if (convert == 0)
    {
        *numberOfCol = 0;
    }
    else
    {
        *numberOfCol = convert;//this is bad because it screws with the values of th Undo call below
    }

    if(*numberOfCol > 0 && *numberOfCol <= *Width)
    {
        
    }
    else if (numberOfCol[0] == 'U')
    {
        Undo(savePlace, restorePlace, Height, Width, numberOfPlay, scoreOne, scoreTwo, whichPlayer, arrSaveAction, arrRestorePlace, numberOfCol, arr);
        flag = 1;
    }
    else if (numberOfCol[0] == 'R')
    {
        Redo(restorePlace, Height, Width, numberOfPlay, scoreOne, scoreTwo, savePlace, whichPlayer, numberOfCol, arrRestorePlace, arr, arrSaveAction);
        flag = 1;
    }
    else if(numberOfCol[0] == 'S')
    {
        saveGame();
        flag = 1;
    }
    else
    {
        flag = 2;
    }

    for(row = 0 ; row < *Height && flag == 0; row++)
    {
if(arr[*Height-row-1][*numberOfCol-1]== 'X' || arr[*Height-row-1][*numberOfCol-1] == 'O')
        {
           
        }
        else
        {
            if (row < *Height)
            {
                *restorePlace = 0;
                if (*numberOfPlay % 2 != 0)
                {
                    arr[*Height-row-1][*numberOfCol -1] = 'X';
                    arrSaveAction[*savePlace] = (*numberOfCol- 1);
                    *savePlace += 1;
                    updateScore(*Height-row-1 , *numberOfCol - 1, Width, Height, numberOfPlay, scoreOne, scoreTwo, numberOfCol, arr);
                }
                else
                {
                    if (whichPlayer == 'H')
                    {
                        arr[*Height-row-1][*numberOfCol - 1] = 'O';
                        arrSaveAction[*savePlace] = (*numberOfCol- 1);
                        *savePlace += 1;
                        updateScore(*Height-row-1 , *numberOfCol - 1, Width, Height, numberOfPlay, scoreOne, scoreTwo, numberOfCol, arr);
                    }
                    else
                    {
                        computerPlayer(arr, Height, Width, restorePlace, arrSaveAction, savePlace, scoreOne, scoreTwo);
                    }
                }

                system("cls");
                PrintArrayValue(Height, Width, scoreOne, scoreTwo, arr);
                flag = 1;
            }
        }
    }
    if (flag == 0 || flag == 2) //if flag = this mean row "counter" is bigger than *Height <<all the row is fulled
    {
        playAgain(); 
    }
}