#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

class point{
public:
    LL x, y ;
    point()
    : x{0}, y{0} { }
    point(LL a, LL b)
    : x{a}, y{b} { }
} ;
point operator - (const point &p1, const point &p2){
    return point(p1.x - p2.x, p1.y - p2.y) ;
}
LL cross(const point &p1, const point &p2){
    return p1.x * p2.y - p1.y * p2.x ;
}
bool operator < (const point &p1, const point &p2){
    return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y)) ;
}
ostream &operator << (ostream &os, const point &p) { 
    return os << p.x << " " << p.y ;
}
inline LL distance_sq(const point &p1, const point &p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}

point origin ;
class cmp{
public:
    bool operator () (const point &a, const point &b){
        LL c_p = cross(a - origin, b - origin) ;
		return c_p == 0 ? distance_sq(origin, a) > distance_sq(origin, b) : c_p > 0 ;
    }
} ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        cin >> n ;
        vector<point> ar ;
        point p ;
        string s ;
        for(int i = 0 ; i < n ; i++){
            cin >> p.x >> p.y >> s ;
            if(s == "Y")
                ar.emplace_back(p) ;
        }

        int pos = 0 ;
        for(int i = 1 ; i < ar.size() ; i++){
            if(ar[i] < ar[pos])
                pos = i ;
        }
        swap(ar[0], ar[pos]) ;
        origin = ar[0] ;
        
        sort(++ar.begin(), ar.end(), cmp()) ;
        cout << ar.size() << endl ;
        for(auto &i : ar)
            cout << i << endl ;
    }

    return 0;
}