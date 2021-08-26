#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

class point{
public:
    LL x, y, id ;
    point()
    : x{0}, y{0} { }
    point(LL a, LL b)
    : x{a}, y{b} { }
} pivot ;
point operator - (const point &p1, const point &p2){
    return point(p1.x - p2.x, p1.y - p2.y) ;
}
point operator + (const point &p1, const point &p2){
    return point(p1.x + p2.x, p1.y + p2.y) ;
}
LL dot(const point &p1, const point &p2){
    return p1.x * p2.x + p1.y * p2.y ;
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
bool operator > (const point &p1, const point &p2){
    return (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y)) ;
}
ostream &operator << (ostream &os, const point &p) { 
    return os << "(" << p.x << ", " << p.y << ")" ;
}
inline LL manhattan_dis(const point &p1, const point &p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) ;
}
inline LL distance_sq(const point &p1, const point &p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}
inline double distance(const point &p1, const point &p2){
    return sqrt((double)distance_sq(p1, p2)) ;
}

class cmp{
public:
    bool operator () (const point &p1, const point &p2){
        LL cp = cross(p1 - pivot, p2 - pivot) ;
        if(cp == 0)
            return distance_sq(pivot, p1) < distance_sq(pivot, p2) ;
        else 
            return cp > 0 ;
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
        vector<point> ar(n) ;

        cin >> ar[0].x >> ar[0].y ;
        ar[0].id = 0 ;
        pivot = ar[0] ;

        for(int i = 1 ; i < n ; i++){
            cin >> ar[i].x >> ar[i].y ;
            ar[i].id = i ;
            if(ar[i] < pivot)
                pivot = ar[i] ;
        }

        sort(ar.begin(), ar.end(), cmp()) ;

        int p = -1 ;
        for(int i = n - 2 ; i > 0 ; i--){
            if(cross(ar[i] - ar[0], ar[n-1] - ar[0]) != 0){
                p = i ;
                break ;
            }
        }

        cout<< "Case "<< tc<< ":" << endl ;
        if(p == -1){
            cout << "Impossible" << endl ;
        }
        else{
            reverse(ar.begin() + p + 1, ar.end()) ;
            for(int i = 0 ; i < n ; i++){
                cout << ar[i].id << " \n"[i == n-1] ;
            }
        }
    }

    return 0;
}