#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

map<string, int> ar;

void generate(){
	queue<string> q;
	string s, t;
	int val = 0;
	q.push("");

	while(!q.empty()){
		s = q.front();	q.pop();
		for(char ch = ( s.empty() ? ch = 'a' : (s.back() + 1) ) ; ch <= 'z' ; ch++){
			t = s;
			t.push_back(ch);
			ar[t] = ++val;
			if(t.size() < 5)
				q.push(t);
		}
	}
}

int main(){

	generate();
	string s;
	while(cin>> s)	cout<< ar[s] << endl;

	return 0;
}