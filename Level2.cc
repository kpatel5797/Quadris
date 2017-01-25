#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "block.h"
#include "oBlock.h"
#include "sblock.h"
#include "zblock.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "tblock.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Level2::Level2() {
}

Level2::~Level2() {}

Level* Level2::levelUp() {
	return new Level3;
}

Level* Level2::levelDown() {
	return new Level1;
}

Block* Level2::getNext() {
	int mod = rand()%7; // set the random var
	if(mod == 0) {
		return new OBlock;
	}
	else if(mod == 1) {
		return new SBlock;
	}
	else if(mod == 2) {
		return new ZBlock;
	}
	else if(mod == 3) {
		return new LBlock;
	}
	else if(mod == 3) {
		return new IBlock;
	}
	else if(mod == 5) {
		return new JBlock;
	}
	else { // if(mod == 6)
		return new TBlock;
	}
}
