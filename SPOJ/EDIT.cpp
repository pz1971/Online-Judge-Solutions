#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int lo_hi_lo(const string &s){
	bool f = 0 ;
	int cnt = 0 ;

	for(auto i : s){
		if(f == 0 && isupper(i))
			cnt++ ;
		else if(f == 1 && islower(i))
			cnt++ ;

		f = !f ;
	}
	return cnt ;
}

int hi_lo_hi(const string &s){
	bool f = 0 ;
	int cnt = 0 ;

	for(auto i : s){
		if(f == 0 && islower(i))
			cnt++ ;
		else if(f == 1 && isupper(i))
			cnt++ ;

		f = !f ;
	}
	return cnt ;
}

int main(){

	string s ;
	while(cin >> s){
		cout << min(lo_hi_lo(s), hi_lo_hi(s)) << endl ;
	}

	return 0;
}