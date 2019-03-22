# cavez
Cavez is a hobby project targeting to build an old school cave flying game. Such games were popular in Finland in '90s and this project aims to provide similar experience. Project was started as a solo hobby in order to have something meaningful to code and there are currently no more ambitious plans behind. Tech: C++17 and SFML (https://www.sfml-dev.org/) library, target platforms Windows and Linux. 

TODO: Write description of cave flyer games

Very rough "backlog" for anyone interested: https://trello.com/b/3sAzYxU9/cavez

Status (9.3.2019): Renders sprite on screen which can be rotated with A and D.. :) Has some sort of physics in place for throttling, gravity and air resistance. Mainly entity-component architecture practice so far. Seems like physics operate differently on Linux.

## Building

Currently building is in a funny state. Linux uses shared libraries and windows uses static libraries. Otherwise building works the similar way. Building expects you to download the SFML binaries, they are not part of this repository currently. SFML version 2.5.1 has been used and currently building has been tested with Visual Studio Express 2017 (stock MSVC) and GCC 7.2.0
* run CMake to root folder
* set SFML_DIR to point into cmake files in SFML binaries
  * e.g. -DSFML_DIR=~/derp/SFML-2.5.1/lib/cmake/SFML
  * As explained above, currently Linux expects shared library (https://www.sfml-dev.org/download/sfml/2.5.1/ pre build GCC 64 bit), and windows expects static library (Visual C++ 15 (2017) - 64-bit). This is due to Visual studio being an ass with dll, should do some CMake magic when there's time.
* generate solution
* build solution
* execute sandbox_app
  * for now there's no real executable as this is so early stage.


Cannot provide better instructions now. Should align the usage (e.g. shared SFML also in Windows) and add binary directory for consistency.
