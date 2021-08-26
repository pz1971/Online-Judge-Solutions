#include <bits/stdc++.h>
#define pi acos(-1)
#define vi vector<int>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
//void scanf(li &n)
//{
//    bool negative = false;
//    char c;
//    n = 0;
//    c = getchar();
//    if (c=='-')
//    {
//        negative = true;
//        c = getchar();
//    }
//    for (; (c>47 && c<58); c=getchar())
//        n = n*10 + c - 48;
//    if (negative)
//        n *= -1;
//}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    double a{}, b{}, c{}, s{}, r1{}, r2{}, t{};
    while(cin>> a>> b >> c)
    {
        s = (a+b+c)/2;
        t = sqrt(fabs(s*(s-a)*(s-b)*(s-c)));
        r1 = a*b*c/(4*t);
        r2 = t/s;
        cout<< fixed<< setprecision(4) << pi*r1*r1 - t<< " "<< t - pi*r2*r2<< " "<< pi*r2*r2<< endl;
    }


///   ///   ///   ///   ///   ///   ///
return 0;
}
