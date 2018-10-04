#include "header.h"

int main()
{
	char arr[100][100];
	char arrSaveAction[100] = {0}; 
	char arrRestorePlace[100] = {0}; 
	char playerInput[20];
	char whichPlayer = ' ';
	char chose = 'C';
    char option = ' ';

	int Width = 0;
	int Height = 0;
	int Highscores = 0;
	int numberOfPlay = 0;
	int savePlace = 0;
	int restorePlace = 0;
	int scoreOne = 0;
	int scoreTwo = 0;
	int gameOut = 0;
	int HighScoreList[50] = {0};
	int listLength = 0;
    int flag = 0;

    while (chose =='C')
    {
        system("color 0A");
        printf("\nIf You Want To Load The Saved Game >> Enter L <<Else Enter Any thing ");
        scanf("%s",&option);

        if (option == 'L')
        {
            loadGame();
			ReadXML(&Width, &Height, &Highscores);
			arrInitialization(Height, Width, arr);
        }
        else
        {
            printf("\n\t >> Human vs. Human << \n OR \n\t >> Human vs. Computer <<\n",BLUE);
            printf("\n>>Enter (H) if two player && (C) if one player\n",GREEN);

            scanf("%s",&whichPlayer);

            while (whichPlayer != 'H' && whichPlayer != 'C')
            {
                printf("\nsome thing error please enter again\n",RED);
                scanf("%s",&whichPlayer);
            }

            numberOfPlay = 1;
            savePlace = 0 , restorePlace = 0 , scoreOne = 0 , scoreTwo = 0;
            ReadXML(&Width, &Height, &Highscores);
            arrInitialization(Height, Width, arr);
        }

        system("cls");// apparently this clears the command prompts screen for windows only. Should change this. ---Ajai Gill

        while ( Width * Height >= numberOfPlay && gameOut != 1)
        {
            system("cls");
            PrintArrayValue(&Height, &Width, &scoreOne, &scoreTwo, arr);

if (numberOfPlay % 2 != 0)
    {
                printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8",INTENSITY);
                printf("\t player1<<Enter your play>> = ",GREEN);
                scanf("%s",playerInput);
                player(playerInput , &numberOfPlay, &Height, arr, arrSaveAction, &savePlace, &Width, &restorePlace, whichPlayer, &scoreOne, &scoreTwo, arrRestorePlace);
                numberOfPlay++;
            }
    else
       {
                if (whichPlayer == 'H')
                {
                    printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`",INTENSITY);
                    printf("\tplayer2<<Enter your play>> = ",BLUE);
                    scanf("%s",playerInput);
                    player(playerInput , &numberOfPlay, &Height, arr, arrSaveAction, &savePlace, &Width, &restorePlace, whichPlayer, &scoreOne, &scoreTwo, arrRestorePlace);
                }
                else
                {
                    computerPlayer(arr, &Height, &Width, &restorePlace, arrSaveAction, &savePlace, &scoreOne, &scoreTwo);
                }

                numberOfPlay++;
            }
        }

        system("cls");
        PrintArrayValue(&Height, &Width, &scoreOne, &scoreTwo, arr);
        system("color 2A");
        if (numberOfPlay-1 == Width*Height)
        {
    if (scoreOne > scoreTwo)
    {
                printf("\n\n\t***player One is winner***");
                printf(" \n\t **Hard luck player Two**\n");
            }
            else if (scoreOne < scoreTwo)
            {
                printf("\n\n\t***player Two is winner***");
                printf(" \n\t **Hard luck player One**\n");
            }
            else
    {
                printf("\n\n\t***The two score is equivalent***\n\n");
            }
            flag = 1;
            HighScoresList(flag, HighScoreList, &listLength, &Highscores, scoreOne, scoreTwo);
        }
        printf("\n\nYou Want To Continue Enter C else Enter any thing ");
scanf("\n%s",&chose);
        system("cls");
    }
    return 0;
}