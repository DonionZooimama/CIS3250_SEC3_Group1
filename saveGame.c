#include "header.h"
/**
 * Oct 8, 2018
 * Refactored by Derek Bowman
 * 
 * This function saves the state of the game
 * Void return
 * */
void saveGame( int *width, int *height, int *highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, 
               int *gameOut, char whichPlayer, int *savePlace, int *restorePlace, char arr[100][100], 
	       char *arrSaveAction, char *arrRestorePlace, char *playerInput )
{
    int counter;
    int counter2;
    char chose;
    char chose2;

    printf( "\nif you save the file you will delete the previous saving file" );
    printf( "\nif you want to continue >>enter Y << else >> enter N << " );
    scanf( "%s", &chose );

    if ( chose =='Y' )
    {
        //write variables about game state to file
        FILE *file = fopen( "saveGame.txt" , "w" );
        fprintf( file, "%d %d %d %d", *width, *height, *highscores, *numberOfPlay );
        fprintf( file, "\n%d %d", *scoreOne, *scoreTwo );
        fprintf( file, "\n%s\n", &whichPlayer );

	//Loop over all positions on board and print a copy of the board from 2d array (arr)
        for( counter = 0 ; counter < *height ; counter++ )
	{
            for( counter2 = 0 ; counter2 < *width ; counter2++ )
            {
                fprintf( file, "%c ", arr[counter][counter2] );
            }
            fprintf( file, "\n" );
        }

        fclose( file );
        
	printf( "\nThe game has been saved if you want to continue playing in the a \n"
               "same game >>Enter Y << else >> Enter N << " );
        scanf( "%s", &chose2 );
        
	if ( chose2 != 'Y' )
        {
            *gameOut = 1; 
        }
    }

    //If the player would like to continue playing
    if( chose == 'N' || chose2 == 'Y' )
    {
        system( "cls" );
        PrintArrayValue( height , width, scoreOne, scoreTwo, arr );

	if ( *numberOfPlay % 2 == 0 )
        {
            printf( "\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`" );
            printf( "\tplayer2<<Enter your play>> = " );
            scanf( "%s", playerInput );
            player( playerInput , numberOfPlay, height, arr, arrSaveAction, savePlace, width, highscores,
            restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
        }
        else
        {
            printf( "\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8" );
            printf( "\t player1<<Enter your play>> = " );
            scanf( "%s", playerInput );
            player( playerInput , numberOfPlay, height, arr, arrSaveAction, savePlace, width, highscores, 
            restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
        }
    }
}
