#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int s;
	double n, i, p;

	cout<< fixed<< showpoint<< setprecision(4);

	cin>> s;
	while (s--)
	{
		cin>> n>> p>> i;
		cout<< ( p == 0.0 ? 0.0 : p * pow(1-p, i-1) / (1 - pow(1-p, n)) ) << endl;
	}

	return 0;
}