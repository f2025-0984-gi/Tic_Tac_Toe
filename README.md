# Tic Tac Toe 4x4

## Overview

Tic Tac Toe 4x4 is a CLI-based strategy game developed in C++ using Object-Oriented Programming (OOP) principles.

Two players take turns marking positions on a 4x4 grid, aiming to place four marks in a row to win.

The game includes a colorful terminal interface, player name customization, persistent win/loss statistics, and enhanced strategy with a larger board.

This project is modular and can be easily extended or integrated into larger systems.

---

## Features

* 4x4 expanded game board
* Two-player local multiplayer
* Player name customization
* Persistent win/loss/draw statistics
* Color-coded terminal UI
* Draw detection
* Input validation and error handling
* Replayable gameplay
* Automatic stat tracking across sessions
* Windows console color support

---

## Gameplay Rules

* The board has 16 positions labeled: 1–4, 5–8, 9–C, D–G
* Player 1 uses O
* Player 2 uses X
* Players take turns entering a position label
* The first player to align four marks in a row wins
* Winning combinations include horizontal, vertical, and diagonal lines
* If all positions are filled without a winner, the game ends in a draw

---

## Board Positions Reference

```
Row 1: 1 | 2 | 3 | 4
Row 2: 5 | 6 | 7 | 8
Row 3: 9 | A | B | C
Row 4: D | E | F | G
```

---

## Winning Conditions

* Four marks horizontally
* Four marks vertically
* Diagonal from top-left to bottom-right
* Diagonal from top-right to bottom-left

---

## Color Scheme

Cyan - Board and menu text
Red - Player X and error messages
Green - Player O and win announcements
Yellow - Position labels and draw messages
Magenta - Turn prompts

---

## OOP Concepts Demonstrated

### Encapsulation

All game data is stored privately inside the TicTacToe class, including:

* Board array
* Current player
* Turn counter
* Player names
* Statistics data

---

### Inheritance

The class is designed for extension:

```cpp
class TicTacToe : public Game
```

---

### Polymorphism

The game includes specialized methods such as:

* drawBoard()
* markBoard()
* checkWin()
* switchPlayer()

---

### Abstraction

Complex logic is handled through simple public methods:

* play()
* resetBoard()
* loadStats()
* saveStats()

---

### Modularity

The system is divided into independent components:

* Board management
* Win checking
* Statistics handling
* UI rendering

---

## File Structure

```
Tic_Tac_Toe/
│
├── TicTacToe.cpp
├── stats.txt
└── README.md
```

---

## Statistics System

The game maintains a stats.txt file to store results.

Example:

```
15 8 5 2
```

Meaning:

* Total games: 15
* Player O wins: 8
* Player X wins: 5
* Draws: 2

Statistics are updated automatically after each game.

---

## Scoring System

The game tracks:

* Total games played
* Wins for both players
* Draws

---

## Integration Support

Basic usage:

```cpp
TicTacToe game;
game.play();
```

Framework integration:

```cpp
Game* game = new TicTacToe();
game->play();
```

---

## Technologies Used

* C++
* Windows.h
* STL (iostream, fstream, cctype)
* File handling
* Console colors
* Object-Oriented Programming

---

## Known Limitations

* Windows-only due to Windows.h dependency
* Requires wide console for proper alignment
* No AI opponent
* English language only

---

## Future Enhancements

* Cross-platform support
* AI opponent
* Undo feature
* Game timer
* Sound effects
* Leaderboard system
* Variable board sizes
* Online multiplayer
* Save and load feature

---

## Author

Developed as part of an Object-Oriented Programming project.

GitHub: f2025-0984-gi


