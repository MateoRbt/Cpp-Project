# Cpp-ProjectCancel changes
A dungeon crawler game made with cpp and ncurses usage.

This particular game is part of the final examination of the Object Oriented Programming course

In order to create this program i used the following libraries 

-ncurses this library is used for the movement of the player ,and the visualisation of the map and the other game assets.
-vectors used for the map parsing.
-fstream used for reading the map from the txt file

The game assets are
1 player that is moved by the user
1 npc that is controled by the game 
1 gem that changes position randomly

in order to run this game you will need linux!

Requirements 
download ncurses with the following command : sudo apt-get install libncurses5-dev libncursesw5-dev 

Run:
g++ -o main main.cpp gameEngine.cpp pawn.cpp Npc.cpp Diamond.cpp -lncurses

I encourage you to create a new maps and play with the game and if you want to sharpen your programming skills 
try to make a new improved algorithm for the npc cuz it has some issues sometimes.

Thank you for your time !
