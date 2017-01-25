#include "zblock.h"

ZBlock::ZBlock() : Block{0,3} {
   tilesOfBlock[0] = Tile{0,1,'Z'};
   tilesOfBlock[1] = Tile{1,1,'Z'};
   tilesOfBlock[2] = Tile{1,0,'Z'};
   tilesOfBlock[3] = Tile{2,0,'Z'};

}

ZBlock::ZBlock(int x = 0, int y =2) : Block{x,y} {
   tilesOfBlock[0] = Tile{0,1,'Z'};
   tilesOfBlock[1] = Tile{1,1,'Z'};
   tilesOfBlock[2] = Tile{1,0,'Z'};
   tilesOfBlock[3] = Tile{2,0,'Z'};
} 

Block* ZBlock::rotateCW(){
   Block* newBlock = new ZBlock{xPos, yPos};
   newBlock->setBlockTile(0, tilesOfBlock[0]);
   newBlock->setBlockTile(1, tilesOfBlock[1]);
   if(tilesOfBlock[2].x == 1){
     newBlock->setBlockTile(2, Tile{0,0,'Z'});
     newBlock->setBlockTile(3, Tile{1,2,'Z'}); 
   }
   else{
     newBlock->setBlockTile(2, Tile{1,0,'Z'});
     newBlock->setBlockTile(3, Tile{2,0,'Z'});
   }
   return newBlock;
}

Block* ZBlock::rotateCCW() {
   return rotateCW(); 
}

