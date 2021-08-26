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
//void scanf(llu &n)
//{
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
//}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    int t;
    double d, v, u, t1, t2;
    cin>> t;
    for(int i=1; i<=t; i++)
    {
        cin>> d>> v>> u;
        cout<< "Case "<< i<< ": ";
        if(u==0 || v==0 || u<=v)
            cout<< "can't determine\n";
        else
        {
            t1 = d/u;
            t2 = d/sqrt(u*u-v*v);
            cout<< fixed<<showpoint<< setprecision(3)<< t2-t1<< endl;
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}