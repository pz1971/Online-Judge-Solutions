#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 10005 ;
int n ;
vector<int> g[mx] ;
int indeg[mx] ;
priority_queue<int, vector<int> , greater<int>> pq ;
vector<int> ans ;

void toposort(){
	for(int i = 1 ; i <= n ; i++)
		if(indeg[i] == 0)
			pq.push(i) ;
	
	while(!pq.empty()){
		int cur = pq.top() ;
		pq.pop() ;
		ans.push_back(cur) ;

		for(auto i : g[cur]){
			if((--indeg[i]) == 0)
				pq.push(i) ;
		}
	}
}

int main(){

	int m ;
	cin >> n >> m ;

	int u, v ;
	while(m--){
		cin >> u >> v ;
		g[u].push_back(v) ;
		indeg[v]++ ;
	}

	toposort() ;

	if(ans.size() == n){
		for(auto i : ans)
			cout << i << " " ;
		cout << endl ;
	}
	else 
		cout << "Sandro fails." << endl ;

	return 0;
}