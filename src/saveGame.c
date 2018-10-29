#include "header.h"
/**
 * Oct 8, 2018
 * Refactored by Derek Bowman
 * 
 * This function saves the state of the game
 * Variables to write to file are: width, height, highscores, scoreOne, scoreTwo, whichPlayer and arr
 * The rest are there only to pass into Player() : arrSaveAction, arrRestorePlace, playerInput, restorePlace, savePlace
 * Void return
 * */
void SaveGame( int *width, int *height, int *highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, 
               int *gameOut, char whichPlayer, int *savePlace, int *restorePlace, char arr[ 100 ][ 100 ], 
	       char *arrSaveAction, char *arrRestorePlace, char *playerInput )
{
    char userChoiceSave = 'N';
    char userChoiceContinue = 'N';

    printf( "\nif you save the file you will delete the previous saving file" );
    printf( "\nif you want to continue >>enter Y << else >> enter N << " );
    scanf( "%s", &userChoiceSave );

    if ( userChoiceSave =='Y' )
    {
        //write variables about game state to file
        FILE *file = NULL;
       	file = fopen( "saveGame.txt" , "w" );
        fprintf( file, "%d %d %d %d", *width, *height, *highscores, *numberOfPlay );
        fprintf( file, "\n%d %d", *scoreOne, *scoreTwo );
        fprintf( file, "\n%s\n", &whichPlayer );

	      //Loop over all positions on board and print a copy of the board from 2d array (arr)
        for( int i = 0 ; i < *height ; i++ )
	      {
            for( int j = 0 ; j < *width ; j++ )
            {
                fprintf( file, "%c ", arr[ i ][ j ] );
            }
            fprintf( file, "\n" );
        }

        fclose( file );
        
	      printf( "\nThe game has been saved if you want to continue playing in the a \n"
               "same game >>Enter Y << else >> Enter N << " );
        scanf( "%s", &userChoiceContinue );
        
	      if ( userChoiceContinue != 'Y' )
        {
            *gameOut = 1; 
        }
    }

    //If the player would like to continue playing
    if( userChoiceSave == 'N' || userChoiceContinue == 'Y' )
    {
        PrintArrayValue( height , width, scoreOne, scoreTwo, arr );

        if ( *numberOfPlay % 2 == 0 )
        {
            printf( "\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`" );
            printf( "\tplayer2<<Enter your play>> = " );
            scanf( "%s", playerInput );
            Player( playerInput , numberOfPlay, height, arr, arrSaveAction, savePlace, width, highscores,
            restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
        }
        else
        {
            printf( "\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8" );
            printf( "\t player1<<Enter your play>> = " );
            scanf( "%s", playerInput );
            Player( playerInput , numberOfPlay, height, arr, arrSaveAction, savePlace, width, highscores, 
            restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
        }
    }
}
