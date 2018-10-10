#include "header.h"

/*
 * Oct 9, 2018
 * 1015577
 * Refactored by Ajai Gill
 * 
 */

//undoes an undo in a human vs human game.
void Redo( int *restorePlace,
		   int *Height,
		   int *Width,
		   int *numberOfPlay,
		   int *scoreOne,
		   int *scoreTwo,
		   int *gameOut,
		   int *highScores,
		   int *savePlace,
		   char whichPlayer,
		   char *playerInput,
		   char *arrRestorePlace,
		   char arr[100][100],
		   char *arrSaveAction )
{
    int i = 0;
	int flag = 0;
	int noOfCol = 0;

	
	//checks if there is a player move that can be restored
    if ( *restorePlace != 0 )
    {
        *restorePlace -= 1;
        noOfCol = arrRestorePlace[ *restorePlace ];
        *savePlace += 1;
		
		//finds the location in the game and places the correct symbol for the redo
        for ( i = 0 ; i < *Height && flag == 0; i++ )
        {
            if ( arr[ *Height - i - 1 ][ noOfCol ] == '-' )
            {
                if ( *numberOfPlay % 2 != 0 )
                {
                    arr[ *Height - i - 1 ][ noOfCol ] = 'X';
                }
                else
                {
                    arr[ *Height - i - 1 ][ noOfCol ] = 'O';
                }
                flag = 1;
            }
        }
		
        updateScore( *Height - i , noOfCol, Width, Height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr );
        *numberOfPlay += 1;
    }
	
    PrintArrayValue( Height, Width, scoreOne, scoreTwo, arr );
	
    if ( *numberOfPlay % 2 == 0 )
    {
        printf( "\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`" );
        printf( "\tplayer2<<Enter your play>> = " );
        scanf( "%s", playerInput );
		
        player( playerInput , numberOfPlay,  Height, arr, arrSaveAction, savePlace, Width, highScores,
				restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
    }
    else
    {
        printf( "\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8" );
        printf( "\t player1<<Enter your play>> = " );
        scanf( "%s", playerInput );
		
        player( playerInput , numberOfPlay,  Height, arr, arrSaveAction, savePlace, Width, highScores,
				restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
    }
} 