#include "header.h"

//Daniel
void PlayAgain(char *playerInput , int *numberOfPlay, int *height, char arr[100][100], char *arrSaveAction, int *savePlace,
			   int *width, int *highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace)
{
    printf("\n\t>>this move isn't valid \n\n >>do another move<< ");
    scanf("%s",playerInput);
    Player(playerInput , numberOfPlay, height, arr, arrSaveAction, savePlace, width, highscores, restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace);
}