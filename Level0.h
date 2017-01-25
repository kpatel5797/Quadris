#ifndef __LEVEL0_H_
#define __LEVEL0_H_
#include "Level.h"
#include "block.h"
#include <iostream>
#include <fstream>


class Level0 : public Level {
    std::string type;
	std::ifstream sequence;
	std::string seqFile;
public:
	Level0(std::string fileName);
	~Level0();
	Level* levelUp();
	Level* levelDown();
	Block* getNext();
};

#endif
