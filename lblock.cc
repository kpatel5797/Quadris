#include "lblock.h"

LBlock::LBlock() : Block{0,3} {
   tilesOfBlock[0] = Tile{0,0,'L'};
   tilesOfBlock[1] = Tile{1,0,'L'};
   tilesOfBlock[2] = Tile{2,0,'L'};
   tilesOfBlock[3] = Tile{2,1,'L'};

}

LBlock::LBlock(int x=0, int y=2) : Block{x,y} {
   tilesOfBlock[0] = Tile{0,0,'L'};
   tilesOfBlock[1] = Tile{1,0,'L'};
   tilesOfBlock[2] = Tile{2,0,'L'};
   tilesOfBlock[3] = Tile{2,1,'L'};
}

Block* LBlock::rotateCW() {
   Block* newBlock = new LBlock{xPos,yPos};
   if(tilesOfBlock[2].x == 2 && tilesOfBlock[2].y == 0){
      newBlock->setBlockTile(0, tilesOfBlock[0]);
      newBlock->setBlockTile(1, tilesOfBlock[1]);
      newBlock->setBlockTile(2 , Tile{0,2,'L'});
      newBlock->setBlockTile(3, Tile{0,1,'L'});
   }
   else if(tilesOfBlock[2].x == 0 && tilesOfBlock[2].y == 2){
      newBlock->setBlockTile(0, tilesOfBlock[0]);
      newBlock->setBlockTile(1, Tile{1,1,'L'});
      newBlock->setBlockTile(2, Tile{2,1,'L'});
      newBlock->setBlockTile(3, tilesOfBlock[3]);
   }
   else if(tilesOfBlock[2].x == 2){
      newBlock->setBlockTile(0, Tile{0,2,'L'});
      newBlock->setBlockTile(1, tilesOfBlock[1]);
      newBlock->setBlockTile(2, Tile{1,0,'L'});
      newBlock->setBlockTile(3, Tile{1,2,'L'});
   }
   else{
      newBlock->setBlockTile(0, Tile{0,0,'L'});
      newBlock->setBlockTile(1, Tile{1,0,'L'});
      newBlock->setBlockTile(2, Tile{2,0,'L'});
      newBlock->setBlockTile(3, Tile{2,1,'L'});
   }
   return newBlock;
}

Block* LBlock::rotateCCW(){
   Block* newBlock = new LBlock{xPos, yPos};
   if(tilesOfBlock[2].x == 2 && tilesOfBlock[2].y == 0){
      newBlock->setBlockTile(0, Tile{0,2,'L'});
      newBlock->setBlockTile(1, Tile{1,1,'L'});
      newBlock->setBlockTile(2, Tile{1,0,'L'});
      newBlock->setBlockTile(3, Tile{1,2,'L'});
   }
   else if(tilesOfBlock[2].x == 1 && tilesOfBlock[2].y == 0){
      newBlock->setBlockTile(0, Tile{0,0,'L'});
      newBlock->setBlockTile(1, tilesOfBlock[1]);
      newBlock->setBlockTile(2,Tile{2,1,'L'});
      newBlock->setBlockTile(3, Tile{0,1,'L'});
   }
   else if(tilesOfBlock[2].x == 2){
      newBlock->setBlockTile(0, tilesOfBlock[0]);
      newBlock->setBlockTile(1, Tile{1,0,'L'});
      newBlock->setBlockTile(2, Tile{0,2,'L'});
      newBlock->setBlockTile(3, Tile{0,1,'L'});
   }
   else{
      newBlock->setBlockTile(0, tilesOfBlock[0]);
      newBlock->setBlockTile(1, tilesOfBlock[1]);
      newBlock->setBlockTile(2, Tile{2,0,'L'});
      newBlock->setBlockTile(3, Tile{2,1,'L'});
   }
   return newBlock;
}
