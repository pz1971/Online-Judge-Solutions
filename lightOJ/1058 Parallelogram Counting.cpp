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
class line_segment{
public:
    point A, D, LX ;
    int t ;
    line_segment()
    : A(), D(), t{0} { }
    line_segment(point a, point b){
        if(a > b)
            swap(a, b) ;
        A = a ;
        D.x = b.x - a.x ;
        D.y = b.y - a.y ;
        int g = __gcd(abs(D.x), abs(D.y)) ;
        D.x /= g ; D.y /= g ;
        if(D.x == 0)
            t = (b.y - a.y) / D.y ;
        else
            t = (b.x - a.x) / D.x ;
        
        LX = A ;
        if(D.x != 0){
            int d = A.x / D.x ;
            LX.x -= d * D.x ;
            LX.y -= d * D.y ;
            while(LX.x < 0){
                LX.x += D.x ;
                LX.y += D.y ;
            }
        }
        else{
            LX.y = 0 ;
        }
    }
} ;
ostream &operator << (ostream &os, const line_segment &obj) {
    return os << "{" << " " << obj.A << ", " << obj.D << ", " << obj.t << ", " << obj.LX << "}" ;
}

class cmp_line_segments{
public :
    bool operator () (const line_segment &ls1, const line_segment &ls2){
        return (ls1.t < ls2.t) || (ls1.t == ls2.t && ls1.D < ls2.D) 
            || (ls1.t == ls2.t && ls1.D == ls2.D && ls1.LX < ls2.LX) ;
    }
} ;

LL calculate(vector<line_segment> &ar, int l, int r){
    if(r - l + 1 == 1)
        return 0 ;
    vector<int> cnt{1} ;
    for(int i = l + 1 ; i <= r ; i++){
        if(ar[i-1].LX == ar[i].LX)
            cnt.back()++ ;
        else 
            cnt.push_back(1) ;
    }
    
    LL cur = 0LL, ret = 0LL ;
    for(auto i : cnt){
        ret += i * cur ;
        cur += i ;
    }
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        cin >> n ;

        vector<point> points(n) ;
        for(auto &p : points){
            cin >> p.x >> p.y ;
        }

        vector<line_segment> ar ;
        for(int i = 0 ; i + 1 < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                ar.push_back(line_segment(points[i], points[j])) ;
            }
        }
        sort(ar.begin(), ar.end(), cmp_line_segments()) ;

        int l = 0 ;
        LL ans = 0 ;
        for(int i = 1 ; i < ar.size() ; i++){
            if(ar[i-1].t == ar[i].t && ar[i-1].D == ar[i].D)
                continue ;
            ans += calculate(ar, l, i - 1) ;
            l = i ;
        }
        ans += calculate(ar, l, ar.size()-1) ;

        cout<< "Case "<< tc<< ": " << (ans >> 1) << endl ;
    }

    return 0;
}