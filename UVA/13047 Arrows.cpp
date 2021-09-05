#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int get_arrow_len(const string &s){
	if(s.empty())
		return -1 ;
	
	int mx = 0 ;
	bool f = 0 ;

	string arrow = "" ;

	for(auto i : s){
		if(i == '<'){
			mx = max(mx, (int) arrow.size()) ;
			arrow.clear() ;
			arrow.push_back(i) ;
			f = 1 ;
		}
		else if(i == '>'){
			mx = max(mx, (int) arrow.size()) ;
			arrow.clear() ;
			f = 0 ;
		}
		else if(f){
			if(arrow.back() == '<' || i == arrow.back())
				arrow.push_back(i) ;
			else {
				mx = max(mx, (int) arrow.size()) ;
				arrow.clear() ;
				f = 0 ;
			}
		}
	}

	if(f == 1){
		mx = max(mx, (int) arrow.size()) ;
	}
	f = 0 ;
	arrow.clear() ;

	for(auto i = s.rbegin(); i != s.rend() ; i++){
		if(*i == '>'){
			mx = max(mx, (int) arrow.size()) ;
			arrow.clear() ;
			arrow.push_back(*i) ;
			f = 1 ;
		}
		else if(*i == '<'){
			mx = max(mx, (int) arrow.size()) ;
			arrow.clear() ;
			f = 0 ;
		}
		else if(f){
			if(arrow.back() == '>' || *i == arrow.back())
				arrow.push_back(*i) ;
			else {
				mx = max(mx, (int) arrow.size()) ;
				arrow.clear() ;
				f = 0 ;
			}
		}
	}

	if(f)
		mx = max(mx, (int) arrow.size()) ;

	return (mx == 0 ? -1 : mx) ;
}

int main(){

	int test_case ;
	cin >> test_case ;
	
	for(int tc = 1 ; tc <= test_case ; tc++){
		string s ;
		cin >> s ;
		cout<< "Case "<< tc<< ": " << get_arrow_len(s) << endl ;
	}

	return 0;
}