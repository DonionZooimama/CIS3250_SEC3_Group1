#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct error_code {
	int  testNum;
	bool success;
	char location[255];
	char message[1000];
} Error;

void Player (char *numberOfCol , int *numberOfPlay, int *height, char arr[100][100], char *arrSaveAction, int *savePlace, int *width, 
	int *highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace);

int driver(Error* err, int* test_number, char playerInput, int numberOfPlay, int height, int width, char whichPlayer, int savePlace, int restorePlace, 
		   char playerInput_out, int numberOfPlay_out, int height_out, int width_out, char whichPlayer_out, int savePlace_out, int restorePlace_out);

void* ResetVariables(char *arrSaveAction, int  *highscores, int *gameOut, int *scoreOne, int  *scoreTwo, char *arrRestorePlace);
char* PrintResult(const Error to_print);
void ArrInitialization(int height, int width, char arr[100][100]);
void fillArrCol(int height, int width, char arr[100][100], int col_num);
//STuBzzZzZ
void Undo(int *savePlace, int *restorePlace, int *height, int *width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *highscores, int *gameOut, char whichPlayer, char *arrSaveAction, char *arrRestorePlace, char *playerInput, char arr[100][100]);
void Redo(int *restorePlace, int *height, int *width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, int *highscores, int *savePlace, char whichPlayer, char *playerInput, char *arrRestorePlace, char arr[100][100], char *arrSaveAction);
void SaveGame(int *width, int *height, int *highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, char whichPlayer, int *savePlace, int *restorePlace, char arr[100][100], char *arrSaveAction, char *arrRestorePlace, char *playerInput);
void PrintArrayValue(int *height , int *width, int *scoreOne, int *scoreTwo, char arr[100][100]);
void UpdateScore(int row , int col, int *width, int *height, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *playerInput, char arr[100][100]);
void ComputerPlayer(char arr[100][100], int *height, int *width, int *restorePlace, char *arrSaveAction, int *savePlace, int *scoreOne, int *scoreTwo, int *numberOfPlay, char *playerInput);
void PlayAgain(char *playerInput , int *numberOfPlay, int *height, char arr[100][100], char *arrSaveAction, int *savePlace, int *width, int *highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace);


#endif
