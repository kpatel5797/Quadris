#ifndef JBLOCK_H
#define JBLOCK_H
#include "block.h"

class JBlock : public Block{
   public:
     JBlock();
     JBlock(int x, int y);
     Block* rotateCW() override;
     Block* rotateCCW() override; 
};

#endif
