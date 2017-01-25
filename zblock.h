#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "block.h"
class ZBlock : public Block{
  public:
   ZBlock();
   ZBlock(int x, int y);
   Block* rotateCW() override;
   Block* rotateCCW() override; 
};
#endif
