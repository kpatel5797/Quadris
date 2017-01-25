#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
using namespace std;

class TextDisplay {
	int rows, cols; 				// dimens of the board
	int currentScore, highScore; 	// scores
	int level; 						// level number
	char nextBlock; 				// the next block
	vector<vector<char>> textBoard; // the board
public:
	TextDisplay(int r, int c);
	~TextDisplay();
	void updateCell(const int row, const int col, const char blockCh);
	void clearCell(const int row, const int col);
	void updateScore(const int newHighScore, const int newCurrentScore);
	void updateLevel(const int newLevel);
	void updateNextBlock(const char newNextBlock);

        friend ostream& operator<<(ostream& out, const TextDisplay& td);
};


#endif
