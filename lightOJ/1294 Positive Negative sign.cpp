#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	cin>> t;
	LL n, m;
	LL a, b;
	for(int tc=1; tc<=t; tc++){
		cin>> n>> m;
		
		a = (m*(m+1))/2;
		b = ((3*m + 1)*m)/2;

		cout<< "Case "<< tc<< ": "<< (b-a) * (n/(2*m))<< endl;
	}

	return 0;
}