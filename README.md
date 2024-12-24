# Settlers of Catan Game Project

## Overview
This project is a C++ implementation of a simulation for the popular board game **Settlers of Catan**. It includes a robust object-oriented design, featuring classes for game elements such as nodes, pathways, terrains, players, and development cards. The game also integrates a graphical visualization of the game board using SFML (Simple and Fast Multimedia Library).

---

## Features

- **Game Mechanics**: Simulates core mechanics of Settlers of Catan, including rolling dice, building settlements, roads, cities, trading resources, and using development cards.
- **Graphical Visualization**: Provides a visual representation of the game board and its elements.
- **Object-Oriented Design**: Employs principles of object-oriented programming, including inheritance, encapsulation, and polymorphism.
- **Dynamic Gameplay**: Supports multiple rounds of gameplay with statistics printed after each round.
- **Extensible**: Designed with modularity, making it easy to extend or modify.

---

## Classes Overview

### Game Elements
- **Node**: Represents a location where players can build settlements or cities. Each node connects to pathways and terrains.
- **Pathway**: Represents roads connecting nodes. Essential for expansion and scoring.
- **Terrain**: Represents resource-producing areas, such as forests, hills, and fields.
- **DevelopmentCard**: Includes special cards that provide unique advantages to players.
- **ResourceCard**: Represents resources like lumber, wool, grain, ore, and brick.

### Player and Game Logic
- **Player**: Manages resources, development cards, and actions like building and trading.
- **GameBoard**: Manages all game components, including nodes, pathways, terrains, and development cards.
- **GameOperator**: Oversees the game flow, including player turns, dice rolls, and victory conditions.

---

## Getting Started

### Prerequisites
- **C++ Compiler**: Ensure you have a modern C++ compiler supporting C++11 or later.
- **SFML Library**: Install SFML for graphical visualization.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo-url/catan-game.git
   cd catan-game
   ```
2. Compile the project:
   ```bash
   make catan
   ```
3. Run the executable:
   ```bash
   ./catan
   ```

---

## How to Play

1. **Initialization**: Players take turns placing initial settlements and roads on the board.
2. **Gameplay**:
   - Players roll dice to determine resource distribution.
   - Use resources to build settlements, roads, cities, or buy development cards.
   - Trade resources with other players or the bank.
   - Use development cards for strategic advantages.
3. **Winning the Game**: The player who reaches the victory point threshold first wins.

---

## File Structure

```
.
├── src
│   ├── main.cpp          # Entry point for the game
│   ├── GameBoard.cpp     # Implementation of the game board
│   ├── Node.cpp          # Node functionality
│   ├── Pathway.cpp       # Pathway functionality
│   ├── Player.cpp        # Player actions and state
│   ├── DevelopmentCard.cpp # Development card logic
│   └── ...
├── include
│   ├── GameBoard.hpp     # Header for game board
│   ├── Node.hpp          # Header for nodes
│   ├── Pathway.hpp       # Header for pathways
│   ├── Player.hpp        # Header for player
│   ├── DevelopmentCard.hpp # Header for development cards
│   └── ...
├── tests
│   ├── test_game.cpp     # Unit tests for game components
│   └── ...
├── Makefile              # Build instructions
└── README.md             # Project documentation
```

---

## Testing

The project uses Doctest for unit testing. To run tests:
```bash
make test
./test
```

### Test Coverage
- Tests for each class and meaningful function.
- Edge cases for gameplay scenarios.

---

## Future Enhancements

- **AI Players**: Add AI for single-player mode.
- **Online Multiplayer**: Enable networked gameplay.
- **Enhanced Visualization**: Improve graphics with animations and effects.
- **Customizable Rules**: Allow players to modify game rules.

---

## Acknowledgments

- **Settlers of Catan**: Inspiration for the project.
- **SFML**: Graphics library used for visualization.
- **Doctest**: Framework used for unit testing.

