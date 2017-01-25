#include "block.h"
#include <iostream>
Block::Block(int x, int y, int created) : levelCreated{created}, xPos{x}, yPos{y} {
   for(int i =0; i<4; i++){
      exist.emplace_back(true);
   }
}
 
void Block::shiftBlock(int xShift, int yShift) {
  xPos += xShift;
  yPos += yShift;
}

char Block::getType(){
  return tilesOfBlock[0].getType();
}

int Block::getPosX(){
  return xPos;
}

int Block::getPosY(){
  return yPos;
}

std::vector<int> Block::getGlobalCoordsX() {
  std::vector<int> xCoords;
  xCoords.emplace_back(yPos - tilesOfBlock[0].y);
  xCoords.emplace_back(yPos -  tilesOfBlock[1].y);
  xCoords.emplace_back(yPos - tilesOfBlock[2].y);
  xCoords.emplace_back(yPos - tilesOfBlock[3].y);
  return xCoords;
}

std::vector<int> Block::getGlobalCoordsY() {
  std::vector<int> yCoords;
  yCoords.emplace_back(xPos + tilesOfBlock[0].x);
  yCoords.emplace_back(xPos + tilesOfBlock[1].x);
  yCoords.emplace_back(xPos + tilesOfBlock[2].x);
  yCoords.emplace_back(xPos + tilesOfBlock[3].x);
  return yCoords;
}

void Block::setBlockTile(int toSet, Tile tile) {
  tilesOfBlock[toSet] = tile;
}

void Block::notify() {
  tilesLeft--;
}      

bool Block::cleared() {
  return tilesLeft == 0;
}

int Block::getLevel() {
  return levelCreated;
}

void Block::setLevel(int level) {
   levelCreated = level;
}

std::vector<bool> Block::getExists() {
  return exist;
}

void Block::setExists(std::vector<bool>& set) {
  exist = set;
}

void Block::shiftTile(int tile, int shift) {
   tilesOfBlock[tile].y -= shift;
}

void Block::changeType(char type){
   tilesOfBlock[0].setType(type);
}
