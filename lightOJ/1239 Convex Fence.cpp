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
    : x{a}, y{b} { }
} pivot ;
point operator - (const point &p1, const point &p2){
    return point(p1.x - p2.x, p1.y - p2.y) ;
}
LL cross(const point &p1, const point &p2){
    return p1.x * p2.y - p1.y * p2.x ;
}
bool operator == (const point &p1, const point &p2){
    return (p1.x == p2.x && p1.y == p2.y) ;
}
bool operator < (const point &p1, const point &p2){
    return (p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x)) ;
}
inline LL distance_sq(const point &p1, const point &p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}
inline double distance(const point &p1, const point &p2){
    return sqrt((double)distance_sq(p1, p2)) ;
}

class cmp{
public:
    bool operator () (const point &a, const point &b){
        LL cp = cross(a - pivot, b - pivot) ;
        if(cp == 0) return distance_sq(pivot, a) < distance_sq(pivot, b) ;
        return cp > 0 ;
    }
} ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fixed << showpoint << setprecision(6) ;

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        LL d ;
        cin >> n >> d ;
        vector<point> ar(n) ;
        cin >> ar[0].x >> ar[0].y ;

        if(n == 1){
            cout<< "Case "<< tc<< ": " << pi * (d * d) << endl ;
            continue ;
        }

        pivot = ar[0] ;
        for(int i = 1 ; i < n; i++){
            cin >> ar[i].x >> ar[i].y ;
            if(ar[i] < pivot)
                pivot = ar[i] ;
        }
        sort(ar.begin(), ar.end(), cmp()) ;

        vector<point> CH{ar[0], ar[1]} ;
        int c = 1 ;

        for(int i = 2 ; i < n ; i++){
            while(c > 1 && cross(CH[c] - CH[c-1], ar[i] - CH[c-1]) <= 0){
                CH.pop_back() ;
                c-- ;
            }
            c++ ;
            CH.emplace_back(ar[i]) ;
        }

        double ans = 2.0 * pi * d ;
        
        for(int i = 1 ; i < CH.size() ; i++)
            ans += distance(CH[i], CH[i - 1]) ;
        ans += distance(CH.front(), CH.back()) ;

        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}