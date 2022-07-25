#include <iostream>
using namespace std;
#include "enemies.h"
#include "player.h"
#include "sorting.h"
#include "stack.h"
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "playerLL.h"
#include <string.h>

void battle(player *, enemies *, int *);
void reward(player *);
int sorting(int, int);
void gameover(int *);

int main(int argc, char **argv) {
  playerLL p;
  
  while(1){

  int restart;
    
  int gameover = 0;
  srand(time(NULL));
  system("clear");

  player* playerP = new player();
  string Pname;

  //player* player = new player;
  //p.insert(player);

  cout << "Please enter a name: ";

  fflush(stdin);
  
  cin>>Pname;

  playerP->set_name(Pname);

  cout << endl;

  system("clear");

  playerP->print_all();
  playerP->draw_player();

  cout << "Press any key to continue...";
  cin.get();

  system("clear");

  cout << "There will be enemies that you have to battle." << endl;
  cout << "Your HP is your health. If that reaches 0, the game is over."
       << endl;
  cout << "Your attack has a range. As you can see, your attack would be a "
          "random number between 1 and 20."
       << endl;
  cout << "You defense is a way to protect yourself. The defense you have will "
          "subtract the total amount the enemy deals to you. So, if the enemy "
          "hits you less than your defense, you will not take any damage."
       << endl
       << endl;

  int n = 10;
  enemies *e = new enemies[n]{
      {"Dan", 25, 10, 2},        {"Juan", 40, 10, 4},   {"Buay", 50, 7, 2},
      {"Best", 60, 20, 6},       {"Kong", 70, 28, 6},   {"Sadge", 80, 26, 8},
      {"Lena", 100, 34, 10},     {"Pepsi", 120, 40, 5}, {"Bam", 160, 40, 2},
      {"SAITAMA", 1000, 500, 10}};

  cout << "This is the attack damage of enemies you have to encouter" << endl;
  bubble(e, n);
  display(e, n);
  cout << endl;
  cout << endl;
  int i;
  for (i = 0; i < n && !gameover; i++) {
    cout << "The enemy that you will face is: " << endl;
    cout << endl;
    e[i].print_all();

    cout << endl;

    cout << "Your stats are: " << endl;
    playerP->print_all();

    cout << endl;

    cout << "Press any key to fight the enemy...";
    cin.get();

    system("clear");

    battle(playerP, e + i, &gameover);
  }
      if (gameover) {
      cout<<endl;
      p.insert(playerP);
      p.printList();
      cout<<endl;
      cout<<"Do you wish to play again?"<<endl;
      cout<<"0 to exit"<<endl;
      cout<<"1 to continue"<<endl;
      cout<<endl;
      cout<<"Enter number: "
      cin>>restart;
      if(!restart){
        return 0;
    }
  }
}
  system("clear");
  cout << "You won the game. Congradulations!" << endl;
  
  return 0;
  }

  


void battle(player *p, enemies *e, int *n) {
  int atkP;
  int atkE;
  int x;
  int y;
  srand(time(NULL));

  while (!p->die() && !e->die()) {
    x = p->get_attack();
    y = e->get_attack();

    atkP = rand() % x + 1;
    atkE = rand() % y + 1;

    cout << "You hit the enemy for: ";
    cout << atkP << endl;

    cout << "The enemy hits you for: ";
    cout << atkE << endl;

    p->damage(atkE);
    e->damage(atkP);

    cout << endl;

    cout << "Your remaining health is: ";
    p->print_hp();

    cout << "The enemie's remaining health is: ";
    e->print_hp();
    cout << endl;

    p->die();
    e->die();

    cout << "Press any key to continue...";
    cin.get();
    cout << endl;

    if (p->die() == 1) {
      gameover(n);

      break;
    } else if (e->die() == 1) {
      reward(p);
    }
  }
}

void reward(player *p) {
  int a = rand() % 20 + 1;
  int d = rand() % 15 + 1;
  int h = rand() % 30 + 1;

  cout << "Choose your upgrade: " << endl;
  cout << "1. +" << a << " Attack" << endl;
  cout << "2. +" << d << " Defense" << endl;
  cout << "3. +" << h << " HP (Heal)" << endl << endl;

  int i = 0;
  while (i != 1 && i != 2 && i != 3) {
    cout << "Your choice is: ";
    cin >> i;
  }

  if (i == 1) {
    p->add_atk(a);
    cout << "Your attack is now: ";
    p->print_atk();
  } else if (i == 2) {
    p->add_def(d);
    cout << "Your defense is now: ";
    p->print_def();
  } else if (i == 3) {
    p->add_hp(h);
    cout << "Your HP is now: ";
    p->print_hp();
  }

  p->add_score(1);

  cout << endl;
  cout << "Press any key to continue..." << endl;
  cin.get();
}

void gameover(int *gameover) {
  cout << "You have no more health, Your dead." << endl;
  cout << "Press any key to accept your fate..." << endl;
  cin.get();
  system("clear");
  cout << "Game over" << endl;


  *gameover = 1;
}