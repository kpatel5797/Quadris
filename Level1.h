#ifndef __LEVEL1_H_
#define __LEVEL1_H_
#include "Level.h"
#include "block.h"
#include <iostream>


class Level1 : public Level {
public:
	Level1();
	~Level1();
	Level* levelUp();
	Level* levelDown();
	Block* getNext();
};

#endif
