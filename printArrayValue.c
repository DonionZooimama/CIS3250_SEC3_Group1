#include "header.h"

//Ronnie

/**
 *  Date: October 8, 2018 - Ronnie Tran
 *  Displays the board and its current state. For an example, it will show
 *  all of the current game pieces that are on the board, the current scores for player 1 and player 2 and
 *  give you options such as undo, redo and save.
 * @param height, the board's height
 * @param width, the board's width
 * @param scoreOne, the first player's score
 * @param scoreTwo, the second player's score
 * @param arr, the game board represented in a 2-D array
 */
void PrintArrayValue(int *height , int *width, int *scoreOne, int *scoreTwo, char arr[100][100])
{
    int h = 0;
    int w = 0;

    // treat this as a boolean
    // used to print out the column numbers on the top once
    int printedColumnNumbers = 0;


    // display the player scores
    printf( "\n\n\t>> Connect 4 \"Have fun\" <<" );
    printf( "\n\n\tPlayer 1's Score: %d", *scoreOne );
    printf( "\t\t\tPlayer 2's Score:  %d", *scoreTwo );
    printf( "\n\n" );

    for( h = 0 ; h < *height ; h++ )
    {

        // this will print out the column numbers ONCE only at the top
        // [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ]
        for( w = 0 ; w < *width && printedColumnNumbers == 0 ; w++ )
        {
            printf( "[ %d ] ", w + 1 );
        }
        printf( "\n" );

        // print out the top side of each box
        for( w = 0 ; w < *width ; w++ )
        {
            printf( "***** " );
        }
        printf( "\n" );


        // print out the first set of sides of each box
        for( w = 0 ; w < *width ; w++ )
        {
            printf( "*   * " );
        }
        printf( "\n" );


        // print out the game pieces that are in the box and the sides
        // X or O
        for( w = 0 ; w < *width ; w++ )
        {
            printf( "* " );
            printf( "%c ", arr[h][w] );
            printf( "* " );
        }
        printf( "\n" );


        // continue to fill the sides of each box
        for( w = 0 ; w < *width ; w++ )
        {
            printf( "*   * " );
        }
        printf( "\n" );


        // print out the bottom of the box
        for( w = 0 ; w < *width ; w++)
        {
            printf( "***** " );
        }

        // set this variable to 1 so we don't print the column numbers again
        printedColumnNumbers = 1;
    }
    printf( "\n\n(U) to make Undo" );
    printf( "\n(R) to make Redo " );
    printf( "\n(S) to save\n" );
}