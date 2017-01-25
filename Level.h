#ifndef __LEVEL_H_
#define __LEVEL_H_
#include <iostream>
#include "block.h"
#include <string>
class Block;

class Level
{
public:
	virtual Block* getNext() = 0;
	virtual Level* levelUp() = 0;
	virtual Level* levelDown() = 0;
        virtual void setRandomOff(std::string file) {};
        virtual void setRandomOn() {};
        virtual ~Level() {};
};

#endif
