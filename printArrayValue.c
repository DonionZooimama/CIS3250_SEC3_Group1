#include "header.h"

//Ronnie
void PrintArrayValue(int *Height , int *Width, int *scoreOne, int *scoreTwo, char arr[100][100]) 
{
    int counter1 , counter2 ; 
    int flag = 0;

    printf("\n\n\t>> Connect 4 \"Have fun\" <<",BLUE);
    printf("\n\n\tScore one = %d",*scoreOne,GREEN);
    printf("\t\t\tScore Two = %d",*scoreTwo,BLUE);
    printf("\n\n");

    for (counter1 = 0 ; counter1 < *Height ; counter1++)
    {

        for(counter2 = 0 ; counter2 < *Width && flag == 0; counter2++)
        {
            printf("[ %d ] ",counter2+1,BLUE);
        }
        printf("\n");

        for(counter2 = 0 ; counter2 < *Width ; counter2++)
        {
            printf("***** ",RED);
        }

        printf("\n");
        for(counter2 = 0 ; counter2 < *Width ; counter2++)
        {
            printf("*   * ",RED);
        }

        printf("\n");
        for(counter2 = 0 ; counter2 < *Width ; counter2++)
        {
            printf("* ",RED);

            if (arr[counter1][counter2] == 'X')
            {
                printf("%c ",arr[counter1][counter2],GREEN);
            }
            else if (arr[counter1][counter2] == 'O')
            {
                printf("%c ",arr[counter1][counter2],BLUE);
            }
            else
            {
                printf("%c ",arr[counter1][counter2],INTENSITY);
            }
            printf("* ",RED);
        }

        printf("\n");
        for(counter2 = 0 ; counter2 < *Width ; counter2++)
        {
            printf("*   * ",RED);
        }

        printf("\n");
        for(counter2 = 0 ; counter2 < *Width ; counter2++)
        {
            printf("***** ",RED);
        }

        flag = 1;
    }
    printf("\n\n(U) to make Undo",INTENSITY);
    printf("\n(R) to make Redo ",GREEN);
    printf("\n(S) to save\n",BLUE);
}