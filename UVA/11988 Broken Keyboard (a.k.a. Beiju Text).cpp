#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	string str;
	while(getline(cin, str)){
		bool f = false;
		string s = "";
		deque<string> vs;

		for(auto ch : str){
			if(ch == '[' || ch == ']'){
				if(!s.empty())
					f ? vs.push_front(s) : vs.push_back(s);
				
				s.clear();
				f = (ch == '[');
			}
			else{
				s.push_back(ch);
			}
		}
		
		f ? vs.push_front(s) : vs.push_back(s);

		for(auto i: vs){
			cout<< i;
		}
		cout<< endl;
	}

	return 0;
}