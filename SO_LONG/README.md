# Description

SO_LONG is a simple 2D game where the player controls a character navigating through a maze-like environment. The objective of the game is to collect all the collectibles and reach the exit door while avoiding enemies.

The project is written in C language and utilizes the MLX42 library for the graphical interface. It incorporates concepts of graphics rendering, input handling, and game logic.

# Features

* Dynamic maze generation
* Character movement using keyboard inputs
* Collectibles to be gathered
* Score tracking
* Collision detection
* Game over and victory conditions

# Requirements

* GCC compiler
* MLX42 library

# Installation

* Clone the repository to your local machine:

``$ git clone [repository_url]``

* Navigate to the project directory:

``$ cd SO_LONG``

* Compile the project:

``$ make``

# Usage

To launch the game, run the following command:

``$ ./so_long [map_file]``

where [map_file] is the path to a valid map file. Map files should have a .ber extension and follow the specified format.

# Map Format
The map file represents the game level. It consists of the following characters:

- '1' (walls)
- '0' (empty spaces)
- 'P' (player starting position)
- 'E' (exit door)
- 'C' (collectibles)
- 'X' (enemies)

Here is an example of a valid map file:

111111

100101

10C0E1

100P01

111111

# Controls

* W/A/S/D or arrow keys: Move the player character
* ESC or close window button: Quit the game

# Resources
MLX42 - MLX42 repository
