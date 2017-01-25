#ifndef SBLOCK_H
#define SBLOCK_H
#include "block.h"
class SBlock : public Block{
   public:
    SBlock();
    SBlock(int x, int y);
    Block* rotateCW() override;
    Block* rotateCCW() override;
    ~SBlock() {};
};
#endif
