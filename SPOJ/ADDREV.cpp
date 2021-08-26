#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

string n1, n2 ;

string find_ans(){
	string ans = "" ;

	if(n2.size() > n1.size())
		swap(n1, n2) ;
	
	int rem = 0 ;
	for(int i = 0 ; i < n1.size() ; i++){
		if(i < n2.size())
			rem = rem + (n1[i] - '0') + (n2[i] - '0') ;
		else 
			rem = rem + (n1[i] - '0') ;
		ans.push_back(rem % 10 + '0') ;
		rem /= 10 ;
	}

	while (rem)
	{
		ans.push_back(rem % 10 + '0') ;
		rem /= 10 ;
	}

	for(int i = 0 ; i < ans.size() ; i++) {
		if(ans[i] != '0')
			return ans.substr(i, ans.size() - i) ;
	}

	return "0" ;
}

int main(){

	int t ;
	cin>> t ;

	while(t--){
		cin>> n1 >> n2 ;
		cout<< find_ans() << endl;
	}

	return 0;
}