#ifndef __LEVEL4_H_
#define __LEVEL4_H_
#include "Level.h"
#include "block.h"
#include <iostream>
#include <fstream>

class Level4 : public Level {
	bool random;
	std::string seqFile;
	std::ifstream fileSource;
	std::string type;
public:
	Level4();
	~Level4();
	Level* levelUp();
	Level* levelDown();
	void setRandomOff(std::string file) override;
	void setRandomOn() override;
	Block* getNext();
};

#endif
