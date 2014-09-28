mkGame
======

mkGame is a simple tic tac toe game which implements the ability to change the board size and the length in a row required to win. It also implements a simple AI to play against or to have play against itself.

Explanation of prompts
----------------------

When running the game it will prompt for the size of M and K. Both of these only accepts numbers with:
- M being the board size with the resulting board being M*M
- K being the length required to win the game

Compiling
---------

The Makefile currently assumes you are using a Arch linux setup when cross-compiling to Windows and staically links the librarys when compiling to windows. This means that it uses the i686-w64-mingw32-gcc package which may not work on all platforms.