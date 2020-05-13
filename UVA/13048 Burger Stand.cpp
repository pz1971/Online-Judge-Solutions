#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int func(const string &str){
	int cnt = 0 ;
	for(int i = 0 ; i < str.size() ; i++){
		if(str[i] != '-')
			continue ;
		if(i + 1 < str.size() && str[i + 1] == 'B')
			continue ;
		if(i + 2 < str.size() && str[i + 2] == 'B')
			continue ;
		if(i + 1 < str.size() && str[i + 1] == 'S')
			continue ;
		if(i > 0 && str[i - 1] == 'S')
			continue ;
		cnt++ ;
	}

	return cnt ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	for(int tc = 1 ; tc <= test_case ; tc++){
		string road ;
		cin >> road ;
		cout<< "Case "<< tc<< ": " << func(road) << endl ;
	}

	return 0;
}