#include "header.h"

//Wil
void computerPlayer()
{
    int row , randomPlay ; 
    int flag = 0; 

    while (flag == 0)
    {
        randomPlay = rand() % (Width) ;

        for(row = 0 ; row < Height && flag == 0; row++)
        {

            if(arr[Height-row-1][randomPlay]== 'X' || arr[Height-row-1][randomPlay] == 'O')
            {
               
            }

    else
            {
                if (row < Height)
                {
                    restorePlace = 0;
                    arr[Height-row-1][randomPlay] = 'O';
                    arrSaveAction[savePlace] = (randomPlay);
                    savePlace++;
                    updateScore(Height-row-1 , randomPlay);
                    system("cls");
                    PrintArrayValue(Height,Width);
                    flag = 1;
                }
            }
        }
    }
}