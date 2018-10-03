All: updateScore undo saveGame redo readXML printArrayValue player playAgain loadGame highScoresList computerPlayer arrInitialization

updateScore: updateScore.c header.h
	gcc -Wall -pedantic -std=c11 -c updateScore.c -o updateScore.o
	
undo: undo.c header.h
	gcc -Wall -pedantic -std=c11 -c undo.c -o undo.o
	
saveGame: saveGame.c header.h
	gcc -Wall -pedantic -std=c11 -c saveGame.c -o saveGame.o
	
redo: redo.c header.h
	gcc -Wall -pedantic -std=c11 -c redo.c -o redo.o
	
readXML: readXML.c header.h
	gcc -Wall -pedantic -std=c11 -c readXML.c -o readXML.o
	
printArrayValue: printArrayValue.c header.h
	gcc -Wall -pedantic -std=c11 -c printArrayValue.c -o printArrayValue.o
	
player: player.c header.h
	gcc -Wall -pedantic -std=c11 -c player.c -o player.o
	
playAgain: playAgain.c header.h
	gcc -Wall -pedantic -std=c11 -c playAgain.c -o playAgain.o
	
loadGame: loadGame.c header.h
	gcc -Wall -pedantic -std=c11 -c loadGame.c -o loadGame.o
	
highScoresList: highScoresList.c header.h
	gcc -Wall -pedantic -std=c11 -c highScoresList.c -o highScoresList.o
	
computerPlayer: computerPlayer.c header.h
	gcc -Wall -pedantic -std=c11 -c computerPlayer.c -o computerPlayer.o
	
arrInitialization: arrInitialization.c header.h
	gcc -Wall -pedantic -std=c11 -c arrInitialization.c -o arrInitialization.o