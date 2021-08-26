#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

inline int id_of_person(const string &s){
	if(s == "Ja")
		return 0 ;
	if(s == "Sam")
		return 1 ;
	if(s == "Sha")
		return 2 ;
	if(s == "Sid")
		return 3 ;
	return 4 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int m, n ;
		string current_person ;
		cin >> m >> n >> current_person ;

		deque<int> _list[5] ;
		for(int i = 0 ; i < 5 ; i++){
			int cnt ;
			string name ;
			cin >> cnt ;

			while(cnt--){
				cin >> name ;
				_list[i].push_back(id_of_person(name)) ;
			}
		}

		vector<int> ar(5, 0) ;
		int cur = id_of_person(current_person) ;
		int cur_time = 0 ;

		while(cur_time < n){
			int x = min(n - cur_time, m) ;
			ar[cur] += x ;
			cur_time += x + 2 ;

			_list[cur].push_back( _list[cur].front() ) ;
			_list[cur].pop_front() ;
			cur = _list[cur].back() ;
		}

		cout<< "Case "<< tc<< ":" << endl ;
		cout << "Ja " << ar[0] << endl;
		cout << "Sam " << ar[1] << endl;
		cout << "Sha " << ar[2] << endl;
		cout << "Sid " << ar[3] << endl;
		cout << "Tan " << ar[4] << endl;
	}

	return 0;
}