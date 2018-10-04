#include "header.h"

//Daniel
void playAgain()
{
    printf("\n\t>>this move isn't valid \n\n >>do another move<< ",RED);
    scanf("%s",playerInput);
    player( playerInput , numberOfPlay);
}