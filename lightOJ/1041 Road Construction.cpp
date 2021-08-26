#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class edge{
public:
	string c1, c2 ;
	int w ;
};

class cmp{
public:
	bool operator () (const edge &a, const edge &b){
		return (a.w < b.w) ;
	}
};

const int mx = 55 ;
int n ;
map<string,string> root ;

string find(string u){
	if(root[u].empty())
		root[u] = u ;
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

int insert(const edge &e){
	string a = find(e.c1) ;
	string b = find(e.c2) ;
	if(a != b){
		root[a] = b ;
		return e.w ;
	}
	return 0 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	stringstream ss ;
	string line ;

	int t ;
	cin >> t;

	for(int tc = 1 ; tc <= t ; tc++){
		root.clear() ;
		cin >> n ;
		cin.ignore() ;

		vector<edge> ar ;
		
		while(getline(cin, line)){
			if(line.empty())
				break ;
			ar.push_back(edge()) ;
			ss.clear() ;
			ss << line ;
			ss >> ar.back().c1 >> ar.back().c2 >> ar.back().w ;
		}

		int cost = 0 ;
		sort(ar.begin(), ar.end(), cmp()) ;
		for(const auto &i : ar){
			cost += insert(i) ;
		}

		bool f = true ;
		string r = find(root.begin()->first) ;
		for(auto i : root){
			if(find(i.first) != r){
				f = false ;
				break ;
			}
		}

		if(f)
			cout<< "Case "<< tc<< ": " << cost << endl ;
		else
			cout<< "Case "<< tc<< ": " << "Impossible" << endl ;
	}

	return 0;
}