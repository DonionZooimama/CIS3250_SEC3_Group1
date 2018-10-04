#include "header.h"

//Jordan
void player(char numberOfCol , int numberOfPlay) 
{
    int row; 
    int flag = 0 , counter ; 
    int convert;

    convert = atoi(playerInput);

    if (convert == 0)
    {
        numberOfCol = 0;
    }
    else
    {
        numberOfCol = convert;
    }

    if(numberOfCol > 0 && numberOfCol <= Width)
    {
        
    }
    else if (playerInput[0] == 'U')
    {
        Undo();
        flag = 1;
    }
    else if (playerInput[0] == 'R')
    {
        Redo();
        flag = 1;
    }
    else if(playerInput[0] == 'S')
    {
        saveGame();
        flag = 1;
    }
    else
    {
        flag = 2;
    }

    for(row = 0 ; row < Height && flag == 0; row++)
    {
if(arr[Height-row-1][numberOfCol-1]== 'X' || arr[Height-row-1][numberOfCol-1] == 'O')
        {
           
        }
        else
        {
            if (row < Height)
            {
                restorePlace = 0;
                if (numberOfPlay % 2 != 0)
                {
                    arr[Height-row-1][numberOfCol -1] = 'X';
                    arrSaveAction[savePlace] = (numberOfCol- 1);
                    savePlace++;
                    updateScore(Height-row-1 , numberOfCol - 1);
                }
                else
                {
                    if (whichPlayer == 'H')
                    {
                        arr[Height-row-1][numberOfCol - 1] = 'O';
                        arrSaveAction[savePlace] = (numberOfCol- 1);
                        savePlace++;
                        updateScore(Height-row-1 , numberOfCol - 1);
                    }
                    else
                    {
                        computerPlayer();
                    }
                }

                system("cls");
                PrintArrayValue(Height,Width);
                flag = 1;
            }
        }
    }
    if (flag == 0 || flag == 2) //if flag = this mean row "counter" is bigger than Height <<all the row is fulled
    {
        playAgain();
    }
}