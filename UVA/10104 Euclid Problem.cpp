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

int egcd(int a, int b, int &x, int &y)
{
    if(a==0)
    {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = egcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    int a, b, x, y, g;
    while(cin>> a>> b)
    {
        g = egcd(a, b, x, y);
        if(a==b && x > y)   swap(x, y);
        cout<< x<< " "<< y<< " "<< g<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}