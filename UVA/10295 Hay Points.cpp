#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int m, n;
	LL sum = 0;
	string s;
	int val;
	map<string, int> dictionary;

	cin>> m>> n;	

	while(m--){
		cin>> s>> val;
		dictionary[s] = val;
	}

	while(n--){
		sum = 0;
		while(cin>> s){
			if(s == "."){
				cout<< sum<< endl;
				break;
			}
			sum += dictionary[s];
		}
	}

	return 0;
}