Project Advanced Programming 2024-2025
=======================================
This project was developed as part of the course **Advanced Programming** during the **second year** of the **Computer
Science** bachelor's program at the **University of Antwerp**, academic year **2024–2025**.

The goal was to design and implement a full-featured, extendable **platformer game** in C++ using the **SFML** graphics
library, inspired by the popular game *Doodle Jump*.

---

## 🎮 Gameplay Overview

In this game, the player controls a character that is continuously jumping. Your only input is **horizontal movement** (
via `A`/`D` or left/right arrow keys), aiming to land on higher platforms and climb as far as possible.

The game features:

- **Infinite vertical world generation**
- **Score tracking** and high-score display
- **Scrolling camera** following the player
- **Bonus items**:
    - **Springs**: boost the jump height 5x
    - **Jetpacks**: launch the player significantly higher for a certain time
- **Platform types**:
    - Static (Green)
    - Moving Horizontal (Blue)
    - Moving Vertical (Yellow)
    - Temporary/Breakable (White)
- **Extra obstacle**:
    - A player can be attracted by Black Holes when getting higher
    - These Black Holes don't kill the player, but slows down the player in te direction it is moving.

If the player falls below the screen with no platform to land on, the game ends.

---

## 🧠 Architecture and Design

This project emphasizes **clean architecture**, **design patterns**, and **modular structure**:

- **Model-View-Controller (MVC)** separation
- **Observer pattern** for view updates and scoring
- **Abstract Factory** to decouple logic from graphics
- **Singletons** for Stopwatch and Random utilities
- **Smart pointer** usage throughout (no raw pointers)

## ⚙️ Configuration

- In the `Src/Configs/GameConfig.h` file, you can adapt some configurations to make gameplay easier or harder.

## Key Components

- `Game`: Main loop, user input, window management
- `World`: Stores and updates all entities (platforms, player, bonuses)
- `Camera`: Manages scrolling and transforms world coords
- `Stopwatch`: Time deltas for consistent logic updates
- `Random`: Deterministic random number generation
- `Entity`, `Platform`, `Bonus`: Base and derived game objects

## Full Information

All theoretical information, extras and screenshots are presented in the `Report/report.pdf` file

---

## ⚙️ CMake & Build Instructions

The project uses **CMake** to build two distinct parts:

1. **Logic Library**: Contains the entire game logic, fully independent of SFML
2. **Game Executable**: Links the logic library to the SFML-based representation

### ✅ Build Instructions

1. Clone the project:

```bash
git clone https://github.com/EmirMurat6606/DoodleJump.git
cd DoodleJump
```

