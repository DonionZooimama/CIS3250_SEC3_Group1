/*
*Group: CIS3250 SEC_3 Group_1
*Lab Time: Monday, 8:30 A.M - 11:20 A.M
*Team Member who edited this function: William Moskal (1011940)
*Edits: Changed the code to better adhere with the team coding convention. Edits included: changing function names to total camel case,
*Adding whitespace on either side of Identifiers for better readability, commenting, changing variable declarations to be on their own 
*lines, and putting complicated expressions on their own lines.
*/

#include "header.h"

/*
*The Variables which are not defined (formerly global variables) are: savePlace, arrSaveAction[], 
*arrRestorePlace[], restorePlace, height, numberOfPlay, arr[], width, whichPlayer and playerIntput     
*/

void Undo(int *savePlace, int *restorePlace, int *height, int *width, int *numberOfPlay, int *scoreOne,
int *scoreTwo, int *highScores, int *gameOut, char whichPlayer, char char *arrSaveAction,
char *arrRestorePlace, char *playerInput, char arr[100][100])
{ //Undo Start

    //Variable declaration and initialization
    int counter = 0; 
    int flag = 0;
    int noOfCol = 0;

    //If the save place is null, nothing hapens. In other words if there has not been a save yet, nothing happens.
    if ( savePlace == 0 )
    {
       
    }

    //otherwise, the save place is decreased, and the previous turn is reversed.
    else
    {
        savePlace--;
        noOfCol = arrSaveAction[ savePlace ];
        arrRestorePlace[ restorePlace ] = noOfCol;
        restorePlace++;

        for ( counter = 0 ; counter < height && flag == 0 ; counter++ )
        {
            if ( arr[ counter ][ noOfCol ] == 'X' 
	    ||  arr[ counter ][ noOfCol ] == 'O' )
            {
		//updates the board, and decreases the move number
                numberOfPlay--;
                UpdateScore( row, col, width, height, numOfPlay, scoreOne, scoreTwo, playerInput, arr );
                arr[ counter ][ noOfCol ] = '-';

                flag = 1;
            }
        }
    }

    system( "cls" );
    PrintArrayValue( height, width, scoreOne, scoreTwo, arr );

    // if it is an even numbered turn
    if ( numberOfPlay % 2 == 0 )
    {
	//If it is the human players turn, display the board, and move to players turn
        if ( whichPlayer == 'H' )
        {
            printf( "\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`" );
            printf( "\tplayer2<<Enter your play>> = " );
            scanf( "%s", playerInput );
            Player( playerInput , numberOfPlay, height, arr, arrSaveAction, savePlace, width,
	    highscores, restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace );
        }

	//otherwise, move to computer player
        else
        {
            ComputerPlayer( height, width, restorePlace, arrSaveAction, savePlace, scoreOne, scoreTwo, numberOfPlay, playerInput );
        }
    }
    //if it is an odd numbered turn, display the board, and move to players turn
    else
    {
        printf( "\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8" );
        printf( "\t player1<<Enter your play>> = " );
        scanf( "%s", playerInput );
        Player( playerInput , numberOfPlay );
    }
} //undo end 