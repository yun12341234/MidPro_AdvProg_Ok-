#ifndef player_h
#define player_h
#include "enemies.h"

class player{
    private: 
      string name;
      int hp;
      int atk;
      int def;

    public:
      player(int=100, int=20, int=20);
      void print_name();
      void print_hp();
      void set_name(string);
      void print_all();
      void print_atk();
      void print_def();
      void attack();
      void draw_player();
      int get_hp();
      int get_attack();
      int die();
      int damage(int);
      void add_hp(int);
      void add_atk(int);
      void add_def(int);
      ~player();
};

player::~player(){
  //cout<<"Player Destructed"<<endl;
}

player::player(int h, int a, int d){
  hp=h;
  atk=a;
  def=d;
}

void player::set_name(string n){name=n;}

void player::print_name(){
  cout<<name<<endl;
}

void player::print_hp(){
  cout<<hp<<endl;
}

void player::print_atk(){
  cout<<atk<<endl;
}

void player::print_def(){
  cout<<def<<endl;
}

void player::print_all(){
  cout<<"Name: "<<name<<endl;
  cout<<"HP: "<<hp<<endl;
  cout<<"Attack: "<<"1->"<<atk<<endl;
  cout<<"Defense: "<<def<<endl;
}

void player::draw_player(){
  cout<<"==============="<<endl;
  cout<<"|  O        O |"<<endl;
  cout<<"|             |"<<endl;
  cout<<"|             |"<<endl;
  cout<<"|     ===     |"<<endl;
  cout<<"==============="<<endl;
}

int player::get_attack(){
  return atk;
}

int player::get_hp(){
  return hp;
}

int player::damage(int x){
  int d=(def-x);
  if(d>0){
    return 0; 
  }
  else{
    hp+=d;
    return x;
  }
}

int player::die(){
  if (hp<=0){
    return 1;
  }
  else{
    return 0;
  }
}

void player::add_hp(int x){
  hp+=x;
}

void player::add_atk(int x){
  atk+=x;
}

void player::add_def(int x){
  def+=x;
}

#endif

