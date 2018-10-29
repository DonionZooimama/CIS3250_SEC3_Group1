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
 *The variables which are not defined (formerly global variables) are: width, height, arr[], restorePlace and savePlace
 */

void ComputerPlayer( char arr[100][100], int *height, int *width, int *restorePlace,
                    char *arrSaveAction, int *savePlace, int *scoreOne, int *scoreTwo, int *numberOfPlay,
                    char *playerInput )
{ //ComputerPlayer start
    
    int row = 0;
    int randomPlay = 0;
    int flag = 0;
    
    //checks if flag is equal to 0
    while ( flag == 0 )
    {
        //creates a random play
        randomPlay = rand() % ( *width );
        
        //loops from 0 to the height of the board
        for( row = 0 ; row < *height && flag == 0; row++ )
        {
            
            //If the board position has a piece already, then do nothing
            if( arr[ *height - row - 1 ][ randomPlay ] == 'X'
               || arr[ *height - row - 1 ][ randomPlay ] == 'O' )
            {
                
            }
            
            //otherwise, the board space is populated with an '0', In other words, the computer places a piece
            else
            {
                if ( row < *height )
                {
                    *restorePlace = 0;
                    //Sets the board location to 'O'
                    arr[ *height - row - 1 ][ randomPlay ] = 'O';
                    arrSaveAction[ *savePlace ] = ( randomPlay );
                    *savePlace += 1; //savePlave is incremented
                    UpdateScore( *height - row - 1 , randomPlay, width, height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr ); //Score is updated

                    PrintArrayValue( height, width, scoreOne, scoreTwo, arr );
                    flag = 1;
                }
            }
        }
    }
} //ComputerPlayer end
