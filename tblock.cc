#include "tblock.h"

TBlock::TBlock() : Block{0,3} {
  tilesOfBlock[0] = Tile{1,1,'T'};
  tilesOfBlock[1] = Tile{0,0,'T'};
  tilesOfBlock[2] = Tile{1,0,'T'};
  tilesOfBlock[3] = Tile{2,0,'T'}; 
}

TBlock::TBlock(int x=0, int y=2) : Block{x,y} {
  tilesOfBlock[0] = Tile{1,1,'T'};
  tilesOfBlock[1] = Tile{0,0,'T'};
  tilesOfBlock[2] = Tile{1,0,'T'};
  tilesOfBlock[3] = Tile{2,0,'T'}; 
}

Block* TBlock::rotateCW(){
  Block* newBlock = new TBlock{xPos, yPos};
  newBlock->setBlockTile(0, tilesOfBlock[0]);
  if(tilesOfBlock[3].x == 2 && tilesOfBlock[3].y == 0){
    newBlock->setBlockTile(1, tilesOfBlock[1]);
    newBlock->setBlockTile(2, Tile{0,1,'T'});
    newBlock->setBlockTile(3, Tile{0,2,'T'});
  }
  else if(tilesOfBlock[3].y == 2 && tilesOfBlock[3].x == 0){
    newBlock->setBlockTile(1, Tile{1,0,'T'}); 
    newBlock->setBlockTile(2, tilesOfBlock[2]);
    newBlock->setBlockTile(3, Tile{2,1,'T'});
  }
  else if(tilesOfBlock[3].y == 1){
    newBlock->setBlockTile(1, tilesOfBlock[1]);
    newBlock->setBlockTile(2, tilesOfBlock[2]);
    newBlock->setBlockTile(3, Tile{1,2,'T'});
  }
  else{
    //Move tiles to original positions
    newBlock->setBlockTile(1, Tile{0,0,'T'});
    newBlock->setBlockTile(2, Tile{1,0,'T'});
    newBlock->setBlockTile(3, Tile{2,0,'T'});
  }
  return newBlock;
}

Block* TBlock::rotateCCW(){
  Block* newBlock = new TBlock{xPos,yPos};
  newBlock->setBlockTile(0, tilesOfBlock[0]);
  if(tilesOfBlock[3].x == 2 && tilesOfBlock[3].y == 0){
     newBlock->setBlockTile(1, Tile{0,1,'T'});
     newBlock->setBlockTile(2, tilesOfBlock[2]);
     newBlock->setBlockTile(3, Tile{1,2,'T'});
  }
  else if(tilesOfBlock[3].y == 2 && tilesOfBlock[3].x == 1){
     newBlock->setBlockTile(1, tilesOfBlock[1]);
     newBlock->setBlockTile(2, tilesOfBlock[2]);
     newBlock->setBlockTile(3, Tile{2,1,'T'});
  }
  else if(tilesOfBlock[3].x == 2){
     newBlock->setBlockTile(1, Tile{0,0,'T'});
     newBlock->setBlockTile(2, Tile{0,1,'T'});
     newBlock->setBlockTile(3, Tile{0,2,'T'});
  }
  else{
     newBlock->setBlockTile(1, tilesOfBlock[1]);
     newBlock->setBlockTile(2, Tile{1,0,'T'});
     newBlock->setBlockTile(3, Tile{2,0,'T'});
  }
  return newBlock;
}
