Monopoly Game
This project is a fully featured implementation of the classic Monopoly board game written in modern C++. It uses SFML for all rendering and input, and provides a graphical game window that runs in fullscreen mode[1]. The source is organized into clear components—GameBoard, GameWindow, GameCell and Player classes—that together build and manage a 40‑space game board[2], handle player turns, and draw the UI.
Features
•	Graphical Interface – The game creates a fullscreen sf::RenderWindow and draws the board, cards, tokens and text using SFML[1]. All fonts and textures (player icons, property images, chance/chest cards, railroads, taxes, utilities, etc.) are loaded from the assets directory at startup[3].
•	Complete Monopoly Board – The board consists of 40 cells with streets (grouped by color), railroads, companies, tax spaces, chance and community chest cards, a jail, a “Free Parking” space and a “Go to Jail” cell[4]. Each GameCell stores information such as name, price, upgrade level and current owner.
•	Multi‑player Support – Up to eight players can join a game. Players are assigned unique IDs when added, start with a configurable balance (default 1500) and take turns rolling dice, buying properties and paying rent[5].
•	Complete Game Logic – The GameBoard class manages turns, checks win conditions, tracks bankrupt players and declares a winner when only one player remains or when a player’s balance exceeds the winning threshold. Helper functions create each type of cell (start, free parking, utilities, railroads, tax, chance, chest, jail, etc.).
•	Unit Tests – A suite of unit tests written with the single‑header doctest framework validates board construction, player management and game state transitions. Running the tests ensures there are 40 spaces on the board, eight players are correctly added and the game can start and progress normally[6].
Requirements
This project targets C++20 (as specified by -std=c++2a in the makefile) and depends on the SFML library for graphics, window management and user input. You will need:
•	C++ Compiler – Tested with clang++ and g++ (versions supporting C++20).
•	SFML 2.x – Install the development headers and libraries (libsfml-graphics, libsfml-window, libsfml-system). On Debian/Ubuntu you can install them with apt install libsfml-dev.
•	Make – The provided makefile uses standard make targets.
Building
1.	Clone this repository (or download the source) and ensure the Monopoly folder with its assets subdirectory remains intact.
2.	Install SFML and a C++20 capable compiler.
3.	Build the project using the makefile:
cd Monopoly
make
The make target compiles all .cpp files and links against sfml-graphics, sfml-window and sfml-system[7]. After building, it launches the game automatically.
If you prefer to use g++, run make g++. To clean the build products, run make clean.
Running the Game
After compilation, an executable named Monopoly will be produced in the Monopoly directory. Launch it from a terminal:
./Monopoly
On launch the game opens a fullscreen window titled “Monopoly”[1]. Use the mouse to click on the board to roll dice, purchase properties and navigate through menus. The game tracks each player's turn, balance and assets, displays logs of recent actions and automatically enforces Monopoly rules.
Running the Tests
To build and run the unit tests, run:
make test
This compiles TestMonopoly.cpp along with the game sources and links against SFML[8]. The test executable uses doctest to run a collection of test cases that verify board layout, player management and game state[6].
Project Structure
•	Monopoly/ – The C++ source code and resources for the game.
•	GameBoard.hpp/cpp – Manages the board state, including the list of players, cells, turn sequence and game logic.
•	GameWindow.hpp/cpp – Handles window creation, drawing the board and UI, loading assets, and capturing input. It creates a fullscreen SFML window and loads textures and fonts from the assets folder[1][3].
•	GameCell.hpp/cpp – Represents individual spaces on the board (properties, railroads, tax spaces, chance/chest cards, jail, etc.) and handles their drawing and interaction.
•	Player.hpp/cpp – Represents players, storing name, balance, position and owned properties.
•	Definitions.hpp – Enumerations and constants used throughout the project.
•	TestMonopoly.cpp – A suite of doctest cases for validating game logic[6].
•	makefile – Build script demonstrating how to compile and link the project with SFML[9].
•	assets/ – Font and image resources used by the game (player icons, card icons, railroads, utilities, etc.)[3].
