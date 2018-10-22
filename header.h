#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ArrInitialization(int Height , int Width, char arr[100][100]);

void SaveGame(int *Width, int *Height, int *Highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, char whichPlayer, int *savePlace, int *restorePlace, char arr[100][100], char *arrSaveAction, char *arrRestorePlace, char *playerInput);

void HighScoresList(int flag, int *HighScoreList, int *listLength, int *Highscores, int scoreOne, int scoreTwo);

void ReadXML(int *Width, int *Height, int *Highscores);

void LoadGame(int *Width, int *Height, int *Highscores, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *whichPlayer, int *savePlace, int *restorePlace, char arr[100][100]);

void PrintArrayValue(int *Height , int *Width, int *scoreOne, int *scoreTwo, char arr[100][100]);

void UpdateScore(int row , int col, int *Width, int *Height, int *numberOfPlay, int *scoreOne, int *scoreTwo, char *playerInput, char arr[100][100]);

void Player (char *numberOfCol , int *numberOfPlay, int *Height, char arr[100][100], char *arrSaveAction, int *savePlace, int *Width, int *Highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace);

void ComputerPlayer(char arr[100][100], int *Height, int *Width, int *restorePlace, char *arrSaveAction, int *savePlace, int *scoreOne, int *scoreTwo, int *numberOfPlay, char *playerInput);

void PlayAgain(char *playerInput , int *numberOfPlay, int *Height, char arr[100][100], char *arrSaveAction, int *savePlace, int *Width, int *Highscores, int *restorePlace, int *gameOut, char whichPlayer, int *scoreOne, int *scoreTwo, char *arrRestorePlace);

void Undo(int *savePlace, int *restorePlace, int *Height, int *Width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *Highscores, int *gameOut, char whichPlayer, char *arrSaveAction, char *arrRestorePlace, char *playerInput, char arr[100][100]);

void Redo(int *restorePlace, int *Height, int *Width, int *numberOfPlay, int *scoreOne, int *scoreTwo, int *gameOut, int *Highscores, int *savePlace, char whichPlayer, char *playerInput, char *arrRestorePlace, char arr[100][100], char *arrSaveAction);

#endif
