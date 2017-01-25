#include "commandinterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "window.h"
int main(int argc, char** argv){
  unsigned int seed = 0;
  bool seedSet = false;
  std::string file = "sequence.txt";
  bool textOnly = false;
  int startLevel = 0;
  std::string argument;
  if(argc > 1){
     for(int i = 1; i < argc; i++){
        argument = std::string{argv[i]};
        if(argument == "-text") textOnly = true;
        else if(argument == "-seed"){
           i++;
           std::istringstream argStream{std::string{argv[i]}};
           argStream >> seed;
           seedSet =true;
        }
        else if(argument == "-scriptfile"){
           i++;
           file = std::string{argv[i]};
        }
        else if(argument == "-startlevel"){
           i++;
           std::istringstream argStream{std::string{argv[i]}};
           argStream >> startLevel;
        }
     }
  }

  if(seedSet){
    srand(seed);
  }
  else{
    std::ifstream seedFile{"seed"};
    seedFile >> seed;
    std::srand(seed);
    std::ofstream seedWrite{"seed"};
    seedWrite << seed+1;
  }

  if (textOnly == true) {
    GraphicDisplay gDisp{nullptr,18,11};
    TextDisplay text{18,11};
    CommandInterface interface{&gDisp,&text,textOnly,file,startLevel};
    interface.start();
    std::string command;
    while(std::cin >> command){
     interface.runCommand(command);
    }
  } else if (textOnly == false) {
    Xwindow w;
    GraphicDisplay gDisp{&w,18,11};
    TextDisplay text{18,11};
    CommandInterface interface{&gDisp,&text,textOnly,file,startLevel};
    gDisp.initDisplay(); // draw the initial display
    interface.start();
    std::string command;
    while(std::cin >> command){
       if (!interface.runCommand(command)) break;
    }
  }
}
