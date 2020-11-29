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
    return sqrt((double)distance_sq(p1, p2)) ;
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
    double ret  ;
    if(r - l + 1 < 3)
        return 1e15 ;
    else if(r - l + 1 == 3){
        ret  = distance(points[l], points[l+1]) ;
        ret += distance(points[l+1], points[l+2]) ;
        ret += distance(points[l+2], points[l]) ;
        return ret ;
    }

    int mid = (l + r) >> 1 ;
    ret = min(closest(l, mid), closest(mid + 1, r)) ;

    vector<point> temp ;
    double a ;
    for(int i = mid ; i >= l ; i--){
        if(points[mid].x - points[i].x <= ret / 2.0)
            temp.emplace_back(points[i]) ;
        else 
            break ;
    }
    for(int i = mid + 1 ; i <= r ; i++){
        if(points[i].x - points[mid].x <= ret / 2.0)
            temp.emplace_back(points[i]) ;
        else 
            break ;
    }
    sort(temp.begin(), temp.end(), cmp_y()) ;

    for(int i = 0 ; i + 2 < temp.size() ; i++){
        for(int j = i + 1 ; j + 1 < temp.size() ; j++){
            if(temp[j].y-temp[i].y > ret / 2.0)
                break ;
            for(int k = j + 1 ; k < temp.size() ; k++){
                if(temp[k].y-temp[i].y > ret / 2.0)
                    break ;
                double d = distance(temp[i], temp[j]) ;
                d += distance(temp[j], temp[k]) ;
                d += distance(temp[k], temp[i]);
                ret = min(ret, d) ;
            }
        }
    }
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fixed << showpoint << setprecision(3) ;

    int n ;
    while(cin >> n){
        if(n == -1)  break ;

        points.resize(n) ;
        for(auto &i : points)
            cin >> i.x >> i.y ;
        
        sort(points.begin(), points.end(), cmp_x()) ;
        cout << closest(0, n - 1) << endl ;
    }

    return 0;
}