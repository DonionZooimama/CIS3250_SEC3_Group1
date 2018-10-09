#include "header.h"

//Derek
void HighScoresList(int flag, int *HighScoreList, int *listLength, int *Highscores, int scoreOne, int scoreTwo)
{
    int counter , counter1 , temp;

    if (flag == 0)
    {
        FILE * file = fopen( "Highscores.txt" , "r");
        while(fscanf(file,"%d",&HighScoreList[*listLength]) != EOF)
        {
            *listLength += 1;
        }
        fclose(file);
    }
	HighScoreList[*listLength]=scoreOne;
    HighScoreList[*listLength+1]=scoreTwo;
    printf("The High Score List\n");

    for (counter = 1 ; counter <= *listLength+1 ; counter++)
    {
        counter1 = counter;
        while ( counter1 > 0 && HighScoreList[counter1] > HighScoreList[counter1-1])
        {
            temp   = HighScoreList[counter1];
            HighScoreList[counter1]   = HighScoreList[counter1-1];
            HighScoreList[counter1-1] = temp;
            counter1--;
        }
    }
    if (flag == 1)
    {
        FILE *file = fopen("Highscores.txt" , "w");
        for(counter=0 ; counter < *Highscores ; counter++)
        {
            fprintf(file,"%d\n",HighScoreList[counter]);
            printf("\n%d",HighScoreList[counter]);
        }
        fclose(file);
    }
    else
    {
        for(counter = 0 ; counter < *listLength ; counter++)
        {
            printf("%d\n",HighScoreList[counter]);
        }
    }
}