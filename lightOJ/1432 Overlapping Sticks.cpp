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
    LL t, id ;
    line_segment()
    : A(), D(), t{0} { }
    line_segment(point a, point b, LL ii){
        id = ii ;
        if(a > b)
            swap(a, b) ;
        A = a ;
        D.x = b.x - a.x ;
        D.y = b.y - a.y ;
        LL g = __gcd(abs(D.x), abs(D.y)) ;
        D.x /= g ; D.y /= g ;
        if(D.x == 0)
            t = (b.y - a.y) / D.y ;
        else
            t = (b.x - a.x) / D.x ;
        
        LX = A ;
        if(D.x != 0){
            LL d = A.x / D.x ;
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
    return os << "{" << obj.id << " " << obj.A << ", " << obj.D << ", " << obj.t << ", " << obj.LX << "}" ;
}

class cmp_line_segments{
public :
    bool operator () (const line_segment &ls1, const line_segment &ls2){
        return (ls1.D < ls2.D) || (ls1.D == ls2.D && ls1.LX < ls2.LX) 
            || (ls1.D == ls2.D && ls1.LX == ls2.LX && ls1.A < ls2.A);
    }
} ;

LL count_overlaping_pairs(vector<line_segment> &ar){
    if(ar.size() <= 1)
        return 0 ;
    vector<pair<LL, int> > Events ;
    for(const auto &i : ar){
        if(i.D.x == 0){
            Events.push_back(make_pair(i.A.y, 1)) ;
            Events.push_back(make_pair(i.A.y + i.D.y * i.t, 0)) ;
        }
        else{
            Events.push_back(make_pair(i.A.x, 1)) ;
            Events.push_back(make_pair(i.A.x + i.D.x * i.t, 0)) ;
        }
    }

    sort(Events.begin(), Events.end()) ;
    LL cnt = 0, cur = 0 ;
    for(auto i : Events){
        if(i.second == 1)
            cur++ ;
        else{
            cnt += --cur ;
        }
    }
    return cnt ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        cin >> n ;
        
        vector<line_segment> ar ;
        point a, b ;
        for(int i = 0 ; i < n ; i++){
            cin >> a.x >> a.y ;
            cin >> b.x >> b.y ;
            ar.emplace_back(line_segment(a, b, i+1)) ;
        }

        sort(ar.begin(), ar.end(), cmp_line_segments()) ;

        vector<line_segment> on_same_line ;
        LL ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(on_same_line.empty() || (ar[i].D == on_same_line.back().D && ar[i].LX == on_same_line.back().LX))
                on_same_line.emplace_back(ar[i]) ;
            else{
                ans += count_overlaping_pairs(on_same_line) ;
                on_same_line.clear() ;
                on_same_line.emplace_back(ar[i]) ;
            }
        }
        if(!on_same_line.empty())
            ans += count_overlaping_pairs(on_same_line) ;
        
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}