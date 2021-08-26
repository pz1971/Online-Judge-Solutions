#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const double pi = acos(-1.0) ;

class point{
public:
	LL x, y ;
	point()
	: x{0}, y{0} { }
	point(LL a, LL b)
	: x(a), y(b) {  }
	bool operator == (const point &p){
		return (x == p.x && y == p.y) ;
	}
	bool operator < (const point &p){
		return (x < p.x || (x == p.x && y < p.y)) ;
	}
} ;
ostream &operator << (ostream &os, const point &p) { 
	return os << "(" << p.x << ", " << p.y << ")" ;
}
inline LL distance_sq(const point &p1, const point &p2){
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}
inline double distance(const point &p1, const point &p2){
	return sqrt((double)distance_sq(p1, p2)) ;
}

inline LL cross_product(const point &O, const point &A, const point &B){
	// (+)ve if counter-clockwise, 0 if colinear, (-)ve if clockwise
	return (A.x - O.x)*(B.y - O.y) - (B.x - O.x)*(A.y - O.y) ;
}

const int mx = 1e5 + 7 ;
int n, k ;
point ar[mx], hull[mx + mx] ;

void convex_hull(){
	sort(ar, ar + n) ;
	k = 0 ;

	for(int i = 0 ; i < n ; i++){
		while(k >= 2 && cross_product(hull[k-2], hull[k-1], ar[i]) <= 0)
			k-- ;
		hull[k++] = ar[i] ;
	}
	for(int i = n - 1, t = k + 1 ; i >= 0 ; i--){
		while(k >= t && cross_product(hull[k-2], hull[k-1], ar[i]) <= 0)
			k-- ;
		hull[k++] = ar[i] ;
	}

	k-- ;
}

inline double get_angle(const point &O, const point &A, const point &B){
	double o = distance(A, B) ;
	double a = distance(O, B) ;
	double b = distance(O, A) ;
	return acos((a*a + b*b - o*o)/(2.0 * a * b)) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed << showpoint << setprecision(6) ;
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		cin >> n ;
		for(int i = 0 ; i < n ; i++)
			cin >> ar[i].x >> ar[i].y ;
		
		convex_hull() ;

		if(k >= 3){
			double ans = pi ;
			for(int i = 0 ; i < k ; i++)
				ans = min(ans, get_angle(hull[i], hull[(i-1+k)%k], hull[(i+1)%k])) ;
			
			cout<< "Case "<< tc<< ": " << ans * 180.0 / pi << endl ;
		}
		else 
			cout<< "Case "<< tc<< ": " << 0 << endl ;
	}

	return 0;
}