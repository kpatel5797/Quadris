#include "sblock.h"

SBlock::SBlock() : Block{0,3} {
   tilesOfBlock[0] = Tile{0,0,'S'};
   tilesOfBlock[1] = Tile{1,0,'S'};
   tilesOfBlock[2] = Tile{1,1,'S'};
   tilesOfBlock[3] = Tile{2,1,'S'}; 
}

SBlock::SBlock(int x = 0, int y =2) : Block{x,y} {
   tilesOfBlock[0] = Tile{0,0,'S'};
   tilesOfBlock[1] = Tile{1,0,'S'};
   tilesOfBlock[2] = Tile{1,1,'S'};
   tilesOfBlock[3] = Tile{2,1,'S'}; 
}

Block* SBlock::rotateCW() {
   Block* newBlock = new SBlock{xPos, yPos};
   newBlock->setBlockTile(1, tilesOfBlock[1]); 
   newBlock->setBlockTile(2, tilesOfBlock[2]);
   if(tilesOfBlock[3].x == 2){
     newBlock->setBlockTile(0, Tile{0,2,'S'});
     newBlock->setBlockTile(3,Tile{0,1,'S'});
   }
   else{
     newBlock->setBlockTile(0, Tile{0,0,'S'});
     newBlock->setBlockTile(3, Tile{2,1,'S'});
   }
   return newBlock;
}

Block* SBlock::rotateCCW() {
  return rotateCW();
}
