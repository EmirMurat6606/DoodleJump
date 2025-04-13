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
    - These Black Holes don't kill the player, but slow down the player in the direction it is moving.

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

### ✅ SFML Installation

Before building the project, you need to install the SFML library. SFML (Simple and Fast Multimedia Library) is used for the graphical representation and input handling in this game.

#### 1. **Windows**:

To install SFML on Windows, follow these steps:

1. **Download SFML**:  
   Go to the official SFML download page: [SFML Downloads](https://www.sfml-dev.org/download.php).

2. **Extract SFML**:  
   Download the **"Visual C++"** version (the version matching your compiler). Extract the contents of the zip file to a folder.

3. **Set up SFML in Visual Studio**:
  - Open your project in **Visual Studio**.
  - Go to `Project` → `Properties`.
  - Under `Configuration Properties`, navigate to `VC++ Directories`.
  - Add the path to the **"include"** directory from the extracted SFML folder to `Include Directories`.
  - Similarly, add the path to the **"lib"** directory from the extracted SFML folder to `Library Directories`.

  - Under `Configuration Properties`, navigate to `Linker` → `Input` → `Additional Dependencies`, and add the following libraries:
    - `sfml-graphics-d.lib`
    - `sfml-window-d.lib`
    - `sfml-system-d.lib`

  - Copy the required **DLLs** from the SFML `bin` folder (e.g., `sfml-graphics-d-2.dll`, `sfml-window-d-2.dll`, `sfml-system-d-2.dll`) into your executable directory or ensure they are in your system’s `PATH`.

4. **Build and run** the project.

---

#### 2. **macOS**:

On macOS, you can easily install SFML using **Homebrew**:

1. **Install Homebrew** (if you don't have it yet):
  - Open a terminal and run the following command:
    ```bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

2. **Install SFML**:
  - Once Homebrew is installed, you can install SFML with the following command:
    ```bash
    brew install sfml
    ```

3. **Link SFML to your project**:
  - You may need to tell your CMake build to link against SFML. Add the following to your `CMakeLists.txt`:
    ```cmake
    find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
    target_link_libraries(your_target sfml-graphics sfml-window sfml-system)
    ```

4. **Build and run** the project using CMake.

---

#### 3. **Linux (Ubuntu/Debian)**:

For Linux (Ubuntu/Debian), SFML can be installed via the package manager.

1. **Install SFML**:
   Open a terminal and run the following command:
   ```bash
   sudo apt-get install libsfml-dev
   ```


  

