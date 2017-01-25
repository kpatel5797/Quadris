#include "textdisplay.h"
#include <vector>
#include <iostream>

TextDisplay::TextDisplay(int r, int c): rows{r}, cols{c}, currentScore{0}, highScore{0}, level{0} {
	for (int i = 0; i < rows; i++) {  // init the board with empty spaces
		std::vector<char> block;
		for (int j = 0; j < cols; j++) {
			block.emplace_back(' ');
		}
		textBoard.emplace_back(block);
	}
}

TextDisplay::~TextDisplay() {}

void TextDisplay::updateCell(const int row, const int col, const char blockCh) {
	textBoard[row][col] = blockCh;
}

void TextDisplay::clearCell(const int row, const int col) {
	textBoard[row][col] = ' ';
}

void TextDisplay::updateScore(const int newHighScore, const int newCurrentScore) {
	currentScore = newCurrentScore;
	highScore = newHighScore;
}

void TextDisplay::updateLevel(const int newLevel) {
	level = newLevel;
}

void TextDisplay::updateNextBlock(const char newNextBlock) {
	nextBlock = newNextBlock;
}

std::ostream& operator<<(std::ostream& out, const TextDisplay& td) {
	out << endl;
	out << "Level:     " << td.level << endl;
	out << "Score:     " << td.currentScore << endl;
	out << "Hi Score:  " << td.highScore << endl;
	out << "-----------" << endl;
	for (int i = 0; i < td.rows; i++) {
		for (int j = 0; j < td.cols; j++) {
			out << td.textBoard[i][j];
		}
		out << endl;
	}
	out << "-----------" << endl;
	out << "Next:" << endl;
	char nextBlock = td.nextBlock;
	if (nextBlock == 'I') {
		out << "IIII" << endl;
	} else if (nextBlock == 'J') {
		out << "J  " << endl;
		out << "JJJ" << endl;
	} else if (nextBlock == 'L') {
		out << "  L" << endl;
		out << "LLL" << endl;
	} else if (nextBlock == 'O') {
		out << "OO" << endl;
		out << "OO" << endl;
	} else if (nextBlock == 'S') {
		out << " SS" << endl;
		out << "SS " << endl;
	} else if (nextBlock == 'Z') {
		out << "ZZ " << endl;
		out << " ZZ" << endl;
	} else {
		out << "TTT" << endl;
		out << " T " << endl;
	}
	out << endl;
	return out;
}
