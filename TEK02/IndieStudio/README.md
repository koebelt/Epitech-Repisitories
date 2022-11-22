# Indie Studio - Let's Bomb Us !



The goal of this project was to re-create an entire Bomberman.



## Getting Started



This is how to **install** all dependencies you need to play the game.



### Prerequisites



#### Make - GCC - Git

For Debian :

`sudo apt install build-essential git`

For Manjaro / ArchLinux

`sudo pacman -Sy base-devel git`

For Fedora:

`sudo dnf install make automake gcc gcc-c++ kernel-devel`



#### CMake

For Debian :

`sudo apt install cmake`

For Manjaro / ArchLinux

`sudo pacman -Sy cmake`

For Fedora:

`sudo dnf install cmake`



### Installation and launch

1. Create the build folder and download raylib through the CMakeLists file

- On Linux:

`mkdir build`

`cd build`

`cmake ..`

`make`

- On Windows:

`mkdir build`

`cd build`

`cmake ..`

`cmake --build`



2. The program is ready to launch !

- On Linux :

`./bomberman`

- On Windows : Run the .exe



## Bonus

#### Prerequisites:



For Debian:

`sudo apt-get install python3-sphinx`

`sudo apt-get install python3-breathe`

`sudo apt-get install doxygen`

`sudo pip install insegel`

`sudo apt-get install graphviz`

For Manjaro / ArchLinux:

`sudo pacman -S python3-sphinx`

`sudo pacman -S python3-breathe`

`sudo pacman -S doxygen`

`sudo pip install insegel`

`sudo pacman -S graphviz`

For Fedora:

`sudo dnf install python3-sphinx`

`sudo dnf install python3-breathe`

`sudo dnf install doxygen`

`sudo pip install insegel`

`sudo dnf install graphviz`



#### Execute:

AutoDoc:

`cd bonus/doc`

`make`

`open projectRoot/doc/html/intex.html`



If you want more details about the implementation of the project:

`open projectRoot/doc/uml/index.html`