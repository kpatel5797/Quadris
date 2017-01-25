#ifndef LBLOCK_H
#define LBLOCK_H
#include "block.h"

class LBlock : public Block{

  public:
   LBlock();
   LBlock(int x, int y);
   Block* rotateCW() override;
   Block* rotateCCW() override;
};


#endif
