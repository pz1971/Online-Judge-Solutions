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

int big_mod(int b, int p)
{
    if(p==0)    return 1;
    int x = big_mod(b, p/2)%1000;
    x = (x*x)%1000;
    if(p%2) x = (x*b)%1000;
    return x;
}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    int t, n, k;
    double x;
    cin>> t;
    while(t--)
    {
        cin>> n>> k;
        x = k*log10(n);
        x -= static_cast<int>(x);
        x = pow(10, x) * 100;
        cout<< (int)x<< "..."<< setw(3)<<setfill('0')<< big_mod(n%1000, k)<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
