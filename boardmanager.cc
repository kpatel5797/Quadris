#include "boardmanager.h"
#include "blocks.h"
#include <vector>

const int ROWS = 18;
const int COLS = 11;



BoardManager::BoardManager(int level, GraphicDisplay* graphics, TextDisplay* text, bool textFlag, std::string lvlFile): currentLevel{level} {
	textOnly = textFlag;
	display = graphics;
	textDisp = text;
	levels.emplace_back(new Level0{lvlFile}); 	// add all the levels to the vec
	levels.emplace_back(new Level1);
	levels.emplace_back(new Level2);
	levels.emplace_back(new Level3);
	levels.emplace_back(new Level4);
	for(int i = 0; i <ROWS; i++) {				// initialize the board with blank spaces 
		vector<Tile> row;
		for(int j = 0; j<COLS; j++) {
			Tile temp{i,j,' '};
			row.emplace_back(temp);
		}
		theBoard.emplace_back(row);
	}
}

void BoardManager::start() {
	currentBlock = levels[currentLevel]->getNext();
	currentBlock->setLevel(currentLevel);
	nextBlock = levels[currentLevel]->getNext();
	nextBlock->setLevel(currentLevel);
	display->updateNextBlock(nextBlock->getType());
	textDisp->updateNextBlock(nextBlock->getType());
	display->updateLevel(currentLevel);
	textDisp->updateLevel(currentLevel);
	drawBlock(currentBlock->getGlobalCoordsX(), currentBlock->getGlobalCoordsY());
}

void BoardManager::drawBlock(std::vector<int> xCoords, std::vector<int> yCoords) {
        if(hintOn){
           clearBlock(hintObj->getGlobalCoordsX(),hintObj->getGlobalCoordsY());
           hintOn = false;
           delete hintObj;
        }
	int size = xCoords.size();
	for (int i=0; i < size; i++) { 					// draw the block on the text and graphic display based on the vec provided
		display->updateCell(xCoords[i],yCoords[i],currentBlock->getType());
		textDisp->updateCell(xCoords[i],yCoords[i],currentBlock->getType());
	}
	//cout << *textDisp;
}

void BoardManager::drawTextDisp() { std::cout << *textDisp; }

void BoardManager::drawBlock(std::vector<int> xCoords, std::vector<int> yCoords, char type){
        if(hintOn){
           clearBlock(hintObj->getGlobalCoordsX(),hintObj->getGlobalCoordsY());
           hintOn=false;
           delete hintObj;
        }
	int size = xCoords.size();
	for (int i=0; i < size; i++) {
		display->updateCell(xCoords[i],yCoords[i],type);
		textDisp->updateCell(xCoords[i],yCoords[i],type);
	}
	//cout << *textDisp;
}

std::vector<int> BoardManager::getCurrentCoordsX() { return currentBlock->getGlobalCoordsX(); }

std::vector<int> BoardManager::getCurrentCoordsY() { return currentBlock->getGlobalCoordsY(); }

void BoardManager::clearBlock(std::vector<int> xCoords, std::vector<int> yCoords) {
	int size = xCoords.size();
	for (int i=0; i < size; i++) { 					// clear block on text and graphic display based on vec provided
		display->clearCell(xCoords[i], yCoords[i]);
		textDisp->clearCell(xCoords[i], yCoords[i]);
	}
}

char BoardManager::getTile(int x, int y) { 			// get the char of the tile obj at (x, y)
	return theBoard[x][y].getType();
}

int BoardManager::getLevel() { 						// get the current level
	return currentLevel;
}

bool BoardManager::getHeavy() { return heavy; }

void BoardManager::moveCurrent(int xShift, int yShift) {
	if (xShift == 0 && yShift == 0) return; // minor optimization
	std::vector<int> xCoords = currentBlock->getGlobalCoordsX();
	std::vector<int> yCoords = currentBlock->getGlobalCoordsY();
	int sizeX = xCoords.size();
	for (int i = 0; i < sizeX; i++) {
	    if (xCoords[i] == ROWS - 1 && yShift > 0) return; 		// for down boundary
 	    if (yCoords[i] == COLS - 1 && xShift > 0) return; 		// for right boundary
	    if (yCoords[i] == 0 && xShift < 0) return; 				//for left boundary
	    if (yCoords[i] + 1 < COLS && theBoard[xCoords[i]][yCoords[i] + 1].getType() != ' ' && xShift > 0) return;
	    if (yCoords[i] - 1 >= 0 && theBoard[xCoords[i]][yCoords[i] - 1].getType() != ' ' && xShift < 0) return;
	    if (xCoords[i] + 1 < ROWS && theBoard[xCoords[i] + 1][yCoords[i]].getType() != ' ' && yShift > 0) return;
	}

	currentBlock->shiftBlock(xShift, yShift); 	// shift the block	
 
}

void BoardManager::rotateCW() { //rotates the block clockwise
	Block* temp = currentBlock->rotateCW(); // make a temp block to rotate
	vector<int> rows = temp->getGlobalCoordsX();
	vector<int> cols = temp->getGlobalCoordsY();
	int sizeRows = rows.size();
	for(int i =0; i < sizeRows; i++){ // if we detect an illegal movement don't use the temp block
		if(rows[i] < 0 || rows[i] >= ROWS){
			delete temp;
			temp = currentBlock;
		}
		else if(cols[i] < 0 || cols[i] >= COLS){
			delete temp;
			temp = currentBlock;
		}
		else if(getTile(rows[i], cols[i]) != ' '){
			delete temp;
			temp = currentBlock;
		}
	}
	if(currentBlock != temp) delete currentBlock; // if the move was legal the temp will be different than the current
	currentBlock = temp;
	if(currentLevel >= 3 && heavy) { // shift down if it is heavy
		moveCurrent(0,1);   
	}
}

void BoardManager::rotateCCW() { //rotats the block counterclockwise
	Block* temp = currentBlock->rotateCCW(); // make a temp block to rotate
	vector<int> rows = temp->getGlobalCoordsX();
	vector<int> cols = temp->getGlobalCoordsY();
	int sizeRows = rows.size();
	for(int i =0; i < sizeRows; i++) {
		if(rows[i] < 0 || rows[i] >= ROWS) { // if we detect an illegal movement don't use the temp block
			delete temp;
		temp = currentBlock;
	}
	else if(cols[i] < 0 || cols[i] >= COLS) {
		delete temp;
		temp = currentBlock;
	}
	else if(getTile(rows[i], cols[i]) != ' '){
		delete temp;
		temp = currentBlock;
	}
}
if(currentBlock != temp) delete currentBlock;
currentBlock = temp;
	if(currentLevel >= 3 && heavy){ // shift down if heavy
		moveCurrent(0,1);
	}
}

void BoardManager::setLevel(int newLevel) { //sets the current level to the passed argument and updates the display
	if(newLevel < MAX_LEVEL && newLevel >= 0) { // check bounds for setting the level [0, 5]
		currentLevel = newLevel;
		display->updateLevel(currentLevel); // update displays
		textDisp->updateLevel(currentLevel);
	}
}

void BoardManager::clear() { // clears the board to restart the game
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			theBoard[i][j].clear();
			textDisp->updateCell(i,j,' '); // clear text disp
			display->updateCell(i,j,' ');
		}
	}
	int size = blocksOnBoard.size();
  	for(int i = 0; i<size; i++) { // clears all the blocks
  		delete blocksOnBoard[i];
  	} 
  	blocksOnBoard.clear();
  	delete currentBlock;
   	delete nextBlock;
  	score = 0;
  	textDisp->updateScore(highScore,score);
  	display->updateScore(highScore,score);
  	start();
  	//cout << *textDisp;
  }

  void BoardManager::setCurrentBlock(char blockType) {
	clearBlock(currentBlock->getGlobalCoordsX(), currentBlock->getGlobalCoordsY()); // clear current block
	int x = currentBlock->getPosX();
	int y = currentBlock->getPosY();
	delete currentBlock;
	if (blockType == 'I') {
		currentBlock = new IBlock{x,y};
	} 
	else if (blockType == 'J') {
		currentBlock = new JBlock{x,y};
	} 
	else if (blockType == 'L') {
		currentBlock = new LBlock{x,y};
	} 
	else if (blockType == 'O') {
		currentBlock = new OBlock{x,y};
	} 
	else if (blockType == 'S') {
		currentBlock = new SBlock{x,y};
	} 
	else if (blockType == 'Z') {
		currentBlock = new ZBlock{x,y};
	} 
	else if (blockType == 'T') {
		currentBlock = new TBlock{x,y};
	}
	drawBlock(currentBlock->getGlobalCoordsX(), currentBlock->getGlobalCoordsY()); // draw block at new coords
}

bool BoardManager::drop() { //drops the current block
	std::vector<int> xCoords = currentBlock->getGlobalCoordsX();
	std::vector<int> yCoords = currentBlock->getGlobalCoordsY();
	int size = xCoords.size();
	clearBlock(xCoords, yCoords); // clear original
	bool canDrop = true;
	while (canDrop) {
		xCoords = currentBlock->getGlobalCoordsX();
		yCoords = currentBlock->getGlobalCoordsY();
		for (int i = 0; i < size; i++) { // if it has space on board to drop then drop it
			if (xCoords[i] == ROWS - 1) {
				canDrop = false;
				break;
			}
			else if (theBoard[xCoords[i] + 1][yCoords[i]].getType() != ' ') {
				canDrop = false;
				break;
			}
		}
		if (canDrop) 
			currentBlock->shiftBlock(0,1);
	}
	for(int i =0; i<size; i++) { // update board with new tiles
		theBoard[xCoords[i]][yCoords[i]] = Tile{xCoords[i],yCoords[i],currentBlock->getType()};
		theBoard[xCoords[i]][yCoords[i]].addObserver(currentBlock);
	}
	if(hintOn) {
		clearBlock(hintObj->getGlobalCoordsX(),hintObj->getGlobalCoordsY()); // clear the old hint block
		hintOn = false;
		delete hintObj;
	}
	if(currentLevel == 4) {
		blocksDropped++;
		if(blocksDropped % 5 == 0) { // drop a single tile if the drop count reaches 10
			for(int i =0; i<ROWS; i++) {
                                if(i == ROWS-1){
                                  theBoard[i][(COLS-1)/2] = Tile{i,(COLS-1)/2,'*'};
                                  display->updateCell(i,(COLS-1)/2,'*');
                                  textDisp->updateCell(i,(COLS-1)/2,'*');
                                }
                                else if(theBoard[i+1][(COLS-1)/2].getType() != ' ') {
					theBoard[i][(COLS-1)/2] = Tile{i,(COLS-1)/2,'*'};
					display->updateCell(i,(COLS-1)/2,'*');
                                        textDisp->updateCell(i,(COLS-1)/2,'*');
					break;
				}
			}
		}
	}
	drawBlock(currentBlock->getGlobalCoordsX(), currentBlock->getGlobalCoordsY()); // draw the block at new coords
	blocksOnBoard.emplace_back(currentBlock);
	currentBlock = nextBlock;
	nextBlock = levels[currentLevel]->getNext();
	nextBlock->setLevel(currentLevel);
	if (theBoard[3][0].occupied() || theBoard[3][1].occupied()) return false;
	checkClear();
	if(score > highScore){
		highScore = score;
	}
	display->updateNextBlock(nextBlock->getType());
	textDisp->updateNextBlock(nextBlock->getType());
	display->updateScore(highScore,score);
	textDisp->updateScore(highScore,score);
	drawBlock(currentBlock->getGlobalCoordsX(), currentBlock->getGlobalCoordsY());
	return true;
}
void BoardManager::checkClear(){ // note: multiple rows can only be cleared if they are together
	int rowsCleared = 0;
	for(int i = ROWS-1; i>=0; i--){ // determine whether a row was cleared
		bool rowCleared = true;
		for(int j = 0; j < COLS; j++){
			if(theBoard[i][j].getType() == ' ') rowCleared=false;
		}
		if(rowCleared){
			for(int j = 0; j < COLS; j++){
				theBoard[i][j].clear();
				for(int k = i; k>=0; k--){
					if(k==0){
						display->updateCell(k,j,' ');
						theBoard[k][j] = Tile{k,j,' '};
						textDisp->updateCell(k,j,' ');
					}
					else{
						theBoard[k][j] = theBoard[k-1][j];
						display->updateCell(k,j,theBoard[k][j].getType());
						textDisp->updateCell(k,j,theBoard[k][j].getType());
					}
				}
			}
			for(unsigned int block = 0; block<blocksOnBoard.size(); block++){ 	// check which blocks are affected by the clear and
				vector<int> xCoords = blocksOnBoard[block]->getGlobalCoordsX(); // move them as far down as possible
				vector<int> yCoords = blocksOnBoard[block]->getGlobalCoordsY();
				bool affected = false;  
				vector<bool> onBoard = blocksOnBoard[block]->getExists();
				vector<bool>canMove(4);
				for(unsigned int j = 0; j < xCoords.size(); j++){
					if(xCoords[j] < i) {
						affected = true;
						blocksOnBoard[block]->shiftTile(j,1);
					}
					else if(xCoords[j] == i) onBoard[j] =false;
				}
				blocksOnBoard[block]->setExists(canMove);
				if(affected){
					xCoords = blocksOnBoard[block]->getGlobalCoordsX();
                              //Checks if any parts of the block are able to be dropped down
					for(unsigned int j = 0; j < xCoords.size(); j++){
						if(onBoard[j] && xCoords[j] < ROWS-1 ){
							if(theBoard[xCoords[j]+1][yCoords[j]].getType() == ' '){
								canMove[j] = true;
							}
							else canMove[j] = false;
						}
						else canMove[j] = false;     
					}
                                        vector<vector<bool>> dependancies(4);
                              //Set up all dependancies
                                        for(unsigned int j = 0; j<xCoords.size(); j++){
                                           if(onBoard[j]){
                                              vector<bool> currentDep(4);
                                              for(unsigned int k = 0; k<xCoords.size(); k++){
                                                 if(onBoard[k]){
                                                    if(j!=k && xCoords[j] == xCoords[k]){
                                                      if(yCoords[j] -1 == yCoords[k] || yCoords[j]+1 == yCoords[k]) currentDep[k] = true;
                                                    }
                                                    else if(j!=k && yCoords[j] == yCoords[k]){
                                                      if(xCoords[j] + 1 == xCoords[k]) currentDep[k] = true;
                                                    }
                                                    else if(j!=k && xCoords[j] -1 == xCoords[k]){
                                                      if(yCoords[j] - 1 == yCoords[k] || yCoords[j] + 1 == yCoords[k]) currentDep[k] = true;
                                                    }
                                                 }
                                                 else currentDep[k] = false; 
                                              }
                                              dependancies[j] = currentDep;
                                           }
                                        }
					for(unsigned int j = 0; j< xCoords.size(); j++){
					       bool willMove = true;
                                               if(onBoard[j] && canMove[j]){
    	                                          for(unsigned int k = 0; k<xCoords.size(); k++){
					             if(onBoard[k] && dependancies[j][k]){
                                                        if(!canMove[k]){
                                                           willMove = false;
                                                           break;
                                                        }
                                                     }	   
						  }
                                               }
                                               else willMove = false;
						if(willMove){
							theBoard[xCoords[j]][yCoords[j]] = Tile{xCoords[j],yCoords[j],' '};
							display->clearCell(xCoords[j],yCoords[j]);
							int shift = 0;
							for(unsigned int k = xCoords[j]+1; k<ROWS; k++){
								if(theBoard[k][yCoords[j]].getType() == ' ') shift++;
								else break;
							}
							blocksOnBoard[block]->shiftTile(j,shift);
							display->updateCell(xCoords[j]+shift,yCoords[j],blocksOnBoard[block]->getType());
							textDisp->updateCell(xCoords[j]+shift,yCoords[j],blocksOnBoard[block]->getType());
							theBoard[xCoords[j]+shift][yCoords[j]] = Tile{xCoords[j]+shift,yCoords[j],blocksOnBoard[block]->getType()};
						}
					}
				}
			}
			rowsCleared++;
			i=ROWS;
		}
	}
	if(rowsCleared != 0){
		score += ((currentLevel + rowsCleared) * (currentLevel  + rowsCleared));
		int size = blocksOnBoard.size();
		for(int i = 0; i<size; i++){
			if(blocksOnBoard[i]->cleared()){
				int levelMade = blocksOnBoard[i]->getLevel() + 1;
				score += (levelMade * levelMade);
				delete blocksOnBoard[i];
				blocksOnBoard.erase(blocksOnBoard.begin() + i);
				size-=1;
				i-=1;
			}
		}
	}
}

void BoardManager::hint() {
	Block* bestBlock = currentBlock;
	Block* hintBlock = currentBlock;
	int rotateX;
	int rotateY;
	int rotateBest = ROWS*COLS;
	for(int blocks = 0; blocks < 4; blocks++) {
		int bestX = 0;
		int bestY = 0;
		int bestScore = ROWS*COLS;
		vector<vector<bool>> valid;
		vector<bool> above;
		for(int i =0; i<ROWS; i++) {
			vector<bool> row;
			for(int j = 0; j<COLS; j++) {
				row.emplace_back(false);
			}
			valid.emplace_back(row);
		}
		vector<int> xCoords = hintBlock->getGlobalCoordsX();
		vector<int> yCoords = hintBlock->getGlobalCoordsY();
		int bottom = 0;
		int left = COLS;
		int right = 0;
		for(unsigned int i = 0; i<xCoords.size(); i++){
			bool over = false;
			for(unsigned int j= 0; j<xCoords.size(); j++){
				if(xCoords[i]+1 == xCoords[j] && yCoords[i] == yCoords[j]){ 
					over =true;
					break;
				}
			}
			above.emplace_back(over);
		}
		for(unsigned int i = 0; i<xCoords.size(); i++){
			if(xCoords[i] > bottom) bottom = xCoords[i];
			if(yCoords[i] < left) left = yCoords[i];
			if(yCoords[i] > right) right = yCoords[i];
		}
		for(unsigned int i = 0; i<xCoords.size(); i++){
			xCoords[i] = xCoords[i] - bottom;
			yCoords[i] = yCoords[i] - left;
		} 
		valid[bottom][left] = true;
		int dropFactor = 0;
		if(currentLevel >= 3 && heavy){
			if(blocks != 0){
				dropFactor = 1;
			}
		}
		reachable(valid,xCoords,yCoords,bottom+1,left);
		reachable(valid,xCoords,yCoords,bottom+dropFactor,left-1);
		reachable(valid,xCoords,yCoords,bottom+dropFactor,left+1);
		for(int i = ROWS-1; i>=bottom; i--){
			for(int j = 0; j<COLS; j++){
				if(valid[i][j]){
					int costForPos = 0;
					for(unsigned int tile = 0; tile<xCoords.size(); tile++){
						if(!above[tile]){
							for(int k = i+1+xCoords[tile]; k<ROWS; k++){
								if(theBoard[k][yCoords[tile]+j].getType() == ' ') costForPos++; 
								else break;
							}
						}
                                                bool left = false;
                                                bool right = false;
                                                bool aboveLeft = false;
                                                bool aboveRight = false;
                                                for(unsigned int otherTile = 0; otherTile < xCoords.size(); otherTile++){
                                                   if(xCoords[otherTile] +1 == xCoords[tile] && yCoords[otherTile] + 1 == yCoords[tile]) aboveLeft = true;
                                                   else if(xCoords[otherTile] + 1 == xCoords[tile] && yCoords[otherTile] - 1 == yCoords[tile]) aboveRight = true;
                                                   else if(xCoords[otherTile] == xCoords[tile] && yCoords[otherTile] + 1 == yCoords[tile]) left = true;
                                                   else if(xCoords[otherTile] == xCoords[tile] && yCoords[otherTile] -1 == yCoords[tile]) right = true;
                                                }
                                                if(yCoords[tile]+j -1 >= 0 && !left && i+xCoords[tile]-1 >= 0){
                                                   if(theBoard[i+xCoords[tile]][j+yCoords[tile]-1].getType() == ' '){
                                                      if(theBoard[i+xCoords[tile]-1][j+yCoords[tile]-1].getType() != ' ' || aboveLeft){
                                                        if(yCoords[tile]+j-2 < 0 || theBoard[i+xCoords[tile]][j+yCoords[tile]-2].getType() != ' '){
                                                          costForPos++;
                                                          j++;
                                                        }
                                                      }
                                                   }
                                                }
                                                if(yCoords[tile]+j + 1 < COLS && !right && i+xCoords[tile]-1 >=0){
                                                  if(theBoard[i+xCoords[tile]][j+yCoords[tile]+1].getType() == ' '){
                                                    if(theBoard[i+xCoords[tile]-1][j+yCoords[tile]+1].getType() != ' ' || aboveRight){
                                                       if(j+yCoords[tile]+2 >= COLS || theBoard[i+xCoords[tile]][j+yCoords[tile]+2].getType() != ' '){
                                                         costForPos++;
                                                         j++;
                                                       }
                                                    }
                                                  }
                                                }
					}
					bool assign = false;
					if(costForPos < bestScore){
						assign = true;
					}
					if(assign){
						bestScore = costForPos;
						bestX = i;
						bestY = j;
					}
				}
			}
		}  
		bool assign = false;
		if(bestScore < rotateBest){
			assign = true;
		}
		else if(bestScore == rotateBest){
			if(bestX > rotateX){
				assign = true;
			}
			else if(bestX == rotateX){
				if(bestY < rotateY){
					assign = true;
				}
			}
		}
		if(assign){
			rotateBest = bestScore;
			rotateX = bestX;
			rotateY = bestY;
			bestBlock = hintBlock;
		}
                Block* temp = hintBlock;
		hintBlock = hintBlock->rotateCW();
                if(temp!=bestBlock) delete temp;
	}
	if(hintBlock != bestBlock) delete hintBlock;
	vector<int> xCoords = bestBlock->getGlobalCoordsX();
	vector<int> yCoords = bestBlock->getGlobalCoordsY();
	int bottom = bestBlock->getPosY();
	int left = bestBlock->getPosX();
        if(currentBlock == bestBlock){
           Block* temp = bestBlock->rotateCW();
           bestBlock = temp->rotateCCW();
           delete temp;
        } 
	hintObj = bestBlock;
	hintObj->shiftBlock(rotateY-left,rotateX-bottom);
	drawBlock(hintObj->getGlobalCoordsX(),hintObj->getGlobalCoordsY(),'?');  
	hintOn = true; 
}

void BoardManager::reachable(vector<vector<bool>>& valids, vector<int>& xCoords, vector<int>& yCoords, int xPos, int yPos){

	if(xPos == ROWS) return;
	if(yPos == COLS || yPos < 0) return;
	if(valids[xPos][yPos]) return;
	for(unsigned int i = 0; i<xCoords.size(); i++){
		if(yPos + yCoords[i] >= COLS) return;
		if(theBoard[xPos+xCoords[i]][yPos+yCoords[i]].getType() != ' ') return;
	}
	valids[xPos][yPos] = true;
	reachable(valids, xCoords,yCoords,xPos+1,yPos);
	reachable(valids, xCoords,yCoords,xPos,yPos-1);
	reachable(valids, xCoords,yCoords,xPos,yPos+1);
}

void BoardManager::noRandom(std::string file){
	levels[3]->setRandomOff(file);
	levels[4]->setRandomOff(file);  
}

void BoardManager::random(){
	levels[3]->setRandomOn();
	levels[4]->setRandomOn();
}

BoardManager::~BoardManager(){
   if(hintOn) delete hintObj;
   delete currentBlock;
   delete nextBlock;
   for(unsigned int i =0; i<blocksOnBoard.size(); i++){
      delete blocksOnBoard[i];
   }

   for(unsigned int i = 0; i<levels.size(); i++){
      delete levels[i];
   }
}
