#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

set<string> vs;

void push_it(string str){
	string s = "";
	for(auto ch : str){
		if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )
			s.push_back(tolower(ch));
		else{
			if(!s.empty())
				vs.insert(s);
			s.clear();
		}
	}
	if(!s.empty())
		vs.insert(s);
}

int main(){

	string s;
	while(cin >> s){
		if(!s.empty())
			push_it(s);
	}

	for(auto i : vs)
		cout<< i<< endl;

	return 0;
}