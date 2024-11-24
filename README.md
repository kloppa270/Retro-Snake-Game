# Retro-Snake-Game

A classic Snake game built with C++ and Raylib.

## Features
- Smooth snake movement
- Random food generation
- Simple retro-style graphics
- 
## Prerequisites
You need to install raylib before building the game. Follow the instructions below for your platform:

### Windows
1. Download the raylib installer or libraries from the [official website](https://www.raylib.com/).
2. Install the library and add it to your Visual Studio project:
   - Add the include directory to **Include Directories**.
   - Add the library directory to **Library Directories**.
   - Link against `raylib.lib` in **Additional Dependencies**.

### macOS
Install raylib using Homebrew:
```bash
brew install raylib

````
### linux
Install raylib using your package manager:
```bash
sudo apt install libraylib-dev
```
## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Snake.git
   cd Snake
   ```
2. Set up Raylib (see raylib installation).
3. Compile the project (use Visual Studio or another compiler).

Controls
Arrow keys or WASD: Move the snake
Spacebar: Resume the game after losing
