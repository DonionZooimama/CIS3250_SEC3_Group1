#include "header.h"

//Daniel
void PlayAgain( char *playerInput , int *numberOfPlay, int *Height, char arr[ 100 ][ 100 ], char *arrSaveAction, int *savePlace,
	       int *Width, int *Highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo,
	       char *arrRestorePlace )
{
    printf( "\n\t>>this move isn't valid \n\n >>do another move<< " );
    scanf( "%s",playerInput );
    player( playerInput , numberOfPlay, Height, arr, arrSaveAction, savePlace, Width,
	   Highscores, restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
}
