#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int n, t, m ;
	cin >> n >> t >> m ;

	vector<pair<int, int>> ar(n, {-1,-1}) ;
	bool solved[t+1][n] ;
	memset(solved, 0, sizeof solved) ;

	int time, teamID ;
	string problem, verdict ;
	
	while(m--){
		cin >> time >> teamID >> problem >> verdict ;
		
		if(verdict == "No")
			continue ;
		
		int i = problem[0] - 'A' ;
		if(ar[i].second != teamID && solved[teamID][i] == false){
			ar[i].first = time ;
			ar[i].second = teamID ;
			solved[teamID][i] = true ;
		}
	}

	for(int i = 0 ; i < n ; i++){
		cout << (char)(i + 'A') << " " ;
		if(ar[i].first == -1 || ar[i].second == -1)
			cout << "- -" << endl ;
		else 
			cout << ar[i].first << " " << ar[i].second << endl ;
	}

	return 0;
}