#include "header.h"

/*
 * Oct 21, 2018
 * 1015577
 * Refactored by Ajai Gill
 *
 * int *restorePlace : value that contains where to restore the movement made by the player.
 * int *height : the height in which to place the player movement that needs to be redone.
 * int *numberOfPlay : which turn it is.
 * int *width, *scoreOne, *scoreTwo, *gameOut, *highScores : to call the other functions.
 * int *savePlace : conatins amount of movements made.
 * char *whichPlayer, arrSaveAction : to call the functions.
 * char *playerInput : the string containing the player input.
 * char *arrRestorePlace : the array that contains the location to restore the movement of the player.
 * char arr[100][100] : the array that holds the game board.
 * void return
 */

//undoes an undo in a human vs human game.
void Redo( int *restorePlace,
		   int *height,
		   int *width,
		   int *numberOfPlay,
		   int *scoreOne,
		   int *scoreTwo,
		   int *gameOut,
		   int *highScores,
		   int *savePlace,
		   char whichPlayer,
		   char *playerInput,
		   char *arrRestorePlace,
		   char arr[ 100 ][ 100 ],
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
        for ( i = 0 ; i < *height && flag == 0; i++ )
        {
            if ( arr[ *height - i - 1 ][ noOfCol ] == '-' )
            {
                if ( *numberOfPlay % 2 != 0 )
                {
                    arr[ *height - i - 1 ][ noOfCol ] = 'X';
                }
                else
                {
                    arr[ *height - i - 1 ][ noOfCol ] = 'O';
                }
                flag = 1;
            }
        }
		
        UpdateScore( *height - i , noOfCol, width, height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr );
        *numberOfPlay += 1;
    }
	
    PrintArrayValue( height, width, scoreOne, scoreTwo, arr );
	
	
	//this can be placed into a helper function
    if ( *numberOfPlay % 2 == 0 )
    {
        printf( "\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`" );
        printf( "\tplayer2<<Enter your play>> = " );
        scanf( "%s", playerInput );
		
        Player( playerInput , numberOfPlay,  height, arr, arrSaveAction, savePlace, width, highScores,
				restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
    }
    else
    {
        printf( "\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8" );
        printf( "\t player1<<Enter your play>> = " );
        scanf( "%s", playerInput );
		
        Player( playerInput , numberOfPlay,  height, arr, arrSaveAction, savePlace, width, highScores,
				restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
    }
} 
