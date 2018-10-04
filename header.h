#ifndef HEADER
#define HEADER

#include<stdio.h>
#include<strings.h>
#include <windows.h>
#define BLUE SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE )
#define RED SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED)
#define INTENSITY SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY)
#define GREEN SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN)

void arrInitialization(int Height , int Width);
void saveGame();
void HighScoresList(int flag);
void ReadXML(int Width, int Height, int Highscores);
void loadGame();
void PrintArrayValue(int Height , int Width);
void updateScore(int row , int col);
void player (char numberOfcol , int numberOfPlay);
void computerPlayer();
void playAgain();
void Undo();
void Redo();

#endif
