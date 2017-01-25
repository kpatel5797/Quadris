#include "Level.h"
#include "Level0.h"
#include "Level1.h"
#include "jblock.h"
#include "oBlock.h"
#include "sblock.h"
#include "zblock.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "tblock.h"
#include <iostream>
#include <fstream>

using namespace std;

Level0::Level0(string fileName) {
	seqFile = fileName;
	sequence = std::ifstream{seqFile};
}

Level0::~Level0() {}

Level* Level0::levelUp() {
	return new Level1;
}

Level* Level0::levelDown() {
	return this;
}

Block* Level0::getNext() { // get the next block based on the file given
    sequence >> type;
    if(sequence.eof()) {
    	sequence = std::ifstream{seqFile};
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
