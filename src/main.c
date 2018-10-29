#include "header.h"

int main(int argc, char** argv){
	char arr[ 100 ][ 100 ];
	char arrSaveAction[ 100 ] = { 0 }; 
	char arrRestorePlace[ 100 ] = { 0 }; 
	char playerInput[ 20 ];
	char whichPlayer = ' ';
	char userChoice = 'C';
	char option = ' ';

	int width = 0;
	int height = 0;
	int highscores = 0;
	int numberOfPlay = 1;
	int savePlace = 0;
	int restorePlace = 0;
	int scoreOne = 0;
	int scoreTwo = 0;
	int gameOut = 0;
	int highScoreList[ 50 ] = { 0 };
	int listLength = 0;
	int flag = 0;

    while ( userChoice == 'C' )
    {
        printf( "\nIf You Want To Load The Saved Game >> Enter L <<Else Enter Any thing " );
        scanf( "%s", &option );

        if ( option == 'L' )
        {
           LoadGame( &width, &height, &highscores, &numberOfPlay, &scoreOne, &scoreTwo, &whichPlayer, &savePlace, &restorePlace, arr );
        }
        else
        {
            printf( "\n\t >> Human vs. Human << \n OR \n\t >> Human vs. Computer <<\n" );
            printf( "\n>>Enter (H) if two player && (C) if one player\n" );
			scanf( "%s", &whichPlayer );

            while ( whichPlayer != 'H' && whichPlayer != 'C' )
            {
                printf( "\nsome thing error please enter again\n" );
                scanf( "%s", &whichPlayer );
            }
			numberOfPlay = 1;
			savePlace = 0;
			restorePlace = 0;
			scoreOne = 0;
			scoreTwo = 0;
            ReadXML(&width, &height, &highscores);
            ArrInitialization(height, width, arr);
        }
		gameOut = 0;
		printf("\n\nnumber of play: %d\n\n", numberOfPlay);
        while ( width * height >= numberOfPlay && gameOut != 1 )
        {
            PrintArrayValue( &height, &width, &scoreOne, &scoreTwo, arr );

            if ( numberOfPlay % 2 != 0 )
            {
                printf( "\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8" );
                printf( "\t player1<<Enter your play>> = " );
                scanf( "%s", playerInput );
                Player( playerInput , &numberOfPlay, &height, arr, arrSaveAction, &savePlace, &width, &highscores, 
        	        &restorePlace, &gameOut, whichPlayer, &scoreOne, &scoreTwo, arrRestorePlace );
                numberOfPlay++;
            }
            else
            {
                if ( whichPlayer == 'H' )
                {
                    printf( "\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`" );
                    printf( "\tplayer2<<Enter your play>> = " );
                    scanf( "%s", playerInput );
                    Player( playerInput , &numberOfPlay, &height, arr, arrSaveAction, &savePlace, &width, &highscores, 
        	            &restorePlace, &gameOut, whichPlayer, &scoreOne, &scoreTwo, arrRestorePlace );
                }
                else
                {
                    ComputerPlayer( arr, &height, &width, &restorePlace, arrSaveAction, &savePlace, &scoreOne, &scoreTwo, &numberOfPlay, playerInput );
                }
                
                numberOfPlay++;  
            }
        }

        PrintArrayValue( &height, &width, &scoreOne, &scoreTwo, arr );
        if ( numberOfPlay - 1 == width * height )
        {
            if ( scoreOne > scoreTwo )
            {
                printf( "\n\n\t***player One is winner***" );
                printf( " \n\t **Hard luck player Two**\n" );
            }
            else if ( scoreOne < scoreTwo )
            {
                printf( "\n\n\t***player Two is winner***" );
                printf( " \n\t **Hard luck player One**\n" );
            }
            else
            {
                printf( "\n\n\t***The two score is equivalent***\n\n" );
            }
                flag = 1;		
                HighScoresList( flag, highScoreList, &listLength, &highscores, scoreOne, scoreTwo );
            }
            printf( "\n\nYou Want To Continue Enter C else Enter any thing " );
            scanf( "%s", &userChoice );
        }

    return 0;
}


