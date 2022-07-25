// self-referential structure    
#include <iomanip>
class Node
{ 
private:
    int score;
    Node *nextPtr;
public:
  Node(int);
  Node* get_next();
  void set_next(Node* t);
  void print();
  int get_score(){return score;}
  ~Node();
  

};
            
typedef Node *NodePtr; // synonym for ListNode*

Node::Node(int y){
  score=y;
  nextPtr=NULL;
  
}

Node::~Node(){
		cout<<score<<" deleted"<<endl;
    
}
  Node* Node::get_next(){
    return nextPtr;
  }
 
  
  void Node::set_next(Node* t){
    nextPtr=t; 
  }
  
  void Node::print(){ 
    cout<<"============================"<<endl;
    cout<<setw(3)<<score; 
  }

