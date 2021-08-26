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
double const pi = acos(-1.0);

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


//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
    int n;
    cin>> n;
    double d, l;
    while(n--)
    {
        cin>> d>> l;
        l /=2;  d/=2;
        cout<< fixed<< showpoint<< setprecision(3)<< l*pi*sqrt(l*l - d*d)<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}