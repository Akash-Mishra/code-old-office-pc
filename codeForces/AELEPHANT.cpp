#include <iostream>
using namespace std;
int min(int a, int b, int c, int d, int e){
	if(a<=b && a<=c && a<=d && a<=e)
		return a;
	else if(b<=a && b<=c && b<=d && b<=e)
		return b;
	else if(c<=a && c<=b && c<=d && c<=e)
		return c;
	else if(d<=a && d<=b && d<=c && d<=e)
		return d;
	else 
		return e;
}
int steps(int n){
	if(n<=5) return 1;
	else
		return(1+min(steps(n-1),steps(n-2),steps(n-3),steps(n-4),steps(n-5)));
}
int main(){
	int x;
	cin>>x;
	cout<<steps(x)<<endl;
	return 0;
}