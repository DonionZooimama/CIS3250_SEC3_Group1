All: updateScore undo saveGame redo readXML printArrayValue player playAgain loadGame highScoresList computerPlayer arrInitialization

main:
	gcc -Wall -pedantic -std=c11 bin/*.o src/main.c -o bin/main -Iincludes

test:
	gcc -Wall -pedantic -std=c11 src/*.c -o bin/main -Iincludes

updateScore: 
	gcc -Wall -pedantic -std=c11 -c src/updateScore.c -o bin/updateScore.o -Iincludes
	
undo: 
	gcc -Wall -pedantic -std=c11 -c src/undo.c -o bin/undo.o -Iincludes
	
saveGame: 
	gcc -Wall -pedantic -std=c11 -c src/saveGame.c -o bin/saveGame.o -Iincludes
	
redo: 
	gcc -Wall -pedantic -std=c11 -c src/redo.c -o bin/redo.o -Iincludes
	
readXML: 
	gcc -Wall -pedantic -std=c11 -c src/readXML.c -o bin/readXML.o -Iincludes
	
printArrayValue:
	gcc -Wall -pedantic -std=c11 -c src/printArrayValue.c -o bin/printArrayValue.o -Iincludes
	
player:
	gcc -Wall -pedantic -std=c11 -c src/player.c -o bin/player.o -Iincludes
	
playAgain:
	gcc -Wall -pedantic -std=c11 -c src/playAgain.c -o bin/playAgain.o -Iincludes
	
loadGame: 
	gcc -Wall -pedantic -std=c11 -c src/loadGame.c -o bin/loadGame.o -Iincludes
	
highScoresList:
	gcc -Wall -pedantic -std=c11 -c src/highScoresList.c -o bin/highScoresList.o -Iincludes
	
computerPlayer:
	gcc -Wall -pedantic -std=c11 -c src/computerPlayer.c -o bin/computerPlayer.o -Iincludes
	
arrInitialization:
	gcc -Wall -pedantic -std=c11 -c src/arrInitialization.c -o bin/arrInitialization.o -Iincludes
	
clean:
	rm bin/*