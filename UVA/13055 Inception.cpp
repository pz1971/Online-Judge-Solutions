#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int n ;
	cin >> n ;

	stack<string> cur_stack ;
	string query_type, name ;
	
	while(n--){
		cin >> query_type ;
		if(query_type == "Sleep"){
			cin >> name ;
			cur_stack.push(name) ;
		}
		else if(query_type == "Kick"){
			if(!cur_stack.empty())
				cur_stack.pop() ;
		}
		else{
			if(cur_stack.empty())
				cout << "Not in a dream" << endl ;
			else 
				cout << cur_stack.top() << endl ;
		}
	}

	return 0;
}