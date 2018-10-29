/**
 *  Jordan Evans
 *  0964044
 *  The Player function is the main game logic for a player to complete
 *  their move. It takes the players input and first checks
 *  to see if the player is requesting to undo, redo or save the game. If
 *  so, the respective functions are called. If the player has input a
 *  column number, the program finds the first available slot in that 
 *  column. If a space is found, it places an 'X' on the board. If not, the
 *  "flag" variable is set and the playAgain function is called.
 */

#include "header.h"

//Just a note for you. This code makes no sense because he's using chars and comparing it with ints so im not gonna fix that.
//still creates errors in compilation but you will figure it out. --- AJAI

//Jordan
void Player(
    char *playerInput , 
    int  *numberOfPlay , 
    int  *height, 
    char arr[ 100 ][ 100 ],
	char *arrSaveAction, 
    int  *savePlace, 
    int  *width, 
    int  *highscores, 
    int  *restorePlace, 
    int  *gameOut,
	char whichPlayer, 
    int  *scoreOne, 
    int  *scoreTwo, 
    char *arrRestorePlace
) //this got really long use our coding convention --- AJAI
{
    // No NULL checking for any of the 12 pointers being passed

    int curRow = 0; 
    int flag = 0;
    int playerInputInt = 0;
	char input = ' ';

    flag = 0;

    playerInputInt = atoi( playerInput ); // atoi returns 0 if no valid conversion could be made... this means that player can never enter 0

    if ( playerInputInt == 0 )
    {
        input = 0;
    }
    else
    {
        input = playerInputInt;
    }

    if( input > 0  && input <= *width )
    {
        // Do nothing
    }
    else if ( playerInput[ 0 ] == 'U' )
    {
        Undo( savePlace, restorePlace, height, width, numberOfPlay, 
              scoreOne, scoreTwo, highscores, gameOut, whichPlayer, 
              arrSaveAction, arrRestorePlace, playerInput, arr );
        flag = 1;
    }
    else if ( playerInput[ 0 ] == 'R' )
    {
        Redo( restorePlace, height, width, numberOfPlay, scoreOne, 
              scoreTwo, gameOut, highscores, savePlace, whichPlayer, 
              playerInput, arrRestorePlace, arr, arrSaveAction );
        flag = 1;
    }
    else if( playerInput[ 0 ] == 'S' )
    {
        SaveGame(width, height, highscores, numberOfPlay, scoreOne, 
              scoreTwo, gameOut, whichPlayer, savePlace, restorePlace, 
              arr, arrSaveAction, arrRestorePlace, playerInput);
        flag = 1;
    }
    else
    {
        flag = 2;
    }

    for( curRow = 0; curRow < *height && flag == 0; curRow++ ) // Iterates through the selected column
    {
        if( arr[ *height - curRow - 1 ][ input - 1 ] == 'X' || arr[ *height - curRow - 1 ][ input - 1 ] == 'O' ) // If the current 'spot' is filled by X or O
        {
           // Do nothing
        }
        else
        {
            if ( curRow < *height ) // This is always true ??
            {
                *restorePlace = 0;
                if ( *numberOfPlay % 2 != 0 ) // If it is player 1's turn or player 2's turn
                {
                    arr[ *height - curRow - 1 ][ input -1 ] = 'X';       // Set the space to X
                    arrSaveAction[ *savePlace ] = ( input - 1 );   // Add to array of completed moves
                    *savePlace += 1;                                 // Increase the index for the array of completed moves
                    UpdateScore( *height - curRow - 1 , input - 1, width, height, 
                                 numberOfPlay, scoreOne, scoreTwo, playerInput, arr );
                }
                else
                {
                    if ( whichPlayer == 'H' ) // Checks if its human v human or human v computer
                    {
                        arr[ *height - curRow - 1 ][ input - 1 ] = 'O';     // Set the space to O
                        arrSaveAction[ *savePlace ] = ( input - 1 );  // Add to array of completed moves
                        *savePlace += 1;                                // Increase the index for the array of completed moves
                        UpdateScore( *height - curRow - 1 , input - 1, width, height, 
                                     numberOfPlay, scoreOne, scoreTwo, playerInput, arr );
                    }
                    else
                    {
                        ComputerPlayer(arr, height, width, restorePlace, arrSaveAction, savePlace, scoreOne, scoreTwo, numberOfPlay, playerInput);
                    }
                }

                /* Would clear terminal between turns
                system("clear"); 
                */

                PrintArrayValue( height, width, scoreOne, scoreTwo, arr );
                flag = 1; // This exits the loop
            }
        }
    }
    if ( flag == 0 || flag == 2 ) //if flag = this mean curRow "counter" is bigger than *height <<all the curRow is fulled
    {
        PlayAgain( playerInput , numberOfPlay, height, arr, arrSaveAction, savePlace, width, highscores, restorePlace, gameOut, whichPlayer, scoreOne, scoreTwo, arrRestorePlace ); 
    }
}

