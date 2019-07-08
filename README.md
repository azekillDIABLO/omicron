## Omicron

### About

#### Credits
Game developped by azekill_DIABLO.
A fork of the work of [Twetzel59](https://github.com/twetzel59), known as **[Craft NG](https://github.com/twetzel59/CraftNG/)**,
a fork of the work of [M. Fogleman](https://github.com/fogleman), the base of everything, **[Craft](http://www.michaelfogleman.com/craft/)**.

#### Running the game

Mac and Windows: Click on the executable file, the game should run.
Linux: Open terminal in the directory of the game and type `./omicron`


See below to compile from source and get the executable.

### Compilation

#### Requirements under Mac OS X

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html)
if you don't already have it. You may use [Homebrew](http://brew.sh) to simplify
the installation:

    brew install cmake

#### Requirements under Linux (and Debian)

    sudo apt-get install cmake libglew-dev xorg-dev libcurl4-openssl-dev
    sudo apt-get build-dep glfw

#### Requirements under Windows

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html)
and [MinGW](http://www.mingw.org/). Add `C:\MinGW\bin` to your `PATH`.

Download and install [cURL](http://curl.haxx.se/download.html) so that
CURL/lib and CURL/include are in your Program Files directory.

Use the following commands in place of the ones described in the next section.

    cmake -G "MinGW Makefiles"
    mingw32-make

#### Compilation (for all platforms)

Once you have the dependencies (see above), install the sources and open the
terminal in the dowloaded source directory. Run the following commands :

    cmake .
    make

Then you can run the game.

### More info

#### Controls

- WASD/ZQSD to move forward, left, backward, right.
- Space to jump.
- Left Click to destroy a block.
- Right Click or Cmd + Left Click to create a block.
- Ctrl + Right Click to toggle a block as a light source.
- 1-9 to select the block type to create.
- E to cycle through the block types.
- Tab to toggle between walking and flying.
- Left shift to zoom.
- F to show the scene in orthographic mode.
- O to observe players in the main view.
- P to observe players in the picture-in-picture view.
- T to type text into chat.
- Forward slash (/) to enter a command.
- Minus (-) to write text on any block (signs).
- Arrow keys emulate mouse movement.
- Enter emulates mouse click.

#### Dependencies

* GLEW is used for managing OpenGL extensions across platforms.
* GLFW is used for cross-platform window management.
* CURL is used for HTTPS / SSL POST for the authentication process.
* lodepng is used for loading PNG textures.
* sqlite3 is used for saving the blocks added / removed by the user.
* tinycthread is used for cross-platform threading.
