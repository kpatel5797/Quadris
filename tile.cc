#include "tile.h"

bool Tile::occupied(){
   return !(tileType == ' ');
}

char Tile::getType(){
   return tileType;
}

void Tile::clear(){
   tileType = ' ';
   notifyObservers();
   removeObservers();
}


void Tile::setType(char type){
   tileType = type;
}

