# SEngine

- An Open Source C++ Opengl engine utilizing the capabilities of Box2D.

- This is meant to be a starting point for your game!

- Under the MIT License.

#Tutorial

Coming very soon + sample project information

# Current state

- This engine is not complete! Not by a far stretch. 

- There is some serious refactoring to do!

- Documentation has not been kept up to date and has mostly been edited away.

- The engine works and there is a small example built into the engine. This utilizes a lot of the primary functionality of the engine.

#Dependencies & Use

NOTE:
All Dependencies target 32bit (x86) architecture!
Unix has not been tested, pathing might differ. I will cross platform the engine very soon!

Dependencies

  SDL2, OpenGL 3.3, SOIL, Box2D

- Folder depends:
  This folder houses the libraries and sources most commonly used in the project, this includes SDL2, OpenGL3.3 and Box2D.
  If you're working in windows, you can point towards these folders for a general overview.

  SDL2:
  
 - Windows: https://www.libsdl.org/release/SDL2-2.0.3-win32-x86.zip 
 
 - Mac: https://www.libsdl.org/release/SDL2-2.0.3.dmg
 
 - Debian:
  - $ apt-cache search libsdl2
  - $ apt-get install libsdl2-dev
  - Extract and cd into folder
  - $ ./configure
  - $ make all
  - $ make install
  
 - Fedora:
  - $ yum search SDL2-devel 
  - $ yum install SDL2-devel
  
  OpenGL3.3:
  
  - Glew: can be found, with necessary info here https://github.com/nigels-com/glew  [Please note that glew32s is being used]
  - Glfw3: can be found here https://github.com/glfw/glfw
  
  Soil:
  
  can be found here http://www.lonesock.net/soil.html.
  The Depends folder holds the libraries for both windows and unix.

  Box2D:
  
  Can be found here https://github.com/erincatto/Box2D. However, the code must be compiled with CMake in-order to be used.
  The .lib can be found in the Depends/Lib folder. 

# Whats to offer?

- Fully working Box2D implementation, ready-to-go.

- 2D OpenGL wrapper. 

- Kept up-to-date as best as I (or contributors) can!

- Very expandable. If you need 3D, implementing bullet and moving to a 3D implementation of OpenGL should be very quick.

# Plans

- Unit tests!!

- Documentation!!

- Any features the engine might need in the future.

# What is this to you?

- A project i've wanted to make open source for far too long.

- Something others can use to make beautiful projects!

- Something I hope we can make fantastic! 


#THANKS!

#Special thanks to
  -Mateusz Belicki : https://github.com/mbelicki for fixing some of the Unix problems!

#Disclaimer

I am not an expert, my code shows this. I'll try to improve wherever I can, but please be aware.
