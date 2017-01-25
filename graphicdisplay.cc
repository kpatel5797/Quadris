#include "window.h"
#include "graphicdisplay.h"
#include <sstream>
#include <vector>

/* COLOUR SCHEME FOR BLOCKS:
	I = RED
	J = GREEN
	L = BLUE
	O = CYAN
	S = YELLOW
	Z = MAGENTA
	T = ORANGE
*/

/* DIMENSIONS FOR GAME GRID */
const int TOP_BOARD_OFFSET = 100;
const int BOTTOM_BOARD_OFFSET = 100;
const int RIGHT_BOARD_OFFSET = 20;

/* DIMENSIONS FOR LEVEL, SCORE, HISCORE */
const int LEVEL_TEXT_OFFSET = 20;
const int SCORE_TEXT_OFFSET = 40;
const int HISCORE_TEXT_OFFSET = 60;
const int HUD_TOP_OFFSET = 20;

/* DIMENSIONS FOR NEXT TEXT + GRID */
const int NEXT_TEXT_OFFSET = 420;
const int RIGHT_NEXT_GRID_OFFSET = 400;
const int TOP_NEXT_GRID_OFFSET = 40;
const int NEXT_TILE_HEIGHT = 90;
const int NEXT_ROWS = 2;
const int NEXT_COLS = 4;

GraphicDisplay::GraphicDisplay(Xwindow* w, int r, int c): rows{r}, cols{c}, currentScore{0}, highScore{0},
level{0}, gameWindow{w} {}

void GraphicDisplay::setWindow(Xwindow* nw) {
	gameWindow = nw;
}

void GraphicDisplay::initDisplay() {
	if (gameWindow) {
		/* draw display */
		std::stringstream l; 	// level string
		std::stringstream s;	// score string
		std::stringstream hs;	// high score string
		l << level;
		s << currentScore;
		hs << highScore;
		gameWindow->drawString(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET + LEVEL_TEXT_OFFSET, "Level:    " + l.str(), Xwindow::Black);
		gameWindow->drawString(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET + SCORE_TEXT_OFFSET, "Score:    " + s.str(), Xwindow::Black);
		gameWindow->drawString(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET + HISCORE_TEXT_OFFSET, "Hi Score: " + hs.str(), Xwindow::Black);

		/* draw next text + next grid */
		gameWindow->drawString(NEXT_TEXT_OFFSET, LEVEL_TEXT_OFFSET, "Next:", Xwindow::Black); // draw next text
		for (int i = 0; i < NEXT_ROWS; i++) {
			for (int j = 0; j < NEXT_COLS; j++) {
				int nextX = j * (480 - RIGHT_NEXT_GRID_OFFSET) / NEXT_COLS + RIGHT_NEXT_GRID_OFFSET;
				int nextY = i * (NEXT_TILE_HEIGHT - TOP_NEXT_GRID_OFFSET) / NEXT_ROWS + TOP_NEXT_GRID_OFFSET;
				int nextWidth = (480 - RIGHT_NEXT_GRID_OFFSET) / NEXT_COLS - 3;
				int nextHeight = (NEXT_TILE_HEIGHT - TOP_NEXT_GRID_OFFSET) / NEXT_ROWS - 3;
				gameWindow->fillRectangle(nextX, nextY, nextWidth, nextHeight, Xwindow::White); // change to BLACK if testing
			}
		}

		/* draw game grid */
		for (int i = 0; i < rows; i++) { // draw the board
			for (int j = 0; j < cols; j++) {
				int x = j * (350 - RIGHT_BOARD_OFFSET) / cols + RIGHT_BOARD_OFFSET;
				int y = i * (500 - TOP_BOARD_OFFSET) / rows + TOP_BOARD_OFFSET;
				int width = (350 - RIGHT_BOARD_OFFSET) / cols - 3;
				int height = (500 - TOP_BOARD_OFFSET) / rows - 3;
				gameWindow->fillRectangle(x, y, width, height, Xwindow::White); // change to BLACK if testing
			}
		}
	}
}

void GraphicDisplay::resetDisplay() {
	if (gameWindow) {
		for (int i = 0; i < rows; i++) { 		// re-draw the board
			for (int j = 0; j < cols; j++) {
				int x = j * (350 - RIGHT_BOARD_OFFSET) / cols + RIGHT_BOARD_OFFSET;
				int y = i * (500 - TOP_BOARD_OFFSET) / rows + TOP_BOARD_OFFSET;
				int width = (350 - RIGHT_BOARD_OFFSET) / cols - 3;
				int height = (500 - TOP_BOARD_OFFSET) / rows - 3;
				gameWindow->fillRectangle(x, y, width, height, Xwindow::White); // change to BLACK if testing
			}
		}
	}
}

void GraphicDisplay::updateCell(const int row, const int col, const char blockCh) {
	if (gameWindow) {
		int x = col * (350 - RIGHT_BOARD_OFFSET) / cols + RIGHT_BOARD_OFFSET;
		int y = row * (500 - TOP_BOARD_OFFSET) / rows + TOP_BOARD_OFFSET;
		int width = (350 - RIGHT_BOARD_OFFSET) / cols - 3;
		int height = (500 - TOP_BOARD_OFFSET) / rows - 3;
		if (blockCh == 'I') {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Red);
		} else if (blockCh == 'J') {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Green);
		} else if (blockCh == 'L') {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Blue);
		} else if (blockCh == 'O') {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Cyan);
		} else if (blockCh == 'S') {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Yellow);
		} else if (blockCh == 'Z') {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Magenta);
		} else if (blockCh == 'T') {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Orange);
		} else if (blockCh == ' '){
			gameWindow->fillRectangle(x, y, width, height, Xwindow::White);
		} else if (blockCh == '*'){
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Brown);
		} else {
			gameWindow->fillRectangle(x, y, width, height, Xwindow::Black);
		}
	}
}

void GraphicDisplay::clearCell(const int row, const int col) {
	if (gameWindow) {
		int x = col * (350 - RIGHT_BOARD_OFFSET) / cols + RIGHT_BOARD_OFFSET;
		int y = row * (500 - TOP_BOARD_OFFSET) / rows + TOP_BOARD_OFFSET;
		int width = (350 - RIGHT_BOARD_OFFSET) / cols - 3;
		int height = (500 - TOP_BOARD_OFFSET) / rows - 3;
		gameWindow->fillRectangle(x, y, width, height, Xwindow::White);
	}
}

void GraphicDisplay::updateScore(const int newHighScore, const int newCurrentScore) {
	if (gameWindow) {
		currentScore = newCurrentScore;
		highScore = newHighScore;
		gameWindow->fillRectangle(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET + SCORE_TEXT_OFFSET - 10, 350, 40, Xwindow::White); // clear score + high score
		std::stringstream s;	// score string
		std::stringstream hs;	// high score string
		s << currentScore;
		hs << highScore;
		gameWindow->drawString(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET + SCORE_TEXT_OFFSET, "Score:    " + s.str(), Xwindow::Black);
		gameWindow->drawString(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET + HISCORE_TEXT_OFFSET, "Hi Score: " + hs.str(), Xwindow::Black);	
	}
}

void GraphicDisplay::updateLevel(const int newLevel) {
	if (gameWindow) {
		level = newLevel;
		gameWindow->fillRectangle(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET, 350, 20, Xwindow::White); // clear level
		std::stringstream l; 	// level string
		l << level;
		gameWindow->drawString(RIGHT_BOARD_OFFSET, HUD_TOP_OFFSET + LEVEL_TEXT_OFFSET, "Level:    " + l.str(), Xwindow::Black);
	}
}

void GraphicDisplay::drawNextShape(std::vector<int> rows, std::vector<int> cols, char block) {
	if (gameWindow) {
		int size = rows.size();
		for (int i = 0; i < size; i++) {
			int x = cols[i] * (480 - RIGHT_NEXT_GRID_OFFSET) / NEXT_COLS + RIGHT_NEXT_GRID_OFFSET;
			int y = rows[i] * (NEXT_TILE_HEIGHT - TOP_NEXT_GRID_OFFSET) / NEXT_ROWS + TOP_NEXT_GRID_OFFSET;
			int width = (480 - RIGHT_NEXT_GRID_OFFSET) / NEXT_COLS - 3;
			int height = (NEXT_TILE_HEIGHT - TOP_NEXT_GRID_OFFSET) / NEXT_ROWS - 3;
			if (block == 'I') {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Red);
			} else if (block == 'J') {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Green);
			} else if (block == 'L') {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Blue);
			} else if (block == 'O') {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Cyan);
			} else if (block == 'S') {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Yellow);
			} else if (block == 'Z') {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Magenta);
			} else if (block == 'T') {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Orange);
			} else {
				gameWindow->fillRectangle(x, y, width, height, Xwindow::Black);
			}	
		}
	}
}

void GraphicDisplay::updateNextBlock(const char newNextBlock) {
	if (gameWindow) {
		nextBlock = newNextBlock;
		gameWindow->fillRectangle(RIGHT_NEXT_GRID_OFFSET, TOP_NEXT_GRID_OFFSET, 200, NEXT_TILE_HEIGHT, Xwindow::White); // clear next
		if (nextBlock == 'I') {
			std::vector<int> rows = {0,0,0,0};
			std::vector<int> cols = {0,1,2,3};
			drawNextShape(rows, cols, 'I');

		} else if (nextBlock == 'J') {
			std::vector<int> rows = {0,1,1,1};
			std::vector<int> cols = {0,0,1,2};
			drawNextShape(rows, cols, 'J');

		} else if (nextBlock == 'L') {
			std::vector<int> rows = {1,1,1,0};
			std::vector<int> cols = {0,1,2,2};
			drawNextShape(rows, cols, 'L');

		} else if (nextBlock == 'O') {
			std::vector<int> rows = {0,0,1,1};
			std::vector<int> cols = {1,2,1,2};
			drawNextShape(rows, cols, 'O');

		} else if (nextBlock == 'S') {
			std::vector<int> rows = {1,0,1,0};
			std::vector<int> cols = {0,1,1,2};
			drawNextShape(rows, cols, 'S');

		} else if (nextBlock == 'Z') {
			std::vector<int> rows = {0,0,1,1};
			std::vector<int> cols = {0,1,1,2};
			drawNextShape(rows, cols, 'Z');

		} else if (nextBlock == 'T') {
			std::vector<int> rows = {0,0,0,1};
			std::vector<int> cols = {0,1,2,1};
			drawNextShape(rows, cols, 'T');
		}
	}
}
