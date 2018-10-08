#include "header.h"

//Ronnie
void arrInitialization(int Height , int Width, char arr[100][100]) 
      {
    int counter1 , counter2 ; 
    for (counter1 = 0 ; counter1 < Height ; counter1++)
    {
        for(counter2 = 0 ; counter2 < Width ; counter2++)
        {
            arr[counter1][counter2] = '-' ;
        }
    }
} 