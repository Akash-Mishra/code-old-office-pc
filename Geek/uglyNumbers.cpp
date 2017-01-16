#include <iostream>
using namespace std;

// This function divides a by greatest divisible power of b
int maxDivide(int a, int b){
	while(a%b==0)
		a = a/b;
	return a;
}

// function to check a number is ugly or not
int isUgly(int no){
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);

	return(no == 1) ? 1 : 0;
}


// function to get the nth ugly number
int getNthUglyNo(int n){
	int i = 1;
	int count = 1; // ugly number count

	//check for all integers until ugly count becomes n
	while(n > count){
		i++;
		if(isUgly(i))
			count++;

	}
	return i;
}

// driver function to test the above function
int main(){
	unsigned no = getNthUglyNo(150);
	cout<<no<<endl;
	return 0;
}