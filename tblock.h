#ifndef TBLOCK_H
#define TBLOCK_H
#include "block.h"

class TBlock : public Block{
   public:
    TBlock();
    TBlock(int x, int y);
    Block* rotateCW() override;
    Block* rotateCCW() override;
};

#endif
