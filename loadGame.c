#include "header.h"

/*
 * Oct 9, 2018
 * 1015577
 * Refactored by Ajai Gill
 * 
 */

void loadGame( int *Width,
			   int *Height,
			   int *highScores,
			   int *numberOfPlay,
			   int *scoreOne,
			   int *scoreTwo,
			   char *whichPlayer,
			   int *savePlace,
			   int *restorePlace,
			   char arr[100][100] )
{
    int i;
	int j;
	int numX = 0;
	int numO = 0;
	int loadError = 0;
	
    FILE *file = fopen( "saveGame.txt", "r" );
	
	//checks if there is a file named saveGame.txt.
    if ( !file )
    {
        loadError = 1;
    }
    else
    {
		//obtains the data in the save file.
        fscanf( file, "%d %d %d %d", Width, Height, highScores, numberOfPlay );
        fscanf( file, "%d %d", scoreOne, scoreTwo );
        fscanf( file, "%s", whichPlayer );
	
		//recreates the board in the arr array.
        for( i = 0; i < *Height ; i++ )
        {
            for( j = 0; j < *Width ; j++ )
            {
                fscanf( file," %c ",&arr[i][j] );
				
                if ( arr[ i ][ j ] == 'X' )
                {
                    numX++;
                }
                else if ( arr[ i ][ j ] == 'O' )
                {
                    numO++;
                }
            }
        }
    }
	
    fclose(file);
	
	//checks if the file is changed and warns the program if there is an error in the file
    if ( *Width < 3 || *Width > 12 || *Height < 3 || *Height > 12 )
    {
        loadError = 1;
    }
    else if ( *numberOfPlay % 2 == 0 && (numX-1 != numO || (numX * 2) != *numberOfPlay) )
    {
        loadError = 1;
    }
    else if ( *numberOfPlay % 2 != 0 && ( numX != numO || ( numX * 2 + 1 ) != *numberOfPlay ) )
    {
        loadError = 1;
    }
    else if ( ( *scoreOne < 0  || *scoreOne > 50 ) && ( *scoreTwo < 0 || *scoreTwo > 50 ) )
    {
        loadError = 1;
    }
	
	//if there is an error in loading the game it creates a new game
    if ( loadError == 1 )
    {
		printf( "\nyour save file is damaged/corrupted or doesn't exist!!!\n\n" );
		
        printf( "\n\t >> Human vs. Human << \n OR \n\t >> Human vs. Computer <<\n" );
        printf( "\n>>Enter (H) if two player && (C) if one player\n" );

        scanf( "%s",whichPlayer );

        while ( *whichPlayer != 'H' && *whichPlayer != 'C' )
        {
            printf( "\n>>Enter (H) if two player && (C) if one player\n" );
            scanf( "%s", whichPlayer );
        }
		
        *numberOfPlay = 1;
        *savePlace = 0;
		*restorePlace = 0;
		*scoreOne = 0;
		*scoreTwo = 0;
		
		ReadXML( Width, Height, highScores );
        arrInitialization( *Height, *Width, arr );
        
    }
}