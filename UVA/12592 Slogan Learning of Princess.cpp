#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int n;
	map<string, string> mp;
	string l1, l2;

	cin>> n;
	cin.ignore();	

	while(n--){
		getline(cin, l1);
		getline(cin, l2);
		mp[l1] = l2;
	}

	cin>> n;
	cin.ignore();

	while(n--){
		getline(cin, l1);
		cout<< mp[l1]<< endl;
	}

	return 0;
}