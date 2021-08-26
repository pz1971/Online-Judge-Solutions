#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

VI get_n_integers(int n){
	VI ar;

	int x;
	cin>> x;
	
	if(x == 0)
		return ar;

	ar.push_back(x);
	while(--n){
		cin>> x;
		ar.push_back(x);
	}

	return ar;
}

int main(){

	int n;
	while(cin>> n && n){
		while(1){
			VI ar = get_n_integers(n);
			if(ar.empty()){
				break;
			}
			bool y = true;

			stack<int> stk;
		
			int pushed = 0;
			for(auto i: ar){
				while(pushed < i)
					stk.push(++pushed);
				
				if(i == stk.top()){
					stk.pop();
				}
				else{
					y = false;
					break;
				}
			}

			cout<< (y ? "Yes\n" : "No\n");
		}
		cout<< endl;
	}

	return 0;
}