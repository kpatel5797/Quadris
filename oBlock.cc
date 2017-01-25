#include "oBlock.h"

OBlock::OBlock() : Block{0,3} {
   tilesOfBlock[0] = Tile{0,0,'O'};
   tilesOfBlock[1] = Tile{0,1,'O'};
   tilesOfBlock[2] = Tile{1,0,'O'};
   tilesOfBlock[3] = Tile{1,1,'O'};
}

OBlock::OBlock(int x = 0, int y =2 ) : Block{x,y} {
   tilesOfBlock[0] = Tile{0,0,'O'};
   tilesOfBlock[1] = Tile{0,1,'O'};
   tilesOfBlock[2] = Tile{1,0,'O'};
   tilesOfBlock[3] = Tile{1,1,'O'};


}

Block* OBlock::rotateCW() {
  Block* newBlock = new OBlock{xPos, yPos};
  newBlock->setBlockTile(0, tilesOfBlock[0]);
  newBlock->setBlockTile(1, tilesOfBlock[1]);
  newBlock->setBlockTile(2, tilesOfBlock[2]);
  newBlock->setBlockTile(3, tilesOfBlock[3]);
  return newBlock;
}

Block* OBlock::rotateCCW() {
  return rotateCW();
}

