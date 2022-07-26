#include "enemies.h"

class enemiesS{
  int size;
  enemies* top;

public:
  enemiesS(enemies* t=NULL);
  void pop();
  void push(enemies*);
  int get_size();
  void print_all();
  enemies* get_top();
  ~enemiesS();
};

enemies* enemiesS::get_top(){
  return top;
}

enemiesS::enemiesS(enemies* t){
  if (t) {
    top = t;
    size = 1;
  } else {
    top = NULL;
    size = 0;
  }
}

void enemiesS::push(enemies *s){
   if(s){
    s->set_next(top); 
    top = s;          
    size++;                 
  }
}

void enemiesS::pop(){
  enemies* t = top;
  string name;
  if (t){
    top = top->get_next();
    name = t->get_name();
    delete t;
    size--;
  }
  else{
    cout<<"There are no more enemies"<<endl;
  }
}

enemiesS::~enemiesS(){
 //cout<<"Killing all enemies"<<endl;
  int i;
  enemies* t = top;
  for(i=0;i<size;i++){
    t = top;
    top=top->get_next();
    delete t;
  }
}

int enemiesS::get_size(){
  return size;
}

void enemiesS::print_all(){
  enemies* s;
  cout<<"Name: "<<s->get_name()<<endl;
  cout<<"HP: "<<s->get_hp()<<endl;
  cout<<"Attack: "<<"1->"<<s->get_attack()<<endl;
  cout<<"Defense: "<<s->get_def()<<endl;
}



