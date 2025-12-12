# Parul's Gaming

Small side-scrolling jump-and-dodge game built with C++ and [raylib](https://www.raylib.com/). You control Scarfy as parallax layers scroll by; avoid the nebula sprites to survive and make it to the finish line.


<img width="518" height="386" alt="image" src="https://github.com/user-attachments/assets/2b6075de-04bf-4fab-983e-9bd7c906bfc9" />

## Introduction
- Uses raylib for rendering, input, and texture handling.
- Parallax background across three layers for depth.
- Animated Scarfy player sprite with jump physics and gravity.
- Simple win/lose conditions: collide with a nebula to lose, reach the finish line to win.

## Setup
1. Install prerequisites:
   - C++14 compiler (`g++`) and `make`.
   - raylib development files. On Debian/Ubuntu: `sudo apt install libraylib-dev`. On macOS with Homebrew: `brew install raylib`.
2. Ensure the texture assets remain in the `textures/` folder next to `main.cpp`.

## Build and Usage
- Build with `make` (uses the provided Makefile, overriding the defaults for this project):
  ```bash
  make PROJECT_NAME=paruls-gaming OBJS=main.cpp
  ./paruls-gaming
  ```
- Or compile directly with `g++` on Linux:
  ```bash
  g++ main.cpp -std=c++14 -o paruls-gaming -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
  ./paruls-gaming
  ```
- Controls: press `Space` to jump. Reach the end without touching a nebula to win.
