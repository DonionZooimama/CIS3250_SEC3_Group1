
Assignment 3 readMe
Section: 3
Group: 1
Team Members:
Jordan Evans: 0964044
Ajai Gill: 1015577
Derek Bowman: 0993439
Daniel Ziorli: 1016491
Ronnie Tran: 1022485
William Moskal: 1011940
Date of Submission: October 29th 2018
Time of Submission: 11:20 A.M.
Program Purpose: The program is a version of connect 4, in which either 2 human players
can play, or a human player, and a computer player can play.

Program Functionality: The program loads XML file representing the size of the board, then
prompts for user input on the game type. From then on, the players enter which place they
want to place their piece, and the computer places a random piece.

How to run the program: run make clean, then run make All, then run make main, run the file
with ./bin/main

Files contained in Submission:
src
arrInitialization.c
computerPlayer.c
highScoresList.c
loadGame.c
main.c
playAgain.c
player.c
printArrValue.c
readXML.c
redo.c
saveGame.c
undo.c
updateScore.c
bin
includes
header.h
In the root, there is
ReadMe.md
data.XML
makefile

Assumptions:
- For the program to run successfully, the ‘data.xml’ file must be present and valid in
the root folder of the program. The data.xml file must follow the following format:
<Configurations>
<Width>INT</Width>
<Height>INT</Height>
<Highscores></Highscores>
</Configurations>

- Where width is an integer between 1 and 10, height is an integer between 1 and 10
and highscores is an optional integer greater than 0.
- At the end of the game, the feature to play again is not working. When asked to play
again, choose to exit the program and re-run it if you would like to play again.
- The highscores list doesn’t work.


Link to individual reviews done by Sec3Group2: https://trello.com/c/45raBZw7
Link to team review done by Sec3Group2: https://trello.com/c/8SJr73BV
