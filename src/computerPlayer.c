#include "header.h"

//Wil
void ComputerPlayer(char arr[100][100], int *height, int *width, int *restorePlace, char *arrSaveAction, int *savePlace, int *scoreOne, int *scoreTwo, int *numberOfPlay,
					char *playerInput)
{
    int row , randomPlay ; 
    int flag = 0; 

    while (flag == 0)
    {
        randomPlay = rand() % (*width) ;

        for(row = 0 ; row < *height && flag == 0; row++)
        {

            if(arr[*height-row-1][randomPlay]== 'X' || arr[*height-row-1][randomPlay] == 'O')
            {
               
            }

    else
            {
                if (row < *height)
                {
                    *restorePlace = 0;
                    arr[*height-row-1][randomPlay] = 'O';
                    arrSaveAction[*savePlace] = (randomPlay);
                    *savePlace += 1;
                    UpdateScore(*height-row-1 , randomPlay, width, height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr);
                    //system("cls");
                    PrintArrayValue(height, width, scoreOne, scoreTwo, arr);
                    flag = 1;
                }
            }
        }
    }
}