#include "header.h"

/**
 *  Date: October 3, 2018 - Ronnie Tran
 *  Creates an empty connect 4 board.
 * @param height, the board's height
 * @param width, the board's width
 * @param arr, the board represented as a 2D array
 */
void ArrInitialization(int height, int width, char arr[100][100])
{
    for( int h = 0 ; h < height ; h++ )
    {
        for( int w = 0 ; w < width ; w++ )
        {
            // fills the board with '-' for the width and height
            arr[ h ][ w ] = '-';
        }
    }
}