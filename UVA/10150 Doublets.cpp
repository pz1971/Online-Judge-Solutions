#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

bool changeInOne(const string &a, const string &b){
	int cnt = 0;
	for(int i=0; i<a.size(); i++){
		if(a[i] != b[i])	cnt++;
		if(cnt > 1)		return false;
	}
	return true;
}

vector<string> dictionary[20];
map<string, vector<string>>	adj;
map<string, string> parent;

void print(string s){
	if(parent[s] != s)
		print(parent[s]);
	cout<< s<< endl;
}

int bfs(string s, string t){
	queue<string> q;
	q.push(s);
	parent[s] = s;
	
	while(!q.empty()){
		string str = q.front();
		q.pop();
		for(auto i: adj[str]){
			if(!parent.count(i)){
				q.push(i);
				parent[i] = str;
				if(i == t){
					print(i);
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){

	string s, t;
	while(getline(cin, s)){
		if(s.size() == 0)	break;
		dictionary[s.size()].push_back(s);
	}

	for(int i=0; i<20; i++){
		if(dictionary[i].size() == 0)	continue;
		for(int j=0; j<dictionary[i].size(); j++){
			for(int k=j+1; k<dictionary[i].size(); k++){
				if(changeInOne(dictionary[i][j], dictionary[i][k])){
					adj[dictionary[i][j]].push_back(dictionary[i][k]);
					adj[dictionary[i][k]].push_back(dictionary[i][j]);
				}
			}
		}
	}

	int f = 0;
	while(cin>> s>> t){
		if(f)	cout<< endl;
		else 	f = 1;

		if(s.size() != t.size()){
			cout<< "No solution."<< endl;
			continue;
		}
		if(s == t){
			cout<< s<< endl;
			continue;
		}
		parent.clear();
		if(bfs(s, t) == 0)
			cout<< "No solution."<< endl;
	}

	return 0;
}