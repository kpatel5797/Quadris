#include "Level.h"
#include "Level3.h"
#include "Level4.h"
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


Level4::Level4() {
	random = true;
	type = "";
}

Level4::~Level4() {}

Level* Level4::levelUp() {
	return this;
}

Level* Level4::levelDown() {
	return new Level3;
}

void Level4::setRandomOff(std::string file) {
	random = false;
	seqFile = file;
	fileSource = std::ifstream{seqFile};
}
	
void Level4::setRandomOn() {
	random = true;
}

Block* Level4::getNext() {
	if(random == true) {
		int mod = rand()%9;
		if(mod == 0 || mod == 1) {
			return new SBlock;
		}
		else if(mod == 2 || mod == 3) {
			return new ZBlock;
		}
		else if(mod == 4) {
			return new OBlock;
		}
		else if(mod == 5) {
			return new LBlock;
		}
		else if(mod == 6) {
			return new IBlock;
		}
		else if(mod == 7) {
			return new JBlock;
		}
		else { // if(mod == 8)
			return new TBlock;
		}
	}
	else {
		fileSource >> type;
		if(fileSource.eof()) {
			setRandomOff(seqFile);
		}
		if(type == "O") {
			return new OBlock;
		}
		else if(type == "S") {
			return new SBlock;
		}
		else if(type == "Z") {
			return new ZBlock;
		}
		else if(type == "I") {
			return new IBlock;
		}
		else if(type == "L") {
			return new LBlock;
		}
		else if(type == "J") {
			return new JBlock;
        }	
		else { // if(type == "T")
			return new TBlock;
		}
	}
}
