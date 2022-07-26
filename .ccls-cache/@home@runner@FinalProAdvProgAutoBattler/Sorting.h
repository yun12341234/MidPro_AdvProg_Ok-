#include <iomanip>
#include "enemies.h"
#include "player.h"

inline void display(int a[], int n){
  int i;
  for(i=0;i<n;i++){
    cout<<a[i];
  }
  }
inline void swap(int &x,int &y){
  int temp = y;
  y = x;
  x = temp;
  
}
void bubble(int a[],int n){
  for(int j=1;j<n-1;j++){
    for(int i=0;i<n-j;i++){
      if(a[i]>a[i+1]) {
        swap(a[i],a[i+1]);
      }
    }
  }
}