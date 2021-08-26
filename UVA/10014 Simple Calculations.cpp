#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t, n, n2; 
	double a0, aNP1, x, a1;
	cin>> t;
	while(t--){
		cin>> n>> a0>> aNP1;
		a1 = n*a0 + aNP1;
		n2 = n;
		while(n2){
			cin>> x;
			a1 -= x*2.0*n2;
			n2--;
		}
		a1 /= (n+1.0);
		cout<< fixed<< showpoint<< setprecision(2)<< a1<< endl;
		if(t)
			cout<< endl;
	}

	return 0;
}