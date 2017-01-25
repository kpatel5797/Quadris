#ifndef __LEVEL2_H_
#define __LEVEL2_H_
#include "Level.h"
#include "block.h"
#include <iostream>


class Level2 : public Level {
public:
	Level2();
	~Level2();
	Level* levelUp();
	Level* levelDown();
	Block* getNext();
};

#endif
