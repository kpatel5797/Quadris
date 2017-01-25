#ifndef TILE_H
#define TILE_H
#include "subject.h"
class Tile : public Subject{  
  char tileType;
  int neighbors = 0;
  public: 
  int x;
  int y; 
  Tile() : tileType{' '}, x{0}, y{0} {}; 
  Tile(int setX, int setY, char setType) : tileType{setType}, x{setX}, y{setY} {};
  bool occupied();
  char getType();
  void setType(char type);
  void clear();
};

#endif
