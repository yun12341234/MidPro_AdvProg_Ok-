#ifndef enemies_h
#define enemies_h

class enemies{
private:
      string name;
      int hp;
      int atk;
      int def;
      enemies* next_enemy;
public:
      void set_name(string);
      void set_hp(int);
      void set_atk(int);
      void set_def(int);
      void print_name();
      void print_hp();
      void print_atk();
      void print_def();
      void print_all();
      int get_hp();
      int get_attack();
      int get_def();
      string get_name();
      void draw_enemies();
      int die();
      int damage(int);
      void set_next(enemies*);
      enemies* get_next();

      enemies(string="Dan",int=100,int=20,int=10);
      ~enemies();
};

enemies::enemies(string n,int h,int a,int d){
  name=n;
  hp=h;
  atk=a;
  def=d;
}

void enemies::set_name(string x){name=x;}

void enemies::set_hp(int x){hp=x;}

void enemies::set_atk(int x){atk=x;}

void enemies::set_def(int x){def=x;}

void enemies::print_name(){
  cout<<name<<endl;
}

void enemies::print_hp(){
  cout<<hp<<endl;
}

void enemies::print_atk(){
  cout<<atk<<endl;
}

void enemies::print_def(){
  cout<<def<<endl;
}

void enemies::print_all(){
  cout<<"Name: "<<name<<endl;
  cout<<"HP: "<<hp<<endl;
  cout<<"Attack: "<<"1->"<<atk<<endl;
  cout<<"Defense: "<<def<<endl;
}

int enemies::get_hp(){
  return hp;
}

int enemies::get_attack(){
  return atk;
}

int enemies::get_def(){
  return def;
}

string enemies::get_name(){
  return name;
}


int enemies::damage(int x){
  int d=(def-x);
  if(d>0){
    return 0; 
  }
  else{
    hp+=d;
    return x;
  }
}

enemies::~enemies(){
  //cout<<name<<" Destroyed"<<endl;
}
int enemies::die(){
  if (hp<=0){
    return 1;
  }
  else{
    return 0;
  }
}

void enemies::set_next(enemies *e){
  next_enemy=e;
}

enemies* enemies::get_next(){
  return next_enemy;
}

#endif