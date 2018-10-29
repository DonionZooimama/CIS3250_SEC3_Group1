#include "header.h"

//Daniel
void UpdateScore(int row , int col, int *width, int *height, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *playerInput, char arr[100][100])
{
    int score = 0;

    if(col+3 <= *width && arr[row][col] == arr[row][col+1] && arr[row][col] ==
            arr[row][col+2] && arr[row][col] == arr[row][col+3] )
    {
        score++;
    }

    if (col-3 >= 0 && arr[row][col] == arr[row][col-1] && arr[row][col] ==
            arr[row][col-2] && arr[row][col] == arr[row][col-3] )
    {
        score++;
    }

    if ( col - 1 >= 0 && col + 2 <= *width && arr[row][col] == arr[row][col-1] &&
            arr[row][col] == arr[row][col+1] && arr[row][col] == arr[row][col+2] )
    {
        score++;
    }

    if (col - 2 >= 0 && col + 1 <= *width && arr[row][col] == arr[row][col-1] &&
            arr[row][col] == arr[row][col-2] && arr[row][col] == arr[row][col+1] )
    {
        score++;
    }

    if(row - 3 >= 0 && arr[row][col] == arr[row-1][col] && arr[row][col] ==
            arr[row-2][col]&& arr[row][col] == arr[row-3][col] )
    {
        score++;
    }

    if (row + 3 <= *height && arr[row][col] == arr[row+1][col] && arr[row][col] ==
            arr[row+2][col] && arr[row][col] == arr[row+3][col] )
    {
        score++;
    }

    if (row - 3 >= 0 && col+3 <= *width && arr[row][col] == arr[row-1][col+1] &&
            arr[row][col] == arr[row-2][col+2] && arr[row][col] == arr[row-3][col+3] )
    {
        score++;
    }
    if (row + 3 <= *height && col+3 <= *width && arr[row][col] == arr[row+1][col+1]
            && arr[row][col] == arr[row+2][col+2] && arr[row][col] == arr[row+3][col+3])
    {
        score++;
    }
    if (col + 1 <= *width && row - 1 >= 0 && col - 2 >=0 && row + 2 <= *height &&
            arr[row][col] == arr[row-1][col+1] && arr[row][col] == arr[row+1][col-1] &&
            arr[row][col] == arr[row+2][col-2])
    {
        score++;
    }
    if(col + 2 <= *width && row - 2 >= 0 && col - 1 >= 0 && row + 1 <= *height &&
            arr[row][col] == arr[row-1][col+1] && arr[row][col] == arr[row-2][col+2] &&
            arr[row][col] == arr[row+1][col-1])
    {
        score++;
    }
    if (col - 3 >= 0 && row - 3 >= 0 && arr[row][col] == arr[row-1][col-1] &&
            arr[row][col] == arr[row-2][col-2] && arr[row][col] == arr[row-3][col-3] )
    {
        score++;
    }
    if (col - 3 >= 0 && row + 3 <= *height && arr[row][col] == arr[row+1][col-1]
            && arr[row][col] == arr[row+2][col-2] && arr[row][col] == arr[row+3][col-3])
    {
        score++;
    }
    if (col + 1 <= *width && row + 1 <= *height && col - 2 >=0 && row - 2 >= 0 &&
            arr[row][col] == arr[row-1][col-1] && arr[row][col] == arr[row-2][col-2] &&
            arr[row][col] == arr[row+1][col+1])
    {
        score++;
    }
    if (col + 2 <= *width && row + 2 <= *height && col - 1 >= 0 && row - 1 >= 0 &&
            arr[row][col] == arr[row-1][col-1] && arr[row][col] == arr[row+1][col+1] &&
            arr[row][col] == arr[row+2][col+2])
    {
        score++;
    }
    if (*numberOfPlay % 2 != 0)
    {
        if (playerInput[0] == 'U')
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
        if (playerInput[0] == 'U')
        {
            *scoreTwo -= score;
        }
        else
        {
            *scoreTwo += score;
        }
    }
}