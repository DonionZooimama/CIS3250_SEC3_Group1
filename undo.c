#inlude "header.h"

//Wil
void Undo()
{
    int counter = 0 , flag = 0 , noOfCol;

    if (savePlace == 0)
    {
       
    }
    else
    {
        savePlace--;
        noOfCol = arrSaveAction[savePlace] ;
        arrRestorePlace[restorePlace] = noOfCol ;
        restorePlace++;

        for (counter = 0 ; counter < Height && flag == 0 ; counter++)
        {
            if (arr[counter][noOfCol] == 'X' ||  arr[counter][noOfCol] == 'O')
            {
                numberOfPlay--;
                updateScore(counter , noOfCol);
                arr[counter][noOfCol] = '-';

                flag = 1;
            }
        }
    }

    system("cls");
    PrintArrayValue(Height,Width);

    if (numberOfPlay % 2 == 0)
    {
        if (whichPlayer == 'H')
        {
            printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`",INTENSITY);
            printf("\tplayer2<<Enter your play>> = ",BLUE);
            scanf("%s",playerInput);
            player( playerInput , numberOfPlay);
        }
        else
        {
            computerPlayer();
        }
    }
    else
    {
        printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8",INTENSITY);
        printf("\t player1<<Enter your play>> = ",GREEN);
        scanf("%s",playerInput);
        player(playerInput , numberOfPlay);
    }
} 
