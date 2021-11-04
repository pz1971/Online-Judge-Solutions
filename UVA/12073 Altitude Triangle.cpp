#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

class point{
public:
   double x, y ;
   point()
   : x{0}, y{0} { }
   point(double a, double b)
   : x{a}, y{b} { }
} ;
inline double distance_sq(const point &p1, const point &p2){
   return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ;
}
inline double distance(const point &p1, const point &p2){
   return sqrt(distance_sq(p1, p2)) ;
}

pair<double, double> perpendicular(point O, point X)
{
    // returns m, c of the equation :  y = mx + c
    double m = (O.y - X.y) / (O.x - X.x) ;
    m = -1.0 / m ;
    double c = X.y - m * X.x ;
    return make_pair(m, c) ;
}

point intersection(double m1, double c1, double m2, double c2)
{
    double x = (c2 - c1) / (m1 - m2) ;
    double y = m1 * x + c1 ;
    return point(x, y) ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x1, x2, x3, y1, y2, y3 ;
    int tc = 0 ;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        if(!(x1 | y1 | x2 | y2 | x3 | y3))
            break ;
        
        point A, B, C ;
        A = point(x1, y1) ;
        B = point(x2, y2) ;
        C = point(x3, y3) ;

        double a = distance(B, C) ;
        double b = distance(A, C) ;
        double c = distance(A, B) ;
        
        point O ( (a*x1 + b*x2 + c*x3)/(a+b+c) , (a*y1 + b*y2 + c*y3)/(a+b+c)  ) ;

        auto DE = perpendicular(O, C) ;
        auto DF = perpendicular(O, B) ;
        auto EF = perpendicular(O, A) ;

        point D = intersection(DE.first, DE.second,  DF.first, DF.second) ;
        point E = intersection(DE.first, DE.second,  EF.first, EF.second) ;
        point F = intersection(EF.first, EF.second,  DF.first, DF.second) ;

        cout << fixed << showpoint << setprecision(3) ;
        cout<< "Case "<< ++tc<< ":" << endl ;
        cout << D.x << " " << D.y << endl ;
        cout << E.x << " " << E.y << endl ;
        cout << F.x << " " << F.y << endl ;
    }

    return 0;
}
