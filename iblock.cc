#include "iblock.h"
#include <iostream>
IBlock::IBlock() : Block{0,3} {
tilesOfBlock[0] = Tile{0,0,'I'};
   tilesOfBlock[1] = Tile{1,0,'I'};
   tilesOfBlock[2] = Tile{2,0,'I'};
   tilesOfBlock[3] = Tile{3,0,'I'};

}

IBlock::IBlock(int x =0, int y = 2) : Block{x,y} {
   tilesOfBlock[0] = Tile{0,0,'I'};
   tilesOfBlock[1] = Tile{1,0,'I'};
   tilesOfBlock[2] = Tile{2,0,'I'};
   tilesOfBlock[3] = Tile{3,0,'I'};
}

Block* IBlock::rotateCW(){
   Block* myNew = new IBlock{xPos,yPos};
   for(int i =0; i<=3; i++){
      myNew->setBlockTile(i,Tile{tilesOfBlock[i].y,tilesOfBlock[i].x,'I'});
   }
   return myNew;
}

Block* IBlock::rotateCCW(){
   Block* newBlock = new IBlock{xPos,yPos};
   for(int i =0; i<=3; i++){
      newBlock->setBlockTile(i, Tile{tilesOfBlock[i].y,tilesOfBlock[i].x,'I'});
   }
   return newBlock;
}
