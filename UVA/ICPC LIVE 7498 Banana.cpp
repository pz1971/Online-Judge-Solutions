#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

map<string, string> dictionary;

int main(){

	int n, k;

	cin>> n;
	string x, y;

	while(n--){
		cin>> x>> y>> y;
		dictionary[x] = y;
	}

	cin>> n;
	while(n--){
		cin>> k;
		while (k--)
		{
			cin>> x;
			cout<< dictionary[x];
			k == 0 ? cout<< "\n" : cout<< " ";
		}
	}

	return 0;
}
