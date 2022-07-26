#include "player.h"

class playerLL{
  int size;
  player* head;

public:
  playerLL();
  void insert(player*);
  void printList();
  ~playerLL();
};

playerLL::playerLL(){
  head=NULL;
  size=0;
}

void playerLL::insert(player *p){
  player* t=head;
  if(t==NULL) head=p;
  else{
   while(t->get_next()) 
   t=t->get_next();
   t->set_next(p);
    }
  size++;
}

void playerLL::printList(){
  player* currentPtr=head;
  if (size == 0) {  
      cout<< "No score yet."<<endl;
   }
  else { 
       cout<< "The scores are:" <<endl;
    while ( currentPtr != NULL ) { 
          cout<<currentPtr->get_name();
          cout<<setw(6)<<currentPtr->get_score();
          cout<<"\n";
          currentPtr = currentPtr->get_next();   
      }
    }
}

playerLL::~playerLL(){
  player* t;
  t=head;
  while(head){
      t=head->get_next();
      delete head;
      head=t;
  } 
}
