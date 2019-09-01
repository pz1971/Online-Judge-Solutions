#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
//void scanf(int &n)
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


    ui a{}, b{}, c{};
    while(cin>> a>> b>> c)
    {
        if(a==0 && b==0 && c==0)
            break;
        if(b < c)
            swap(b, c);
        if(a < b)
            swap(a, b);
        if((a*a == b*b + c*c) && a!=1 && a!=0 && b!=0 && c!=0 && b+c > a)
            cout<< "right"<< endl;
        else
            cout<< "wrong"<< endl;
    }


///   ///   ///   ///   ///   ///   ///
return 0;
}
