
# 🎲 Monopoly Game – Modern C++ Implementation

This project is a complete, fully-featured implementation of the **classic Monopoly board game**, written in **modern C++ (C++20)** and built using **SFML** for rendering, window management, textures, fonts, and player input.  
The game runs in **fullscreen mode**, displays a full Monopoly board, and supports up to **8 players** with complete game logic, asset loading, and automated win/loss conditions.

## 🚀 Features

### 🎨 Graphical Interface (SFML)
- Renders a fullscreen `sf::RenderWindow` titled **“Monopoly”**
- Draws:
  - board  
  - player tokens  
  - property cards  
  - chance & community chest cards  
  - utilities, railroads, taxes  
  - logs, dice output, UI text  
- All fonts and textures are automatically loaded from the `assets/` directory at startup.

### 🧩 Complete Monopoly Board (40 Cells)
The board includes:
- 22 colored streets  
- 4 railroads  
- 2 companies (water & electricity)  
- 3 chance spaces  
- 3 community chest spaces  
- Income tax & luxury tax  
- Jail  
- Free Parking  
- Go to Jail  
- Start (“GO”)  

Each **GameCell** stores:
- name  
- type  
- price  
- rent logic / upgrade level  
- owner  
- texture  

### 👥 Multiplayer Support
- Up to **8 players**
- Unique ID per player
- Default starting balance: **1500**
- Stores:
  - name  
  - balance  
  - position  
  - owned properties  
- Automatic turn rotation  
- Dice rolls, purchases, rent payments, jail system, and bankruptcy handling  

### 🧠 Complete Game Logic
The **GameBoard** class handles:
- player order  
- property buying  
- rent calculation  
- passing “GO”  
- win conditions  
- bankruptcy & elimination  
- declaring a winner when:
  - only 1 player remains **or**
  - a player exceeds a configured “winning balance”

Helper functions generate each board space:
- start cell  
- streets (with colors)  
- railroads  
- utilities  
- chance & chest  
- taxes  
- jail / free parking / go to jail  

### 🧪 Unit Tests (doctest)
A full test suite covers:
- correct board construction (40 cells)  
- adding/removing players  
- turn transitions  
- player movement  
- game start conditions  

Run tests using:

```
make test
```

## 📦 Requirements

The project uses:

- **C++20** (`-std=c++2a`)
- **SFML 2.x**
  Install via Debian/Ubuntu:
  ```
  sudo apt install libsfml-dev
  ```
- Make
- Clang++ or g++ (C++20 compatible)

## 🔧 Building the Game

1. Clone or download the repository:
   ```
   git clone <repo-url>
   ```
2. Ensure the `Monopoly/` folder contains the `assets/` directory.
3. Build the game:

```
cd Monopoly
make
```

To use `g++` explicitly:

```
make g++
```

To clean builds:

```
make clean
```

## ▶️ Running the Game

After build, an executable named **Monopoly** appears in the directory.

Run it:

```
./Monopoly
```

The game opens in fullscreen.  
Use the **mouse** to:
- roll dice  
- select actions  
- buy properties  
- navigate menus  

The UI shows:
- current player turn  
- balances  
- property ownership  
- action logs  
- dice results  

Game logic enforces all Monopoly rules automatically.

## 🧪 Running the Tests

```
make test
```

This builds and runs the `TestMonopoly.cpp` suite using the **doctest** framework.

## 📁 Project Structure

```
Monopoly/
 ├── assets/                # images, icons, fonts used by the game
 ├── GameBoard.hpp/cpp      # main game logic, player turns, board management
 ├── GameWindow.hpp/cpp     # fullscreen window, drawing, input handling
 ├── GameCell.hpp/cpp       # board cell logic
 ├── Player.hpp/cpp         # player info and property ownership
 ├── Definitions.hpp        # enums and constants
 ├── TestMonopoly.cpp       # unit tests
 ├── makefile               # build instructions
 └── README.md              # this file
```

## 👤 Author

**Mohamad**  
GitHub: https://github.com/mohamad99988765434567

## 📜 License  
For educational and personal use.
