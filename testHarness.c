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

	const int TOTAL_TEST_AMOUNT = 1;
	int cur_test_num = 0;
 
    Error err[TOTAL_TEST_AMOUNT];
    
    //TESTS


    // Print test results
    for(int i = 0; i < TOTAL_TEST_AMOUNT; i++){
    	char* res = PrintResult((const)err[i]);
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


    // TEST ONE
    ResetVariables(&arrSaveAction, &highscores, &gameOut, &scoreOne, &scoreTwo, &arrRestorePlace);
    ArrInitialization(height, width, arr);


    Player( &playerInput , &numberOfPlay, &height, arr, &arrSaveAction, &savePlace, &width, &highscores, 
        	            &restorePlace, &gameOut, &whichPlayer, &scoreOne, &scoreTwo, &arrRestorePlace );

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
    	strcpy(err[*test_number].message, "Test 1 passed.");
    }
    else {
    	err[*test_number].success = false;
		strcpy(err[*test_number].message, "");
    	// Additional for handling specific errors
    	if(playerInput != playerInput_out){
			sprintf(err[*test_number].message, "Expected output: %d, actual output: %d\n", playerInput, playerInput_out);
    	}
        if(numberOfPlay != numberOfPlay_out){
			char buffer[500] = "";
	        sprintf(buffer, "Expected output: %d, actual output: %d\n", numberOfPlay, numberOfPlay_out);
			strcat(err[*test_number].message, buffer);
    	}
        if( height != height_out){
			char buffer[500] = "";
	       	sprintf(buffer, "Expected output: %d, actual output: %d\n", height, height_out);
			strcat(err[*test_number].message, buffer);
		}
        if(savePlace != savePlace_out){
			char buffer[500] = "";
	       	sprintf(buffer, "Expected output: %d, actual output: %d\n", savePlace, savePlace_out);
			strcat(err[*test_number].message, buffer);
		}
        if(width != width_out){
			char buffer[500] = "";
	       	sprintf(buffer, "Expected output: %d, actual output: %d\n", width, width_out);
			strcat(err[*test_number].message, buffer);
		}
        if(whichPlayer != whichPlayer_out){
			char buffer[500] = "";
	       	sprintf(buffer, "Expected output: %d, actual output: %d\n", whichPlayer, whichPlayer_out);
			strcat(err[*test_number].message, buffer);
		}
   	
    }

    *test_number++;

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
		strcat(ret, " at ");
		strcat(ret, to_print.location);
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

void Undo(int *savePlace, int *restorePlace, int *height, int *width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *highscores, int *gameOut, char whichPlayer, char *arrSaveAction, char *arrRestorePlace, char *playerInput, char arr[100][100]){
	printf("Undo function called\n");
}

void Redo(int *restorePlace, int *height, int *width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, int *highscores, int *savePlace, char whichPlayer, char *playerInput, char *arrRestorePlace, char arr[100][100], char *arrSaveAction){
	printf("Redo function called\n");
}

void SaveGame(int *width, int *height, int *highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, char whichPlayer, int *savePlace, int *restorePlace, char arr[100][100], char *arrSaveAction, char *arrRestorePlace, char *playerInput){
	printf("Save game function called\n");
}

void PrintArrayValue(int *height , int *width, int *scoreOne, int *scoreTwo, char arr[100][100]){
	printf("Print array value function called\n");
}
void UpdateScore(int row , int col, int *width, int *height, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *playerInput, char arr[100][100]){
	printf("Update score function called\n");
}
void ComputerPlayer(char arr[100][100], int *height, int *width, int *restorePlace, char *arrSaveAction, int *savePlace, int *scoreOne, int *scoreTwo, int *numberOfPlay, char *playerInput){
	printf("Computer player function called\n");
}
void PlayAgain(char *playerInput , int *numberOfPlay, int *height, char arr[100][100], char *arrSaveAction, int *savePlace, int *width, int *highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace){
	printf("Play again function called\n");
}

