# SFML-2D-Shapes-Renderer

A simple and configurable 2D renderer for moving shapes (rectangles and circles) made with C++ and SFML. Configurations for the shapes are read into the application through a text file, and then the application will continuously calculate and draw the shapes to the window (given their initial position and speed).

This project is heavily inspired by assignment 1 of professor Dave Churchill's "C++ Game Programming" course, taught at the Memorial University of Newfoundland during the fall 2022 term (COMP4300). I was able to unofficially complete his course because he graciously posted every lecture of the course on YouTube. I will include the link to the YouTube playlist for anyone interested [here](https://www.youtube.com/playlist?list=PL_xRyXins848nDj2v-TJYahzvs-XW9sVV). I want to be clear, I did not copy any code from him (in fact, none were provided). All the code written in this repository was written by me, after watching and studying his lectures.

I posted a short YouTube clip showcasing the application in action [here](https://www.youtube.com/watch?v=7kvdFnJ9VuM).

## How to configure the shapes

Each line of the configuration text file specifies one of the config settings of the program, with the first string in each line being the type of setting that the rest of the line specifies. Lines in the config file can be one of the following types, and lines can appear in (generally) any order in the file.

**Window W H**
- Always the first line in the configuration file
- This line declares that the SFML Window must be constructed with width W and height H, each of which will be integers

**Font F S R G B**
- This line defines the font which is to be used to draw text for this program. The format of the line is as follows:
- Font name (must be located inside the `Fonts` folder) - F - `std::string` (it will have no spaces)
- Font Size - S - `int`
- RGB Color - (R, G, B) - `int, int, int`

**Rectangle N X Y SX SY R G B W H**
- Defines a Rectangle Shape with:
- Shape Name - Name - `std::string`
- Initial Position - (X, Y) - `float, float`
- Initial Speed - (SX, SY) - `float, float`
- RGB Color - (R, G, B) - `int, int, int`
- Size - (W, H) - `float, float`

**Circle N X Y SX SY R G B R**
- Defines a Circle Shape with:
- Shape Name - Name - `std::string`
- Initial Position - (X, Y) - `float, float`
- Initial Speed - (SX, SY) - `float, float`
- RGB Color - (R, G, B) - `int, int, int`
- Radius - R - `float`

## How to run on MacOS

Currently, I've only been developing this project on MacOS, so these instructions will be specific to MacOS. In the near future I will update with Windows instructions as well, but it should be similar steps.

1. Install SFML, CMake, and a C++ compiler (I am using Apple clang version 15.0.0 (clang-1500.1.0.2.5))
2. Install all relevant C++ and CMake extensions in Visual Studio Code
3. Using CMake, launch the application!

## License

The source code is licensed under Public Domain.
