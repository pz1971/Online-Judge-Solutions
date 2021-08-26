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


    vector<ll> fib{1, 2};
    for(int i=2; i<55; i++)
    {
        fib.push_back(fib.at(i-1)+fib.at(i-2));
    }
    int t{}, n{};
    cin>> t;
    for(int i=1; i<=t; i++)
    {
        cin>> n;
        cout<< "Scenario #"<< i<< ":"<< endl<< fib.at(n)<< endl<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}