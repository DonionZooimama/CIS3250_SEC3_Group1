#include "header.h"

/*
 * Oct 8, 2018
 * Refactored by Derek Bowman
 * 
 * int readOrWrite : changes whether you read or write from file (can be changed to two seporate functions
 * int *highScoreList, *listLength, highscores : deals with the highscore list
 * int scoreOne, scoreTwo : the scores to add
 * void return
 * */

void HighScoresList( int readOrWrite, int *highScoreList, int *listLength, int *highscores, int scoreOne, int scoreTwo )
{

    //readOrWrite flag 0 reads Highscores from file to array
    if ( readOrWrite == 0 )
    {
        FILE *file = fopen( "Highscores.txt", "r" );
        while( fscanf( file, "%d", &highScoreList[ *listLength ] ) != EOF )

        {
            *listLength += 1;
        }
        fclose( file );
    }


    /* Adds highscores, then sorts the list
     *
     * Design notes:
     *  - Does not currently check to see if it's past the largest size of array
     *  - Currently adds scoreOne and scoreTwo, then sorts. Should this be done
     *    differently /in seporate methods?
     */
    highScoreList[ *listLength ] = scoreOne;
    highScoreList[ *listLength+1 ] = scoreTwo;
    printf( "The High Score List\n" );

    for ( int i = 1 ; i <= *listLength + 1 ; i++ )
    {
        int j = i;
        while ( j > 0 && highScoreList[ j ] > highScoreList[ j-1 ] )
        {
            int swap = highScoreList[ j ];
            highScoreList[ j ] = highScoreList[ j - 1 ];
            highScoreList[ j - 1 ] = swap;
            j--;
        }
    }

    //readOrWrite flag 1 will print to file and screen
    if ( readOrWrite == 1 )
    {
        FILE *file = fopen( "Highscores.txt" , "w" );
        for( int i = 0 ; i < *highscores ; i++ )
        {
            fprintf( file, "%d\n", highScoreList[ i ] );
            printf( "\n%d", highScoreList[ i ] );

        }
        fclose( file );
    }
    else
    {
        for( int i = 0 ; i < *listLength ; i++ )
        {
            printf( "%d\n", highScoreList[ i ] );

        }
    }
}
