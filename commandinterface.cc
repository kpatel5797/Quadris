#include "commandinterface.h"
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
const std::vector<std::string> COMMANDS = {"left", "right", "down", 
"clockwise", "counterclockwise", "drop", "levelup", "leveldown", 
"norandom", "random", "sequence", "I", "J", "L", "S", "Z", "O",
"T", "restart", "hint", "quit", "q", "exit"};
const int COMMANDS_SIZE = COMMANDS.size();

int countMatches(const std::string& s1, const std::string& s2) {
  int length1 = s1.length();
  int length2 = s2.length();
  int matches = 0;
  int shorterLen = (length1 < length2) ? length1 : length2;
  for (int i = 0; i < shorterLen; i++) {
    if (s1[i] == s2[i]) ++matches;
  }
  return matches;
}

std::vector<std::string> CommandInterface::getPossibleCommands(std::string command) {
  std::vector<std::string> retVec;
  std::vector<std::pair<int,int>> matchesPerCommand;  // keeps track of the matches for each command
  for (int i = 0; i < COMMANDS_SIZE; i++) {           // store the number of matches for each command
    if (COMMANDS[i] == command) {                     // return right away if we find a match
      retVec.emplace_back(command);
      return retVec;
    }                                                 // else append to the vec a pair with index and number of matches
    std::pair<int,int> p = {i, countMatches(COMMANDS[i],command)};
    matchesPerCommand.emplace_back(p);
  }

  std::sort(matchesPerCommand.begin(), matchesPerCommand.end(), 
    [](auto &x, auto &y) { return x.second > y.second;}); // sort the pairs

  for (int i = 0; i < COMMANDS_SIZE-1; i++) { // compose a vector of all the words with the most matches
    if (matchesPerCommand[i].second != matchesPerCommand[i+1].second) {
      retVec.emplace_back(COMMANDS[matchesPerCommand[i].first]);
      return retVec;
    } else {
      retVec.emplace_back(COMMANDS[matchesPerCommand[i].first]);
    }
  }
  return retVec;
}

void CommandInterface::start(){
   board.start();
   board.drawTextDisp();
}

bool CommandInterface::runCommand(std::string command){
  std::istringstream commandStream{command};
  int repetitions = 0;
  if(!(commandStream >> repetitions)){
    commandStream.ignore();
    repetitions = 1; 
  }
  commandStream >> command;

  std::vector<std::string> possibleCmds = getPossibleCommands(command); // get list of possible commands
  int sizePossible = possibleCmds.size();
  if (sizePossible == 1) {
    command = possibleCmds[0]; // execute the only possibility
  } else { // display a message if > 1
    std::cout << "You entered: \"" << command << "\" did you mean one of these? " << std::endl;
    for (int i = 0; i < sizePossible; i++) {
      std::cout << possibleCmds[i] << " ";
    }
    std::cout << std::endl;
    return true; // break from the current command input
  }

  for(int i = 0; i<repetitions; i++){
  if(command == "left"){ 
    board.clearBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // clear old block
    for (int j = 0; j < repetitions; j++) {
      board.moveCurrent(-1,0);
    }
    if(board.getLevel() >= 3 && board.getHeavy()) { // move the block down if it is a heavy block
      board.moveCurrent(0,1);
    }
    board.drawBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // draw new block
    board.drawTextDisp();
    return true;
  }
  else if(command == "right"){
    board.clearBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // clear old block
    for (int j = 0; j < repetitions; j++) {
      board.moveCurrent(1,0);
    }
    if(board.getLevel() >= 3 && board.getHeavy()) { // move the block down if it is a heavy block
      board.moveCurrent(0,1);
    }
    board.drawBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // draw new block
    board.drawTextDisp();
    return true;
  }
  else if(command == "down"){
    board.clearBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // clear old block
    for (int j = 0; j < repetitions; j++) {
      board.moveCurrent(0,1);
    }
    board.drawBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // draw new block
    board.drawTextDisp();
    return true;
  }
  else if(command == "clockwise"){
    board.clearBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // clear old block
    for (int j = 0; j < repetitions; j++) {
      board.rotateCW();
    }
    board.drawBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // draw new block
    board.drawTextDisp();
    return true;
  }
  else if(command == "counterclockwise"){
    board.clearBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // clear old block
    for (int j = 0; j < repetitions; j++) {
      board.rotateCCW();
    }
    board.drawBlock(board.getCurrentCoordsX(), board.getCurrentCoordsY()); // draw new block
    board.drawTextDisp();
    return true;
  }
  else if(command == "drop"){
    if (!board.drop()) {
      std::cout << "The game is over. The board will now be reset!" << std::endl;
      board.clear();
      board.drawTextDisp();
      return true;
    }
    board.drawTextDisp();
  }
  else if(command == "levelup"){
    board.setLevel(board.getLevel() + 1);
    board.drawTextDisp();
  }
  else if(command == "leveldown"){
    board.setLevel(board.getLevel() - 1);
    board.drawTextDisp();
  }
  else if(command == "norandom"){
    std::string filename;
    std::cin >> filename;
    board.noRandom(filename);  
  }
  else if(command == "random"){
    board.random();
  }
  else if(command == "sequence"){
    std::string filename;
    std::cin >> filename;
    std::ifstream seqFile{filename};
    while(!seqFile.eof()){
       std::string command;
       seqFile >> command;
       runCommand(command); 
    }
  }
  else if(command == "I"){
    board.setCurrentBlock('I');
    board.drawTextDisp();
  }
  else if(command == "J"){
    board.setCurrentBlock('J');
    board.drawTextDisp();
  }
  else if(command == "L"){
    board.setCurrentBlock('L');
    board.drawTextDisp();
  }
  else if(command == "S"){
    board.setCurrentBlock('S');
    board.drawTextDisp();
  }
  else if(command == "Z"){
    board.setCurrentBlock('Z');
    board.drawTextDisp();
  }
  else if(command == "O"){
    board.setCurrentBlock('O');
    board.drawTextDisp();
  }
  else if(command == "T"){
    board.setCurrentBlock('T');
    board.drawTextDisp();
  }
  else if(command == "restart"){
    board.clear();
    board.drawTextDisp();
  }
  else if(command == "hint"){
    board.hint();
    board.drawTextDisp();
    return true;
  }
  else if (command == "quit" || command == "q" || command == "exit") return false;
  }
  //board.drawBlock(board.getCurrentCoordsX(),board.getCurrentCoordsY());
  return true;
}

