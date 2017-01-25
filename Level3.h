#ifndef __LEVEL3_H_
#define __LEVEL3_H_
#include "Level.h"
#include "block.h"
#include <iostream>
#include <fstream>

class Level3 : public Level {
	bool random;
	std::string seqFile;
	std::ifstream fileSource;
	std::string type;
public:
	Level3();
	~Level3();
	Level* levelUp();
	Level* levelDown();
	void setRandomOff(std::string file) override;
	void setRandomOn() override;
	Block* getNext();
};

#endif
