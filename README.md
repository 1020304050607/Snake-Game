# 🐍 Snake Game with SFML in C++

A simple Snake game built with **SFML** in C++.  
This is my first game project while learning C++17 and SFML.

## ✨ Current Features

- Graphical window with SFML
- Snake head that moves using arrow keys and WASD
- Food that spawns at random positions
- Collision detection working score system
- Basic wall collision detection (working on it more)
- Score displayed on screen
- Main menu screen with "Start Game" and "Quit" options
- Textured background, apple, and snake head all homemade 
- Simple movement with delay

**Note:** The snake is currently only the head no growing body yet. This is an active working project for learning.

## 🎮 Controls

**In Menu:**
- **Up / W** → Move selection up
- **Down / S** → Move selection down
- **Enter** → Select option

**In Game:**
- **Arrow Keys** or **WASD** → Change direction
- The snake moves automatically at a fixed interval

## 🛠️ How to Build and Run

### Prerequisites
- **SFML 3.0.1+** installed on your system
- CMake 3.10 or higher
- C++ compiler (g++, clang++, or MSVC)

**Note:** You must copy and paste the SFML foldier in the project the file tree should look like Assets
                                                                                                 build
                                                                                                 SFML/bin/include/lib (in inlude copy paste the .hpp files and in bin all the .dlls lib will be used for CMake)

### Build Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/1020304050607/Snake-Game.git
   cd Snake-Game
   cd Build
   ninja && Game.exe
