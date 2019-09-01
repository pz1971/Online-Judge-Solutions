#include <bits/stdc++.h>
#define vi vector<int>
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
    std::ios::sync_with_stdio(false);
    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    li n, m;
    bool c;
    while(cin>> n>> m>> c && (m || n || c))
    {
        n -= 7;
        m -= 7;
        n *= m;
        if(c)
            n++;
        n/=2;
        cout<< n<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
