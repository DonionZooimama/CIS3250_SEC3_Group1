#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

// CHECK TO CODING CONVENTION

/* Struct to represent the output of a test. For simplicity's sake it is
 * just two strings to represent the location of the failure, and the 
 * message attached to the failure. Also a boolean to indicate if the
 * test was passed/failed, and an int to represent what test number it is.
 * Don't dynamically allocate this struct.
 */

int main(int argc, char** argv){

	const int TOTAL_TEST_AMOUNT = 8;
	int cur_test_num = 0;
 
    Error err[TOTAL_TEST_AMOUNT];
    
    //TESTS
    /*
	Test Cases – Data flow group
	tests if(convert == 0)
	driver(err, testNo , “Y”, 0, 5, 5, “P”, 0, 0,“Y”, 0, 5, 5, “P”, 0, 0);
	tests else
	driver(err, testNo , “1”, 0, 5, 5, “P”, 0, 0,“1”, 0, 5, 5, “P”, 0, 0);
	tests if(playerInput[0] == ‘U’)
	driver(err, testNo, “U”, 0, 5, 5, “P”, 1, 0, “U”, 0, 5 ,5 “P”, 0, 1);
	tests if(playerInput[0] != ‘U’)
	driver(err, testNo , “f”, 0, 5, 5, “P”, 0, 0,“f”, 0, 5, 5, “P”, 0, 0);
	tests if(playerInput[0] == ‘R’)
	driver(err, testNo, “R”, 0, 5, 5, “P”, 0, 1, “R”, 0, 5 ,5 “P”, 1, 0);
	tests if(playerInput[0] != ‘R’ )
	driver(err, testNo , “f”, 0, 5, 5, “P”, 0, 0,“f”, 0, 5, 5, “P”, 0, 0);
	tests if(playerInput[0] == ‘S’)
	driver(err, testNo, “S”, 0, 5, 5, “P”, 0, 0, “S”, 0, 5 ,5 “P”, 0, 0);
	tests if(playerInput[0] != ‘S’
	driver(err, testNo , “f”, 0, 5, 5, “P”, 0, 0,“f”, 0, 5, 5, “P”, 0, 0);
    */

    //tests if(convert == 0)
	driver(err, &cur_test_num , 'Y', 0, 5, 5, 'P', 0, 0, 'Y', 0, 5, 5, 'P', 0, 0);
	//tests else
	driver(err, &cur_test_num , '1', 0, 5, 5, 'P', 0, 0, '1', 0, 5, 5, 'P', 0, 0);
	//tests if(playerInput[0] == ‘U’)
	driver(err, &cur_test_num , 'U', 0, 5, 5, 'P', 1, 0, 'U', 0, 5, 5, 'P', 0, 1);
	//tests if(playerInput[0] != ‘U’)
	driver(err, &cur_test_num , 'f', 0, 5, 5, 'P', 0, 0, 'f', 0, 5, 5, 'P', 0, 0);
	//tests if(playerInput[0] == ‘R’)
	driver(err, &cur_test_num , 'R', 0, 5, 5, 'P', 0, 1, 'R', 0, 5, 5, 'P', 1, 0);
	//tests if(playerInput[0] != ‘R’ )
	driver(err, &cur_test_num , 'f', 0, 5, 5, 'P', 0, 0, 'f', 0, 5, 5, 'P', 0, 0);
	//tests if(playerInput[0] == ‘S’)
	driver(err, &cur_test_num , 'S', 0, 5, 5, 'P', 0, 0, 'S', 0, 5, 5, 'P', 0, 0);
	//tests if(playerInput[0] != ‘S’
	driver(err, &cur_test_num , 'f', 0, 5, 5, 'P', 0, 0, 'f', 0, 5, 5, 'P', 0, 0);


    // Print test results
    for(int i = 0; i < TOTAL_TEST_AMOUNT; i++){
    	char* res = PrintResult((const Error)err[i]);
    	if(res != NULL){
    		printf("%s\n", res);
    		free(res);
    	}
    	else {
    		printf("Error printing results of test %d\n", (i+1));
    	}
    }

}

int driver(Error* err, int* test_number, char playerInput, int numberOfPlay, int height, int width, char whichPlayer, int savePlace, int restorePlace, 
		   char playerInput_out, int numberOfPlay_out, int height_out, int width_out, char whichPlayer_out, int savePlace_out, int restorePlace_out){

/*
	
	=>	Test Variables for Player
	char *playerInput , 	=> Affects logic path
    int  *numberOfPlay , 	=> Affects logic path
    int  *height, 			=> Affects logic path
    char arr[ 100 ][ 100 ],	=> Affects logic path
	char *arrSaveAction, 	=> Default: '0'
    int  *savePlace, 		=> Default:  0
    int  *width, 			=> Affects logic path
    int  *highscores, 		=> Default:  0
    int  *restorePlace, 	=> Default:  0
    int  *gameOut,			=> Default:  0
	char whichPlayer, 		=> Affects logic path
    int  *scoreOne, 		=> Default:  0
    int  *scoreTwo, 		=> Default:  0
    char *arrRestorePlace	=> Default: '0'
*/
 
    char arr[ 100 ][ 100 ];
	char arrSaveAction;
    int  highscores;
    int  gameOut;
    int  scoreOne; 
    int  scoreTwo;
    char arrRestorePlace;

    printf("Running test %d:\n", (*test_number+1));

    // TEST ONE
    ResetVariables(&arrSaveAction, &highscores, &gameOut, &scoreOne, &scoreTwo, &arrRestorePlace);
    ArrInitialization(height, width, arr);


    Player( &playerInput , &numberOfPlay, &height, arr, &arrSaveAction, &savePlace, &width, &highscores, 
        	            &restorePlace, &gameOut, whichPlayer, &scoreOne, &scoreTwo, &arrRestorePlace );

    err[*test_number].testNum = *test_number + 1;
    // Check all variables for the success 
    if(
    	playerInput     == playerInput_out    &&
    	numberOfPlay    == numberOfPlay_out   &&
    	height          == height_out         &&
    	savePlace       == savePlace_out      &&
    	width           == width_out          &&
    	restorePlace    == restorePlace_out   &&
		whichPlayer     == whichPlayer_out    ){

    	err[*test_number].success = true;
    	strcpy(err[*test_number].location, "");

    	char* buffer = malloc(sizeof(char) * 50);
        sprintf(buffer, "Test %d passed.\n", (*test_number+1));
		strcpy(err[*test_number].message, buffer);
		free(buffer);
    }
    else {
    	err[*test_number].success = false;
		strcpy(err[*test_number].message, "");
    	// Additional for handling specific errors
    	if(playerInput != playerInput_out){
			sprintf(err[*test_number].message, "Expected output: %d, actual output: %d", playerInput, playerInput_out);
    	}
        if(numberOfPlay != numberOfPlay_out){
			char* buffer = malloc(sizeof(char) * 200);
	        sprintf(buffer, "Expected output: %d, actual output: %d", numberOfPlay, numberOfPlay_out);
			strcat(err[*test_number].message, buffer);
			free(buffer);
    	}
        if( height != height_out){
			char* buffer = malloc(sizeof(char) * 200);
	       	sprintf(buffer, "Expected output: %d, actual output: %d", height, height_out);
			strcat(err[*test_number].message, buffer);
			free(buffer);
		}
        if(savePlace != savePlace_out){
			char* buffer = malloc(sizeof(char) * 200);
	       	sprintf(buffer, "Expected output: %d, actual output: %d", savePlace, savePlace_out);
			strcat(err[*test_number].message, buffer);
			free(buffer);
		}
        if(width != width_out){
			char* buffer = malloc(sizeof(char) * 200);
	       	sprintf(buffer, "Expected output: %d, actual output: %d", width, width_out);
			strcat(err[*test_number].message, buffer);
			free(buffer);
		}
        if(whichPlayer != whichPlayer_out){
			char* buffer = malloc(sizeof(char) * 200);
	       	sprintf(buffer, "Expected output: %d, actual output: %d\n", whichPlayer, whichPlayer_out);
			strcat(err[*test_number].message, buffer);
			free(buffer);
		}
   	
    }

    *test_number = *test_number + 1;

	return 0;
}

/* 
 *	PrintResult
 *	
 *	const Error to_print	-> T
 */
char* PrintResult(const Error to_print){
	
	char* ret = NULL;
	int retLen;

	if(to_print.success){
		retLen = 9 + strlen(to_print.message);
		ret = malloc(sizeof(char) * retLen);

		strcpy(ret, "[PASS]: ");
		strcat(ret, to_print.message);
	}
	else {
		retLen = 14 + strlen(to_print.message) + strlen(to_print.location);
		ret = malloc(sizeof(char) * retLen);

		strcpy(ret, "[FAIL]: ");
		strcat(ret, to_print.message);

        if(strcmp(to_print.location, "") != 0){
            strcat(ret, " at ");
            strcat(ret, to_print.location);
        }
		
	}

	return ret;
}

/*
 *
 */
void* ResetVariables(
	char *arrSaveAction, 
    int  *highscores, 
    int  *gameOut, 
    int  *scoreOne, 
    int  *scoreTwo, 
    char *arrRestorePlace
	) {

	*arrSaveAction   = '0';
	*highscores      =  0;
	*gameOut         =  0;
	*scoreOne        =  0;
	*scoreTwo        =  0;
	*arrRestorePlace = '0';

	return NULL;
}

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

void fillArrCol(int height, int width, char arr[100][100], int col_num){
    if(col_num >= width){
        printf("Invalid column to fill in fillArrCol()\n");
        return;
    }
    else {
        for(int i = 0; i < height; i++){
            if(i % 2 == 0){
                arr[i][col_num] = 'X';
            }
            else {
                arr[i][col_num] = 'O';
            }
            
        }
    }
}

// MODIFIED STUBS TO REMOVE PLAYER INPUT
// necessary in order to automate tests.

void Undo(int *savePlace, int *restorePlace, int *height, int *width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *highscores, int *gameOut, char whichPlayer, char *arrSaveAction, char *arrRestorePlace, char *playerInput, char arr[100][100]){
	
	int counter = 0;
    int flag = 0;
    int noOfCol = 0;
    
	if ( *savePlace != 0 )
    {
        *savePlace -= 1;
        noOfCol = arrSaveAction[ *savePlace ];
        arrRestorePlace[ *restorePlace ] = noOfCol;
        *restorePlace += 1;
        
        for ( counter = 0 ; counter < *height && flag == 0 ; counter++ )
        {
            if ( arr[ counter ][ noOfCol ] == 'X'
                ||  arr[ counter ][ noOfCol ] == 'O' )
            {
                //updates the board, and decreases the move number
                *numberOfPlay -= 1;
                UpdateScore( counter, noOfCol, width, height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr );
                arr[ counter ][ noOfCol ] = '-';
                
                flag = 1;
            }
        }
    }
}

void Redo(int *restorePlace, int *height, int *width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, int *highscores, int *savePlace, char whichPlayer, char *playerInput, char *arrRestorePlace, char arr[100][100], char *arrSaveAction){
	int i = 0;
	int flag = 0;
	int noOfCol = 0;

	
	//checks if there is a player move that can be restored
    if ( *restorePlace != 0 )
    {
        *restorePlace -= 1;
        noOfCol = arrRestorePlace[ *restorePlace ];
        *savePlace += 1;
		
		//finds the location in the game and places the correct symbol for the redo
        for ( i = 0 ; i < *height && flag == 0; i++ )
        {
            if ( arr[ *height - i - 1 ][ noOfCol ] == '-' )
            {
                if ( *numberOfPlay % 2 != 0 )
                {
                    arr[ *height - i - 1 ][ noOfCol ] = 'X';
                }
                else
                {
                    arr[ *height - i - 1 ][ noOfCol ] = 'O';
                }
                flag = 1;
            }
        }
		
        UpdateScore( *height - i , noOfCol, width, height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr );
        *numberOfPlay += 1;
    }
}

void SaveGame(int *width, int *height, int *highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, char whichPlayer, int *savePlace, int *restorePlace, char arr[100][100], char *arrSaveAction, char *arrRestorePlace, char *playerInput){
	return;
}

void PrintArrayValue(int *height , int *width, int *scoreOne, int *scoreTwo, char arr[100][100]){
	return;
}
void UpdateScore(int row , int col, int *width, int *height, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *playerInput, char arr[100][100]){
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
void ComputerPlayer(char arr[100][100], int *height, int *width, int *restorePlace, char *arrSaveAction, int *savePlace, int *scoreOne, int *scoreTwo, int *numberOfPlay, char *playerInput){
	int row = 0;
    int randomPlay = 0;
    int flag = 0;
    
    //checks if flag is equal to 0
    while ( flag == 0 )
    {
        //creates a random play
        randomPlay = rand() % ( *width );
        
        //loops from 0 to the height of the board
        for( row = 0 ; row < *height && flag == 0; row++ )
        {
            
            //If the board position has a piece already, then do nothing
            if( arr[ *height - row - 1 ][ randomPlay ] == 'X'
               || arr[ *height - row - 1 ][ randomPlay ] == 'O' )
            {
                
            }
            
            //otherwise, the board space is populated with an '0', In other words, the computer places a piece
            else
            {
                if ( row < *height )
                {
                    *restorePlace = 0;
                    //Sets the board location to 'O'
                    arr[ *height - row - 1 ][ randomPlay ] = 'O';
                    arrSaveAction[ *savePlace ] = ( randomPlay );
                    *savePlace += 1; //savePlave is incremented
                    UpdateScore( *height - row - 1 , randomPlay, width, height, numberOfPlay, scoreOne, scoreTwo, playerInput, arr ); //Score is updated

                    PrintArrayValue( height, width, scoreOne, scoreTwo, arr );
                    flag = 1;
                }
            }
        }
    }
}
void PlayAgain(char *playerInput , int *numberOfPlay, int *height, char arr[100][100], char *arrSaveAction, int *savePlace, int *width, int *highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace){
	*height = 999;
    *width  = 999;
}

