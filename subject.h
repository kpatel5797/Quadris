#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <vector>

class Subject{
   std::vector<Observer*> observers;
  protected: 
   void removeObservers();
   void notifyObservers();
  public:
   void addObserver(Observer* toAdd);
};

#endif
