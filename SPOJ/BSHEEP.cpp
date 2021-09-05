#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

class point{
public:
	LL x, y;
	int id ;
	bool operator == (const point &p){
		return (x == p.x) && (y == p.y) ;
	}
} origin ;

inline LL dis_sqr(const point &a, const point &b){
	// distance square
	return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)) ;
}

inline LL cross_product(const point &o, const point &a, const point &b){
	// (+)ve if counter-clockwise
	// ( 0 ) if all three points are co-linear
	// (-)ve if clockwise
	return ((a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)) ;
}

class compare{
public:
	bool operator () (const point &a, const point &b){
		LL c_p = cross_product(origin, a, b) ;
		return c_p == 0 ? dis_sqr(origin, a) > dis_sqr(origin, b) : c_p > 0 ;
	}
} ;

int bottom_left_index(const vector<point> &ar){
	int ret = 0 ;
	for(int i = 1 ; i < ar.size() ; i++){
		if(ar[i].y < ar[ret].y || (ar[i].y == ar[ret].y && ar[i].x < ar[ret].x))
			ret = i ;
	}
	return ret ;
}

vector<point> convex_hull(vector<point> &ar){
	swap(ar[0], ar[ bottom_left_index(ar) ]) ;
	origin = ar[0] ;
	sort(++(ar.begin()), ar.end(), compare()) ;
	
	if(ar.size() < 3)
		return ar ;

	vector<point> H{ar[0], ar[1]} ;
	int top = 1 ;
	for(int i = 2 ; i < ar.size() ; i++){
		if(cross_product(origin, H[top], ar[i]) == 0)
			continue ;
		while(top >= 1 && cross_product(H[top], H[top - 1], ar[i]) >= 0){
			H.pop_back() ;
			top-- ;
		}

		H.emplace_back(ar[i]) ;
		top++ ;
	}

	return H ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cout << fixed << showpoint << setprecision(2) ;

	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n ;
		cin >> n ;
		vector<point> ar(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> ar[i].x >> ar[i].y ;
			ar[i].id = i + 1 ;
		}

		vector<point> c_h = convex_hull(ar) ;

		double cir = 0.0 ;
		for(int i = 1 ; i < c_h.size() ; i++)
			cir += sqrt(dis_sqr(c_h[i-1], c_h[i])) ;
		if(c_h.size() > 1)
			cir += sqrt(dis_sqr(c_h.front(), c_h.back())) ;

		cout << cir << endl ;

		for(int i = 0 ; i < c_h.size() ; i++)
			cout << c_h[i].id << " \n"[i + 1 == c_h.size()] ;
		cout << endl ;
	}

	return 0;
}