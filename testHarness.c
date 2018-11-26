#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void* ResetVariables(
	char *playerInput, int  *numberOfPlay, int  *height, char arr[ 100 ][ 100 ],
	char *arrSaveAction, int  *savePlace, int  *width, int  *highscores, 
    int  *restorePlace, int  *gameOut, char whichPlayer, int  *scoreOne, 
    int  *scoreTwo, char *arrRestorePlace);
char* PrintResult(const Error to_print);
void ArrInitialization(int height, int width, char arr[100][100]);

// CHECK TO CODING CONVENTION

/* Struct to represent the output of a test. For simplicity's sake it is
 * just two strings to represent the location of the failure, and the 
 * message attached to the failure. Also a boolean to indicate if the
 * test was passed/failed, and an int to represent what test number it is.
 * Don't dynamically allocate this struct.
 */
typedef struct error_code {
	int  testNum;
	bool success;
	char location[255];
	char message[1000];
} Error;


int main(int argc, char** argv){

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
	
	char playerInput; 
    int  numberOfPlay; 
    int  height;
    char arr[ 100 ][ 100 ];
	char arrSaveAction;
    int  savePlace; 
    int  width;
    int  highscores;
    int  restorePlace; 
    int  gameOut;
	char whichPlayer; 
    int  scoreOne; 
    int  scoreTwo;
    char arrRestorePlace;

    // Initialize the error messages
    int curTest = 0;
    int amtOfTests = 1;
    Error err[amtOfTests];
    for(int i = 0; i < amtOfTests; i++){
    	err[i].testNum = i+1;
    }


    /*
    Ideally the below code would run through a loop to set all of the error structs
    then they could be iterated and printed at the end. Due to the fact that the Player
    function runs completely on a lot of pointers, I cant think of a way to do that.
    My initial thought was to create a 2D character array of the success conditions
    of each variable for each test:

    e.g successConditions[testNum][varNum]
    	successConditions[4][7] would give the successful value of width in test 5

	This seems like it is waaaay too many variables to keep track of though so we
	may just have to hardcode each test we do.
	
	Either way, I layed out the basic test structure as follows:
	1. Reset all the variables to a default value
	2. Set the variables that affect code logic (hardcoded for now)
	3. Initialize the board based on your height and width.
	   NOTE: If we want to alter the board before the test, that must
	   		 be done manually unfortunatelyu.
	4. Run player function with desired values
	5. Compare altered values to check for success/failure and set error messages
	6. Increase curTest by 1
	7. (Ideally) Repeat.
	*/

    // TEST ONE
    ResetVariables(&playerInput, &numberOfPlay, &height, &arrSaveAction,
    			   &savePlace, &width, &highscores, &restorePlace, &gameOut, 
    			   &whichPlayer, &scoreOne, &scoreTwo, &arrRestorePlace);

    playerInput = 
    numberOfPlay = 
    height =
    width = 
    whichPlayer = 
    ArrInitialization(height, width, arr);

    Player( playerInput , &numberOfPlay, &height, arr, arrSaveAction, &savePlace, &width, &highscores, 
        	            &restorePlace, &gameOut, whichPlayer, &scoreOne, &scoreTwo, arrRestorePlace );

    // Check all variables for the success 
    if(
    	playerInput     == XX  &&
    	numberOfPlay    == XX  &&
    	height          == XX  &&
		arrSaveAction   == XX  &&
    	savePlace       == XX  &&
    	width           == XX  &&
    	highscores      == XX  &&
    	restorePlace    == XX  &&
    	gameOut         == XX  &&
		whichPlayer     == XX  &&
    	scoreOne        == XX  &&
    	scoreTwo        == XX  &&
    	arrRestorePlace == XX  ){

    	err[curTest].success = true;
    	strcpy(err[curTest].location, "");
    	strcpy(err[curTest].message, "Test 1 passed.");
    }
    else {
    	err[curTest].success = false;
    	// Additional for handling specific errors
    	if(){

    	}
    	else if(){

    	}
    	else {

    	}
    }

    curTest++;
    


    // Print test results
    for(int i = 0; i < amtOfTests; i++){
    	char* res = PrintResult((const)err[i]);
    	if(res != NULL){
    		printf("%s\n", res);
    		free(res);
    	}
    	else {
    		printf("Error printing results of test %d\n", (i+1));
    	}
    }

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
	char *playerInput , 
    int  *numberOfPlay , 
    int  *height, 
	char *arrSaveAction, 
    int  *savePlace, 
    int  *width, 
    int  *highscores, 
    int  *restorePlace, 
    int  *gameOut,
	char whichPlayer, 
    int  *scoreOne, 
    int  *scoreTwo, 
    char *arrRestorePlace
	) {

	&playerInput     = '0';
	&numberOfPlay    =  0;
	&height          =  0;
	&arrSaveAction   = '0';
	&savePlace       =  0;
	&width           =  0;
	&highscores      =  0;
	&restorePlace    =  0;
	&gameOut         =  0;
	&whichPlayer     = 'H';
	&scoreOne        =  0;
	&scoreTwo        =  0;
	&arrRestorePlace = '0';

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