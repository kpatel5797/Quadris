#include "subject.h"


void Subject::addObserver(Observer* toAdd){
    observers.emplace_back(toAdd);
}

void Subject::removeObservers(){
   observers.clear();
}

void Subject::notifyObservers(){
   int size = observers.size();
   for(int i = 0; i<size; i++){
      observers[i]->notify();
   }
}
