#include "Level.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
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
#include <fstream>
using namespace std;

Level1::Level1() {
}

Level1::~Level1() {}

Level* Level1::levelUp() {
	return new Level2;
}

Level* Level1::levelDown() {
	return new Level0{"sequence"};
}

Block* Level1::getNext() {
	int mod = rand()%12; // set the random var
	if(mod == 0) {
		return new SBlock;
	}
	else if(mod == 1) {
		return new ZBlock;
    }	
	else if(mod == 2 || mod == 3) {
		return new OBlock;
	}
	else if(mod == 4 || mod == 5) {
		return new IBlock;
	}
	else if(mod == 6 || mod == 7) {
		return new LBlock;
	}
	else if(mod == 8 || mod == 9) {
		return new JBlock;
	}
	else { // if(mod == 10 || mod == 11)
		return new TBlock;
	}
}
