#ifndef OBLOCK_H
#define OBLOCK_H
#include "block.h"

class OBlock : public Block{
  public:
   OBlock();
   OBlock(int x, int y) ;
   Block* rotateCW() override; 

   Block* rotateCCW() override;  
};

#endif
