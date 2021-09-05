#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	cin>> t;
	cin.ignore();

	while(t--){
		string s;
		stringstream idxs, elems;
		getline(cin, s);
		getline(cin, s);
		idxs << s;
		getline(cin, s);
		elems << s;

		int n;

		vector<pair<int, string>> ar;

		while(idxs>> n){
			elems >> s;
			ar.push_back(make_pair(n, s));
		}

		sort(ar.begin(), ar.end());

		for(auto i : ar){
			cout<< i.second<< endl;
		}
		if ( t )	cout << endl;
	}

	return 0;
}