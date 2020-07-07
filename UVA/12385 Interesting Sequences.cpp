#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n, x ;
		cin >> n ;
		map<int, vector<int> > mp ;
		
		for(int i = 1 ; i <= n ; i++){
			cin >> x ;
			mp[x].push_back(i) ;
		}

		vector<pair<int, int> > ar ;
		for(auto i : mp){
			if(i.second.size() < 2)
				continue ;
			
			for(int j = 1 ; j < i.second.size() ; j++)
				ar.emplace_back(make_pair(i.second[j], i.second[j-1])) ;
		}
		sort(ar.begin(), ar.end()) ;

		int cur_end = 0, cnt = 0 ;
		for(auto i : ar){
			if(i.second >= cur_end){
				cnt++ ;
				cur_end = i.first ;
			}
		}

		cout << cnt << endl ;
	}

	return 0;
}