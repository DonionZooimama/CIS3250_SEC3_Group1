#include "header.h"

/*
 * Oct 8, 2018
 * Refactored by Derek Bowman
 * 
 * int flag : changes whether you read or write from file (can be changed to two seporate functions
 * int *highScoreList, *listLength, highscores : deals with the highscore list
 * int scoreOne, scoreTwo : the scores to add
 * void return
 * */

void HighScoresList( int flag, int *highScoreList, int *listLength, int *highscores, int scoreOne, int scoreTwo )
{
    int counter;
    int counter1;
    int temp;

    //Flag 0 reads Highscores from file to array
    if ( flag == 0 )
    {
        FILE *file = fopen( "Highscores.txt", "r" );
        while( fscanf( file, "%d", &highScoreList[*listLength] ) != EOF )
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
    highScoreList[*listLength] = scoreOne;
    highScoreList[*listLength+1] = scoreTwo;
    printf( "The High Score List\n" );

    for ( counter = 1 ; counter <= *listLength+1 ; counter++)
    {
        counter1 = counter;
        while ( counter1 > 0 && highScoreList[counter1] > highScoreList[counter1-1] )
        {
            temp = highScoreList[counter1];
            highScoreList[counter1] = highScoreList[counter1-1];
            highScoreList[counter1-1] = temp;
            counter1--;
        }
    }

    //Flag 1 will print to file and screen
    if ( flag == 1 )
    {
        FILE *file = fopen( "Highscores.txt" , "w" );
        for( counter=0 ; counter < *Highscores ; counter++ )
        {
            fprintf( file, "%d\n", highScoreList[counter] );
            printf( "\n%d", highScoreList[counter] );
        }
        fclose( file );
    }
    else
    {
        for( counter = 0 ; counter < *listLength ; counter++ )
        {
            printf( "%d\n", highScoreList[counter] );
        }
    }
}
