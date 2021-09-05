#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 205;

class point{
public:
	double x, y ;
} ar[mx];

double dis(const point &a, const point &b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) ;
}

class edge{
public: 
	int u, v ;
	double w ;
	edge(){
	}
	edge(int u, int v, double w){
		this -> u = u ;
		this -> v = v ;
		this -> w = w ;
	}
};

class cmp{
public:
	bool operator () (const edge &a, const edge &b){
		return a.w < b.w ;
	}
} ;

int n ;
int root[mx] ;

void init(){
	for(int i = 0 ; i < n; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

double insert(const edge &e){
	int a = find(e.u) ;
	int b = find(e.v) ;
	if(a != b){
		root[a] = b ;
		return e.w ;
	}
	return 0.0 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << fixed << showpoint << setprecision(3) ;
	
	int sce = 0 ;
	while(cin >> n && n){
		init() ;
		for(int i = 0 ; i < n; i++){
			cin >> ar[i].x >> ar[i].y ;
		}

		vector<edge> edges ;
		for(int i = 0 ; i < n; i++){
			for(int j = i + 1 ; j < n ; j++){
				edges.push_back(edge(i, j, dis(ar[i], ar[j]))) ;
			}
		}
		sort(edges.begin(), edges.end(), cmp()) ;

		double ans = 0.0 ;
		for(const auto &i : edges){
			ans = max(ans, insert(i)) ;
			if(find(0) == find(1))
				break ;
		}

		cout << "Scenario #" << ++sce << endl ;
		cout << "Frog Distance = " << ans << endl << endl ;
	}

	return 0;
}