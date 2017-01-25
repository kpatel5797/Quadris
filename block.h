#ifndef BLOCK_H
#define BLOCK_H
#include "tile.h"
#include "observer.h"
#include <vector>
class Block : public Observer{
   int tilesLeft = 4;
   int levelCreated;
   std::vector<bool> exist;
   protected:
   int xPos;
   int yPos;
   Tile tilesOfBlock[4];
   public:
    Block(int x, int y, int created=0);
    virtual ~Block() {};
    virtual Block* rotateCW() = 0;
    virtual Block* rotateCCW() = 0;
    char getType();
    void shiftBlock(int xShift, int yShift);
    int getPosX();
    int getPosY();
    void setBlockTile(int toSet, Tile tile);
    std::vector<int> getGlobalCoordsX();
    std::vector<int> getGlobalCoordsY();
    void notify() override;
    int getLevel();
    void setLevel(int level);
    bool cleared();
    std::vector<bool> getExists();
    void setExists(std::vector<bool>& set);
    void shiftTile( int tile, int shift);
    void changeType(char type);
};

#endif
