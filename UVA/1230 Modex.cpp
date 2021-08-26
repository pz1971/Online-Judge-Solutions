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
//void scanf(int &n)
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

int big_mod(int b, int p, int m)
{
    if(p==0)    return 1%m;
    int x = big_mod(b, p/2, m)%m;
    x = (x*x)%m;
    if(p%2) x = (x*b)%m;
    return x;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    int t, a, b, m;
    while(cin>> t && t)
    {
        while(t--)
        {
            cin>> a>> b>> m;
            cout<< big_mod(a, b, m)<< endl;
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
