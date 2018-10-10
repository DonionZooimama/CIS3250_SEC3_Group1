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
	int numberOfPlay = 1;
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
        printf("\nIf You Want To Load The Saved Game >> Enter L <<Else Enter Any thing ");
        fgets(&option, 3, stdin);

        if (option == 'L')
        {
            loadGame(&Width, &Height, &Highscores, &numberOfPlay, &scoreOne, &scoreTwo, &whichPlayer, &savePlace, &restorePlace, arr);
        }
        else
        {
            printf("\n\t >> Human vs. Human << \n OR \n\t >> Human vs. Computer <<\n");
            printf("\n>>Enter (H) if two player && (C) if one player\n");
			fgets(&whichPlayer, 3, stdin);

            while (whichPlayer != 'H' && whichPlayer != 'C')
            {
                printf("\n>>Enter (H) if two player && (C) if one player\n\n");
                scanf("%s",&whichPlayer);
            }
            ReadXML(&Width, &Height, &Highscores);
            arrInitialization(Height, Width, arr);
        }

        while ( Width * Height >= numberOfPlay && gameOut != 1)
        {
            PrintArrayValue(&Height, &Width, &scoreOne, &scoreTwo, arr);

	if (numberOfPlay % 2 != 0)
    {
        printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8");
        printf("\t player1<<Enter your play>> = ");
        scanf("%s",playerInput);
        player(playerInput , &numberOfPlay, &Height, arr, arrSaveAction, &savePlace, &Width, &Highscores, &restorePlace, &gameOut, whichPlayer, &scoreOne, &scoreTwo, arrRestorePlace);
        numberOfPlay++;
    }
    else
       {
                if (whichPlayer == 'H')
                {
                    printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`");
                    printf("\tplayer2<<Enter your play>> = ");
                    scanf("%s",playerInput);
                    player(playerInput , &numberOfPlay, &Height, arr, arrSaveAction, &savePlace, &Width, &Highscores, &restorePlace, &gameOut, whichPlayer, &scoreOne, &scoreTwo, arrRestorePlace);
                }
                else
                {
                    computerPlayer(arr, &Height, &Width, &restorePlace, arrSaveAction, &savePlace, &scoreOne, &scoreTwo, &numberOfPlay, playerInput);
                }

                numberOfPlay++;
            }
        }

        PrintArrayValue(&Height, &Width, &scoreOne, &scoreTwo, arr);
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