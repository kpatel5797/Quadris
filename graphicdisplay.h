#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include "window.h"
#include <vector>
using namespace std;

class GraphicDisplay {
	int rows, cols;
	int currentScore, highScore;
	int level;
	char nextBlock;
	Xwindow* gameWindow;
	void drawNextShape(vector<int> rows, vector<int> cols, char block);
public:
	GraphicDisplay(Xwindow* w, int r, int c);
	void setWindow(Xwindow* nw);
	void initDisplay();
	void resetDisplay();
	void updateCell(const int row, const int col, const char blockCh);
	void clearCell(const int row, const int col);
	void updateScore(const int newHighScore, const int newCurrentScore);
	void updateLevel(const int newLevel);
	void updateNextBlock(const char newNextBlock);
};

#endif
