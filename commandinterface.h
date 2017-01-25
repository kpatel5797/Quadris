#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

#include "boardmanager.h"
#include "graphicdisplay.h"
#include "textdisplay.h"
#include <string>
#include <vector>

class CommandInterface{
   BoardManager board;
   
   public:
   	CommandInterface(GraphicDisplay* graphics, TextDisplay* text, bool textFlag, std::string lvlFile, int startLevel  ) : board{startLevel,graphics,text,textFlag,lvlFile} {};
   	std::vector<std::string> getPossibleCommands(std::string command);
    bool runCommand(std::string command);
    void start();
};

#endif
