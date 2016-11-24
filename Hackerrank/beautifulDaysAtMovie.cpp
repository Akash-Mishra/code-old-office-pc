#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long int rev(unsigned long long int x){
	unsigned long long int y=0,temp = x, temp1 = 0, counter=0;
	while(temp!=0){
		temp1 = temp%10;
		temp = temp/10;
		y = y*pow(10,counter) + temp1;
        // if(y>0)
		counter++;
	}
    cout<<y<<endl;
	return y;
}

unsigned long long int mod(long long int x){
	return (x<0)?(-1*x):x;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long int i, j, k;
    unsigned long long int result=0;
    cin>>i>>j>>k;
    for(unsigned long long int p = i; p<=j; p++){
    	// revP = rev(p);
    	if(mod(p-rev(p))%k == 0)
    		result++;
    }
    cout<<result<<endl;
    return 0;
}
