#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

class point{
public:
    int x, y ;
    point()
    : x{0}, y{0} { }
    point(int a, int b)
    : x{a}, y{b} { }
} ;
point operator - (const point &p1, const point &p2){
    return point(p1.x - p2.x, p1.y - p2.y) ;
}
int cross(const point &p1, const point &p2){
    return p1.x * p2.y - p1.y * p2.x ;
}
bool operator < (const point &p1, const point &p2){
    return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y)) ;
}
inline int distance_sq(const point &p1, const point &p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}

point origin ;
class compare{
public:
	bool operator () (const point &a, const point &b){
		int c_p = cross(a - origin, b - origin) ;
		return c_p == 0 ? distance_sq(origin, a) > distance_sq(origin, b) : c_p > 0 ;
	}
} ;

int left_bottom_index(const vector<point> &ar){
	int ret = 0 ;
	for(int i = 1 ; i < ar.size() ; i++)
		if(ar[i] < ar[ret])
			ret = i ;
	return ret ;
}

vector<point> convex_hull(vector<point> &ar){
	swap(ar[0], ar[ left_bottom_index(ar) ]) ;
	origin = ar[0] ;
	sort(++(ar.begin()), ar.end(), compare()) ;
	
	if(ar.size() < 3)
		return ar ;

	vector<point> H{ar[0], ar[1]} ;
	int top = 1 ;
	for(int i = 2 ; i < ar.size() ; i++){
		if(cross(H[top] - origin, ar[i] - origin) == 0)
			continue ;
		while(top >= 1 && cross(ar[i] - H[top], H[top - 1] - H[top]) <= 0){
			H.pop_back() ;
			top-- ;
		}

		H.emplace_back(ar[i]) ;
		top++ ;
	}

	return H ;
}

double area(vector<point> &ar){
    int ret = 0 ;
    for(int i = 0 ; i < ar.size() ; i++)
        ret += cross(ar[i], ar[(i + 1) % ar.size()]) ;
    return abs(ret) * 0.5 ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << showpoint << setprecision(2) ;

    int n, tc = 0 ;
    while(cin >> n){
        if(!n)  break ;
        
        vector<point> ar(n) ;
        for(auto &i : ar)
            cin >> i.x >> i.y ;
            
        double tile_area = area(ar) ;
        ar = convex_hull(ar) ;
        double container_area = area(ar) ;
        double wasted = container_area - tile_area ;
        double ans = wasted / container_area * 100.0 ;

        cout << "Tile #" << ++tc << endl ;
        cout << "Wasted Space = " << ans << " %" << endl << endl ;
    }

    return 0;
}