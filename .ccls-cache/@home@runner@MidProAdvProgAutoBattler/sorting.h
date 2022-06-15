#include <iomanip>
#include "enemies.h"
#include "player.h"

inline void display(enemies a[], int n){
  int i;
  for(i=0;i<n;i++){
    cout<<setw(5)<<a[i].get_attack();
  }
  }
inline void swap(enemies &x,enemies &y){
  enemies temp = y;
  y = x;
  x = temp;
  
}
void bubble(enemies a[],int n){
  for(int j=1;j<n-1;j++){
    for(int i=0;i<n-j;i++){
      if(a[i].get_attack()>a[i+1].get_attack()) {
        swap(a[i],a[i+1]);
      }
    }
  }
  }