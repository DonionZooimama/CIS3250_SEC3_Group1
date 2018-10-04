#include "header.h"

//Derek
void saveGame()
{
    int counter ,counter2;
    char chose , chose2;
    printf("\nif you save the file you will delete the previous saving file",INTENSITY);
    printf("\nif you want to continue >>enter Y << else >> enter N << ",INTENSITY);
    scanf("%s",&chose);

    if (chose =='Y')
    {
        FILE * file = fopen( "saveGame.txt" , "w");
        fprintf(file,"%d %d %d %d",Width,Height,Highscores,numberOfPlay);
        fprintf(file,"\n%d %d",scoreOne,scoreTwo);
        fprintf(file,"\n%s\n",&whichPlayer);

        for(counter = 0 ; counter < Height ; counter++)
	    {
for(counter2 = 0 ; counter2 < Width ; counter2++)
            {
                fprintf(file,"%c ",arr[counter][counter2]);
            }
            fprintf(file,"\n");
        }
        fclose(file);
        printf("\nThe game has been saved if you want to continue playing in the a \n"
               "same game >>Enter Y << else >> Enter N << ",BLUE);
        scanf("%s",&chose2);
        if (chose2 == 'Y')
        {
           
        }
        else
        {
            gameOut = 1;
        }
    }
    if(chose == 'N' || chose2 == 'Y')
    {
        system("cls");
        PrintArrayValue(Height,Width);
if (numberOfPlay % 2 == 0)
        {
            printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`",INTENSITY);
            printf("\tplayer2<<Enter your play>> = ",BLUE);
            scanf("%s",playerInput);
            player( playerInput , numberOfPlay);
        }
        else
        {
            printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8",INTENSITY);
            printf("\t player1<<Enter your play>> = ",GREEN);
            scanf("%s",playerInput);
            player(playerInput , numberOfPlay);
        }
    }
}