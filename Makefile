make_game:
	g++  -o mkGame ./main.cpp ./parseInput.cpp ./board.cpp ./player.cpp ./humanPlayer.cpp ./computerPlayer.cpp
windows:
	i686-w64-mingw32-gcc -Wall -o mkGame.exe ./main.cpp ./parseInput.cpp ./board.cpp ./player.cpp ./humanPlayer.cpp ./computerPlayer.cpp -lstdc++ -static
armv7:
	g++ -march=armv7 -Wall -o mkGame-arch ./main.cpp ./parseInput.cpp ./board.cpp ./humanPlayer.cpp ./computerPlayer.cpp
debug:
	g++ -Wall -g -o mkGame ./main.cpp ./parseInput.cpp ./board.cpp ./player.cpp ./humanPlayer.cpp ./computerPlayer.cpp
