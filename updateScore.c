#include "header.h"

//Daniel
void UpdateScore( int row , int col, int *Width, int *Height, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *playerInput, char arr[ 100 ][ 100 ] )
{
    int score = 0;

    if( col + 3 <= *Width && arr[ row ][ col ] == arr[ row ][ col + 1 ]
       && arr[ row ][ col ] == arr[ row ][ col + 2 ] && arr[ row ][ col ] == arr[ row ][ col + 3 ] )
    {
        score++;
    }

    if( col - 3 >= 0 && arr[ row ][ col ] == arr[ row ][ col - 1 ] && arr[ row ][ col ] = arr[ row ][ col - 2 ] 
        && arr[ row ][ col ] == arr[ row ][ col - 3 ] )
    {
        score++;
    }

    if( col - 1 >= 0 && col + 2 <= *Width && arr[ row ][ col ] == arr[ row ][ col - 1 ]
        && arr[ row ][ col ] == arr[ row ][ col + 1 ] && arr[ row ][ col ] == arr[ row ][ col + 2 ] )
    {
        score++;
    }

    if( col - 2 >= 0 && col + 1 <= *Width && arr[ row ][ col ] == arr[ row ][ col - 1 ]
        && arr[ row ][ col ] == arr[ row ][ col - 2 ] && arr[ row ][ col ] == arr[ row ][ col + 1 ] )
    {
        score++;
    }

    if( row - 3 >= 0 && arr[ row ][ col ] == arr[ row - 1 ][ col ] && arr[ row ][ col ] == arr[ row - 2 ][ col ]
       && arr[ row ][ col ] == arr[ row - 3 ][ col ] )
    {
        score++;
    }

    if ( row + 3 <= *Height && arr[ row ][ col ] == arr[ row + 1 ][ col ] && arr[ row ][ col ] == arr[ row + 2 ][ col ] 
        && arr[ row ][ col ] == arr[ row + 3 ][ col ] )
    {
        score++;
    }

    if ( row - 3 >= 0 && col + 3 <= *Width && arr[ row ][ col ] == arr[ row - 1 ][ col + 1 ]
        && arr[ row ][ col ] == arr[ row - 2 ][ col + 2 ] && arr[ row ][ col ] == arr[ row - 3 ][ col + 3 ] )
    {
        score++;
    }
    if( row + 3 <= *Height && col + 3 <= *Width && arr[ row ][ col ] == arr[ row + 1 ][ col + 1 ]
        && arr[ row ][ col ] == arr[ row + 2 ][ col + 2 ] && arr[ row ][ col ] == arr[ row + 3 ][ col + 3 ] )
    {
        score++;
    }
    if( col + 1 <= *Width && row - 1 >= 0 && col - 2 >=0 && row + 2 <= *Height
        && arr[ row ][ col ] == arr[ row - 1 ][ col + 1 ] && arr[ row ][ col ] == arr[ row + 1 ][ col - 1 ]
        && arr[ row ][ col ] == arr[ row + 2 ][ col - 2 ] )
    {
        score++;
    }
    if( col + 2 <= *Width && row - 2 >= 0 && col - 1 >= 0 && row + 1 <= *Height
       && arr[ row ][ col ] == arr[ row - 1 ][ col + 1 ] && arr[ row ][ col ] == arr[ row - 2 ][ col + 2 ]
       && arr[ row ][ col ] == arr[ row + 1 ][ col - 1 ] )
    {
        score++;
    }
    if( col - 3 >= 0 && row - 3 >= 0 && arr[ row ][ col ] == arr[ row - 1 ][ col - 1 ]
        && arr[ row ][ col ] == arr[ row - 2 ][ col - 2 ] && arr[ row ][ col ] == arr[ row - 3 ][ col - 3 ] )
    {
        score++;
    }
    if( col - 3 >= 0 && row + 3 <= *Height && arr[ row ][ col ] == arr[ row + 1 ][ col - 1 ]
       && arr[ row ][ col ] == arr[ row + 2 ][ col - 2 ] && arr[ row ][ col ] == arr[ row + 3 ][ col - 3 ] )
    {
        score++;
    }
    if( col + 1 <= *Width && row + 1 <= *Height && col - 2 >= 0 && row - 2 >= 0
        && arr[ row ][ col ] == arr[ row - 1 ][ col - 1 ] && arr[ row ][ col ] == arr[ row - 2 ][ col - 2 ]
        && arr[ row ][ col ] == arr[ row + 1 ][ col + 1 ] )
    {
        score++;
    }
    if( col + 2 <= *Width && row + 2 <= *Height && col - 1 >= 0 && row - 1 >= 0
        && arr[ row ][ col ] == arr[ row - 1 ][ col - 1 ] && arr[ row ][ col ] == arr[ row + 1 ][ col + 1 ]
        && arr[ row ][ col ] == arr[ row + 2 ][ col + 2 ] )
    {
        score++;
    }
    if ( *numberOfPlay % 2 != 0 )
    {
        if ( playerInput[ 0 ] == 'U' )
        {
            *scoreOne -= score;
        }
        else
        {
            *scoreOne += score;
        }
    }
    else
    {
        if ( playerInput[ 0 ] == 'U' )
        {
            *scoreTwo -= score;
        }
        else
        {
            *scoreTwo += score;
        }
    }
}
