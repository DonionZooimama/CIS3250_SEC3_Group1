#include "header.h"

//Wil
void computerPlayer(char arr[100][100], int *Height, int *Width, int *restorePlace, char *arrSaveAction, int *savePlace, int *scoreOne, int *scoreTwo)
{
    int row , randomPlay ; 
    int flag = 0; 

    while (flag == 0)
    {
        randomPlay = rand() % (*Width) ;

        for(row = 0 ; row < *Height && flag == 0; row++)
        {

            if(arr[*Height-row-1][randomPlay]== 'X' || arr[*Height-row-1][randomPlay] == 'O')
            {
               
            }

    else
            {
                if (row < *Height)
                {
                    *restorePlace = 0;
                    arr[*Height-row-1][randomPlay] = 'O';
                    arrSaveAction[*savePlace] = (randomPlay);
                    *savePlace += 1;
                    updateScore(*Height-row-1 , randomPlay);
                    system("cls");
                    PrintArrayValue(Height, Width, scoreOne, scoreTwo, arr);
                    flag = 1;
                }
            }
        }
    }
}