#include <ncurses.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include "Automaton.hpp"
#include "Display.hpp"
#include "Brain.hpp"

using namespace std;

int main (int argc, char *argv[]) {

    initscr(); // Initialise ncurses
    cbreak(); // Enable C-c to break out of programm for dev purposes
    noecho(); // Don't echo key presses
    curs_set (0); // Hide the cursor
    nodelay (stdscr, true); // make getch() non-blocking for main loop

    // Get terminal dimensions
    int maxY, maxX;
    getmaxyx (stdscr, maxY, maxX);

    // Make main window the size of screen
    Display display (maxY, maxX);

    // Default rule
    int rule = 105;

    // Convert command line argument
    if (argc > 1){
    std::stringstream convert (argv[1]);
    convert >> rule;
    }

    // Make Automaton with state size respecting window border
    Automaton automaton (maxX - 2, rule);

    // Make Brain to handle the programm logic
    Brain brain (&automaton, &display);

    // Main loop
    char c = ' ';

    brain.init();

    while (1)
        {
            c = getch(); // Wait for key press before exiting the program
            switch (c)
                {
                    case 'q':
                        endwin(); // End ncurses functionality
                        return 0;
                    case 's':
                        brain.runHalt();
                        break;
                }

            if (brain.isRunning())
                {
                    brain.next();
                    usleep (50000);
                }
        }

    return 0;
}
