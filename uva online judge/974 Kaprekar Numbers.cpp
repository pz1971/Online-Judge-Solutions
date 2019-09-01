#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
void scanf(lu &n)
 {
     bool negative = false;
     char c;
     n = 0;
     c = getchar();
     if (c=='-')
     {
         negative = true;
         c = getchar();
     }
     for (; (c>47 && c<58); c=getchar())
         n = n*10 + c - 48;
     if (negative)
         n *= -1;
 }

bool chk_kn(lu x)
{
    lu y{x*x};
    lu y2{y};
    int d{};
    while(y2)
    {
        d++;
        y2/=10;
    }
    y2 = 10;
    bool yes{false};
    for(int i=1; i<d; i++)
    {
        if(y%y2!=0 && y/y2!=0)
        {
            if((y%y2) + (y/y2) == x)
                return true;
        }
        y2*=10;
    }
    return false;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int t{}, tc;
    cin>> t;
    cin.ignore();
    lu a, b;
    for(tc = 1; tc<=t; tc++)
    {
        scanf(a),   scanf(b);
        cout<< "case #"<< tc<< endl;
        bool yes{0};
        for(lu i=a; i<=b; i++)
        {
            if(chk_kn(i))
            {
                yes = 1;
                cout<< i<< endl;
            }
        }
        if(!yes)
            cout<< "no kaprekar numbers"<< endl;
        if(tc!=t)
            cout<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
