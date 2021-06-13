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
point operator + (const point &p1, const point &p2){
    return point(p1.x + p2.x, p1.y + p2.y) ;
}
int dot(const point &p1, const point &p2){
    return p1.x * p2.x + p1.y * p2.y ;
}
int cross(const point &p1, const point &p2){
    return p1.x * p2.y - p1.y * p2.x ;
}
bool operator == (const point &p1, const point &p2){
    return (p1.x == p2.x && p1.y == p2.y) ;
}
bool operator < (const point &p1, const point &p2){
    return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y)) ;
}
bool operator > (const point &p1, const point &p2){
    return (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y)) ;
}
ostream &operator << (ostream &os, const point &p) { 
    return os << "(" << p.x << ", " << p.y << ")" ;
}
inline int manhattan_dis(const point &p1, const point &p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) ;
}
inline int distance_sq(const point &p1, const point &p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}
inline double distance(const point &p1, const point &p2){
    return sqrt((double)distance_sq(p1, p2)) ;
}

point origin ;
class compare{
public:
	bool operator () (const point &a, const point &b){
		int c_p = cross(a - origin, b - origin) ;
		return c_p == 0 ? distance_sq(origin, a) > distance_sq(origin, b) : c_p > 0 ;
	}
} ;

int bottom_left_index(const vector<point> &ar){
	int ret = 0 ;
	for(int i = 1 ; i < ar.size() ; i++)
		if(ar[i] < ar[ret])
			ret = i ;
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

inline int twice_triangle_area(const point &a, const point &b, const point &c){
    return abs(cross(a, b) + cross(b, c) + cross(c, a)) ;
}

bool point_inside_convex_hull(const vector<point> &ch, const point &p){
    if(cross(ch.back() - ch[0], p - ch[0]) > 0 or cross(p - ch[0], ch[1] - ch[0]) > 0)
        return false ;

    int lo = 1, hi = ch.size() - 2, mid, indx = 1 ;
    while(lo <= hi){
        mid = (lo + hi) >> 1 ;
        if(cross(ch[mid] - ch[0], p - ch[0]) >= 0){
            indx = mid ;
            lo = mid + 1 ;
        }
        else
            hi = mid - 1 ;
    }

    return twice_triangle_area(ch[0], ch[indx], p)
         + twice_triangle_area(ch[0], p, ch[indx+1])
         + twice_triangle_area(p, ch[indx], ch[indx+1]) 
        == twice_triangle_area(ch[0], ch[indx], ch[indx+1]);
}

double get_area(const vector<point> &poly){
    int ret = 0 ;
    for(int i = 1 ; i < poly.size() ; i++)
        ret += cross(poly[i], poly[i-1]) ;
    ret += cross(poly.front(), poly.back()) ;
    return abs(ret) * 0.5 ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<point> > kingdoms ;

    int n ;
    while(cin >> n){
        if(n == -1)
            break ;
        kingdoms.emplace_back(vector<point> ()) ;
        kingdoms.back().resize(n) ;
        for(point &i : kingdoms.back())
            cin >> i.x >> i.y ;
        kingdoms.back() = convex_hull(kingdoms.back()) ;
    }

    vector<bool> status(kingdoms.size(), false) ;

    double ans = 0.0 ;
    point missile ;

    while(cin >> missile.x >> missile.y){
        for(int i = 0 ; i < kingdoms.size() ; i++){
            if(!status[i] and point_inside_convex_hull(kingdoms[i], missile)){
                status[i] = true ;
                ans += get_area(kingdoms[i]) ;
                break ;
            }
        }
    }

    cout << fixed << showpoint << setprecision(2) << ans << endl ;

    return 0;
}