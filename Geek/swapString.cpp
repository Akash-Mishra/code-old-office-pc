// cpp program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// function to swap values at two pointers
void swap(char *x, char *y){
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
  return;
}

// function to print permutations of string .The function takes 3 parameters
// 1. String   2. Starting index of the string    3. Ending index of the String

void permute(char *a, int l, int r){
  int i;
  if(l == r)
      cout<<a<<endl;
  else {
    for(i = l; i <= r; i++){
      swap((a+l), (a+i));
      permute(a, l+1, r);
      swap((a+l), (a+i)); // backtrack
    }
  }
}
// driver function
int main(){
  char str[] = "ABC";
  int n = strlen(str);
  permute(str, 0, n-1);
  return 0;
}
