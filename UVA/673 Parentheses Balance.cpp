#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

string s;
bool check(){
	stack<char> stk;
	for(char ch : s){
		if(ch == '(' || ch == '[')
			stk.push(ch);
		
		else if(ch == ')'){
			if(!stk.empty() && stk.top() == '('){
				stk.pop();
			}
			else{
				return false;
			}
		}

		else if(ch == ']'){
			if(!stk.empty() && stk.top() == '['){
				stk.pop();
			}
			else{
				return false;
			}
		}
	}

	return stk.empty();
}

int main(){

	int n;
	cin>> n;
	cin.ignore();

	while(n--){
		getline(cin, s);
		cout<< (check() ? "Yes\n" : "No\n") ;
	}

	return 0;
}