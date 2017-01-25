#include "jblock.h"

JBlock::JBlock() : Block{0,3} {
  tilesOfBlock[0] = Tile{0,0,'J'};
  tilesOfBlock[1] = Tile{0,1,'J'};
  tilesOfBlock[2] = Tile{1,0,'J'};
  tilesOfBlock[3] = Tile{2,0,'J'}; 
}

JBlock::JBlock(int x =0, int y =2) : Block{x,y} {
  tilesOfBlock[0] = Tile{0,0,'J'};
  tilesOfBlock[1] = Tile{0,1,'J'};
  tilesOfBlock[2] = Tile{1,0,'J'};
  tilesOfBlock[3] = Tile{2,0,'J'}; 
}

Block* JBlock::rotateCW(){
  Block* newBlock = new JBlock{xPos,yPos};
  if(tilesOfBlock[3].x == 2 && tilesOfBlock[3].y == 0){
     newBlock->setBlockTile(0,tilesOfBlock[0]);
     newBlock->setBlockTile(1,tilesOfBlock[1]);
     newBlock->setBlockTile(2, Tile{0,2,'J'});
     newBlock->setBlockTile(3, Tile{1,2,'J'});
  }
  else if(tilesOfBlock[3].x == 1 && tilesOfBlock[3].y == 2){
     newBlock->setBlockTile(0, Tile{2,1,'J'});
     newBlock->setBlockTile(1, tilesOfBlock[1]);
     newBlock->setBlockTile(2, Tile{2,0,'J'});
     newBlock->setBlockTile(3, Tile{1,1,'J'});
  }
  else if(tilesOfBlock[3].x == 1 && tilesOfBlock[3].y == 1){
     newBlock->setBlockTile(0, Tile{0,0,'J'});
     newBlock->setBlockTile(1, Tile{1,1,'J'});
     newBlock->setBlockTile(2, Tile{1,2,'J'});
     newBlock->setBlockTile(3, Tile{1,0,'J'});
  }
  else{
     newBlock->setBlockTile(0, tilesOfBlock[0]);
     newBlock->setBlockTile(1, Tile{0,1,'J'});
     newBlock->setBlockTile(2, Tile{1,0,'J'});
     newBlock->setBlockTile(3, Tile{2,0,'J'});

  }
  return newBlock;
}

Block* JBlock::rotateCCW(){
  Block* newBlock = new JBlock{xPos, yPos};
  if(tilesOfBlock[3].x == 2 && tilesOfBlock[3].y == 0){
    newBlock->setBlockTile(0, tilesOfBlock[0]);
    newBlock->setBlockTile(1, Tile{1,1,'J'});
    newBlock->setBlockTile(2, Tile{1,2,'J'});
    newBlock->setBlockTile(3, Tile{1,0,'J'});
  }
  else if(tilesOfBlock[3].x == 1 && tilesOfBlock[3].y == 0){
    newBlock->setBlockTile(0, Tile{2,1,'J'});
    newBlock->setBlockTile(1, Tile{0,1,'J'});
    newBlock->setBlockTile(2, Tile{2,0,'J'});
    newBlock->setBlockTile(3, Tile{1,1,'J'});
  }
  else if(tilesOfBlock[3].x == 1 && tilesOfBlock[3].y == 1){
    newBlock->setBlockTile(0, Tile{0,0,'J'});
    newBlock->setBlockTile(1, Tile{0,1,'J'});
    newBlock->setBlockTile(2, Tile{0,2,'J'});
    newBlock->setBlockTile(3, Tile{1,2,'J'});
  }
  else{
    newBlock->setBlockTile(0, tilesOfBlock[0]);
    newBlock->setBlockTile(1, tilesOfBlock[1]);
    newBlock->setBlockTile(2, Tile{1,0,'J'});
    newBlock->setBlockTile(3, Tile{2,0,'J'});
  }
  return newBlock;
}
