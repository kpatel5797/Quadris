#ifndef IBLOCK_H
#define IBLOCK_H
#include "block.h"

class IBlock : public Block{
   public:
    IBlock();
    IBlock(int x, int y);
    Block* rotateCW() override;
    Block* rotateCCW() override;
};


#endif
