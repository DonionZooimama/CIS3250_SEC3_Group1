#include "header.h"

//Ajai
void loadGame(int *Width, int *Height, int *Highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *whichPlayer,
			  int *savePlace, int *restorePlace, char arr[100][100])
{
    int counter , counter1  , flag = 0 ,counterX = 0 , counterO = 0;
    FILE *file = fopen("saveGame.txt" , "r");
    if ( file == NULL )
    {
        flag = 1;
    }
    else
    {
        fscanf(file,"%d %d %d %d",Width,Height,Highscores,numberOfPlay);
        fscanf(file,"%d %d",scoreOne,scoreTwo);
        fscanf(file,"%s",whichPlayer);

        for(counter = 0; counter < *Height ; counter++)
        {
            for(counter1 = 0; counter1 < *Width ; counter1++)
            {
                fscanf(file," %c ",&arr[counter][counter1]);
                if (arr[counter][counter1] == 'X')
                {
                    counterX++;
                }
                else if (arr[counter][counter1] == 'O')
                {
                    counterO++;
                }
            }
        }
    }
    fclose(file);
    if (*Width < 3 || *Width > 12 || *Height < 3 || *Height > 12)
    {
        flag = 1;
    }
    if ( *numberOfPlay % 2 == 0 && (counterX-1 != counterO || counterX*2 != *numberOfPlay) )
    {
        flag = 1;
    }
    if ( *numberOfPlay % 2 != 0 && (counterX != counterO || counterX*2+1 != *numberOfPlay ))
    {
        flag = 1;
    }
    if ( (*scoreOne >= 0  && *scoreOne <= 50) && (*scoreTwo >= 0 && *scoreTwo <= 50) )
    {
        
    }
    else
    {
        flag = 1;
    }
    if (flag == 1)
    {
        printf("\n\t >> Human vs. Human << \n OR \n\t >> Human vs. Computer <<\n");
        printf("\n>>Enter (H) if two player && (C) if one player\n");

        scanf("%s",whichPlayer);

        while (*whichPlayer != 'H' && *whichPlayer != 'C')
        {
            printf("\nsome thing error please enter again\n");
            scanf("%s",whichPlayer);
        }
		
        *numberOfPlay = 1;
        *savePlace = 0;
		*restorePlace = 0;
		*scoreOne = 0;
		*scoreTwo = 0;
        
    }
}