#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

class point{
public:
    double x, y ;
    point()
    : x{0.0}, y{0.0} { }
    point(double a, double b)
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
double distance_sq(const point &p1, const point &p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}
double distance(const point &p1, const point &p2){
    return sqrt(distance_sq(p1, p2)) ;
}

class cmp_x{
public:
    bool operator () (const point &p1, const point &p2){
        return (p1.x < p2.x) ;
    }
} ;
class cmp_y{
public:
    bool operator () (const point &p1, const point &p2){
        return (p1.y < p2.y) ;
    }
} ;

vector<point> points ;

double closest(int l, int r){
    double ret = 1e15 ;
    if(r - l + 1 <= 3){
        for(int i = l ; i + 1 <= r ; i++)
            for(int j = i + 1 ; j <= r ; j++)
                ret = min(ret, distance(points[i], points[j])) ;
        return ret ;
    }

    int mid = (l + r) >> 1 ;
    ret = min(closest(l, mid), closest(mid + 1, r)) ;

    vector<point> temp ;
    for(int i = mid ; i >= l ; i--){
        if(abs(points[i].x - points[mid].x) <= ret)
            temp.emplace_back(points[i]) ;
        else 
            break ;
    }
    for(int i = mid + 1 ; i <= r ; i++){
        if(abs(points[i].x - points[mid].x) <= ret)
            temp.emplace_back(points[i]) ;
        else 
            break ;
    }
    sort(temp.begin(), temp.end(), cmp_y()) ;

    for(int i = 0 ; i + 1 < temp.size() ; i++){
        for(int j = i + 1 ; j < temp.size() ; j++){
            if(temp[j].y - temp[i].y > ret)
                break ;
            ret = min(ret, distance(temp[i], temp[j])) ;
        }
    }
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fixed << showpoint << setprecision(4) ;

    int n ;
    while(cin >> n){
        if(!n)  break ;

        points.resize(n) ;
        
        for(auto &i : points)
            cin >> i.x >> i.y ;
        
        sort(points.begin(), points.end(), cmp_x()) ;

        double ans = closest(0, n - 1) ;
        if(ans < 10000.0)
            cout << ans << endl ;
        else 
            cout << "INFINITY" << endl ;
    }

    return 0;
}