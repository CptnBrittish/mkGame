make_game:
	g++  -o mkGame ./src/main.cpp ./src/parseInput.cpp ./src/board.cpp ./src/player.cpp ./src/humanPlayer.cpp ./src/computerPlayer.cpp
windows:
	i686-w64-mingw32-gcc -Wall -o mkGame.exe ./src/main.cpp ./src/parseInput.cpp ./src/board.cpp ./src/player.cpp ./src/humanPlayer.cpp ./src/computerPlayer.cpp -lstdc++ -static
armv7:
	g++ -march=armv7 -Wall -o mkGame-arch ./src/main.cpp ./src/parseInput.cpp ./src/board.cpp ./src/humanPlayer.cpp ./src/computerPlayer.cpp
debug:
	g++ -Wall -g -o mkGame ./src/main.cpp ./src/parseInput.cpp ./src/board.cpp ./src/player.cpp ./src/humanPlayer.cpp ./src/computerPlayer.cpp
