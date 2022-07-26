#include "enemies.h"

class enemiesStack{
  int size;
  enemies* top;

public:
  enemiesStack();
  int pop();
  void push(int);
  ~enemiesStack();
};

enemiesStack::enemiesStack(enemies* p){
  
}



