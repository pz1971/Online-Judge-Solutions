#include <bits/stdc++.h>
using   namespace  std ;
using ULL  = unsigned long long ;

ULL fact[11] ;

int n ;
string s ;
ULL ans ;

ULL seg[21][21] ;
vector<ULL> ar{0ULL} ;

ULL calculate(){
	ULL ret = fact[9] / fact[9 - n] ; // 9Pn

	map<ULL, int> cnt ;
	for(auto i : ar)	cnt[i]++ ;
	for(auto i : cnt)	ret /= fact[i.second] ;

	return ret ;
}

void func(int id, int l){
	if(id == n && l == s.size()){
		ans += calculate() ;
		return ;
	}
	if(l >= s.size() || id == n || s[l] == '0')
		return ;

	if(id == n-1){
		if(seg[l][s.size()-1] >= ar.back()){
			ar.push_back(seg[l][s.size()-1]) ;
			func(id + 1, s.size()) ;
			ar.pop_back() ;
		}
		return ;
	}

	for(int r = l ; r < s.size() ; r++){
		if(seg[l][r] >= ar.back()){
			ar.push_back(seg[l][r]) ;
			func(id + 1, r + 1) ;
			ar.pop_back() ;
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fact[0] = 1 ;
	for(int i = 1 ; i < 11 ; i++)
		fact[i] = fact[i-1] * i ;

	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		cin >> s ;
		n = s[0] - '0' ;
		s = s.substr(1) ;
		
		for(int i = 0 ; i < s.size() ; i++){
			for(int j = i ; j < s.size() ; j++){
				seg[i][j] = 0ULL ;
				for(int k = i ; k <= j ; k++)
					seg[i][j] = (seg[i][j] * 10ULL) + (s[k] - '0') ;
			}
		}
		
		ans = 0ULL ;
		func(0, 0) ;
		cout << ans << endl ;
	}

	return 0;
}