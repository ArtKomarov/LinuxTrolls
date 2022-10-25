#include "shell_troll.h"

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

const int SLEEP_TIME = 20; // sec

void ShellTroll::LOL()
{
    std::string shellsPath = "/dev/pts/";
    std::string command = "ls " + shellsPath;
    char terminalName[256];

    if (daemon(0, 0) == -1) {
        throw std::runtime_error("Can not create a daemon");
    }


    while (1) {
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            throw std::runtime_error("Popen failed");
        }

        while (fgets(terminalName, sizeof terminalName, pipe) != NULL) {
            std::string terminalNameString = std::string(terminalName);
            terminalNameString.pop_back();
            // std::cout << '<' << terminalNameString << '>' << std::endl;
            std::ofstream stream(shellsPath + terminalNameString);
            if (stream.is_open()) {
                stream << "LOL" << std::endl;
            } else {
                // std::cerr << "Stream '" << terminalNameString << "' was not open" << std::endl;
            }
        }
        sleep(SLEEP_TIME);
    }

    // Fix: pgrep main.out
    // kill <id>
}
