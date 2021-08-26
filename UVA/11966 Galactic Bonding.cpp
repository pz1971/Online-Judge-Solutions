#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n ;
double d ;
int par[1005] ;

void init(){
	for(int i = 1 ; i <= n ; i++)
		par[i] = i ;
}

int find(int u){
	return (par[u] == u) ? u : (par[u] = find(par[u])) ;
}

void insert(int u, int v){
	int a = find(u) ;
	int b = find(v) ;

	if(a != b){
		par[b] = a ;
	}
}

double dis(const pair<double,double> &a, const pair<double, double> &b){
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second)) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n >> d ;
		init() ;
		
		pair<double,double> ar[n+1] ;
		for(int i = 1 ; i <= n ; i++)
			cin >> ar[i].first >> ar[i].second ;
		
		for(int i = 1 ; i < n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				if(dis(ar[i], ar[j]) <= d)
					insert(i, j) ;
			}
		}

		set<int> st ;
		for(int i = 1 ; i <= n ; i++)
			st.insert(find(i)) ;
		cout<< "Case "<< tc<< ": " << st.size() << endl;
	}

	return 0;
}