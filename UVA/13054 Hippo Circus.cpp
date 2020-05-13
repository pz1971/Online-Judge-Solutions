#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	for(int tc = 1 ; tc <= test_case ; tc++){
		int n, h, ta, td ;
		cin >> n >> h >> ta >> td ;

		deque<int> height(n) ;
		for(auto &i : height)
			cin >> i ;
		
		if(td >= 2 * ta){
			cout<< "Case "<< tc<< ": " << (ta * n) << endl ;
			continue ;
		}

		sort(height.begin(), height.end()) ;
		int time = 0 ;

		while(!height.empty()){
			if(height.size() >= 2 && height.front() + height.back() < h){
				time += td ;
				height.pop_front() ;
				height.pop_back() ;
			}
			else {
				time += ta ;
				height.pop_back() ;
			}
		}

		cout<< "Case "<< tc<< ": " << time << endl ;
	}

	return 0;
}