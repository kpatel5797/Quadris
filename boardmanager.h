#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H
#include "graphicdisplay.h"
#include "textdisplay.h"
#include "tile.h"
#include "block.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level0.h"
#include <vector>
#include <string>
class BoardManager{
   int blocksDropped = 0; 
   Block* hintObj;
   bool hintOn = false;
   std::vector<std::vector<Tile>> theBoard;
   std::vector<Block*> blocksOnBoard;
   int currentLevel;
   int score = 0;
   int highScore = 0;
   bool textOnly;
   bool heavy = true;
   const int MAX_LEVEL = 5;
   std::vector<Level*> levels;
   Block* currentBlock;
   Block* nextBlock;
   GraphicDisplay* display;
   TextDisplay* textDisp;
   void reachable(vector<vector<bool>>&valids, vector<int>&xCoords,vector<int>&yCoords,int xPos, int yPos);
   public:
    BoardManager(int level, GraphicDisplay* graphics, TextDisplay* text, bool textFlag, std::string lvlFile);
    ~BoardManager();
    void start();
    char getTile(int xPos, int yPos);
    int getLevel();
    bool getHeavy();
    void drawTextDisp();
    std::vector<int> getCurrentCoordsX();
    std::vector<int> getCurrentCoordsY();
    void clearBlock(std::vector<int> xCoords, std::vector<int> yCoords);
    void drawBlock(std::vector<int> xCoords, std::vector<int> yCoords);
    void drawBlock(std::vector<int> xCoords, std::vector<int> yCoords, char type);
    void moveCurrent(int xMove, int yMove);
    void rotateCW();
    void rotateCCW();
    void setLevel(int level);
    void clear();
    void setCurrentBlock(char blockName);
    bool dropOne();
    bool drop();
    void hint();
    void checkClear();
    void noRandom(std::string file);
    void random();
};


#endif
