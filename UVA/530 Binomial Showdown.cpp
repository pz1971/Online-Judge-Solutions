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
//double const pi = acos(-1.0);

//void scanf(ll &n)
// {
//     bool negative = false;
//     char c;
//     n = 0;
//     c = getchar();
//     if (c=='-')
//     {
//         negative = true;
//         c = getchar();
//     }
//     for (; (c>47 && c<58); c=getchar())
//         n = n*10 + c - 48;
//     if (negative)
//         n *= -1;
// }

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int n2{}, m2{};
    while(cin>> n2>> m2)
    {
        if(n2==0 && m2==0)
            break;
        int m{m2}, n{n2};
        if(m > n-m2)
            m = n-m2;
        double ans{1};
        for(int i=1; i<=m; i++)
        {
            ans *= (n*1.0)/(i*1.0);
            n--;
        }
        cout<< fixed<< setprecision(0)<< ans<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}