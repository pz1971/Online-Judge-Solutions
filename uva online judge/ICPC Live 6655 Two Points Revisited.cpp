#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t, x1, x2, x3, x4, y1, y2, y3, y4;
	cin>> t;
	
	for(int tc = 1; tc <= t; tc++){
		cin>> x1>> y1>> x2>> y2;
		y4 = x1;	y3 = x2;
		x4 = y2;	x3 = y1;
		cout<< "Case "<< tc<< ": "<< x3<< " "<< y3<< " "<< x4<< " "<< y4<< endl;
	}

	return 0;
}