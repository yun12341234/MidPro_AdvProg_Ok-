#include "node.h"

class LL{
  NodePtr hol;
  int size=0;
public:
  LL();
  int isEmpty();
  void insert(int score);
  void printList();
  ~LL();
};

LL::LL(){
  hol=NULL;
  size=0;
}

LL::~LL(){
  cout<<"deleting all scores"<<endl;
  NodePtr t;
  t=hol;
  int i;
  for(i=0;i<size;i++){
      hol=hol->get_next();
      delete t;
      t=hol;
   }
}

void LL::insert(int score){
  NodePtr t=hol;
  if(t==NULL) hol=new Node(score);
  else{
   while(t->get_next()) t=t->get_next();
   t->set_next(new Node(score));
    }
  size++;
  }  


int LL::isEmpty(  )
{ 
   return hol == NULL;
}

void LL::printList( )
{ 
  NodePtr currentPtr=hol;

  if ( size != 0  ) {   //isEmpty ()
      cout<< "No best score yet."<<endl;
   }
  else { 
       cout<< "The scores are:" <<endl;
    while ( currentPtr != NULL ) { 
          currentPtr->print();
          cout<<"\n";
          currentPtr = currentPtr->get_next();   
      }
    }
  }
